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
#include "GestionJugadas.h"
#include <vector>

#define max_x 10//columnas
#define max_y 8//filas

class Tablero {

	Pieza *tablero[max_y][max_x];
	std::vector<Pieza*> piezasB;
	std::vector<Pieza*> piezasN;
	std::vector<Pieza*> piezaseliminadas;
	int numero;

	int n_eliN, n_eliB;
	color c_eliminada;
	bool flag = false;
	bool flagMovInvalido = false;
	bool flagJaque = false;
	//bool flagJaqueM = false;
	bool flagEnroque = false;

	//bool flagCasElegida = false;

	casilla cas_origen{ -1 , -1 };
	casilla cas_destino{ - 1, -1 };
	bool turno = true; //true BLANCAS,  false NEGRAS

public:
	Tablero();
	~Tablero();
	void set_tablero();
	bool getTurno();
	bool getFlagMovValido();
	bool getFlagJaque();
	//bool getFlagJaqueM();
	bool getFlagEnroque();

	///////ELIMINAR PIEZA
	bool eliminarPiezaT(int x, int y);


	void definirCoordenadasTablero(int button, int state, int x, int y);
	bool checkCasillaOcupada(int x, int y);
	Pieza* checkPiezaEnCasilla(casilla pos);


	bool esCasillaValida(const casilla& casilla) const;

	virtual bool moverPieza(casilla origen, casilla destino);
};
