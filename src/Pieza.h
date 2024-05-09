#pragma once
#include "Basico.h"
#include "ETSIDI.h"
#include <math.h>

#define max_x 10//columnas
#define max_y 8//filas

class Pieza {

	casilla pos;
	color colorPieza;
	tipo tipoPieza;

public:

	// Constructor por defecto para inicializar una casilla vac�a.
	Pieza() : tipoPieza(tipo::vacio), colorPieza(color::ninguno) {} // Valor por defecto, puedes ajustarlo como desees.
	virtual void dibuja();
	// Constructor para crear una pieza con tipo y color espec�ficos.
	Pieza(tipo t, color c) : tipoPieza(t), colorPieza(c) {}

	tipo getTipo();
	color getColor();

	//bool caminoLibreY(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
	//bool caminoLibreX(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
	
	void setPos(int x, int y);

	virtual bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) = 0;
};


//	Sprite peon_b{ "bin/imagenes/peon_b.png", pos.x, pos.y, 9, 9 };
//	Sprite peon_n{ "bin/imagenes/peon_n.png", pos.x, pos.y, 9, 9 };
