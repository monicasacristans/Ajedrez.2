#pragma once
#include "Pieza.h"

class Caballo : public Pieza {
public:
	Caballo(tipo tip, color col);
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};

