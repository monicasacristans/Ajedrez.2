#include "Tablero.h"

using namespace std;

GestionJugadas jugada;

Tablero::Tablero() {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr; //Pieza crea una pieza vacia 
		}
	}
}

Tablero::~Tablero(){
	delete[]tablero;
	
}

bool Tablero::eliminarPiezaT(int x, int y) {
	if (x < 0 || x >= max_x || y < 0 || y >= max_y) {
		std::cout << "Posición fuera de los límites del tablero." << std::endl;
		return false;
	}

	// Obtener la pieza en la posición (x, y)
	Pieza* piezaEliminada = tablero[y][x];

	if (piezaEliminada == nullptr) {
		std::cout << "No hay ninguna pieza en la posición especificada." << std::endl;
		return false;
	}

	// Eliminar la pieza del tablero (asignar nullptr a la casilla)
	tablero[y][x] = nullptr;

	// Agregar la pieza eliminada a la lista de piezas eliminadas
	piezaseliminadas.push_back(piezaEliminada);

	std::cout << "Pieza eliminada del tablero y agregada a la lista de piezas eliminadas." << std::endl;
	return true;
}



//void Tablero::definirCoordenadasTablero(int button, int state, int x, int y) {
//	Pieza* p = checkPiezaEnCasilla(cas_origen);
//	static int click = 0;
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		int columna = (x - 283) / 80;
//		int fila = (y - 64) / 80;
//		click++;
//
//		if (columna < 0 || columna >= 10 || fila < 0 || fila >= 8) {
//			cout << "Clic fuera de los limites del tablero." << endl;
//			click = 0;
//			return;
//		}
//
//		if (!flag && click == 1) {
//			cas_origen = { columna, fila };
//			flag = true;
//			cout << "Casilla de origen: (" << cas_origen.x << ", " << cas_origen.y << ")" << endl;
//		}
//		else if (click == 2) {
//			cas_destino = { columna, fila };
//			cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << endl;
//			flag = false;
//			click = 0;
//
//			bool mov_valido = false;
//			Pieza* p = checkPiezaEnCasilla(cas_origen);
//
//			if (p != nullptr && ((p->getColor() == color::blanco && turno == true) || (p->getColor() == color::negro && turno == false))) {
//				if (p->getTipo() == tipo::rey && abs(cas_destino.x - cas_origen.x) == 4) {
//					mov_valido = jugada.enroque(cas_origen, cas_destino, tablero);
//					if (mov_valido) {
//						flagEnroque = true;
//						cout << "ENROQUE REALIZADO CORRECTAMENTE" << endl;
//					}
//					else {
//						flagEnroque = false;
//						cout << "ENROQUE NO VALIDO INTENTA DE NUEVO" << endl;
//					}
//				}
//				else {
//					mov_valido = moverPieza(cas_origen, cas_destino);
//					if (!mov_valido) {
//						cout << "Movimiento no valido, intenta de nuevo." << endl;
//					}
//				}
//
//				if (mov_valido) {
//					color colOponente = (p->getColor() == color::blanco) ? color::negro : color::blanco;
//					if (jugada.jaque(colOponente, tablero)) {
//						cout << "REY " << (colOponente == color::blanco ? "BLANCO" : "NEGRO") << " EN JAQUE" << endl;
//						flagJaque = true;
//					}
//					else {
//						flagJaque = false;
//					}
//					turno = !turno;
//				}
//			}
//		}
//	}
//}

void Tablero::definirCoordenadasTablero(int button, int state, int x, int y) {

	Pieza* p = checkPiezaEnCasilla(cas_origen);
	static int click = 0;

	int screenX = x;
	int screenY = y;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la columna y fila en función de las coordenadas x e y
		int columna = ((x - 283) / 80);
		int fila = ((y - 64) / 80);
		click++;

		if (columna < 0 || columna >= 10 || fila < 0 || fila >= 8) {
			cout << "Clic fuera de los limites del tablero." << endl;
		}

		if (!flag && click == 2) {
			cas_origen = { columna, fila };
			flag = true;
			cout << "Casilla de origen: (" << cas_origen.x << ", " << cas_origen.y << ")" << endl;
		}
		else if(click == 3){ 
			cas_destino = { columna, fila };
			if (cas_origen.x == cas_destino.x && cas_origen.y == cas_destino.y) {
				cout << "Origen y destino son iguales, seleccione otra casilla." <<endl;
				cas_destino = { -1, -1 }; // Reiniciar casilla destino si es igual al origen
			}
			cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << endl;
			flag = false;
			click = 1;

			bool mov_valido = false;

			//Si el movimiento realizado es incorrecto no cambia de turno hasta que el movimiento sea valido
			while (!mov_valido && tablero[cas_origen.y][cas_origen.x] != nullptr) {
				if ((p->getColor() == color::blanco && turno == true) || (p->getColor() == color::negro && turno == false)) {
					
					//primero compruebo el enroque
					if (p->getTipo() == tipo::rey && abs(cas_destino.x - cas_origen.x) == 4) {
					mov_valido = jugada.enroque(cas_origen, cas_destino, tablero);
					if (!mov_valido) {
						flagEnroque = true;
						cout << "ENROQUE NO VALIDO INTENTA DE NUEVO" << endl;
						break;
					}
					else {
						flagEnroque = false;
						cout << "ENROQUE REALIZADO CORRECTAMENTE" << endl;
					}
					turno = !turno; //cambiar turno despues del movimiento
					}
					else {
						mov_valido = moverPieza(cas_origen, cas_destino);
						if (!mov_valido) {
							cout << "Movimiento no valido, intenta de nuevo." << endl;
							break;
						}
					}
					if(mov_valido){
						//Comprobar el jaque
						color colOponente = (p->getColor() == color::blanco) ? color::negro : color::blanco;
						if (jugada.jaque(colOponente, tablero)) {
							std::cout << "REY " << (colOponente == color::blanco ? "BLANCO" : "NEGRO") << " EN JAQUE" << std::endl;
							flagJaque = true; // Actualizar la flag de jaque
						}
						else {
							flagJaque = false; // Si no hay jaque, resetear la flag
						}
						turno = !turno; //Cambia el turno despues del movimiento
					}
				}
				break;
			}
		}
	}
}

bool Tablero::moverPieza(casilla origen, casilla destino) {

	// Mover la pieza
	Pieza* piezaMovida = tablero[origen.y][origen.x]; // Tomar la pieza en la casilla de origen

	if (piezaMovida->movimientoValido(origen, destino, tablero) == true) {
		tablero[destino.y][destino.x] = piezaMovida; // Colocar la pieza en la casilla de destino
		tablero[origen.y][origen.x] = nullptr; // Dejar la casilla de origen vacía
		cout << "Movimiento realizado de (" << origen.x << ", " << origen.y << ") a (" << destino.x << ", " << destino.y << ")" << endl;
		flagMovInvalido = false;
		return true;
	}
	else {

		flagMovInvalido = true;
		return false;
	}
}
///////////////CASILLA LEGAL/////////////////


//std::vector<casilla> Tablero::calcularCasillasLegales() {
//	std::vector<casilla> casillasLegales;
//
//	// Recorre todo el tablero
//	for (int y = 0; y < max_y; ++y) {
//		for (int x = 0; x < max_x; ++x) {
//			Pieza* piezaActual = tablero[y][x];
//
//			if (piezaActual != nullptr) {
//				// Obtén las casillas legales para la pieza actual
//				casilla origen = { x, y };
//
//				// Recorre todas las casillas del tablero para verificar movimientos legales
//				for (int j = 0; j < max_y; ++j) {
//					for (int i = 0; i < max_x; ++i) {
//						casilla destino = { i, j };
//
//						if (piezaActual->movimientoValido(origen, destino, tablero)) {
//							casillasLegales.push_back(destino);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return casillasLegales;
//}


bool Tablero::esCasillaValida(const casilla& casilla) const {
	return (casilla.x >= 0 && casilla.x < max_x&& casilla.y >= 0 && casilla.y < max_y);
}


bool Tablero::getTurno() {
	return turno;
}

bool Tablero::getFlagMovValido() {
	return flagMovInvalido;
}

bool Tablero::getFlagJaque() {
	return flagJaque;
}

bool Tablero::getFlagEnroque() {
	return flagEnroque;
}


bool Tablero::checkCasillaOcupada(int x, int y) {
	if (x >= 0 && x < max_x && y >= 0 && y < max_y) {  //Comprueba que estamos dentro del tablero
		
		Pieza *mipieza = tablero[y][x]; //Obtiene la pieza que hay en la casilla

		if (mipieza != nullptr) {
			return true; //casilla ocupada
		}
	}
	return false; //casilla vacía
}

Pieza* Tablero::checkPiezaEnCasilla(casilla pos) {

	if (pos.x >= 0 && pos.x < max_x && pos.y >= 0 && pos.y < max_y) { //Comprueba que estamos dentro del tablero
		return tablero[pos.y][pos.x];  //Devuelve la pieza que hay en la casilla
	}
	else {
		// Si la casilla está fuera del tablero, devuelve una pieza vacía
		return nullptr;
	}
}

void Tablero::set_tablero() {

	//Iniciar todo el tablero a nullptr
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr;
		}
	}
	//Piezas blancas
	tablero[0][0]= new Torre(tipo::torre, color::blanco);
	tablero[0][1] = new Caballo(tipo::caballo, color::blanco);
	tablero[0][2] = new Arzobispo(tipo::arzobispo, color::blanco);
	tablero[0][3] = new Alfil(tipo::alfil, color::blanco);
	tablero[0][4] = new Rey(tipo::rey, color::blanco);
	tablero[0][5] = new Reina(tipo::reina, color::blanco);
	tablero[0][6] = new Alfil(tipo::alfil, color::blanco);
	tablero[0][7] = new Canciller(tipo::canciller, color::blanco);
	tablero[0][8] = new Caballo(tipo::caballo, color::blanco);
	tablero[0][9] = new Torre(tipo::torre, color::blanco);
	//Peones blancos 
	for (int i = 0; i < 10; i++) {
		tablero[1][i] = new Peon(tipo::peon, color::blanco);
		piezasB.push_back(tablero[0][i]);
		piezasB.push_back(tablero[1][i]);
	}

	

	//Peones negros
	for (int i = 0; i < 10; i++) {
		tablero[6][i] = new Peon(tipo::peon, color::negro);
		piezasN.push_back(tablero[6][i]);
	}

	//Piezas negras
	tablero[7][0] = new Torre(tipo::torre, color::negro);
	tablero[7][1] = new Caballo(tipo::caballo, color::negro);
	tablero[7][2] = new Arzobispo(tipo::arzobispo, color::negro);
	tablero[7][3] = new Alfil(tipo::alfil, color::negro);
	tablero[7][4] = new Rey(tipo::rey, color::negro);
	tablero[7][5] = new Reina(tipo::reina, color::negro);
	tablero[7][6] = new Alfil(tipo::alfil, color::negro);
	tablero[7][7] = new Canciller(tipo::canciller, color::negro);
	tablero[7][8] = new Caballo(tipo::caballo, color::negro);
	tablero[7][9] = new Torre(tipo::torre, color::negro);

	for (int i = 0; i < 10; i++) {
		piezasN.push_back(tablero[7][i]);
	}

}
