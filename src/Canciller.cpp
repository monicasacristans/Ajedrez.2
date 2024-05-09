#include "Canciller.h"
#include <iostream>


Canciller::Canciller(tipo t, color c) :Pieza(t, c) {}

bool Canciller::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	//Se mueve indistintamente como torre o caballo

	return true;
}