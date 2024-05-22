#include "Pintar.h"

  /* 1 - Crear un una nueva varibale de tipo OPCION(la estructura)
   2-Ir al mouse primero y seguir el primer caso
   3- Ir al raton y seguir la estructura. 

   los shapx,y desaparecen

*/

Tablero tablero;
Pintar miPintura(&tablero);
GestionJugadas mijugada(&tablero);
bool juegoInicializado = false;
bool clicInicializado = false;

struct OPCION {
	int x, y, w, h;
	int sel;
	const char* texto;
};
OPCION MENU_INI[]{ {401,390,561,60,1,"MODO JUEGO"},{455,230,404,60,2, "OPCIONES"} };
				//  x inicial, y inicila, ancho de las letras, altura de las letras, numero de selección, texto

OPCION MENU_OPC[]{ {478,500,561,60,1,"AYUDA"} ,{320,350,561,60,2,"INSTRUCCIONES"} ,{478,200,561,60,3,"ATRAS"} };
//  x inicial, y inicila, ancho de las letras, altura de las letras, numero de selección, texto

OPCION MENU_PAUSA[]{ {538,470,561,60,1,"VOLVER A LA PARTIDA"} ,{560,400,561,60,2,"REINICIAR PARTIDA"} ,{600,330,561,60,3,"ABANDONAR"} };
OPCION MENU_AYUDA[]{ {520,550,561,60,1,"Torre"} ,{529,487,561,60,2,"Peon"} ,{489,424,561,60,3,"Caballo"} ,{554,360,561,60,4,"Alfil"} ,{551,294,561,60,5,"Rey"} ,{515,230,561,60,6,"Reina"},{440,168,561,60,7,"Arzobispo"},{480,100,561,60,8,"Canciller"},{110,60,261,20,9,"atras"} };
OPCION TEXTOTORRE[]{ {110,60,261,20,1,"atras"} }; //0
OPCION TEXTOPEON[]{ {110,60,261,20,1,"atras"} }; //1
OPCION TEXTOCABALLO[]{ {110,60,261,20,1,"atras"} }; //2
OPCION TEXTOALFIL[]{ {110,60,261,20,1,"atras"} }; //3
OPCION TEXTOREY[]{ {110,60,261,20,1,"atras"} }; //4
OPCION TEXTOREINA[]{ {110,60,261,20,1,"atras"} }; //5 
OPCION TEXTOARZOBISPO[]{ {110,60,261,20,1,"atras"} }; //6
OPCION TEXTOCANCILLER[]{ {110,60,261,20,1,"atras"} }; //7

OPCION MENU_INST[]{ {510,530,561,60,1,"Objetivo"} ,{509,455,561,60,2,"Enroque"} ,{449,380,561,60,3,"Jaque Mate"} ,{461,305,561,60,4,"Coronacion"} ,{405,230,561,60,5,"Captura al paso"} ,{515,155,561,60,6,"Tablas"},{520,80,561,60,7,"Atras"} };

OPCION TEXTOOBJETIVO[]{ {110,60,261,20,1,"atras"} }; //0
OPCION TEXTOENROQUE[]{ {110,60,261,20,1,"atras"} }; //1
OPCION TEXTOJAQUEMATE[]{ {110,60,261,20,1,"atras"} }; //2
OPCION TEXTOCORONACION[]{ {110,60,261,20,1,"atras"} }; //3
OPCION TEXTOCAPTURAPASO[]{ {110,60,261,20,1,"atras"} }; //4
OPCION TEXTOTABLAS[]{ {110,60,261,20,1,"atras"} }; //5 

OPCION M_FINAL[]{ 560,400,561,60,1,"REVANCHA" ,600,330,561,60,2,"ABANDONAR" };

Usuario::Usuario() {

	estado = INICIO;
	seleccion_ini = 0;
	seleccion_estado = estado;
	opcion = O;
	n_ayuda = 0;
	n_inst = 0;
	n_texto_a = 0;
	n_texto_ins = 0;
	menu_ayuda = H;
	menu_instrucciones = INS;
	coronar = C;
}

Usuario:: ~Usuario() {}


void Usuario::mouse(int x, int y) {
	if (estado == INICIO) {
		for (auto m : MENU_INI)
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//modo de juego
	}

	if (estado == MODOJUEGO) {
		if (estadodejuego == PAUSA) {
			for (auto m : MENU_PAUSA)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//pausa
		}
		if (estadodejuego == FINAL) {
			for (auto m : M_FINAL)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//final
		}
	}
	
	if (estado == OP) {
		for (auto m : MENU_OPC)
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//opciones
	}
	if (estado == AYU) {
		for (auto m : MENU_AYUDA)
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//ayuda		
	}
	if (estado == TEXTO_A) {
		if (n_ayuda == 0) {
			for (auto m : TEXTOTORRE)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//torre
		}
		if (n_ayuda == 1) {
			for (auto m : TEXTOPEON)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//peon
		}
		if (n_ayuda == 2) {
			for (auto m : TEXTOCABALLO)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//caballo
		}
		if (n_ayuda == 3) {
			for (auto m : TEXTOALFIL)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//alfil
		}
		if (n_ayuda == 4) {
			for (auto m : TEXTOREY)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//rey
		}
		if (n_ayuda == 5) {
			for (auto m : TEXTOREINA)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//reina
		}
		if (n_ayuda == 6) {
			for (auto m : TEXTOARZOBISPO)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//arzobispo
		}
		if (n_ayuda == 7) {
			for (auto m : TEXTOCANCILLER)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//canciller
		}
	}
	if (estado == INST) {
		for (auto m : MENU_INST)
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//ayuda		
	}
	if (estado == TEXTO_IN) {
		if (n_inst == 0) {
			for (auto m : TEXTOOBJETIVO)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//objetivo
		}
		if (n_inst == 1) {
			for (auto m : TEXTOENROQUE)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//enroque
		}
		if (n_inst == 2) {
			for (auto m : TEXTOJAQUEMATE)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//jaquemate
		}
		if (n_inst == 3) {
			for (auto m : TEXTOCORONACION)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//coronacion
		}
		if (n_inst == 4) {
			for (auto m : TEXTOCAPTURAPASO)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//capturapaso
		}
		if (n_inst == 5) {
			for (auto m : TEXTOTABLAS)
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//TABLAS
		}
	}
}

void Usuario::setReshape(float x, float y) {
	shapx = x;
	shapy = y;
}

int Usuario::getEstado() {
	return estado;
}

void Usuario::teclado(unsigned char key) {
	if (estado == MODOJUEGO) {
		if (estadodejuego == TURNO) {
			if (key == 'p' || key == 'P') { estadodejuego = PAUSA; }
			if (key == 'E' || key == 'e') { 
				//tablero.setEnroqueActivado(true);
				enroqueActivado = true;

				std::cout << "enroque activado" << std::endl;
			
			}
			
		}
	}
}

bool Usuario::getenroqueActivado() {
	return enroqueActivado;
}

void Usuario::raton(int button, int state, int x, int y) {
	int screenX = x;
	int screenY = y;


	// Actualizar las coordenadas del objeto en el juego
	std::cout << "Coordenadas del raton en la pantalla: (" << screenX << ", " << screenY << ")" << std::endl;

	//tablero.definirCoordenadasTablero(button, state, x, y);

	if (estado == INICIO) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			for (auto m : MENU_INI) {
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
					for (int i = INICIO; i <= TEXTO_IN; i++) {
						if (m.sel == 1) estado = MODOJUEGO;
						if (m.sel == 2) estado = OP;
					}
				}
			}
		}
	}

	if (estado == MODOJUEGO) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (estadodejuego == TURNO) {
				tablero.definirCoordenadasTablero(button, state, x, y);

				Pieza* tableroActual[max_y][max_x];
				tablero.getTablero(tableroActual);
				if (tablero.getFinTurnoN() == true) {
					if (mijugada.jaque(color::negro, tableroActual) == true || mijugada.jaque_mate(color::blanco, tableroActual) == true) {
						if (mijugada.jaque(color::negro, tableroActual) == true) { ganador = 1; }
						else if (mijugada.jaque_mate(color::blanco, tableroActual) == true) { ganador = 0; }
						estadodejuego = JAQUE_MATE;
						return;
					}
					else if (mijugada.jaque(color::blanco, tableroActual) == true) {
						estadodejuego = JAQUE;
						return;
					}
				}
				if (tablero.getFinTurnoB() == true) {
					if (mijugada.jaque(color::blanco, tableroActual) == true || mijugada.jaque_mate(color::negro, tableroActual) == true) {
						if (mijugada.jaque_mate(color::negro, tableroActual) == true) { ganador = 1; }
						else if (mijugada.jaque(color::blanco, tableroActual) == true) { ganador = 0; }
						estadodejuego = JAQUE_MATE;
						return;
					}
					else if (mijugada.jaque(color:: negro, tableroActual) == true) {
						estadodejuego = JAQUE;
						return;
					}
				}
			}
			if (estadodejuego == PAUSA) {
				for (auto m : MENU_PAUSA) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1) estadodejuego = TURNO;
							if (m.sel == 2) estadodejuego = TURNO;
							if (m.sel == 3) estado = INICIO;
						}
					}
				}
			}
			
		}
	}
	//if (estado == FINAL) {
	//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	//	{


	//	}
	//}
	if (estado == OP) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{

			for (auto m : MENU_OPC) {
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
					for (int i = INICIO; i <= TEXTO_IN; i++) {
						if (m.sel == 1) estado = AYU; menu_ayuda = H;
						if (m.sel == 2) estado = INST; menu_instrucciones = INS;
						if (m.sel == 3) estado = INICIO;
					}
				}
			}
		}
	}
	if (estado == AYU) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			for (auto m : MENU_AYUDA) {
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
					for (int i = INICIO; i <= TEXTO_IN; i++) {
						if (m.sel == 1)  n_ayuda = 0; estado = TEXTO_A;
						if (m.sel == 2) n_ayuda = 1;   estado = TEXTO_A;
						if (m.sel == 3) n_ayuda = 2;  estado = TEXTO_A;
						if (m.sel == 4) n_ayuda = 3; estado = TEXTO_A;
						if (m.sel == 5) n_ayuda = 4;   estado = TEXTO_A;
						if (m.sel == 6) n_ayuda = 5;  estado = TEXTO_A;
						if (m.sel == 7) n_ayuda = 6;  estado = TEXTO_A;
						if (m.sel == 8) n_ayuda = 7; estado = TEXTO_A;
						if (m.sel == 9)  estado = OP;
					}
				}
			}
		}
	}
	if (estado == TEXTO_A) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (n_ayuda == 0) {
				for (auto m : TEXTOTORRE) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
			if (n_ayuda == 1) {
				for (auto m : TEXTOPEON) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
			if (n_ayuda == 2) {
				for (auto m : TEXTOCABALLO) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
			if (n_ayuda == 3) {
				for (auto m : TEXTOALFIL) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
			if (n_ayuda == 4) {
				for (auto m : TEXTOREY) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
			if (n_ayuda == 5) {
				for (auto m : TEXTOREINA) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
			if (n_ayuda == 6) {
				for (auto m : TEXTOARZOBISPO) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}if (n_ayuda == 7) {
				for (auto m : TEXTOCANCILLER) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = AYU;
						}
					}
				}
			}
		}
	}

	if (estado == INST) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{

			for (auto m : MENU_INST) {
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
					for (int i = INICIO; i <= TEXTO_IN; i++) {
						if (m.sel == 1) n_inst = 0;  estado = TEXTO_IN; 
						if (m.sel == 2) n_inst = 1;  estado = TEXTO_IN;  
						if (m.sel == 3) n_inst = 2; estado = TEXTO_IN;  
						if (m.sel == 4) n_inst = 3;  estado = TEXTO_IN; 
						if (m.sel == 5) n_inst = 4;  estado = TEXTO_IN;
						if (m.sel == 6) n_inst = 5;  estado = TEXTO_IN;  
						if (m.sel == 7) estado = OP;

					}
				}
			}
		}
	}

	if (estado == TEXTO_IN) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (n_inst == 0) {
				for (auto m : TEXTOOBJETIVO) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = INST;
						}
					}
				}
			}
			if (n_inst == 1) {
				for (auto m : TEXTOENROQUE) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = INST;
						}
					}
				}
			}
			if (n_inst == 2) {
				for (auto m : TEXTOJAQUEMATE) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = INST;
						}
					}
				}
			}
			if (n_inst == 3) {
				for (auto m : TEXTOCORONACION) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = INST;
						}
					}
				}
			}
			if (n_inst == 4) {
				for (auto m : TEXTOCAPTURAPASO) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = INST;
						}
					}
				}
			}
			if (n_inst == 5) {
				for (auto m : TEXTOTABLAS) {
					if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
						for (int i = INICIO; i <= TEXTO_IN; i++) {
							if (m.sel == 1)  estado = INST;
						}
					}
				}
			}
		}
	}
}



void Usuario::dibujaFondo() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(0, 0, -0.5);
	glTexCoord2d(1, 1); glVertex3d(1366, 0, -0.5);
	glTexCoord2d(1, 0); glVertex3d(1366, 768,- 0.5);
	glTexCoord2d(0, 0); glVertex3d(0, 768, -0.5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Usuario::dibuja() {

	if (estado == INICIO) {


		dibujaFondo();

		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 80);
		printxy("CHESS GAME", 300, 525);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 60);

		for (auto m : MENU_INI) {
			printxy(m.texto, m.x, m.y);
			if (m.sel == seleccion_ini) {
				corona.setPos(m.x - 60, m.y + 25);
				corona.draw();
			}
		}



	}
	if (estado == MODOJUEGO) {
		if (estadodejuego == TURNO) {
			if (!juegoInicializado) {

				tablero.set_tablero();

				juegoInicializado = true;
			}

			miPintura.pintarPiezasTablero();
			///////////////CASILLA LEGAL/////////////////

			//miPintura.pintarCasillaLegal();


			glutPostRedisplay();
			miPintura.pintarPause();
			miPintura.pintarCuadricula();
			miPintura.pintarCorona();
			miPintura.pintarError();
			miPintura.pintarJaque();
			miPintura.pintarJaqueM();
			miPintura.pintarPromocion();
			miPintura.pintarEnroque();
		}
		if (estadodejuego == PAUSA) {
			miPintura.pintarPantalla();
			miPintura.pintarCorona();
			for (auto m : MENU_PAUSA) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}
			miPintura.pintarPiezasTablero();
			glutPostRedisplay();
			miPintura.pintarPause();
			miPintura.pintarCuadricula();
			miPintura.pintarError();
			miPintura.pintarJaque();
			miPintura.pintarJaqueM();
			miPintura.pintarPromocion();
			miPintura.pintarEnroque();

		}
		if (estadodejuego == FINAL) {
			miPintura.pintarPantalla();
			miPintura.pintarCorona();


			if (ganador == 1) {
				setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
				setFont("bin/fuentes/Bitwise.ttf", 70);
				printxy("GANADOR BLANCO", 450, 620);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				for (auto m : M_FINAL) {
					printxy(m.texto, m.x, m.y);
					if (m.sel == seleccion_ini) {
						corona.setPos(m.x - 60, m.y + 25);
						corona.draw();
					}
				}
			}
			else if (ganador == 0) {
				setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
				setFont("bin/fuentes/Bitwise.ttf", 70);
				printxy("GANADOR NEGRO", 450, 620);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				for (auto m : M_FINAL) {
					printxy(m.texto, m.x, m.y);
					if (m.sel == seleccion_ini) {
						corona.setPos(m.x - 60, m.y + 25);
						corona.draw();
					}

				}
			}
				miPintura.pintarPiezasTablero();
				glutPostRedisplay();
				miPintura.pintarPause();
				miPintura.pintarCuadricula();
				miPintura.pintarError();
				miPintura.pintarJaque();
				miPintura.pintarJaqueM();
				miPintura.pintarPromocion();
				miPintura.pintarEnroque();
			
		}
	}

	if (estado == OP) {

		dibujaFondo();


		for (auto m : MENU_OPC) {
			printxy(m.texto, m.x, m.y);
			if (m.sel == seleccion_ini) {
				corona.setPos(m.x - 60, m.y + 25);
				corona.draw();
			}
		}
	}

	if (estado == AYU) {

		dibujaFondo();

		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 70);
		printxy("AYUDA", 450, 620);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 50);

		for (auto m : MENU_AYUDA) {
			printxy(m.texto, m.x, m.y);
			if (m.sel == seleccion_ini) {
				corona.setPos(m.x - 60, m.y + 25);
				corona.draw();
			}
		}

	}



	if (estado == TEXTO_A) {
		switch (n_ayuda) {
		case 0:

			dibujaFondo();
			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("TORRE", 483, 600);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Las torres pueden moverse tantas casillas como", 180, 472);
			printxy("quieran, pero en sentido vertical y horizontal, es", 169, 407);
			printxy("decir, arriba, abajo, derecha e izquierda", 220, 342);

			for (auto m : TEXTOTORRE) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 1:
			dibujaFondo();
			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("PEON", 510, 600);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Los peones tienen diferentes tipos de movimientos", 150, 537);
			printxy("y capturas, pero ambos obligan a moverse hacia adelante.", 100, 472);
			printxy("Solo pueden moverse una casilla hacia delante,", 170, 407);
			printxy("excepto el primer movimiento, que puede ser de dos casillas", 70, 342);
			printxy("La captura es en diagonal y deben estar frente a ellos.", 100, 277);
			printxy("Si una pieza esta frente a ellos no podran avanzar", 130, 212);
			setFont("bin/fuentes/Bitwise.ttf", 45);

			for (auto m : TEXTOPEON) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 2:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("CABALLO", 480, 579);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Los caballos se mueven de la manera mas particular", 110, 472);
			printxy("Avanza dos cuadrados en una direccion, luego uno", 117, 407);
			printxy("mas en un angulo de 90 grados, dibujando la letra L", 110, 342);
			printxy("Estas piezas son las unicas que pueden saltar", 130, 277);
			printxy("sobre otras piezas", 450, 212);
			setFont("bin/fuentes/Bitwise.ttf", 45);

			for (auto m : TEXTOCABALLO) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 3:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("ALFIL", 550, 570);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Los alfiles pueden moverse tantas casillas como", 170, 472);
			printxy("quieran, pero solo en diagonal, lo que significa que", 155, 407);
			printxy("permanecen en el mismo color de la casilla inicial", 160, 342);
			printxy("durante toda la partida", 390, 277);
			setFont("bin/fuentes/Bitwise.ttf", 45);
			for (auto m : TEXTOALFIL) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;

		case 4:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("REY", 550, 550);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("El rey puede moverse solo una casilla", 230, 472);
			printxy("pero en cualquier direccion", 300, 407);

			for (auto m : TEXTOREY) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 5:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("REINA", 530, 550);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("La reina puede moverse tantas casillas como", 220, 472);
			printxy("quiera, incluso en cualquier direccion sin saltar", 210, 407);
			printxy("sobre las piezas de su mismo color", 270, 342);

			for (auto m : TEXTOREINA) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 6:

			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("ARZOBISPO", 483, 550);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Se mueve como Alfil y como Caballo", 300, 472);


			for (auto m : TEXTOARZOBISPO) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}
			break;
		case 7:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("CANCILLER", 480, 559);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Combina lo poderes de la torre y el caballo", 200, 472);
			printxy("Mueve una casilla en diagonal hacia adelante,", 180, 407);
			printxy("pero captura moviendo una casilla hacia adelante", 160, 342);

			for (auto m : TEXTOCANCILLER) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}
			break;

		default:
			break;
		}
	}

	if (estado == INST) {
		dibujaFondo();

		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 70);
		printxy("INSTRUCCIONES", 250, 600);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 50);

		for (auto m : MENU_INST) {
			printxy(m.texto, m.x, m.y);
			if (m.sel == seleccion_ini) {
				corona.setPos(m.x - 60, m.y + 25);
				corona.draw();
			}
		}
	}

	if (estado == TEXTO_IN) {
		switch (n_inst) {
		case 0:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("OBJETIVO", 480, 579);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Dar Jaque Mate al rey contrario", 320, 497);

			for (auto m : TEXTOOBJETIVO) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 1:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("ENROQUE", 483, 600);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Este movimiento deja colocar al rey en una posicion mas segura", 10, 537);
			printxy("y sacar la torre de la esquina. El rey se mueve dos casillas", 28, 472);
			printxy("lateralmente y la torre se sitúa al lado opuesto del rey", 100, 407);
			printxy("Condiciones:", 500, 342);
			printxy("1.- Debe ser el primer movimiento de ambas figuras", 90, 277);
			printxy("2.- No puede haber piezas entre el rey y la torre", 90, 212);
			printxy("No puede estar en jaque ni pasar por una casilla amenazada", 38, 147);

			for (auto m : TEXTOENROQUE) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 2:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("JAQUE MATE", 404, 576);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Un jugador esta en jaque cuando su rey esta siendo atacado por", 11, 499);
			printxy("una o dos piezas enemigas y seria posible para el rival", 83, 434);
			printxy("capturarlo en el siguiente turno.", 323, 369);
			printxy("Cuando el jugador no puede ejecutar ningun movimiento", 83, 304);
			printxy("que lo resuelva, ha perdido la partida", 249, 239);
			for (auto m : TEXTOJAQUEMATE) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;

		case 3:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("CORONACION", 400, 577);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 27);
			printxy("Cuando un peon llega a la ultima fila ha de ser cambiado por", 90, 497);
			printxy("un caballo, alfil, torre o dama, aunque el jugador ya posea esa pieza", 29, 432);
			printxy("Esta sustitucion esta incluida en el mismo turno del peon", 99, 367);
			for (auto m : TEXTOCORONACION) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 4:
			dibujaFondo();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("CAPTURA AL PASO", 325, 600);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 23);
			printxy("Forma adicional de un PEON para capturar peones enemigos:", 225, 512);
			printxy("El peon original debe estar en su quinta fila", 310, 447);
			printxy("El peon rival debe estar en su posicion inicial en una columna adyacente", 110, 382);
			printxy("El rival debe mover su peón dos pasos para que ambos peones queden en la misma fila", 20, 317);
			printxy("En ese momento, puede capturar al enemigo como si solo se hubiera movido", 105, 252);
			printxy("una casilla desplazando el propio en diagonal a la fila siguiente y", 210, 187);
			printxy("retirando  al capturado", 470, 122);
			for (auto m : TEXTOCAPTURAPASO) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;
		case 5:
			dibujaFondo();
			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 50);
			printxy("TABLAS", 487, 609);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Posibilidades:", 499, 542);
			printxy("Un jugador que no esta en jaque no puede mover en su turno", 25, 477);
			printxy("Por mutuo acuerdo", 470, 412);
			printxy("Se ha producido la repeticion de la misma posicion 3 veces", 45, 347);
			printxy("No hay suficientes piezas de ningún bando para hacer jaque mate", 15, 282);
			printxy("Se produce una secuencia de 50 jugadas de cada bando", 39, 217);
			printxy("sin captura o movimiento del peon", 280, 152);
			for (auto m : TEXTOTABLAS) {
				printxy(m.texto, m.x, m.y);
				if (m.sel == seleccion_ini) {
					corona.setPos(m.x - 60, m.y + 25);
					corona.draw();
				}
			}

			break;

		default:
			break;
		}
	}
}

