#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
private:
	int value;
public:

	Reina(int value);

	virtual void draw();
};