#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
public:
	Alfil(tipo tip, color col);
	~Alfil() override {};
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};
