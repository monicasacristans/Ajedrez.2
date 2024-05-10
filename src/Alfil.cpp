#include "Alfil.h"
#include <iostream>

Alfil::Alfil(tipo t, color c) :Pieza(t, c) {}

bool Alfil::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	
	int movX = (destino.x > origen.x) ? 1 : -1;
	int movY = (destino.y > origen.y) ? 1 : -1;
	

	
	return true;
}