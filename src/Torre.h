#pragma once
#include "Pieza.h"

class Torre : public Pieza {
public:
	Torre(tipo tip, color col);
	~Torre() override {};
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
	//void moverPieza(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);

};

