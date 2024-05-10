#pragma once
#include "Pieza.h"
#include <vector>



#define max_x 10//columnas
#define max_y 8//filas

class Tablero {

	Pieza *tablero[max_y][max_x];
	bool flag = false;
	bool flagMovInvalido = false;
	//bool flagCasElegida = false;

	casilla cas_origen{ -1 , -1 };
	casilla cas_destino{ - 1, -1 };

	bool turno = true; //true BLANCAS,  false NEGRAS

public:

	Tablero();

	void ratonTablero(int button, int state, int x, int y);

	void set_tablero();
	bool getTurno();
	bool getFlagMovValido();

	void definirCoordenadasTablero(int button, int state, int x, int y);
	bool checkCasillaOcupada(int x, int y);
	Pieza* checkPiezaEnCasilla(casilla pos);

	virtual bool moverPieza(casilla origen, casilla destino);

	void dibujar();
};
