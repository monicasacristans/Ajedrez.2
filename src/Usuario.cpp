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


Usuario::Usuario() {

	estado = INICIO;
	seleccion_ini = 0;
	seleccion_estado = estado;
	opcion = O;
	n_ayuda = 0;
	n_inst = 0;
	n_texto_a = 0;
	n_texto_ins = 0;
	coronar = C;
}

Usuario:: ~Usuario() {}


void Usuario::mouse(int x, int y) {
	if (estado == INICIO) {
		for (auto m : MENU_INI)
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y)seleccion_ini = m.sel;//modo de juego
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
		if (n_ayuda == 6) {
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
			tablero.definirCoordenadasTablero(button, state, x, y);
			//if (estadodejuego == TURNO) {
			//	///////turno acabado para el jugador negro
			//	if (tablero.getTurno() == false) {
			//		if (jugada.jaque(color::negro) == true || jugada.jaque_mate(color::blanco) == true) {
			//			if (jugada.jaque(color::negro) == true) {
			//				ganador = 1; //NEGRO GANA SI ESTA EN JAQUE
			//			}
			//			else if (jugada.jaque_mate(color::blanco) == true) { ganador = 0; }
			//			i = 0;
			//			estadodejuego = JAQUE_MATE;
			//			return;
			//		}
			//		else if (jugada.jaque(color::blanco) == true) {
			//			estadodejuego = JAQUE;
			//			i = 0;
			//			return;
			//		}
			//	}

			//	//////turno acabado para el jugador blanco
			//	if (tablero.getTurno() == true) {
			//		if (jugada.jaque(color::blanco) == true || jugada.jaque_mate(color::negro) == true) {
			//			if (jugada.jaque_mate(color::negro) == true) { ganador = 1; }
			//			else if (jugada.jaque(color::blanco) == true) { ganador = 0; }
			//			i = 0;
			//			estadodejuego = JAQUE_MATE;
			//			return;
			//		}
			//		else if (jugada.jaque(color::negro) == true) {
			//			estadodejuego = JAQUE;
			//			i = 0;
			//			return;
			//		}
			//	}
			//}
			//miPintura.pintarCasillaLegal();
		}
	}
	if (estado == OP) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{

			for (auto m : MENU_OPC) {
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
					for (int i = INICIO; i <= TEXTO_IN; i++) {
						if (m.sel == 1) estado = AYU;
						if (m.sel == 2) estado = INST;
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
						if (m.sel == 1)  estado = TEXTO_A; n_ayuda = 0;
						if (m.sel == 2)   estado = TEXTO_A; n_ayuda = 1;
						if (m.sel == 3)  estado = TEXTO_A;  n_ayuda = 2;
						if (m.sel == 4) estado = TEXTO_A;  n_ayuda = 3;
						if (m.sel == 5)   estado = TEXTO_A; n_ayuda = 4;
						if (m.sel == 6)  estado = TEXTO_A; n_ayuda = 5;
						if (m.sel == 7)  estado = TEXTO_A; n_ayuda = 6;
						if (m.sel == 8) estado = TEXTO_A; n_ayuda = 7;
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
		printxy("CHEST GAME", 300, 525);
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
		if (!juegoInicializado) {

			tablero.set_tablero();

			juegoInicializado = true;
		}

		miPintura.pintarPiezasTablero();
		///////////////CASILLA LEGAL/////////////////

		//miPintura.pintarCasillaLegal();


		glutPostRedisplay();
		miPintura.pintarCuadricula();
		miPintura.pintarCorona();
		miPintura.pintarError();
		miPintura.pintarJaque();
		miPintura.pintarJaqueM();
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
			printxy("TORRE", -15, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Las torres pueden moverse tantas casillas como", -60, 10);
			printxy("quieran, pero en sentido vertical y horizontal, es", -61.5, 3);
			printxy("decir, arriba, abajo, derecha e izquierda", -53, -4);

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
			printxy("PEON", -15, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Los peones tienen diferentes tipos de movimientos", -60, 10);
			printxy("y capturas, pero ambos obligan a moverse hacia adelante.", -69.5, 3);
			printxy("Solo pueden moverse una casilla hacia delante,", -55, -4);
			printxy("excepto el primer movimiento, que puede ser de dos casillas", -73, -11);
			printxy("La captura es en diagonal y deben estar frente a ellos.", -66, -18);
			printxy("Si una pieza esta frente a ellos no podran avanzar", -61, -25);
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
			printxy("CABALLO", -25, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Los caballos se mueven de la manera mas particular", -70, 10);
			printxy("Avanza dos cuadrados en una direccion, luego uno", -70, 3);
			printxy("mas en un angulo de 90 grados, dibujando la letra L", -70, -4);
			printxy("Estas piezas son las unicas que pueden saltar", -65, -11);
			printxy("sobre otras piezas", -20, -18);
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
			printxy("ALFIL", -15, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Los alfiles pueden moverse tantas casillas como", -60, 10);
			printxy("quieran, pero solo en diagonal, lo que significa que", -62, 3);
			printxy("permanecen en el mismo color de la casilla inicial", -60, -4);
			printxy("durante toda la partida", -35, -11);
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
			printxy("REY", -12.5, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("El rey puede moverse solo una casilla", -45, 10);
			printxy("pero en cualquier direccion", -33, 0);

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
			printxy("REINA", -15, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("La reina puede moverse tantas casillas como", -60, 10);
			printxy("quiera, incluso en cualquier direccion sin saltar", -62, 3);
			printxy("sobre las piezas de su mismo color", -46, -4);

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
			break;
		case 7:
			dibujaFondo();
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
			printxy("OBJETIVO", 444, 579);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Dar Jaque Mate al rey contrario", 283, 497);

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
			printxy("ENROQUE", 483, 620);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Este movimiento deja colocar al rey en una posicion mas segura", 2, 537);
			printxy("y sacar la torre de la esquina. El rey se mueve dos casillas", 18, 472);
			printxy("lateralmente y la torre se sitúa al lado opuesto del rey", 73, 407);
			printxy("Condiciones:", 500, 342);
			printxy("1.- Debe ser el primer movimiento de ambas figuras", 90, 277);
			printxy("2.- No puede haber piezas entre el rey y la torre", 90, 212);
			printxy("No puede estar en jaque ni pasar por una casilla amenazada", 18, 147);

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
			printxy("CORONACION", 379, 577);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 27);
			printxy("Cuando un peon llega a la ultima fila ha de ser cambiado por", 50, 497);
			printxy("un caballo, alfil, torre o dama, aunque el jugador ya posea esa pieza", 2, 432);
			printxy("Esta sustitucion esta incluida en el mismo turno del peon", 82, 367);
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
			printxy("CAPTURA AL PASO", 325, 658);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 23);
			printxy("Forma adicional de un PEON para capturar peones enemigos:", 225, 577);
			printxy("El peon original debe estar en su quinta fila", 5, 512);
			printxy("El peon rival debe estar en su posicion inicial en una columna adyacente", 5, 447);
			printxy("El rival debe mover su peón dos pasos para que ambos peones queden en la misma fila", 5, 382);
			printxy("En ese momento, puede capturar al enemigo como si solo se hubiera movido", 5, 317);
			printxy("una casilla desplazando el propio en diagonal a la fila siguiente y", 5, 252);
			printxy("retirando  al capturado", 5, 187);
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
			printxy("TABLAS", 487, 659);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 30);
			printxy("Posibilidades:", 499, 576);
			printxy("Un jugador que no esta en jaque no puede mover en su turno", 9, 511);
			printxy("Por mutuo acuerdo", 9, 446);
			printxy("Se ha producido la repeticion de la misma posicion 3 veces", 9, 381);
			printxy("No hay suficientes piezas de ningún bando para hacer jaque mate", 9, 316);
			printxy("Se produce una secuencia de 50 jugadas de cada bando", 9, 251);
			printxy("sin captura o movimiento del peon", 9, 186);
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

