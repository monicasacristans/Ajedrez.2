#pragma once
#include "ETSIDI.h"

using namespace ETSIDI;

class Pieza {
protected:
	
	//int value;
	Vector2D pos;

	Sprite peon_b{ "bin/imagenes/peon_b.png", pos.x, pos.y, 9, 9 };
	Sprite peon_n{ "bin/imagenes/peon_n.png", pos.x, pos.y, 9, 9 };
	Sprite torre_b{ "bin/imagenes/torre_b.png", pos.x, pos.y, 9, 9 }; //-34.5 y -34
	Sprite torre_n{ "bin/imagenes/torre_n.png", pos.x, pos.y, 9, 9 };
	Sprite caballo_b{ "bin/imagenes/caballo_b.png", pos.x,pos.y, 9, 9 };
	Sprite caballo_n{ "bin/imagenes/caballo_n.png", pos.x, pos.y, 9, 9 };
	Sprite alfil_b{ "bin/imagenes/alfil_b.png", pos.x,pos.y, 9, 9 };
	Sprite alfil_n{ "bin/imagenes/alfil_n.png", pos.x, pos.y, 9, 9 };
	Sprite rey_b{ "bin/imagenes/rey_b.png", pos.x, pos.y, 9, 9 };
	Sprite rey_n{ "bin/imagenes/rey_n.png", pos.x, pos.y, 9, 9 };
	Sprite reina_b{ "bin/imagenes/reina_b.png", pos.x, pos.y, 9, 9 };
	Sprite reina_n{ "bin/imagenes/reina_n.png", pos.x, pos.y, 9, 9 };


public:
	
	Pieza();
	virtual void draw();
	virtual void setPos(float x, float y);
};