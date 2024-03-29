#pragma once
#include "ETSIDI.h"


class Pieza {
protected:
	//ETSIDI::Sprite sprite;
	//int value;
	ETSIDI::Sprite peon_b{ "bin/imagenes/peon_b.png", -34.5,-24, 9, 9 };
	ETSIDI::Sprite peon_n{ "bin/imagenes/peon_n.png", -34.5, 24, 9,9 };
public:
	
	Pieza();
	virtual void draw();

};