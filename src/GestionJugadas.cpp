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


bool::GestionJugadas::verificarEnroque(color jugador, Pieza* tablero[max_y][max_x]) {
	// Verificar si la pieza en la casilla de origen es un Rey
	int reyY = (jugador == color::blanco) ? 0 : max_y - 1;
	int reyX = 5;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);
	if (rey == nullptr || !(rey->haSidoMovido())) {
		return false; // No es un rey o ya se ha movido
	}

	//comprobamos que es una torre y que no ha sido movido
	//ENROQUE CORTO
	int torreX_dcha = max_x - 1;
	Torre* torre_derecha = dynamic_cast<Torre*>(tablero[reyY][torreX_dcha]);
	bool enroqueDerechaPosible = (torre_derecha != nullptr && torre_derecha->haSidoMovido()); 
	
	if (enroqueDerechaPosible) {
		for (int x = reyX + 1; x < torreX_dcha; x++) {
			if (tablero[reyY][x] != nullptr) {
				enroqueDerechaPosible = false; // Hay una pieza en el camino
				break;
			}
		}
	}

	//ENROQUE LARGO
	int torreX_izqd = 0;
	Torre* torre_izquierda = dynamic_cast<Torre*>(tablero[reyY][torreX_izqd]);
	bool enroqueIzquierdaPosible = (torre_izquierda != nullptr && torre_izquierda->haSidoMovido());
	if (enroqueIzquierdaPosible) {
		for (int x = reyX - 1; x > torreX_izqd; x--) {
			if (tablero[reyY][x] != nullptr) {
				enroqueIzquierdaPosible = false; // Hay una pieza en el camino
				break;
			}
		}
	}
	return enroqueDerechaPosible || enroqueIzquierdaPosible;
}

/////////CLICKANDO PRIMERO REY Y DESPUES TORRE SE HACE EL ENROQUE
//bool GestionJugadas::enroque(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
//	Pieza* rey = tablero[origen.y][origen.x];
//	if (rey == nullptr || rey->getTipo() != tipo::rey) {
//		return false; // No hay rey en la posición de origen
//	}
//
//	// Diferencia de columnas entre origen y destino
//	int movX = destino.x - origen.x;
//
//	// Verificar enroque corto (movimiento a la derecha del rey)
//	if (movX == 5 && rey->getColor() == color::blanco && rey->haSidoMovido() == false) {
//		if (tablero[origen.y][origen.x + 1] == nullptr && tablero[origen.y][origen.x + 2] == nullptr && tablero[origen.y][origen.x + 3] == nullptr && tablero[origen.y][origen.x + 4] == nullptr) {
//			Pieza* torre = tablero[origen.y][origen.x + 5];
//			if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
//				// Realizar el movimiento del enroque
//				tablero[origen.y][origen.x + 2] = rey;
//				tablero[origen.y][origen.x] = nullptr;
//				tablero[origen.y][origen.x + 3] = torre;
//				tablero[origen.y][origen.x + 5] = nullptr;
//				rey->marcarComoMovido();
//				torre->marcarComoMovido();
//
//				return true;
//			}
//		}
//	}
//	// Verificar enroque largo (movimiento a la izquierda del rey)
//	else if (movX == -4 && rey->getColor() == color::blanco && rey->haSidoMovido() == false) {
//		if (tablero[origen.y][origen.x - 1] == nullptr && tablero[origen.y][origen.x - 2] == nullptr && tablero[origen.y][origen.x - 3] == nullptr) {
//			Pieza* torre = tablero[origen.y][origen.x - 4];
//			if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
//				// Realizar el movimiento del enroque
//				tablero[origen.y][origen.x - 2] = rey;
//				tablero[origen.y][origen.x] = nullptr;
//				tablero[origen.y][origen.x - 1] = torre;
//				tablero[origen.y][origen.x - 4] = nullptr;
//				rey->marcarComoMovido();
//				torre->marcarComoMovido();
//
//				return true;
//			}
//		}
//	}
//
//	// Enroque para el rey negro
//	if (movX == -4 && rey->getColor() == color::negro && rey->haSidoMovido() == false) {
//		if (tablero[origen.y][origen.x - 1] == nullptr && tablero[origen.y][origen.x - 2] == nullptr && tablero[origen.y][origen.x - 3] == nullptr) {
//			Pieza* torre = tablero[origen.y][origen.x - 4];
//			if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
//				// Realizar el movimiento del enroque
//				tablero[origen.y][origen.x - 2] = rey;
//				tablero[origen.y][origen.x] = nullptr;
//				tablero[origen.y][origen.x - 1] = torre;
//				tablero[origen.y][origen.x - 4] = nullptr;
//				rey->marcarComoMovido();
//				torre->marcarComoMovido();
//
//				return true;
//			}
//		}
//	}
//	// Verificar enroque largo (movimiento a la derecha del rey)
//	else if (movX == 5 && rey->getColor() == color::negro && rey->haSidoMovido() == false) {
//		if (tablero[origen.y][origen.x + 1] == nullptr && tablero[origen.y][origen.x + 2] == nullptr && tablero[origen.y][origen.x + 3] == nullptr && tablero[origen.y][origen.x + 4] == nullptr) {
//			Pieza* torre = tablero[origen.y][origen.x + 5];
//			if (torre != nullptr && torre->getTipo() == tipo::torre && torre->haSidoMovido() == false) {
//				// Realizar el movimiento del enroque
//				tablero[origen.y][origen.x + 2] = rey;
//				tablero[origen.y][origen.x] = nullptr;
//				tablero[origen.y][origen.x + 3] = torre;
//				tablero[origen.y][origen.x + 5] = nullptr;
//				rey->marcarComoMovido();
//				torre->marcarComoMovido();
//
//				return true;
//			}
//		}
//	}
//
//	return false;
//}

bool GestionJugadas::reySaleDeJaque(color col, Pieza* tablero[max_y][max_x]) {
	// Encontrar la posicion del rey
	casilla posRey = encontrarPosicionRey(col, tablero);

	// Verificar todas las casillas alrededor del rey para ver si puede moverse a una casilla segura
	std::vector<casilla> movimientosRey = {
		{posRey.x, posRey.y + 1}, {posRey.x, posRey.y - 1}, {posRey.x + 1, posRey.y},
		{posRey.x - 1, posRey.y}, {posRey.x + 1, posRey.y + 1}, {posRey.x + 1, posRey.y - 1},
		{posRey.x - 1, posRey.y + 1}, {posRey.x - 1, posRey.y - 1}
	};

	for (const auto& movimiento : movimientosRey) {
		if (movimiento.x >= 0 && movimiento.x < max_x && movimiento.y >= 0 && movimiento.y < max_y &&
			(tablero[movimiento.y][movimiento.x] == nullptr || tablero[movimiento.y][movimiento.x]->getColor() == col)) {

			// Simular el movimiento del rey
			Pieza* piezaDestino = tablero[movimiento.y][movimiento.x];
			tablero[movimiento.y][movimiento.x] = tablero[posRey.y][posRey.x];
			tablero[posRey.y][posRey.x] = nullptr;

			// Verificar si el rey sigue en jaque
			bool estaEnJaque = !jaque(col, tablero);

			// Restaurar el estado original del tablero
			tablero[posRey.y][posRey.x] = tablero[movimiento.y][movimiento.x];
			tablero[movimiento.y][movimiento.x] = piezaDestino;

			if (estaEnJaque == true) {
				return true; // Se encontró una pieza que puede sacar al rey de jaque
			}
			else {
				return false;// No se encontró una pieza que puede sacar al rey de jaque
			}
		}
	}

	// Verificar si alguna pieza del mismo color puede proteger al rey
	for (const auto& movimiento : movimientosRey) {
		if (movimiento.x >= 0 && movimiento.x < max_x && movimiento.y >= 0 && movimiento.y < max_y &&
			(tablero[movimiento.y][movimiento.x] == nullptr || tablero[movimiento.y][movimiento.x]->getColor() != col)) {

			for (int y = 0; y < max_y; y++) {
				for (int x = 0; x < max_x; x++) {
					Pieza* pMiColor = tablero[y][x];

					if (pMiColor != nullptr && pMiColor->getColor() == col) {
						casilla origen = { x, y };

						if (pMiColor->movimientoValido(origen, movimiento, tablero)) {
							// Simular el movimiento para comprobar si saca al rey del jaque
							Pieza* piezaDestino = tablero[movimiento.y][movimiento.x];
							tablero[movimiento.y][movimiento.x] = pMiColor;
							tablero[y][x] = nullptr;

							bool estaEnJaque = !jaque(col, tablero);

							// Restaurar el estado original del tablero
							tablero[y][x] = pMiColor;
							tablero[movimiento.y][movimiento.x] = piezaDestino;

							if (estaEnJaque == true) {
								return true; // Se encontró una pieza que puede sacar al rey de jaque
							}
							else {
								return false;// No se encontró una pieza que puede sacar al rey de jaque
							}
						}
					}
				}
			}
		}
	}

	return false; // No se encontró ninguna forma de sacar al rey del jaque
}


bool GestionJugadas::jaque_mate(color col, Pieza* tablero[max_y][max_x]) {
	//Primero, verificar si el rey esta en jaque
	if (jaque(col, tablero) == false) {
		return false; // Si no esta en jaque, no puede estar en jaque mate, y si sale del jaque tampoco
	}
	else if (reySaleDeJaque(col, tablero) == false) {
		return true;
	}
	else return false;
}


//

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





