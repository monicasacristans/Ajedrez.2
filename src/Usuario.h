#pragma once
#include "freeglut.h"
#include <iostream>
#include "ETSIDI.h"

class Usuario {

private:
	ETSIDI::Sprite menuinicio{ "imagenes/menuprincipal.png",0,0,160,90 };
	ETSIDI::Sprite opciones{ "imagenes/opciones.png",0,0,160,90 };
	ETSIDI::Sprite ayudas{ "imagenes/AYUDA.png",0,0,160,90 };
	ETSIDI::Sprite a_alfil{ "imagenes/texto_ayuda/H_Alfil.png",0,0,160,90 };
	ETSIDI::Sprite a_caballo{ "imagenes/texto_ayuda/H_Caballo.png",0,0,160,90 };
	ETSIDI::Sprite a_peon{ "imagenes/texto_ayuda/H_Peon.png",0,0,160,90 };
	ETSIDI::Sprite a_reina{ "imagenes/texto_ayuda/H_Reina.png",0,0,160,90 };
	ETSIDI::Sprite a_rey{ "imagenes/texto_ayuda/H_Rey.png",0,0,160,90 };
	ETSIDI::Sprite a_torre{ "imagenes/texto_ayuda/H_Torre.png",0,0,160,90 };
	/*ETSIDI::Sprite instrucciones{"imagenes/INSTRUCCIONES.png",0,0,160,90};
	ETSIDI::Sprite i_capturapaso{ "imagenes/texto_instrucciones/CAPTURAPASO.png",0,0,160,90 };
	ETSIDI::Sprite i_coronacion{ "imagenes/texto_instrucciones/CORONACION.png",0,0,160,90 };
	ETSIDI::Sprite i_enroque{ "imagenes/texto_instrucciones/ENROQUE.png",0,0,160,90 };
	ETSIDI::Sprite i_jaquemate{ "imagenes/texto_instrucciones/JAQUE MATE.png",0,0,160,90 };
	ETSIDI::Sprite i_objetivo{ "imagenes/texto_instrucciones/OBJETIVO.png",0,0,160,90 };
	ETSIDI::Sprite i_tablas{ "imagenes/texto_instrucciones/TABLAS.png",0,0,160,90 };*/

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
