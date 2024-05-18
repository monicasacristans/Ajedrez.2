#include "GestionJugadas.h"

using namespace std;

casilla GestionJugadas::encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]) {
	// Buscar la posición del rey del color dado en el tablero
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			if (tablero[y][x] != nullptr && tablero[y][x]->getTipo() == tipo::rey && tablero[y][x]->getColor() == col) {
				return { x, y };
			}
		}
	}
	return { -1, -1 }; // Retornar posición inválida si no se encuentra el rey
}




//en un turno, has de comprobar si puedes hacer jaque al rival
bool GestionJugadas::jaque(color col, Pieza* tablero[max_y][max_x]) {
	//ENCONTRAR AL REY 
	casilla posRey = encontrarPosicionRey(col, tablero);

	// Verifica si el rey fue encontrado
	if (posRey.x == -1 && posRey.y == -1) {
		return false; // No se encontró el rey del color dado
	}

	// Verifica si alguna pieza del oponente puede atacar al rey
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			Pieza* pieza = tablero[y][x];
			if (pieza != nullptr && pieza->getColor() != col) {
				casilla origen = { x, y };
				casilla destino = { posRey.x, posRey.y };
				if (pieza->movimientoValido(origen, destino, tablero) == true) {
					return true; // El rey está en jaque
				}
			}
		}
	}
	return false; // El rey no está en jaque
}

bool GestionJugadas::sacardeJaque(color col, Pieza* tablero[max_y][max_x]) {
	if (jaque(col, tablero) == true) {
		//Recorre todas las piezas del tablero
		for (int y = 0; y < max_y; y++) {
			for (int x = 0; x < max_x; x++) {
				Pieza* pieza = tablero[y][x];
				if (pieza != nullptr && pieza->getColor() == col) {
					casilla origen = { x, y };

					// Verificar si la pieza puede moverse a una casilla para proteger al rey
					for (int yDest = 0; yDest < max_y; yDest++) {
						for (int xDest = 0; xDest < max_x; xDest++) {
							casilla destino = { xDest, yDest };
							if (pieza->movimientoValido(origen, destino, tablero)) {
								// Simular el movimiento para comprobar si saca al rey del jaque
								Pieza* piezaDestino = tablero[yDest][xDest];
								tablero[yDest][xDest] = pieza;
								tablero[y][x] = nullptr;

								if (jaque(col, tablero) == false) {
									// Restaurar el estado original del tablero
									tablero[y][x] = pieza;
									tablero[yDest][xDest] = piezaDestino;
									return true; // Se encontró una pieza que puede sacar al rey de jaque
								}

								// Restaurar el estado original del tablero
								tablero[y][x] = pieza;
								tablero[yDest][xDest] = piezaDestino;
							}
						}
					}
				}
			}
		}
	}
	return false;
}


bool GestionJugadas::jaque_mate(color col, Pieza* tablero[max_y][max_x]) {
	// Primero, verificar si el rey esta en jaque
	if (jaque(col, tablero) == false) {
		return false; // Si no esta en jaque, no puede estar en jaque mate
	}

	// Encontrar la posicion del rey
	casilla posRey = encontrarPosicionRey(col, tablero);

	// Verificar todas las casillas alrededor del rey para ver si puede moverse a una casilla segura
	std::vector<casilla> movimientosRey = {
		{posRey.x, posRey.y + 1}, {posRey.x, posRey.y - 1}, {posRey.x + 1, posRey.y},
		{posRey.x - 1, posRey.y}, {posRey.x + 1, posRey.y + 1}, {posRey.x + 1, posRey.y - 1},
		{posRey.x - 1, posRey.y + 1}, {posRey.x - 1, posRey.y - 1}
	};

	for (const auto& movimiento : movimientosRey) {
		if (movimiento.x >= 0 && movimiento.x < max_x && movimiento.y >= 0 && movimiento.y < max_y && (tablero[movimiento.y][movimiento.x] == nullptr || tablero[movimiento.y][movimiento.x]->getColor() != col)) {
			// Mover temporalmente al rey para verificar si sale del jaque
			Pieza* piezaDestino = tablero[movimiento.y][movimiento.x];
			tablero[movimiento.y][movimiento.x] = tablero[posRey.y][posRey.x];
			tablero[posRey.y][posRey.x] = nullptr;

			if (jaque(col, tablero) == false) {
				// Restaurar el movimiento y retornar falso
				tablero[posRey.y][posRey.x] = tablero[movimiento.y][movimiento.x];
				tablero[movimiento.y][movimiento.x] = piezaDestino;
				return false; // El rey puede salir del jaque, no es jaque mate
			}

			// Restaurar el movimiento
			tablero[posRey.y][posRey.x] = tablero[movimiento.y][movimiento.x];
			tablero[movimiento.y][movimiento.x] = piezaDestino;
		}
	}

	// Si todas las casillas alrededor del rey estan en jaque o fuera del tablero, es jaque mate
	return true;

}

color GestionJugadas::peonFinal(casilla origen,Pieza* tablero[max_y][max_x]) {

	//for (int y = 0; y < max_y; y++) {
		if (tablero[origen.y][7] != nullptr && tablero[origen.y][7]->getColor() == color::blanco && tablero[origen.y][7]->getTipo() == tipo::peon) {
			return color::blanco;
		}
	//}

	//for (int y = 0; y < max_y; y++) {
		if (tablero[origen.y][0] != nullptr && tablero[origen.y][0]->getColor() == color::negro && tablero[origen.y][0]->getTipo() == tipo::peon) {
			return color::negro;
			//break; 
		}
	//}

	return color::ninguno;


}



bool GestionJugadas::promocion(casilla cas, Pieza *tablero[max_y][max_x] ) {
	
	/*const std::vector<Pieza*>& negras = tablero->getPiezasEliminadasN();
	const std::vector<Pieza*>& blancas = tab->getPiezasEliminadasB();*/
	//casilla cas;
	//Tablero* tab = nullptr;

	if(peonFinal(cas, tablero) != color::ninguno) {
		
		for (auto a : tab->getPiezasEliminadasB()) {
			cout << a << endl;
		}
		return true;
	}
	

}



