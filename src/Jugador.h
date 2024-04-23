#pragma once
#include <iostream>
#include "Pieza.h"

using namespace std;


class Jugador {
private:
	char colorJugador;
	bool finTurno;
	bool piezaEscogida;
	Pieza* piezaini, * piezafin;

public:
	Jugador();
	Jugador(char colorJug);

	void posicionarPieza(int button, int state, int x, int y);
	

	char getColorJugador();
	bool getFinTurno();

	void setFinTurno(bool finTurno);
	void setColorJugador(char color);
};