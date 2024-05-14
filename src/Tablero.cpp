//<iostream> en Basico.h
#include "Tablero.h"
#include "Usuario.h"
#include "Peon.h"
#include "Torre.h"
#include "Arzobispo.h"
#include "Caballo.h"
#include "Canciller.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Pieza.h"


using namespace std;

Tablero::Tablero() {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr; //Pieza crea una pieza vacia 
		}
	}
}

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
			std::cout << "Clic fuera de los limites del tablero." << std::endl;
		}

		if (!flag && click == 2) {
			cas_origen = { columna, fila };
			flag = true;
			std::cout << "Casilla de origen: (" << cas_origen.x << ", " << cas_origen.y << ")" << std::endl;
		}
		else if(click == 3){
			cas_destino = { columna, fila };
			if (cas_origen.x == cas_destino.x && cas_origen.y == cas_destino.y) {
				std::cout << "Origen y destino son iguales, seleccione otra casilla." << std::endl;
				cas_destino = { -1, -1 }; // Reiniciar casilla destino si es igual al origen
			}
			std::cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << std::endl;
			flag = false;
			click = 1;

			bool mov_valido = false;
			//Si el movimiento realizado es incorrecto no cambia de turno hasta que el movimiento sea valido
			while (!mov_valido && p != nullptr) {
				if ((p->getColor() == color::blanco && turno == true) || (p->getColor() == color::negro && turno == false)) {
					mov_valido = moverPieza(cas_origen, cas_destino);
					std::cout << mov_valido << std::endl;
					if (!mov_valido) {
						std::cout << "Movimiento no valido, intenta de nuevo." << std::endl;
						break;
					}
					else 
						turno = !turno; //Cambia el turno despues del movimiento
				}
			}
		}
	}
}



//en un turno, has de comprobar si puedes hacer jaque al rival
bool Tablero::jaque(color col) {
	//el tablero esta realizado desde 0 a mayores osea que significa que es como si 
	//el rey no estuviera encontrado o se encuentre fuera de los limites
	int rey_x = -1;
	int rey_y = -1;

	// Encuentra la posición del rey del color dado
	for (int y = 0; y < max_y; ++y) {
		for (int x = 0; x < max_x; ++x) {
			Pieza* pieza = tablero[y][x];
			if (pieza != nullptr && pieza->getTipo() == tipo::rey && pieza->getColor() == col) {
				//si lo encontramos se actualizan las coordenadas correctas del rey
				rey_x = x;
				rey_y = y;
				break;
			}
		}
		if (rey_x != -1 && rey_y != -1) {
			
			break;
		}
	}

	if (rey_x == -1 || rey_y == -1) {
		
		return false; // No se encontró el rey del color dado
	}

	// Verifica si alguna pieza del oponente puede atacar al rey
	for (int y = 0; y < max_y; ++y) {
		for (int x = 0; x < max_x; ++x) {
			Pieza* pieza = tablero[y][x];
			if (pieza != nullptr && pieza->getColor() != col) {
				casilla origen = { x, y };
				casilla destino = { rey_x, rey_y };
				if (pieza->movimientoValido(origen, destino, tablero)) {
					std::cout << "REY EN JAQUE" << std::endl;
					return true; // El rey está en jaque
				}
			}
		}
	}

	return false; // El rey no está en jaque


}

casilla Tablero::encontrarPosicionRey(color col) {
	// Buscar la posición del rey del color dado en el tablero
	for (int y = 0; y < max_y; ++y) {
		for (int x = 0; x < max_x; ++x) {
			if (tablero[y][x] != nullptr && tablero[y][x]->getTipo() == tipo::rey && tablero[y][x]->getColor() == col) {
				return { x, y };
			}
		}
	}
	return { -1, -1 }; // Retornar posición inválida si no se encuentra el rey
}




bool Tablero::jaque_mate(color col) {
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
	std::cout << "REY EN JAQUE MATE" << std::endl;
	return true; // No hay movimientos legales disponibles para evitar el jaque mate
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

bool Tablero::moverPieza(casilla origen, casilla destino) {

	// Mover la pieza
	Pieza *piezaMovida = tablero[origen.y][origen.x]; // Tomar la pieza en la casilla de origen

	if (piezaMovida->movimientoValido(origen, destino, tablero) == true) {
		tablero[destino.y][destino.x] = piezaMovida; // Colocar la pieza en la casilla de destino
		tablero[origen.y][origen.x] = nullptr; // Dejar la casilla de origen vacía
		std::cout << "Movimiento realizado de (" << origen.x << ", " << origen.y << ") a (" << destino.x << ", " << destino.y << ")" << std::endl;
		flagMovInvalido = false;
		return true;
	}
	else {
		
		flagMovInvalido = true;
		return false;
	}
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
	}

	//Peones negros
	for (int i = 0; i < 10; i++) {
		tablero[6][i] = new Peon(tipo::peon, color::negro);
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


}

