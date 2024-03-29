#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
private: 
	int value;
public:

	Peon(int value) ;

	virtual void draw();
};