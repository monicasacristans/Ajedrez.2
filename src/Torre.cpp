#include "Torre.h"
#include <iostream>

Torre::Torre(tipo t, color c) :Pieza(t, c) {}


bool Torre::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	if (origen.x != destino.x && origen.y != destino.y) {
		return false; // Las torres se mueven solo en línea recta.
		std::cout << "NO PUEDES" << std::endl;
	}



	if (origen.x == destino.x) {
		int stepY = (destino.y > origen.y) ? 1 : -1;
		for (int y = origen.y + stepY; y != destino.y; y += stepY) {
			if (tablero[origen.x][y] != nullptr) {
				return false;
			}
		}
	}
	else if (origen.y == destino.y) {
		int stepX = (destino.x > origen.x) ? 1 : -1;
		for (int x = origen.x + stepX; x != destino.x; x += stepX) {
			if (tablero[x][origen.] != nullptr) {
				return false;
			}
		}
	}

	return true;

	/*
	//Vertical
	if (origen.x == destino.x) {				//NO CREO Q VALGA PARA LOS DOS COLORES
		for (int i = 0; i < max_y; i++) {
			if (tablero[origen.x][i] == nullptr) {
				return true; // puede avanzar 
			}
			else return false;
		}
	}

	//Horizontal
	if (origen.y == destino.y) {				
		for (int i = 0; i < max_x; i++) {
			if (tablero[i][origen.y] == nullptr) {
				return true; // puede avanzar 
			}
			else return false;
		}
	} 
	*/
}

//ESTO ES CAOS, ES IGUAL QUE EN LA ANTERIOR
/*
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

*/