#pragma once
#include "Pieza.h"

class Reina: public Pieza {
public:
	Reina(tipo tip, color col);
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};
