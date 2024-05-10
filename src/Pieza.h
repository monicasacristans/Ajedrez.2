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

	// Constructor por defecto para inicializar una casilla vacía.
	Pieza() : tipoPieza(tipo::vacio), colorPieza(color::ninguno) {} // Valor por defecto, puedes ajustarlo como desees.
	virtual void dibuja();
	// Constructor para crear una pieza con tipo y color específicos.
	Pieza(tipo t, color c) : tipoPieza(t), colorPieza(c) {}

	tipo getTipo();
	color getColor();
	
	void setPos(int x, int y);

	virtual bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) = 0;
};
