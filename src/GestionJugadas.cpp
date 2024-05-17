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
	if (tablero == nullptr) {
		return false;
	}
	// Verifica si alguna pieza del oponente puede atacar al rey
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			Pieza* pieza = tablero[y][x];
			if (pieza != nullptr && pieza->getColor() != col) {
				casilla origen = { x, y };
				casilla destino = { posRey.x, posRey.y };
				if (pieza->movimientoValido(origen, destino, tablero) == true) {
					//cout << "REY EN JAQUE" << endl;
					return true; // El rey está en jaque
				}
			}
		}
	}
	return false; // El rey no está en jaque
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

//bool GestionJugadas::jaque_mate(color col, Pieza* tablero[max_y][max_x]) {
//	// Verificar primero si el rey está en jaque
//	if (!jaque(col, tablero)) {
//		return false; // El rey no está en jaque, por lo tanto no hay jaque mate
//	}
//	//ENCONTRAR AL REY 
//	casilla posRey = encontrarPosicionRey(col,tablero);
//	// Iterar sobre todas las piezas del color dado
//
//
//	for (int y = 0; y < max_y; ++y) {
//		for (int x = 0; x < max_x; ++x) {
//			if (tablero[y][x] != nullptr && tablero[y][x]->getColor() == col) {
//				// Obtener los movimientos válidos de la pieza actual
//				casilla origen = { x, y };
//				for (int destY = 0; destY < max_y; ++destY) {
//					for (int destX = 0; destX < max_x; ++destX) {
//						casilla destino = { destX, destY };
//						if (tablero[y][x]->movimientoValido(origen, destino, tablero)) {
//							// Intentar mover la pieza y verificar si el rey sigue en jaque
//							Pieza* piezaTemporal = tablero[destY][destX];
//							tablero[destY][destX] = tablero[y][x];
//							tablero[y][x] = nullptr;
//
//							bool sigueEnJaque = jaque(col,tablero);
//
//							// Deshacer el movimiento
//							tablero[y][x] = tablero[destY][destX];
//							tablero[destY][destX] = piezaTemporal;
//
//							if (!sigueEnJaque) {
//								return false; // Hay al menos un movimiento legal que evita el jaque mate
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << "REY EN JAQUE MATE" << endl;
//	return true; // No hay movimientos legales disponibles para evitar el jaque mate
//}

bool GestionJugadas::enroque(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
    Pieza* rey = tablero[origen.y][origen.x];
    if (rey == nullptr || rey->getTipo() != tipo::rey) {
        return false; // No hay rey en la posición de origen
    }

    // Diferencia de columnas entre origen y destino
    int movX = destino.x - origen.x;

    // Verificar enroque corto (movimiento a la derecha del rey)
    if (movX == 2 && rey->getColor() == color::blanco && rey->haSidoMovido() == false) {
        if (tablero[origen.y][origen.x + 1] == nullptr && tablero[origen.y][origen.x + 2] == nullptr) {
            Pieza* torre = tablero[origen.y][origen.x + 3];
            if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
                // Realizar el movimiento del enroque
                tablero[origen.y][origen.x + 2] = rey;
                tablero[origen.y][origen.x] = nullptr;
                tablero[origen.y][origen.x + 1] = torre;
                tablero[origen.y][origen.x + 3] = nullptr;
                rey->marcarComoMovido();
                torre->marcarComoMovido();
                return true;
            }
        }
    }
    // Verificar enroque largo (movimiento a la izquierda del rey)
    else if (movX == -2 && rey->getColor() == color::blanco && rey->haSidoMovido() == false) {
        if (tablero[origen.y][origen.x - 1] == nullptr && tablero[origen.y][origen.x - 2] == nullptr && tablero[origen.y][origen.x - 3] == nullptr) {
            Pieza* torre = tablero[origen.y][origen.x - 4];
            if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
                // Realizar el movimiento del enroque
                tablero[origen.y][origen.x - 2] = rey;
                tablero[origen.y][origen.x] = nullptr;
                tablero[origen.y][origen.x - 1] = torre;
                tablero[origen.y][origen.x - 4] = nullptr;
                rey->marcarComoMovido();
                torre->marcarComoMovido();
                return true;
            }
        }
    }

    // Enroque para el rey negro
    if (movX == 2 && rey->getColor() == color::negro && rey->haSidoMovido() == false) {
        if (tablero[origen.y][origen.x + 1] == nullptr && tablero[origen.y][origen.x + 2] == nullptr) {
            Pieza* torre = tablero[origen.y][origen.x + 3];
            if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
                // Realizar el movimiento del enroque
                tablero[origen.y][origen.x + 2] = rey;
                tablero[origen.y][origen.x] = nullptr;
                tablero[origen.y][origen.x + 1] = torre;
                tablero[origen.y][origen.x + 3] = nullptr;
                rey->marcarComoMovido();
                torre->marcarComoMovido();
                return true;
            }
        }
    }
    // Verificar enroque largo (movimiento a la izquierda del rey)
    else if (movX == -2 && rey->getColor() == color::negro && rey->haSidoMovido() == false) {
        if (tablero[origen.y][origen.x - 1] == nullptr && tablero[origen.y][origen.x - 2] == nullptr && tablero[origen.y][origen.x - 3] == nullptr) {
            Pieza* torre = tablero[origen.y][origen.x - 4];
            if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
                // Realizar el movimiento del enroque
                tablero[origen.y][origen.x - 2] = rey;
                tablero[origen.y][origen.x] = nullptr;
                tablero[origen.y][origen.x - 1] = torre;
                tablero[origen.y][origen.x - 4] = nullptr;
                rey->marcarComoMovido();
                torre->marcarComoMovido();
                return true;
            }
        }
    }

    return false;
}
//bool GestionJugadas::getPromocion(color col) {
//	for (int i = 0; i < max_y; i++) {
//		for (int j = 0; j < max_x; j++) {
//			if (tablero[i][j]->getTipo() == tipo::peon && tablero[i][j]->getColor() == col) {
//				if (col == color::negro) {
//					if (j == 0) {
//						return true;
//					}
//				}
//				if (col == color::blanco) {
//					if (j == 9) {
//						return true;
//					}
//				}
//			}
//		}
//	}
//}
//
//
//void GestionJugadas::setPromocion(tipo t) {
//	int pos_x_peon = 0;
//	int pos_y_peon = 0;
//	color col = color::negro;
//	for (int i = 0; i < max_y; i++) {
//		for (int j = 0; j < max_x; j++) {
//			if (tablero[i][j]->getTipo() == tipo::peon && (j == 9 || j == 0)) {
//				if (j == 0) {
//					col = color::negro;
//					pos_x_peon = i;
//					pos_y_peon = j;
//				}
//				if (j == 9) {
//					col = color::blanco;
//					pos_x_peon = i;
//					pos_y_peon = j;
//				}
//			}
//		}
//	}
//	//delete[]tablero;
//
//	//~Tablero(tablero[pos_x_peon][pos_y_peon]);
//	
//
//	if (t == tipo::alfil) {
//		
//		tablero[pos_x_peon][pos_y_peon] = new Alfil(tipo::alfil, col);
//	}
//	if (t == tipo::caballo) {
//		tablero[pos_x_peon][pos_y_peon] = new Caballo(tipo::caballo, col);
//	}
//	if (t == tipo::torre) {
//		tablero[pos_x_peon][pos_y_peon] = new Torre(tipo::torre, col);
//	}
//	if (t == tipo::reina) {
//		tablero[pos_x_peon][pos_y_peon] = new Reina(tipo::reina, col);
//	}
//}
//
//

