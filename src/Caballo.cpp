#include "Caballo.h"
#include <iostream>


Caballo::Caballo(tipo t, color c) :Pieza(t, c) {}

bool Caballo::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	return true;
}