#include "Pieza.h"

tipo Pieza::getTipo() {
	return tipoPieza;
}

color Pieza::getColor() {
	return colorPieza;
}

int Pieza::getFila() {
	return fila;
}

int Pieza::getColumna() {
	return columna;
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


