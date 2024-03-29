#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
private:
	int value;
public:

	Rey(int value);

	virtual void draw();
};