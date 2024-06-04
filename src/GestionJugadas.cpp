#include "GestionJugadas.h"

using namespace std;
extern Usuario usuario;

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


bool GestionJugadas::reyPuedeMoverse(color col, Pieza* tablero[max_y][max_x]) {
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
			(tablero[movimiento.y][movimiento.x] == nullptr || tablero[movimiento.y][movimiento.x]->getColor() != col)) {

			// Simular el movimiento del rey
			Pieza* piezaDestino = tablero[movimiento.y][movimiento.x];
			tablero[movimiento.y][movimiento.x] = tablero[posRey.y][posRey.x];
			tablero[posRey.y][posRey.x] = nullptr;

			// Verificar si el rey sigue en jaque
			bool estaEnJaque = jaque(col, tablero);

			// Restaurar el estado original del tablero
			tablero[posRey.y][posRey.x] = tablero[movimiento.y][movimiento.x];
			tablero[movimiento.y][movimiento.x] = piezaDestino;

			if (estaEnJaque == false) {
				return true; // Se encontró una pieza que puede sacar al rey de jaque
			}
		}
	}
	return false; // No se encontró ninguna forma de sacar al rey del jaque
}

bool GestionJugadas::piezaPuedeProteger(color col, Pieza* tablero[max_y][max_x]) {
	// Encontrar la posicion del rey
	casilla posRey = encontrarPosicionRey(col, tablero);

	// Verificar todas las casillas alrededor del rey para ver si puede moverse a una casilla segura
	std::vector<casilla> movimientosRey = {
		{posRey.x, posRey.y + 1}, {posRey.x, posRey.y - 1}, {posRey.x + 1, posRey.y},
		{posRey.x - 1, posRey.y}, {posRey.x + 1, posRey.y + 1}, {posRey.x + 1, posRey.y - 1},
		{posRey.x - 1, posRey.y + 1}, {posRey.x - 1, posRey.y - 1}
	};

	// Verificar si alguna pieza del mismo color puede proteger al rey
	for (const auto& movimiento : movimientosRey) {
		if (movimiento.x >= 0 && movimiento.x < max_x && movimiento.y >= 0 && movimiento.y < max_y && tablero[movimiento.y][movimiento.x] == nullptr) {
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

							bool estaEnJaque = jaque(col, tablero);

							// Restaurar el estado original del tablero
							tablero[y][x] = pMiColor;
							tablero[movimiento.y][movimiento.x] = piezaDestino;

							if (estaEnJaque == false) {
								return true; // Se encontró una pieza que puede sacar al rey de jaque
							}
						}
					}
				}
			}
		}
	}
	return false; // No se encontró forma de sacar al rey del jaque
}

bool GestionJugadas::reySaleDeJaque(color col, Pieza* tablero[max_y][max_x]) {
	if (reyPuedeMoverse(col, tablero) == true || piezaPuedeProteger(col, tablero) == true) {
		return false;//Rey sale del jaque
	}
	else if (reyPuedeMoverse(col, tablero) == false && piezaPuedeProteger(col, tablero) == false) {
		return true;//El rey no ha salido del jaque de ninguna forma, jaque mate
	}
}


bool GestionJugadas::jaque_mate(color col, Pieza* tablero[max_y][max_x]) {
	//Primero, verificar si el rey esta en jaque
	if (jaque(col, tablero) == false){
		return false; // Si no esta en jaque, no puede estar en jaque mate, y si sale del jaque tampoco
	}
	else if (reySaleDeJaque(col, tablero) == false) {
		return false;
	}
	else 
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

Pieza* GestionJugadas::crearPieza(tipo t, color col) {
	switch (t) {
	case tipo::reina:
		return new Reina(tipo::reina, col);
		std::cout << "Se ha creado una reina" << std::endl;
	case tipo::torre:
		return new Torre(tipo::torre, col);
	case tipo::alfil:
		return new Alfil(tipo::alfil, col);
	case tipo::caballo:
		return new Caballo(tipo::caballo, col);
	case tipo::canciller:
		return new Canciller(tipo::canciller, col);
	case tipo::arzobispo:
		return new Arzobispo(tipo::arzobispo, col);
	default:
		return nullptr;
	}
}


void GestionJugadas::promocion(casilla cas, Pieza *tablero[max_y][max_x], int tipo ) {

	
	Pieza* p = tablero[cas.y][cas.x];
	
	std::cout << "Piezas disponibles para la promoción: " << std::endl;
	

		int eleccion = 0;
		cout << "Elige una nueva pieza para la promocion del peon:" << endl;
		cout << "1-Reina\n 2-Torre\n 3-Alfil\n 4-Caballo\n 5-Canciller\n6-Arzobispo\n";
		Pieza* nuevaPieza = nullptr;

		//usuario.teclado(eleccion);

		//cin >> eleccion;
		switch (tipo) {
		case 1:

			nuevaPieza = crearPieza(tipo::reina, p->getColor());
			break;
		case 2:		
			nuevaPieza = crearPieza(tipo::torre, p->getColor());
			break;
		case 3:			
			nuevaPieza = crearPieza(tipo::alfil, p->getColor());
			break;
		case 4:
			nuevaPieza = crearPieza(tipo::caballo, p->getColor());
			break;
		case 5:	
			nuevaPieza = crearPieza(tipo::canciller, p->getColor());
			break;
		case 6:			
			nuevaPieza = crearPieza(tipo::arzobispo, p->getColor());
			break;
		default:
			break;
		}
		if (nuevaPieza != NULL) {
			delete p; //elimino el peon
			tablero[cas.y][cas.x] = nuevaPieza;
			//tab->dibujarPromocion(tablero);
			//dibujarPromocion(tablero[cas.y][cas.x]);
			//nuevaPieza.push_back(tablero[cas.y][cas.x]);
			
		}
			
}

bool::GestionJugadas::verificarEnroqueIzquierda(color jugador, Pieza* tablero[max_y][max_x]) {
	// Verificar si la pieza en la casilla de origen es un Rey
	int reyY = (jugador == color::blanco) ? 0 : max_y - 1;
	int reyX = 5;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);
	if (rey == nullptr || !(rey->haSidoMovido())) {
		return false; // No es un rey o ya se ha movido
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

	return enroqueIzquierdaPosible;

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

	////ENROQUE LARGO
	//int torreX_izqd = 0;
	//Torre* torre_izquierda = dynamic_cast<Torre*>(tablero[reyY][torreX_izqd]);
	//bool enroqueIzquierdaPosible = (torre_izquierda != nullptr && torre_izquierda->haSidoMovido());
	//if (enroqueIzquierdaPosible) {
	//	for (int x = reyX - 1; x > torreX_izqd; x--) {
	//		if (tablero[reyY][x] != nullptr) {
	//			enroqueIzquierdaPosible = false; // Hay una pieza en el camino
	//			break;
	//		}
	//	}
	//}
	return enroqueDerechaPosible;
}

void GestionJugadas::realizarEnroque(color jugador, Pieza* tablero[max_y][max_x]) {
	int reyY = (jugador == color::blanco) ? 0 : max_y - 1;
	int reyX = 5;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);

	// Variables para la torre y las nuevas posiciones del rey y la torre
	Torre* torre = nullptr;
	int torreX = 0;
	int nuevoReyX = 0;
	int nuevaTorreX = 0;

	// ENROQUE CORTO
	int torreX_dcha = max_x - 1;
	Torre* torre_derecha = dynamic_cast<Torre*>(tablero[reyY][torreX_dcha]);

	if ((verificarEnroque(jugador, tablero) == true)) {
		torre = torre_derecha;
		torreX = torreX_dcha;
		nuevoReyX = reyX + 3;
		nuevaTorreX = reyX + 2;

	}
	// ENROQUE LARGO
	else {
		int torreX_izqd = 0;
		Torre* torre_izquierda = dynamic_cast<Torre*>(tablero[reyY][torreX_izqd]);

		if (verificarEnroqueIzquierda(jugador, tablero) == true) {
			torre = torre_izquierda;
			torreX = torreX_izqd;
			nuevoReyX = reyX - 3;
			nuevaTorreX = reyX - 2;
		}
	}
	// Si un enroque es posible, mover las piezas
	if (torre != nullptr) {
		// Mover el rey
		tablero[reyY][nuevoReyX] = rey;
		tablero[reyY][reyX] = nullptr;
		rey->marcarComoMovido();


		// Mover la torre
		tablero[reyY][nuevaTorreX] = torre;
		tablero[reyY][torreX] = nullptr;
		torre->marcarComoMovido();
	}
}







