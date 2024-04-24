#pragma once
#include "Pieza.h"

class Canciller : public Pieza {
public:
	Canciller(tipo tip, color col);
	void dibuja();
};