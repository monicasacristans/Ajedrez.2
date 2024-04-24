#pragma once
#include "Pieza.h"

class Rey: public Pieza {
public:
	Rey(tipo tip, color col);
	void dibuja();
};