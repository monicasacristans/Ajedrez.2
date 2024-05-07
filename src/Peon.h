#pragma once
#include "Pieza.h"

class Peon : public Pieza {

	bool peonMovido;

public:
	Peon(tipo tip, color col);
	void dibuja();

	void moverPieza(casilla origen, casilla destino, Pieza *tablero[max_y][max_x]);
};