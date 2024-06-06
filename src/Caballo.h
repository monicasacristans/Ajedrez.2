#pragma once
#include "Pieza.h"

class Caballo : public Pieza {
public:
	Caballo(tipo tip, color col);
	~Caballo() override {};
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};

