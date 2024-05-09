#pragma once
#include "Pieza.h"

class Peon : public Pieza {

	bool peonMovido = false;//inicializado como no movido

public:
	Peon(tipo tip, color col);
	bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
};