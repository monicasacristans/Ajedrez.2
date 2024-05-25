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

class GestionJugadas; // Declaración anticipada

class Tablero {

	Pieza *tablero[max_y][max_x];
	std::vector<Pieza*> piezasB;
	std::vector<Pieza*> piezasN;
	std::vector<Pieza*> piezasEliminadasB;
	std::vector<Pieza*> piezasEliminadasN;

	bool turno = true; //true BLANCAS,  false NEGRASbool finturnon=false;
	bool finturnon = false;
	bool finturnob = false;

	bool flag = false;
	bool flagMovInvalido = false;
	bool flagJaque = false;
	bool flagJaqueM = false;
	//bool flagPromocion = false;
	bool flagEnroque = false;
	bool enroqueActivado = false;


	casilla cas_origen{ -1 , -1 };
	casilla cas_destino{ - 1, -1 };


public:
	Tablero();
	~Tablero();

	void set_tablero();
	void getTablero(Pieza* tableroActual[max_y][max_x]);
	bool getTurno() { return turno; }
	void set_turno(bool t) { turno = t; }
	void setEnroqueActivado(bool estado) { enroqueActivado = estado; }

	bool getFlagMovValido(){ return flagMovInvalido; }//Flag para pintar los avisos
	bool getFlagJaque(){ return flagJaque; }
	bool getFlagJaqueM(){ return flagJaqueM; }
	//bool getFlagPromocion(){ return flagPromocion; }
	//void setFlagPromocion(bool prom) { flagPromocion= prom; }

	bool getFlagEnroque() { return flagEnroque; }
	/*bool set_promocion(casilla c, Pieza* p);*/

	casilla getCasillaOrigen() const { return cas_origen; }

	//Turnos
	bool getFinTurnoN() {
		if (turno == true)
			return !finturnon;
		else
			return finturnon;
	}
	bool getFinTurnoB() {
		if (turno == true)
			return finturnob;
		else
			return !finturnob;
	}

	const std::vector<Pieza*>& getPiezasEliminadasB() const {
		return piezasEliminadasB;
	}
	const std::vector<Pieza*>& getPiezasEliminadasN() const {
		return piezasEliminadasN;
	}

	std::vector<Pieza*>& inicializarvector() {

		for (int pieza = 0; pieza < 20; pieza++) {
			piezasEliminadasB[pieza] = nullptr;
		}
		for (int pieza = 0; pieza < 20; pieza++) {
			piezasEliminadasN[pieza] = nullptr;
		}
	}
	void definirCoordenadasTablero(int button, int state, int x, int y);
	void realizarMovimiento(Pieza* p, casilla cas_origen, casilla cas_destino);
	Pieza* checkPiezaEnCasilla(casilla pos);

	void eliminarPieza(casilla destino);

	virtual bool moverPieza(casilla origen, casilla destino);
};
