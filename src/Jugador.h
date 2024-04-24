#pragma once
#include <iostream>
#include "Pieza.h"
#include "ETSIDI.h"


using namespace ETSIDI;
using namespace std;


class Jugador {
private:
	color colorJugador;
	//bool finTurno;
	bool piezaEscogida;
	Pieza* piezaini, * piezafin;
	int posicioninicial, posicionfinal;

protected:

	//FALLO
	bool finTurno = 0;
public:
	Jugador();
	Jugador(color colorJug);

	void posicionarPieza(int button, int state, int x, int y);
	
	void dibujarcorona();

	color getColorJugador();
	bool getFinTurno();

	void setFinTurno(bool finTurno);
	void setColorJugador(color color);

};