#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Tablero.h"

class Pintar {

	Tablero* tablero = nullptr;

	casilla c;
	Sprite peon_b{ "bin/imagenes/peon_b.png", c.x, c.y, 20,20 };
	Sprite peon_n{ "bin/imagenes/peon_n.png", c.x, c.y, 20,};

public:

	Pintar(Tablero* ptrTab) : tablero(ptrTab) {}

	void setPos(float x, float y);
	void draw();
	casilla restringirCasilla(int x, int y);
	void pintarCuadricula();
	casilla definirCoordenadasTablero(int button, int state, int x, int y);
	void pintarPiezasTablero();


};
