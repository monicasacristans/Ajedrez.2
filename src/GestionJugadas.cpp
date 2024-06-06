#include "GestionJugadas.h"

using namespace std;
extern Usuario usuario;

casilla GestionJugadas::encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]) {
	
	// Buscar la posici�n del rey del color dado en el tablero
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			if (tablero[y][x] != nullptr && tablero[y][x]->getTipo() == tipo::rey && tablero[y][x]->getColor() == col) {
				return { x, y };
			}
		}
	}
	return { -1, -1 }; // Retornar posici�n inv�lida si no se encuentra el rey
}


bool GestionJugadas::jaque(color col, Pieza* tablero[max_y][max_x]) {
	//ENCONTRAR AL REY 
	casilla posRey = encontrarPosicionRey(col, tablero);

	// Verifica si el rey fue encontrado
	if (posRey.x == -1 && posRey.y == -1) {
		return false; // No se encontr� el rey del color dado
	}

	// Verifica si alguna pieza del oponente puede atacar al rey
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			Pieza* pieza = tablero[y][x];
			if (pieza != nullptr && pieza->getColor() != col) {
				casilla origen = { x, y };
				casilla destino = { posRey.x, posRey.y };
				if (pieza->movimientoValido(origen, destino, tablero) == true) {
					return true; // El rey est� en jaque
				}
			}
		}
	}
	return false; // El rey no est� en jaque
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
		if (movimiento.x >= 0 && movimiento.x < max_x && movimiento.y >= 0 && movimiento.y < max_y && tablero[movimiento.y][movimiento.x] == nullptr) {

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
				return true; // Se encontr� una pieza que puede sacar al rey de jaque
			}
		}
	}
	return false; // No se encontr� ninguna forma de sacar al rey del jaque
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
		if (movimiento.x >= 0 && movimiento.x < max_x && movimiento.y >= 0 && movimiento.y < max_y && (tablero[movimiento.y][movimiento.x] == nullptr || tablero[movimiento.y][movimiento.x]->getColor() != col)) {
			for (int y = 0; y < max_y; y++) {
				for (int x = 0; x < max_x; x++) {
					Pieza* pMiColor = tablero[y][x];
					casilla origen = { x, y };

					if (pMiColor != nullptr && pMiColor->getColor() == col && pMiColor->getTipo() != tipo::rey) {
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
								return true; // Se encontr� una pieza que puede sacar al rey de jaque
							}
						}
					}
				}
			}
		}
	}
	return false; // No se encontr� forma de sacar al rey del jaque
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
	if (reySaleDeJaque(col,tablero) == true) {
		return true;// Jaque mate
	}
	return false;//No hay jaque mate
}

bool GestionJugadas::peonFinal(casilla origen) {
	//Comprobar que el peon ha llegado al otro lado del tablero
	if (origen.y == 7 ||origen.y == 0) {
		return true;
	}
	else {
		return false;
	}
}


void GestionJugadas::promocion(casilla cas, Pieza *tablero[max_y][max_x], int tipo ) {

	Pieza* p = tablero[cas.y][cas.x];
	int eleccion = 0;	
	Pieza* nuevaPieza = nullptr;

	//Creo una nueva pieza del tipo que haya seleccionado
	switch (tipo) {
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
		delete p; //Elimino el peon
		tablero[cas.y][cas.x] = nuevaPieza; //Situo la nueva pieza deonde estaba el peon
	}
}

bool::GestionJugadas::verificarEnroqueIzquierda(color jugador, Pieza* tablero[max_y][max_x]) {
	// Verificar si la pieza en la casilla de origen es un Rey
	int reyY = (jugador == color::blanco) ? 0 : max_y - 1;
	int reyX = 2;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);
	if (rey == nullptr || (rey->haSidoMovido())) {
		return false; // No es un rey o ya se ha movido
	}
	//ENROQUE LARGO
	int torreX_izqd = 0;
	Torre* torre_izquierda = dynamic_cast<Torre*>(tablero[reyY][torreX_izqd]);
	bool enroqueIzquierdaPosible = (torre_izquierda != nullptr && !torre_izquierda->haSidoMovido());
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
	int reyX = 8;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);
	if (rey == nullptr || (rey->haSidoMovido())) {
		return false; // No es un rey o ya se ha movido
	}

	//Comprobamos que es una torre y que no ha sido movido
	//ENROQUE CORTO
	int torreX_dcha = max_x - 1;
	Torre* torre_derecha = dynamic_cast<Torre*>(tablero[reyY][torreX_dcha]);
	bool enroqueDerechaPosible = (torre_derecha != nullptr && !torre_derecha->haSidoMovido());

	if (enroqueDerechaPosible) {
		for (int x = reyX + 1; x < torreX_dcha; x++) {
			if (tablero[reyY][x] != nullptr) {
				enroqueDerechaPosible = false; // Hay una pieza en el camino
				break;
			}
		}
	}

	return enroqueDerechaPosible;
}

void GestionJugadas::realizarEnroqueIzquierda(color jugador, Pieza* tablero[max_y][max_x]) {
	int reyY = (jugador == color::blanco) ? 0 : max_y - 1;
	int reyX = 2;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);
	if (rey == nullptr)return;

	// Variables para la torre y las nuevas posiciones del rey y la torre
	Torre* torre = nullptr;
	int torreX = 0;
	int nuevoReyX = 2;
	int nuevaTorreX = 3;

	// ENROQUE LARGO

	int torreX_izqd = 0;
	Torre* torre_izquierda = dynamic_cast<Torre*>(tablero[reyY][torreX_izqd]);

	if (verificarEnroqueIzquierda(jugador, tablero) == true) {
		torre = torre_izquierda;
		torreX = torreX_izqd;
		nuevoReyX = reyX;
		nuevaTorreX = reyX + 1;
	}
	// Si un enroque es posible, mover las piezas
	if (torre != nullptr) {
		// Mover el rey
		tablero[reyY][nuevoReyX] = rey;
		tablero[reyY][5] = nullptr;
		rey->marcarComoMovido();

		// Mover la torre
		tablero[reyY][nuevaTorreX] = torre;
		tablero[reyY][torreX] = nullptr;
		torre->marcarComoMovido();
	}
}

void GestionJugadas::realizarEnroqueDerecha(color jugador, Pieza* tablero[max_y][max_x]) {
	int reyY = (jugador == color::blanco) ? 0 : max_y - 1;
	int reyX = 8;

	Rey* rey = dynamic_cast<Rey*>(tablero[reyY][reyX]);
	if (rey == nullptr)return;

	// Variables para la torre y las nuevas posiciones del rey y la torre
	Torre* torre = nullptr;
	int torreX = 0;
	int nuevoReyX = 0;
	int nuevaTorreX = 0;

	// ENROQUE CORTO
	int torreX_dcha = max_x - 1;
	Torre* torre_derecha = dynamic_cast<Torre*>(tablero[reyY][torreX_dcha]);

	if ((verificarEnroque(jugador, tablero))) {
		torre = torre_derecha;
		torreX = torreX_dcha;
		nuevoReyX = reyX;
		nuevaTorreX = reyX - 1;

	}
	// Si un enroque es posible, mover las piezas
	if (torre != nullptr) {
		// Mover el rey
		tablero[reyY][nuevoReyX] = rey;
		tablero[reyY][5] = nullptr;
		rey->marcarComoMovido();

		// Mover la torre
		tablero[reyY][nuevaTorreX] = torre;
		tablero[reyY][torreX] = nullptr;
		torre->marcarComoMovido();

		this->tab->setFlagEnroque(true);
	}
}