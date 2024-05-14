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
	std::vector<casilla> calcularCasillasLegales();
	bool esCasillaValida(const casilla& casilla) const;
	//jaque 

	bool jaque(color col);

	//Jaque Mate
	bool piezaAmenazada(casilla pos, color col);
	bool jaque_mate(color col);
	casilla encontrarPosicionRey(color col);
	bool estaEnJaque(color col);

	bool sinMovimientos(color col);
	virtual bool moverPieza(casilla origen, casilla destino);

	void dibujar();
};
