#pragma once
#include "Basico.h"
#include <vector>

class Pieza {

	casilla pos;
	color colorPieza;
	tipo tipoPieza;

	bool haMovido; //controlar que la pieza se ha movido

	

protected:

	int fila;
	int columna;
	std::vector<casilla> casillasValidas;

public:

	// Constructor por defecto para inicializar una casilla vacía.
	Pieza() : tipoPieza(tipo::vacio), colorPieza(color::ninguno), haMovido(false){
		fila = pos.x; columna = pos.y;
	} // Valor por defecto, puedes ajustarlo como desees.

	// Constructor para crear una pieza con tipo y color específicos.
	Pieza(tipo t, color c) : tipoPieza(t), colorPieza(c) {}

	tipo getTipo();
	color getColor();

	std::vector<casilla> movDiagonal(casilla origen, Pieza* tablero[max_y][max_x]);
	std::vector<casilla> movCruz(casilla origen, Pieza* tablero[max_y][max_x]);
	std::vector<casilla> movCuadrado(casilla origen,  Pieza* tablero[max_y][max_x]);

	virtual bool movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) = 0;


	//FUERAAAAAAAAAA REVISAR

	bool enroque = false;

	void setEnroque(bool x);

	// Métodos para controlar el estado de movimientos
	bool haSidoMovido();
	void marcarComoMovido();
	void reiniciarMovimiento();

	int getFila();
	int getColumna();
	bool getEnroque();
	
};
