#pragma once
#include "Tablero.h"
#include "Pieza.h"

class Tablero;

class GestionJugadas {
	Tablero* tab = nullptr ;
public:
	//GestionJugadas(Tablero *miTablero):tab(miTablero){};
	GestionJugadas() {};
	//GestionJugadas(Tablero *miTablero):tab(miTablero) {};
	
	casilla encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]);

	//JAQUE 
	bool jaque(color col, Pieza* tablero[max_y][max_x]);
	bool reySaleDeJaque(color col, Pieza* tablero[max_y][max_x]);

	//JAQUE MATE
	bool jaque_mate(color col, Pieza* tablero[max_y][max_x]);

	//PROMOCION
	bool peonFinal(casilla origen);
	void promocion(casilla cas, Pieza* tablero[max_y][max_x]);

	//ENROQUE
	//bool enroque(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]);
	bool verificarEnroque(color jugador, Pieza* tablero[max_y][max_x]);
	bool verificarEnroqueIzquierda(color jugador, Pieza* tablero[max_y][max_x]);
	void realizarEnroque(color jugador, Pieza* tablero[max_y][max_x]);

	friend class Tablero;
};