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
	bool haMovido; //controlar que la pieza se ha movido

public:

	// Constructor por defecto para inicializar una casilla vacía.
	Pieza() : tipoPieza(tipo::vacio), colorPieza(color::ninguno), haMovido(false){} // Valor por defecto, puedes ajustarlo como desees.
	virtual void dibuja();
	// Constructor para crear una pieza con tipo y color específicos.
	Pieza(tipo t, color c) : tipoPieza(t), colorPieza(c) {}

	tipo getTipo();
	color getColor();
	bool enroque = false;

	void setPos(int x, int y);
	void setEnroque(bool x);

	// Métodos para controlar el estado de movimientos
	bool haSidoMovido();
	void marcarComoMovido();
	void reiniciarMovimiento();


	bool getEnroque();
	virtual bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) = 0;
};
