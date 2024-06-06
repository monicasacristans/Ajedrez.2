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
public:
	Pieza *tablero[max_y][max_x];
private:

	bool turno = true; //true BLANCAS,  false NEGRASbool finturnon=false;
	bool finturnon = false;
	bool finturnob = false;

	bool flag = false;
	bool flagMovInvalido = false;
	bool flagJaque = false;
	bool flagJaqueM = false;
	bool flagPromocion = false;
	bool flagEnroque = false;
	bool enroqueActivado = false;

	unsigned char tipoPromocion;

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
	bool getFlagPromocion(){ return flagPromocion; }
	void setFlagPromocion(bool prom) { flagPromocion= prom; }
	
	bool getFlagEnroque() { return flagEnroque; }



	void setCasillaDestino(casilla cas) { cas_destino = cas; }
	casilla getCasillaOrigen() const { return cas_origen; }
	casilla getCasillaDestino() const { return cas_destino; }
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

	
	void definirCoordenadasTablero(int button, int state, int x, int y);
	void realizarMovimiento(Pieza* p, casilla cas_origen, casilla cas_destino);
	Pieza* checkPiezaEnCasilla(casilla pos);

	void eliminarPieza(casilla destino);

	virtual bool moverPieza(casilla origen, casilla destino);
};
