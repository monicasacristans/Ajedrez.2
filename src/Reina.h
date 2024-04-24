#pragma once
#include "Pieza.h"

class Reina: public Pieza {
public:
	Reina(tipo tip, color col);
	void dibuja();
};