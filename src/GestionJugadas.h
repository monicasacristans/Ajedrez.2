#pragma once
#include "Pieza.h"
#include "Tablero.h"

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
	bool enroque(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
		//promocion
	bool getPromocion(color col);
	void setPromocion(tipo t);

	
	
	
};