#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Tablero.h"

class Pintar {

	Tablero* tablero = nullptr;
protected:
	//casilla c = { 40, 18};
	Sprite peon_b{ "bin/imagenes/peon_b.png", 0, 0, 9, 9 };
	Sprite peon_n{ "bin/imagenes/peon_n.png", 0, 0, 9, 9 };
	Sprite torre_b{ "bin/imagenes/torre_b.png", 0, 0, 9, 9 };
	Sprite torre_n{ "bin/imagenes/torre_n.png", 0, 0, 9, 9 };
	Sprite alfil_b{ "bin/imagenes/alfil_b.png", 0, 0, 9, 9 };
	Sprite alfil_n{ "bin/imagenes/alfil_n.png", 0, 0, 9, 9 };
public:

	Pintar(Tablero* ptrTab) : tablero(ptrTab) {}

	void draw();

	casilla restringirCasilla(int x, int y);
	void pintarCuadricula();
	casilla definirCoordenadasTablero(int button, int state, int x, int y);
	void pintarPiezasTablero();


};
