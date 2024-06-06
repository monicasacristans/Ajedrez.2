#pragma once
#include "Pieza.h"

class Canciller : public Pieza {
public:
	Canciller(tipo tip, color col);
	~Canciller() override {};
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};
