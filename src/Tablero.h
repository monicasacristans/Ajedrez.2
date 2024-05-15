#pragma once
#include "Pieza.h"
#include "Usuario.h"
#include "Peon.h"
#include "Torre.h"
#include "Arzobispo.h"
#include "Caballo.h"
#include "Canciller.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"

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

	//void ratonTablero(int button, int state, int x, int y);

	void set_tablero();
	bool getTurno();
	bool getFlagMovValido();

	void definirCoordenadasTablero(int button, int state, int x, int y);
	bool checkCasillaOcupada(int x, int y);
	Pieza* checkPiezaEnCasilla(casilla pos);
	//std::vector<casilla> calcularCasillasLegales();
	bool esCasillaValida(const casilla& casilla) const;

	//bool sinMovimientos(color col);
	virtual bool moverPieza(casilla origen, casilla destino);

	//void dibujar();
};
