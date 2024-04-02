#pragma once
#include "Pieza.h"

class Canciller : public Pieza
{
private:
	int value;
public:

	Canciller(int value);

	virtual void draw();
};