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
	bool flagJaqueM = false;

	casilla cas_origen{ -1 , -1 };
	casilla cas_destino{ - 1, -1 };

public:
	Tablero();
	~Tablero();

	void set_tablero();
	bool getTurno();
	bool getFlagMovValido();
	bool getFlagJaque();
	bool getFlagJaqueM();

	void definirCoordenadasTablero(int button, int state, int x, int y);
	void realizarMovimiento(Pieza* p, casilla cas_origen, casilla cas_destino);
	Pieza* checkPiezaEnCasilla(casilla pos);

	//ELIMINAR PIEZA
	//void eliminarPieza(casilla origen, casilla destino);
	void eliminarPieza(casilla destino);

	virtual bool moverPieza(casilla origen, casilla destino);
};
