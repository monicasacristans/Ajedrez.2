#pragma once
#include "Pieza.h"
#include "Tablero.h"

class GestionJugadas {
	Pieza* tablero[max_y][max_x];
public:
	GestionJugadas(){};
	//JAQUE 
	bool jaque(color col);
	//JAQUE MATE
	//bool piezaAmenazada(casilla pos, color col);
	bool jaque_mate(color col);
	casilla encontrarPosicionRey(color col);
	//bool estaEnJaque(color col);

		//promocion
	bool getPromocion(color col);
	void setPromocion(tipo t);
};