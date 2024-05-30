#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
using namespace ETSIDI;

class Usuario {

	Sprite fondo{ "bin/imagenes/fondo.png", 0, 0, 220, 140 };
	Sprite corona{ "bin/imagenes/corona.png", 0,0, 80, 40 };

public:
	Usuario();
	virtual ~Usuario();

	void mouse(int x, int y);
	void raton(int button, int state, int x, int y);
	void dibuja();
	void dibujaFondo();
	void setReshape(float x, float y) { shapx = x; shapy = y; }
	void teclado(unsigned char key);
	int getEstado() { return estado; }

	bool ganador; //blancas TRUE, negras FALSE 
	bool getGanador() {return ganador;}

	int n_ayuda;
	int n_inst;
	int n_texto_a;
	int n_texto_ins;
	float shapx, shapy;

	int seleccion_ini = 0;
	int seleccion_estado = 0;

	enum Estado { INICIO, MODOJUEGO, OP, AYU, INST, TEXTO_A, TEXTO_IN, FINAL};
	Estado estado;

	enum EstadodeJuego{TURNO, JAQUE, JAQUE_MATE, TABLAS, PAUSA, BLANCAS_CORONACION, NEGRAS_CORONACION};
	EstadodeJuego estadodejuego;

	enum Opcion { O, AYUDA, INSTRUCCIONES, A_OPCION };
	Opcion opcion;

	enum Ayuda_texto { H, TEXTO };
	Ayuda_texto menu_ayuda;

	enum Instrucciones { INS, TEXTO_I };
	Instrucciones menu_instrucciones;


};
