#include "Pieza.h"
#include <iostream>

tipo Pieza::getTipo() {
	return tipoPieza;
}

color Pieza::getColor() {
	return colorPieza;
}

void Pieza::dibuja() {};

void Pieza::setPos(int x, int y) {
	pos.x = x;
	pos.y = y;
}

//bool Pieza::caminoLibreY(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
//	int movX = (destino.x > origen.x) ? 1 : -1;
//	for (int i = origen.y; i <= destino.y; i+=movX) {
//		if (tablero[i][origen.x] == nullptr) {
//			return true;
//		}
//		else
//			return false;
//	}
//}
//
//bool Pieza::caminoLibreX(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
//	int movY = (destino.y > origen.y) ? 1 : -1;
//	for (int i = origen.x + movY; i <= destino.x; i+= movY) {
//		if (tablero[origen.y][i] == nullptr) {
//			return true;
//		}
//		else
//			return false;
//	}
//}


