#pragma once
#include "Pieza.h"

class Caballo : public Pieza
{
private:
	int value;
public:

	Caballo(int value);

	virtual void draw();
};