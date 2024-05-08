#pragma once
#include "Pieza.h"

class Rey : public Pieza {
public:
	Rey(tipo tip, color col);
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};
