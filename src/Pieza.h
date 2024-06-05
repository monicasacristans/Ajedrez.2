#pragma once
#include "Basico.h"
#include <vector>

class Pieza {
	casilla pos;
	color colorPieza;
	tipo tipoPieza;

	bool haMovido; //controlar que la pieza se ha movido
public:
	// Constructor por defecto para inicializar una casilla vacía.
	Pieza() : tipoPieza(tipo::vacio), colorPieza(color::ninguno), haMovido(false) {}

	// Constructor para crear una pieza con tipo y color específicos.
	Pieza(tipo t, color c) : tipoPieza(t), colorPieza(c) {}

	tipo getTipo();
	color getColor();

	// Métodos para controlar el estado de movimientos
	bool haSidoMovido() { return haMovido; }
	void marcarComoMovido() { haMovido = true; }
	void reiniciarMovimiento() { haMovido = false; }

	virtual bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) = 0;
};
