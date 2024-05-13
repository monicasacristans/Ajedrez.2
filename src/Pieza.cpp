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


// Métodos para controlar el estado de movimientos
bool Pieza::haSidoMovido() {
	return haMovido;
}
void Pieza::marcarComoMovido() { 
	haMovido = true; 
}

void Pieza::reiniciarMovimiento() { 
	haMovido = false; 

}
void Pieza::setEnroque(bool x) {
	enroque = true;
}

bool Pieza::getEnroque() {
	return enroque;
}


