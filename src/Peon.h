#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
	Peon(tipo tip, color col);
	void dibuja();
};