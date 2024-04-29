#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Tablero.h"

class Pintar {

	Tablero* tablero = nullptr;

	// Dimensiones del tablero
	int anchoTablero = 10 * 80;
	int altoTablero = 8 * 80;

	//casilla c;
	Sprite peon_b{ "bin/imagenes/peon_b.png", 0, 0, 60,60 };
	Sprite peon_n{ "bin/imagenes/peon_n.png", 0, 0, 60,60 };
	Sprite torre_b{ "bin/imagenes/torre_b.png", 0, 0, 60,60 };
	Sprite torre_n{ "bin/imagenes/torre_n.png", 0, 0, 60,60 };
	Sprite caballo_b{ "bin/imagenes/caballo_b.png", 0, 0, 60,60 };
	Sprite caballo_n{ "bin/imagenes/caballo_n.png", 0, 0, 60,60 };
	Sprite alfil_b{ "bin/imagenes/alfil_b.png", 0, 0, 60,60 };
	Sprite alfil_n{ "bin/imagenes/alfil_n.png", 0, 0, 60,60 };
	Sprite reina_b{ "bin/imagenes/reina_b.png", 0, 0, 60,60 };
	Sprite reina_n{ "bin/imagenes/reina_n.png", 0, 0, 60,60 };
	Sprite rey_b{ "bin/imagenes/rey_b.png", 0, 0, 60,60 };
	Sprite rey_n{ "bin/imagenes/rey_n.png", 0, 0, 60,60 };

public:
	
	Pintar(Tablero* ptrTab) : tablero(ptrTab) {}

	void setPos(float x, float y);
	void draw();
	casilla restringirCasilla(int x, int y);
	void pintarCuadricula();
	casilla definirCoordenadasTablero(int button, int state, int x, int y);
	void pintarPiezasTablero();


};
