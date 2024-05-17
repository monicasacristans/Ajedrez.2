#pragma once
#include "Basico.h"


class Pieza {

	casilla pos;
	color colorPieza;
	tipo tipoPieza;

	bool haMovido; //controlar que la pieza se ha movido

protected:

	int fila;
	int columna;

public:

	// Constructor por defecto para inicializar una casilla vac�a.
	Pieza() : tipoPieza(tipo::vacio), colorPieza(color::ninguno), haMovido(false){
		fila = pos.x; columna = pos.y;
	} // Valor por defecto, puedes ajustarlo como desees.

	// Constructor para crear una pieza con tipo y color espec�ficos.
	Pieza(tipo t, color c) : tipoPieza(t), colorPieza(c) {}

	tipo getTipo();
	color getColor();

	virtual bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) = 0;


	//FUERAAAAAAAAAA REVISAR

	bool enroque = false;

	void setEnroque(bool x);

	// M�todos para controlar el estado de movimientos
	bool haSidoMovido();
	void marcarComoMovido();
	void reiniciarMovimiento();

	int getFila();
	int getColumna();
	bool getEnroque();
	
};
