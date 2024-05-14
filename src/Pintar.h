#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Tablero.h"

using namespace ETSIDI;

class Pintar {

	Tablero* tablero = nullptr;

	// Dimensiones del tablero
	int anchoTablero = 10 * 80;
	int altoTablero = 8 * 80;
	Sprite casilla_legal{ "bin/imagenes/casilla_legal.png", 0,0, 60,60 };
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
	Sprite canciller_b{ "bin/imagenes/canciller_b.png", 0, 0, 60,60 };
	Sprite canciller_n{ "bin/imagenes/canciller_n.png", 0, 0, 60,60 };
	Sprite arzobispo_b{ "bin/imagenes/arzobispo_b.png", 0, 0, 60,60 };
	Sprite arzobispo_n{ "bin/imagenes/arzobispo_n.png", 0, 0, 60,60 };

	Sprite corona{ "bin/imagenes/corona.png", 0, 0, 80, 40 };

public:
	
	Pintar(Tablero* ptrTab) : tablero(ptrTab) {}


	/////CASILLA LEGAL///////
	int calcularCoordenadaX(int casillaX) const;
	int calcularCoordenadaY(int casillaX) const;
	void pintarCasillaLegal();


	void setPos(float x, float y);
	void draw();

	casilla restringirCasilla(int x, int y);

	void pintarCuadricula();
	void pintarPiezasTablero();
	//void pintarCasillaElegida();
	void pintarCorona();
	void pintarError();

};
