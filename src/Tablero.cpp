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
		//std::cout << "Clic en: x=" << x << ", y=" << y << " -> columna=" << columna << ", fila=" << fila << std::endl;
		click++;

		if (columna < 0 || columna >= 10 || fila < 0 || fila >= 8) {
			std::cout << "Clic fuera de los límites del tablero." << std::endl;
			return;
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
				return;
			}
			std::cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << std::endl;
			flag = false;
			click = 1;

			if ((p->getColor() == color::blanco && turno == true) || (p->getColor() == color::negro && turno == false)) {
				moverPieza(cas_origen, cas_destino);
				turno = !turno; //cambia el turno despues del movimiento
			}
			
		}
	}
}


void Tablero::moverPieza(casilla origen, casilla destino) {

	// Mover la pieza
	Pieza *piezaMovida = tablero[origen.y][origen.x]; // Tomar la pieza en la casilla de origen

	if (piezaMovida->movimientoValido(origen, destino, tablero) == true) {
		tablero[destino.y][destino.x] = piezaMovida; // Colocar la pieza en la casilla de destino
		tablero[origen.y][origen.x] = nullptr; // Dejar la casilla de origen vacía
		std::cout << "Movimiento realizado de (" << origen.x << ", " << origen.y << ") a (" << destino.x << ", " << destino.y << ")" << std::endl;
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

