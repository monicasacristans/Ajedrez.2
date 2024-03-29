#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
private:
	int value;
public:

	Alfil(int value);

	virtual void draw();
};