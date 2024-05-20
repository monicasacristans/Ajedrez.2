#pragma once
#include "Tablero.h"
#include "Pieza.h"


class Tablero;

class GestionJugadas {
	Tablero* tab = nullptr ;
public:
	//GestionJugadas(Tablero *miTablero):tab(miTablero){};
	GestionJugadas() {};
	GestionJugadas(Tablero *miTablero):tab(miTablero) {};
	
	//JAQUE 
	bool jaque(color col, Pieza* tablero[max_y][max_x]);
	bool reySaleDeJaque(color col, Pieza* tablero[max_y][max_x]);

	//JAQUE MATE
	bool jaque_mate(color col, Pieza* tablero[max_y][max_x]);
	casilla encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]);

	//promocion
	bool peonFinal(casilla origen);
	void promocion(casilla cas, Pieza* tablero[max_y][max_x]);

	friend class Tablero;
};