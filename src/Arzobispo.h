#pragma once
#include "Pieza.h"

class Arzobispo : public Pieza
{
private:
	int value;
public:

	Arzobispo(int value);

	virtual void draw();
};