#pragma once
#include "freeglut.h"
#include "ETSIDI.h"


using namespace ETSIDI;

class Usuario {

	Sprite fondo{ "bin/imagenes/fondo.png", 0, 0, 220, 140 };
	Sprite corona{ "bin/imagenes/corona.png", 0,0, 80, 40 };

	int n_ayuda;
	int n_inst;
	int n_texto_a;
	int n_texto_ins;
	int seleccion_ini = 0;
	int seleccion_estado = 0;
	int tipoPieza;

	bool ganador; //blancas TRUE, negras FALSE 

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
	bool getGanador() {return ganador;}

	float shapx = 0.0, shapy = 0.0;

	enum Estado { INICIO, MODOJUEGO, OP, AYU, INST, TEXTO_A, TEXTO_IN, FINAL};
	Estado estado;

	enum EstadodeJuego{TURNO, JAQUE, JAQUE_MATE, PROMOCION, REINICIO};
	EstadodeJuego estadodejuego;

	void setEstadoJuego(EstadodeJuego nuevoestado) { estadodejuego = nuevoestado; }
	enum Opcion { O, AYUDA, INSTRUCCIONES, A_OPCION };
	Opcion opcion;

	enum Ayuda_texto { H, TEXTO };
	Ayuda_texto menu_ayuda;

	enum Instrucciones { INS, TEXTO_I };
	Instrucciones menu_instrucciones;

	void pantallaInicio(int x, int y);
	void pantallaOpciones(int x, int y);
	void pantallaAyuda(int x, int y);
	void subpantallasAyuda(int x, int y);
	void pantallaInstrucciones(int x, int y);
	void subpantallasInstrucciones(int x, int y);
	void pantallaFinal(int x, int y);
	void botonReinicio(int x, int y);

	void textoInicio();
	void textoOpciones();
	void textoAyuda();
	void textoSubpantallasAyuda();
	void textoInstrucciones();
	void textoSubpantallasInstrucciones();
	void textoFinal();
};
