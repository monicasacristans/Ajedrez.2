#include "GestionJugadas.h"

using namespace std;

casilla GestionJugadas::encontrarPosicionRey(color col) {
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
bool GestionJugadas::jaque(color col) {
	//ENCONTRAR AL REY 
	casilla posRey = encontrarPosicionRey(col);

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
				if (pieza->movimientoValido(origen, destino, tablero)) {
					cout << "REY EN JAQUE" << endl;
					return true; // El rey está en jaque
				}
			}
		}
	}

	return false; // El rey no está en jaque
}

bool GestionJugadas::jaque_mate(color col) {
	// Verificar primero si el rey está en jaque
	if (!jaque(col)) {
		return false; // El rey no está en jaque, por lo tanto no hay jaque mate
	}
	//ENCONTRAR AL REY 
	casilla posRey = encontrarPosicionRey(col);
	// Iterar sobre todas las piezas del color dado


	for (int y = 0; y < max_y; ++y) {
		for (int x = 0; x < max_x; ++x) {
			if (tablero[y][x] != nullptr && tablero[y][x]->getColor() == col) {
				// Obtener los movimientos válidos de la pieza actual
				casilla origen = { x, y };
				for (int destY = 0; destY < max_y; ++destY) {
					for (int destX = 0; destX < max_x; ++destX) {
						casilla destino = { destX, destY };
						if (tablero[y][x]->movimientoValido(origen, destino, tablero)) {
							// Intentar mover la pieza y verificar si el rey sigue en jaque
							Pieza* piezaTemporal = tablero[destY][destX];
							tablero[destY][destX] = tablero[y][x];
							tablero[y][x] = nullptr;

							bool sigueEnJaque = jaque(col);

							// Deshacer el movimiento
							tablero[y][x] = tablero[destY][destX];
							tablero[destY][destX] = piezaTemporal;

							if (!sigueEnJaque) {
								return false; // Hay al menos un movimiento legal que evita el jaque mate
							}
						}
					}
				}
			}
		}
	}
	cout << "REY EN JAQUE MATE" << endl;
	return true; // No hay movimientos legales disponibles para evitar el jaque mate
}