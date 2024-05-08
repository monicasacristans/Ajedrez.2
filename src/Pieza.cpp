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


