#pragma once
#include "Pieza.h"
#include <vector>
#include "Jugador.h"


#define max_x 10//columnas
#define max_y 8//filas

class Tablero {

	Pieza *tablero[max_y][max_x];
	//std::vector<Pieza*> listapiezas;

	bool turno; //1 BLANCAS 0 NEGRAS
	//bool finturno;
	bool finturnonegro;
	bool finturnoblanco;

	Jugador* jugadorblanco;
	Jugador* jugadornegro;
	
public:


	Tablero();

	void ratonTablero(int button, int state, int x, int y);

	//setters
	void set_tablero();
	void setJugadorBlanco(Jugador* x);
	void setJugadorNegro(Jugador* x);

	//getters
	bool getFinTurnoNegro();
	bool getFinTurnoBlanco();
	bool getTurno();

	bool checkCasillaOcupada(int x, int y);
	Pieza* checkPiezaEnCasilla(casilla pos);


	void dibujar();
};
