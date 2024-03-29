#pragma once
#include "ETSIDI.h"

using namespace ETSIDI;

class Pieza {
protected:
	
	//int value;
	Sprite peon_b{ "bin/imagenes/peon_b.png", -34.5,-24, 9, 9 };
	Sprite peon_n{ "bin/imagenes/peon_n.png", -34.5, 24, 9, 9 };
	Sprite torre_b{ "bin/imagenes/torre_b.png", -34.5,-34, 9, 9 };
	Sprite torre_n{ "bin/imagenes/torre_n.png", -34.5, 34, 9, 9 };
	Sprite caballo_b{ "bin/imagenes/caballo_b.png", -24.5,-34, 9, 9 };
	Sprite caballo_n{ "bin/imagenes/caballo_n.png", -24.5, 34, 9, 9 };
	Sprite alfil_b{ "bin/imagenes/alfil_b.png", -14.5,-34, 9, 9 };
	Sprite alfil_n{ "bin/imagenes/alfil_n.png", -14.5, 34, 9, 9 };
	Sprite rey_b{ "bin/imagenes/rey_b.png", -4.5,-34, 9, 9 };
	Sprite rey_n{ "bin/imagenes/rey_n.png", -4.5, 34, 9, 9 };
	Sprite reina_b{ "bin/imagenes/reina_b.png", 5.5,-34, 9, 9 };
	Sprite reina_n{ "bin/imagenes/reina_n.png", 5.5, 34, 9, 9 };


public:
	
	Pieza();
	virtual void draw();

};