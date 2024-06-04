#pragma once
#include "Tablero.h"
#include "Pieza.h"

class Tablero;

class GestionJugadas {
	Tablero* tab = nullptr;
	bool flagPromocion = false;


public:

	GestionJugadas() {};
	GestionJugadas(Tablero *miTablero):tab(miTablero) {};


	//JAQUE 
	bool jaque(color col, Pieza* tablero[max_y][max_x]);
	bool reySaleDeJaque(color col, Pieza* tablero[max_y][max_x]);
	bool reyPuedeMoverse(color col, Pieza* tablero[max_y][max_x]);
	bool piezaPuedeProteger(color col, Pieza* tablero[max_y][max_x]);

	//JAQUE MATE
	bool jaque_mate(color col, Pieza* tablero[max_y][max_x]);
	casilla encontrarPosicionRey(color col, Pieza* tablero[max_y][max_x]);

	//promocion

	bool peonFinal(casilla origen);
	void promocion(casilla cas, Pieza* tablero[max_y][max_x], int tipo);
	bool getFlagPromocion() { return flagPromocion; }
	void setFlagPromocion(bool prom) { flagPromocion = prom; };
	Pieza* crearPieza(tipo t, color col);

	//ENROQUE
	bool verificarEnroque(color jugador, Pieza* tablero[max_y][max_x]);
	bool verificarEnroqueIzquierda(color jugador, Pieza* tablero[max_y][max_x]);
	void realizarEnroque(color jugador, Pieza* tablero[max_y][max_x]);
	friend class Tablero;
};