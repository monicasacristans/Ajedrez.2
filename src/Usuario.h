#pragma once
#include "freeglut.h"
#include <iostream>
#include "ETSIDI.h"

class Usuario {

private:

	//ETSIDI::Sprite corona{ "imagenes/corona.png", 0,0,10,5};

public:
	Usuario();
	virtual ~Usuario();

	void mouse(int x, int y);
	void raton(int button, int state, int x, int y);
	void dibuja();

	void setMenuInicio(int x);
	void setOpciones(int x);
	void setReshape(float x, float y);

	int getEstado();

	int n_ayuda;
	int n_inst;
	int n_texto_a;
	int n_texto_ins;
	float shapx, shapy;

	enum Estado { INICIO, MODOJUEGO, OP, AYU, INST };
	Estado estado;

	enum Inicio { I, OPCIONES, MODODEJUEGO };
	Inicio menu_inicio;

	enum Opcion { O, AYUDA, INSTRUCCIONES, A_OPCION };
	Opcion opcion;

	enum Ayuda_texto { H, TEXTO };
	Ayuda_texto menu_ayuda;

	enum Instrucciones { INS, TEXTO_I };
	Instrucciones menu_instrucciones;


};
