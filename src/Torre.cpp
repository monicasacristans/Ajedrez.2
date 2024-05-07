#include "Torre.h"
#include <iostream>

Torre::Torre(tipo t, color c) :Pieza(t, c) {
	t = tipo::torre;
	c = color::blanco;
}


bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	//Vertical
	if (origen.x == destino.x) {				//NO CREO Q VALGA PARA LOS DOS COLORES
		for (int i = 0; i < max_y; i++) {
			if (tablero[i][origen.x] == nullptr) {
				return true; // puede avanzar 
			}
			else return false;
		}
	}

	//Horizontal
	if (origen.y == destino.y) {				
		for (int i = 0; i < max_x; i++) {
			if (tablero[origen.y][i] == nullptr) {
				return true; // puede avanzar 
			}
			else return false;
		}
	}

}

//ESTO ES CAOS, ES IGUAL QUE EN LA ANTERIOR

void Torre::moverPieza(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	if (movimientoValido(origen, destino, tablero)==1 ) {	//para que funcione hay que pasarle Pieza* tablero[max_x][max_y], pero se estropea virtual
		Pieza* paux = tablero[origen.x][origen.y];
		tablero[destino.x][destino.y] = paux; 
		tablero[origen.x][destino.y] = nullptr;	//la mueve y se la carga 
	}
	else {
		std::cout << "Movimiento no valido" << std::endl;
	}
}

