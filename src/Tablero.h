#pragma once
#include <vector>
#include "GestionJugadas.h"
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



class Tablero {

	Pieza *tablero[max_y][max_x];
	std::vector<Pieza*> piezasB;
	std::vector<Pieza*> piezasN;
	std::vector<Pieza*> piezaseliminadas;

	bool turno = true; //true BLANCAS,  false NEGRAS
	bool flag = false;
	bool flagMovInvalido = false;
	bool flagJaque = false;

	casilla cas_origen{ -1 , -1 };
	casilla cas_destino{ - 1, -1 };

public:
	Tablero();
	~Tablero();

	void set_tablero();
	bool getTurno();
	bool getFlagMovValido();
	bool getFlagJaque();

	void definirCoordenadasTablero(int button, int state, int x, int y);
	Pieza* checkPiezaEnCasilla(casilla pos);

	//ELIMINAR PIEZA
	bool eliminarPiezaT(int x, int y);

	virtual bool moverPieza(casilla origen, casilla destino);
};
