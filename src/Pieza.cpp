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
char Pieza::obtenerRepresentacion() {
	if (colorPieza == color::blanco) {
		switch (tipoPieza) {
		case tipo::peon:
			return 'P';
			break;
		case tipo::torre:
			return 'T';
			break;
		case tipo::caballo:
			return 'C';
			break;
		case tipo::canciller:
			return 'N';
			break;
		case tipo::arzobispo:
			return 'A';
			break;
		case tipo::rey:
			return 'R';
			break;
		case tipo::reina:
			return 'I';
			break;
		default:
			return ' ';
		}
	}
	else {
		switch (tipoPieza) {
		case tipo::peon:
			return 'p';
			break;
		case tipo::torre:
			return 't';
			break;
		case tipo::caballo:
			return 'c';
			break;
		case tipo::canciller:
			return 'n';
			break;
		case tipo::arzobispo:
			return 'a';
			break;
		case tipo::rey:
			return 'r';
			break;
		case tipo::reina:
			return 'i';
			break;
		default:
			return ' ';
		}
	}
}

