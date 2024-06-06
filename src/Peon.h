#pragma once
#include "Pieza.h"

class Peon : public Pieza {

public:
	Peon(tipo tip, color col);
	~Peon() override {};
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};