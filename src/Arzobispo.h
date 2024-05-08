#pragma once
#include "Pieza.h"

class Arzobispo : public Pieza {
public:
	Arzobispo(tipo tip, color col);
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};
