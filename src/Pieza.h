#pragma once
#include "ETSIDI.h"


class Pieza {
private:
	ETSIDI::Sprite sprite;
	int value;
public:
	
	Pieza(ETSIDI::Sprite& sprite, ETSIDI::Vector2D posicion, int val);


};