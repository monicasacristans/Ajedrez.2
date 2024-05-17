#pragma once
#include "Tablero.h"
#include "Pieza.h"

class GestionJugadas {
public:
	GestionJugadas(){};
	//JAQUE 
	bool jaque(color col, Pieza* tablero[max_y][max_x]);
	//JAQUE MATE
	//bool piezaAmenazada(casilla pos, color col);
	bool jaque_mate(color col, Pieza* tablero[max_y][max_x]);
	casilla encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]);
	//bool estaEnJaque(color col);

		//promocion
	bool getPromocion(color col);
	void setPromocion(tipo t);
};