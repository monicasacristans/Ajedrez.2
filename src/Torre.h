#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
private:
	int value;
public:

	Torre(int value);

	virtual void draw();
	
};