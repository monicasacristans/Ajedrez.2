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
							if (pieza->movimientoValido(origen, destino, tablero) == true) {
								// Simular el movimiento para comprobar si saca al rey del jaque
								Pieza* piezaDestino = tablero[yDest][xDest];
								tablero[yDest][xDest] = pieza;
								tablero[y][x] = nullptr;

								bool estaEnJaque = jaque(col, tablero);

								// Restaurar el estado original del tablero
								tablero[y][x] = pieza;
								tablero[yDest][xDest] = piezaDestino;

								if (!estaEnJaque) {
									return true; // Se encontró una pieza que puede sacar al rey de jaque
								}
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

			if (jaque(col, tablero) == true) {
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

bool GestionJugadas::peonFinal(casilla origen) {

	if (origen.y == 7 ||origen.y == 0) {
		return true;
	}
	else {
		return false;
	}
	
}



void GestionJugadas::promocion(casilla cas, Pieza *tablero[max_y][max_x] ) {
	
	Pieza* p = tablero[cas.y][cas.x];
	auto& listapiezas = (p->getColor() == color::blanco) ? tab->getPiezasEliminadasB() : tab->getPiezasEliminadasN();

	cout << tab->getPiezasEliminadasN().size();
	// Solicitar al usuario que elija una pieza para la promoción
	std::cout << "Piezas disponibles para la promoción: " << std::endl;
	int i = 1;
		for (Pieza* pieza: listapiezas) {
			std::cout <<i<<": "<< pieza << " , " << std::endl;
			i++;
		}

		int eleccion = 0;
		cout << "Elige una nueva pieza para la promocion del peon:" << endl;
		cout << "1-Reina\n 2-Torre\n 3-Alfil\n 4-Caballo\n 5-Canciller\n6-Arzobispo\n";
		Pieza* nuevaPieza = nullptr;
		cin >> eleccion;
		switch (eleccion) {
		case 1:
			nuevaPieza = new Reina(tipo::reina, p->getColor());
			break;
		case 2:
			nuevaPieza = new Torre(tipo::torre, p->getColor());
			break;
		case 3:
			nuevaPieza = new Alfil(tipo::alfil, p->getColor());
			break;
		case 4:
			nuevaPieza = new Caballo(tipo::caballo, p->getColor());
			break;
		case 5:
			nuevaPieza = new Canciller(tipo::canciller, p->getColor());
			break;
		case 6:
			nuevaPieza = new Arzobispo(tipo::arzobispo, p->getColor());
			break;
		default:
			break;
		}

		if (nuevaPieza != NULL) {
			tablero[cas.y][cas.x] = nuevaPieza;
			delete p; //elimino el peon
		}
		
	
}





