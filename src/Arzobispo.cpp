#include "Arzobispo.h"
#include <iostream>

Arzobispo::Arzobispo(tipo t, color c) :Pieza(t, c) {}

bool Arzobispo::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	return true;
}