#pragma once
#include "Tablero.h"
#include "Pieza.h"


class Tablero;

class GestionJugadas {
	Tablero* tab = nullptr ;
public:
	//GestionJugadas(Tablero *miTablero):tab(miTablero){};
	GestionJugadas(Tablero *miTablero):tab(miTablero) {};
	
	//JAQUE 
	bool jaque(color col, Pieza* tablero[max_y][max_x]);
	bool sacardeJaque(color col, Pieza* tablero[max_y][max_x]);
	//JAQUE MATE
	//bool piezaAmenazada(casilla pos, color col);
	bool jaque_mate(color col, Pieza* tablero[max_y][max_x]);
	casilla encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]);
	//bool estaEnJaque(color col);

	//promocion
	color peonFinal(casilla origen, Pieza* tablero[max_y][max_x]);
	bool promocion(casilla cas, Pieza* tablero[max_y][max_x]);

	friend class Tablero;
};