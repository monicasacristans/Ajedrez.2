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
	int n_texto_a;
	float shapx, shapy;

	enum Estado { INICIO, MODOJUEGO, OP, AYU, INST };
	Estado estado;

	enum Inicio { I, OPCIONES, MODODEJUEGO };
	Inicio menu_inicio;

	enum Opcion{O, AYUDA, INSTRUCCIONES, A_OPCION};
	Opcion opcion;

	enum Ayuda{A, TORRE,PEON,CABALLO,ALFIL,REY,REINA, A_AYUDA};
	Ayuda ayuda;

	enum Ayuda_texto{H, TEXTO};
	Ayuda_texto menu_ayuda;

};
