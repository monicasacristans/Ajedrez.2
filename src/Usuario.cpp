#include <iostream>
#include "Usuario.h"
#include "Tablero.h"
#include "Peon.h"

// Definir el objeto corona fuera de las funciones
ETSIDI::Sprite corona{"imagenes/corona.png", 0,0,10,5 };

Tablero tablero;

Usuario::Usuario() {

	estado = INICIO;
	menu_inicio = I;
	opcion = O;
	n_ayuda = 0;
	n_inst = 0;
	n_texto_a = 0;
	n_texto_ins = 0;
}

Usuario:: ~Usuario() {}

void Usuario::mouse(int x, int y) {
	if (estado == INICIO) {
		setMenuInicio(0);
		//if (x > shapx * 1030 || x< shapx * 280 || y> shapy * 500 || y < shapy * 240) {
		//} //sin nada
		if (x<shapx * 1071 && x> shapx * 315 && y< shapy * 377 && y>shapy * 310) {
			setMenuInicio(1);
		} //modo de juego
		else if (x< shapx * 910 && x>shapx * 461 && y < shapy * 520 && y>shapy * 450) {
			setMenuInicio(2);
		}//opciones

	}
	if (estado == OP) {
		//if (x > shapx * 1230 || x<shapx * 152 || y>shapy * 584 || y < shapy * 98) {
		setOpciones(0);
		//} //sin nada

		if (x < shapx * 919 && x> shapx * 478 && y<shapy * 220 && y>shapy * 128) {
			setOpciones(1);
		} //ayuda
		else if (x < shapx * 1216 && x> shapx * 220 && y<shapy * 435 && y>shapy * 341) {
			setOpciones(2);
		} //instrucciones
		else if (x < shapx * 930 && x> shapx * 516 && y<shapy * 640 && y>shapy * 550) {
			setOpciones(3);
		} //atras

	}

	if (estado == AYU) {
		if (menu_ayuda == H) {
			if (x < shapx * 257 && x> shapx * 65 && y<shapy * 730 && y>shapy * 660) {
				n_ayuda = 6;
			}//atras
			else if (x > shapx * 830 || x<shapx * 520 || y>shapy * 710 || y < shapy * 200) {
				n_ayuda = 7;

			} //sin nada
			else if (x < shapx * 790 && x>shapx * 520 && y<shapy * 270 && y>shapy * 200) {
				n_ayuda = 0;

			} //torre
			else if (x < shapx * 739 && x>shapx * 527 && y<shapy * 368 && y>shapy * 300) {
				n_ayuda = 1;

			} //peon
			else if (x < shapx * 781 && x>shapx * 481 && y<shapy * 457 && y>shapy * 370) {
				n_ayuda = 2;


			} //caballo
			else if (x < shapx * 717 && x>shapx * 554 && y<shapy * 530 && y>shapy * 457) {
				n_ayuda = 3;

			} //alfil
			else if (x < shapx * 710 && x>shapx * 551 && y<shapy * 610 && y>shapy * 540) {
				n_ayuda = 4;

			} //rey
			else if (x < shapx * 636 && x> shapx * 575 && y<shapy * 720 && y>shapy * 610) {
				n_ayuda = 5;

			} //reina
		}
	}

	if (estado == INST) {
		if (menu_instrucciones == INS) {

			if (x > shapx * 1015 || x<shapx * 319 || y>shapy * 730 || y < shapy * 112) {

				n_inst = 0;
			} //sin nada
			else if (x < shapx * 834 && x>shapx * 481 && y<shapy * 220 && y>shapy * 112) {

				n_inst = 1;
			} //objetivo
			else if (x < shapx * 842 && x>shapx * 472 && y<shapy * 300 && y>shapy * 220) {

				n_inst = 2;


			} //enroque
			else if (x < shapx * 916 && x>shapx * 409 && y<shapy * 400 && y>shapy * 305) {

				n_inst = 3;
			} //jaquemate
			else if (x < shapx * 900 && x>shapx * 412 && y<shapy * 490 && y>shapy * 405) {

				n_inst = 4;
			} //coronacion
			else if (x < shapx * 1015 && x>shapx * 319 && y<shapy * 570 && y>shapy * 495) {

				n_inst = 5;
			} //captura al paso
			else if (x < shapx * 817 && x> shapx * 509 && y<shapy * 650 && y>shapy * 575) {

				n_inst = 6;
			} //tablas
			else if (x < shapx * 793 && x> shapx * 587 && y<shapy * 730 && y>shapy * 655) {

				n_inst = 7;
			} //atras
		}
	}

}


void Usuario::setMenuInicio(int x) {
	if (x == 0) menu_inicio = I;
	if (x == 1) menu_inicio = OPCIONES;
	if (x == 2) menu_inicio = MODODEJUEGO;
}

void Usuario::setOpciones(int x) {
	if (x == 0) opcion = O;
	if (x == 1) opcion = AYUDA;
	if (x == 2) opcion = INSTRUCCIONES;
	if (x == 3) opcion = A_OPCION;
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


	if (estado == INICIO) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (x<shapx * 1071 && x> shapx * 315 && y< shapy * 377 && y>shapy * 310) {

				estado = MODOJUEGO;
				return;
			}
			else if (x< shapx * 910 && x>shapx * 461 && y < shapy * 520 && y>shapy * 450) {
				estado = OP;

			}

		}
	}

	if (estado == OP) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (x < shapx * 919 && x> shapx * 478 && y<shapy * 220 && y>shapy * 128) {
				estado = AYU;
				return;
			} //ayuda
			else if (x < shapx * 1216 && x> shapx * 220 && y<shapy * 435 && y>shapy * 341) {
				estado = INST;
				return;
			} //instrucciones
			else if (x < shapx * 930 && x> shapx * 516 && y<shapy * 640 && y>shapy * 550) {
				estado = INICIO;
				return;
			} //atras

		}
	}
	if (estado == AYU) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (menu_ayuda == H) {
				if (x < shapx * 257 && x> shapx * 65 && y<shapy * 730 && y>shapy * 660) {
					estado = OP;
					return;
				}//atras
				else if (x > shapx * 830 || x<shapx * 520 || y>shapy * 710 || y < shapy * 200) {
					n_ayuda = 7;
					return;

				} //sin nada
				else if (x < shapx * 790 && x>shapx * 520 && y<shapy * 270 && y>shapy * 200) {
					menu_ayuda = TEXTO;
					n_texto_a = 0;
					return;

				} //torre
				else if (x < shapx * 739 && x>shapx * 527 && y<shapy * 368 && y>shapy * 300) {
					menu_ayuda = TEXTO;
					n_texto_a = 1;
					return;

				} //peon
				else if (x < shapx * 781 && x>shapx * 481 && y<shapy * 457 && y>shapy * 370) {
					menu_ayuda = TEXTO;
					n_texto_a = 2;
					return;


				} //caballo
				else if (x < shapx * 717 && x>shapx * 554 && y<shapy * 530 && y>shapy * 457) {
					menu_ayuda = TEXTO;
					n_texto_a = 3;
					return;

				} //alfil
				else if (x < shapx * 710 && x>shapx * 551 && y<shapy * 610 && y>shapy * 540) {
					menu_ayuda = TEXTO;
					n_texto_a = 4;
					return;

				} //rey
				else if (x < shapx * 636 && x> shapx * 575 && y<shapy * 720 && y>shapy * 610) {
					menu_ayuda = TEXTO;
					n_texto_a = 5;
					return;

				} //reina
			}
			if (menu_ayuda == TEXTO) {
				menu_ayuda = H;
				return;
			}
		}
	}

	if (estado == INST) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (menu_instrucciones == INS) {

				//if (x > shapx * 1015 || x<shapx * 319 || y>shapy * 730 || y < shapy * 112) {
				//	n_inst = 0;
				//} //sin nada
				if (x < shapx * 793 && x> shapx * 587 && y<shapy * 730 && y>shapy * 655) {
					estado = OP;
					return;
				}
				else if (x < shapx * 834 && x>shapx * 481 && y<shapy * 220 && y>shapy * 112) {
					menu_instrucciones = TEXTO_I;
					n_texto_ins = 0;
					return;
				} //objetivo
				else if (x < shapx * 842 && x>shapx * 472 && y<shapy * 300 && y>shapy * 220) {
					menu_instrucciones = TEXTO_I;
					n_texto_ins = 1;
					return;
				} //enroque
				else if (x < shapx * 916 && x>shapx * 409 && y<shapy * 400 && y>shapy * 305) {
					menu_instrucciones = TEXTO_I;
					n_texto_ins = 2;
					return;
				} //jaquemate
				else if (x < shapx * 900 && x>shapx * 412 && y<shapy * 490 && y>shapy * 405) {
					menu_instrucciones = TEXTO_I;
					n_texto_ins = 3;
					return;
				} //coronacion
				else if (x < shapx * 1015 && x>shapx * 319 && y<shapy * 570 && y>shapy * 495) {
					menu_instrucciones = TEXTO_I;
					n_texto_ins = 4;
					return;
				} //captura al paso
				else if (x < shapx * 817 && x> shapx * 509 && y<shapy * 650 && y>shapy * 575) {

					menu_instrucciones = TEXTO_I;
					n_texto_ins = 5;
					return;
				} //tablas
				//else if (x < shapx * 793 && x> shapx * 587 && y<shapy * 730 && y>shapy * 655) {
					//estado = OP;
					//return;

				//} //atras
			}
			if (menu_instrucciones == TEXTO_I) {
				menu_instrucciones = INS;
				return;
			}
		}
	}




}

void Usuario::dibuja() {
	if (estado == INICIO) {

		//Dibuja la pantalla de inicio

		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 


		//A�adir fondo
		/*glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/menuprincipal.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		glTexCoord2d(0, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 0); glVertex2f(10, 15);
		glTexCoord2d(0, 0); glVertex2f(-10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);*/

		
	
		//Hay que mirar lo de las letras
		setTextColor(1, 1, 0);
		setFont("bin/fuentes/Bitwise.ttf", 80);
		printxy("CHEST GAME", -58, 30);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 60);
		printxy("MODO DE JUEGO", -53, 8);
		printxy("OPCIONES", -32, -12);
		//menuinicio.draw();
		


		switch (menu_inicio) {
		case I:
			fondo.draw();

			//menuinicio.draw();

			
		case OPCIONES:
			corona.setPos(shapx * -52, shapy * 5);
			corona.draw();
			//menuinicio.draw();
		
		case MODODEJUEGO:
			corona.setPos(shapx * -33, shapy * -14);
			corona.draw();
			//menuinicio.draw();
	
		}
	}
	if (estado == MODOJUEGO) {
		tablero.dibujar();
		tablero.piezasdibujar();
	}

	if (estado == OP) {
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 65);
		printxy("AYUDA", -20, 20);
		printxy("INSTRUCCIONES", -50, -4);
		printxy("ATRAS", -16, -27);
		switch (opcion) {
		case O:
			//opciones.draw();
		case AYUDA:
			corona.setPos(shapx * -32, shapy * 25);
			corona.draw();
			//opciones.draw();
		case INSTRUCCIONES:
			corona.setPos(shapx * -64, shapy * 0);
			corona.draw();
			//opciones.draw();
		case A_OPCION:
			corona.setPos(shapx * -28, shapy * -27);
			corona.draw();
			//opciones.draw();
		}
	}

	if (estado == AYU) {
		if (menu_ayuda == H) {
			setTextColor(1, 1, 0);
			setFont("bin/fuentes/Bitwise.ttf", 70);
			printxy("AYUDA", -24, 25);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 45);
			printxy("TORRE", -15, 13);
			printxy("PEON", -13, 4);
			printxy("CABALLO", -19, -6);
			printxy("ALFIL", -10, -15);
			printxy("REY", -10, -25);
			printxy("REINA", -15, -35);
			printxy("atras", -70, -38);
			//ayudas.draw();
			switch (n_ayuda) {
			case 0:
				corona.setPos(shapx * -22, shapy * 17);
				corona.draw();
				//ayudas.draw();
			case 1:
				corona.setPos(shapx * -21, shapy * 7);
				corona.draw();
				//ayudas.draw();
			case 2:
				corona.setPos(shapx * -27, shapy * -3);
				corona.draw();

			case 3:
				corona.setPos(shapx * -18, shapy * -14);
				corona.draw();
				//ayudas.draw();
			case 4:
				corona.setPos(shapx * -17, shapy * -25);
				corona.draw();
				//ayudas.draw();
			case 5:
				corona.setPos(shapx * -22, shapy * -35);
				corona.draw();
				//ayudas.draw();
			case 6:
				corona.setPos(shapx * -82, shapy * -40);
				corona.draw();
				//ayudas.draw();
			}
		}
		if (menu_ayuda == TEXTO) {
			switch (n_texto_a) {
			case 0:
				//a_torre.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("TORRE", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Las torres pueden moverse tantas casillas como", -60, 10);
				printxy("quieran, pero en sentido vertical y horizontal, es", -62, 3);
				printxy("decir, arriba, abajo, derecha e izquierda", -60, -4);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 1:
				//a_peon.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("ALFIL", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Los peones tienen diferentes movimientos para sus desplazamientos", -60, 10);
				printxy("y capturas, pero ambos obligan a moverse hacia adelante.", -62, 3);
				printxy("Para moverse, solo pueden moverse una casilla hacia delante,", -60, -4);
				printxy("excepto el primer movimiento, que puede ser de dos casillas", -35, -11);
				printxy("Para capturar, lo hacen en diagonal, y deben estar frente a ellos.", -37, -18);
				printxy("Si una pieza esta frente a ellos no podran avanzar", -30, -25);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 2:
				//a_caballo.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("CABALLO", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Los caballos se mueven de la manera mas particular", -60, 10);
				printxy("Avanza dos cuadrados en una direccion, luego uno", -62, 3);
				printxy("mas en un angulo de 90 grados, dibujando la letra L", -60, -4);
				printxy("Estas piezas son las unicas que pueden saltar", -35, -11);
				printxy("sobre otras piezas", -17, -18);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 3:
				//a_alfil.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("ALFIL", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Los alfiles pueden moverse tantas casillas como", -60, 10);
				printxy("quieran, pero solo en diagonal, lo que significa que", -62, 3);
				printxy("permanecen en el mismo color de la casilla inicial", -60, -4);
				printxy("durante toda la partida", -35, -11);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);

			case 4:
				//a_rey.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("REY", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("El rey puede moverse solo una casilla, pero en cualquier direccion", -60, 10);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 5:
				//a_reina.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("REINA", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("La reina puede moverse tantas casillas como", -60, 10);
				printxy("quiera, incluso en cualquier direccion sin saltar", -62, 3);
				printxy("sobre las piezas de su mismo color", -60, -4);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			}
		}

	}
	if (estado == INST) {
		if (menu_instrucciones == INS) {
			setTextColor(1, 1, 0);
			setFont("bin/fuentes/Bitwise.ttf", 70);
			printxy("INSTRUCCIONES", -45, 33);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 45);
			printxy("OBJETIVO", -18, 22);
			printxy("ENROQUE", -19, 11);
			printxy("JAQUE MATE", -28, 1);
			printxy("CORONACION", -28, -9);
			printxy("CAPTURA AL PASO", -39, -19);
			printxy("TABLAS", -14, -29);
			setTextColor(1, 1, 0);
			printxy("atras", -9, -37);
			switch (n_inst) {
			case 0:
				//instrucciones.draw();
				
			case 1:
				corona.setPos(shapx * -27, shapy * 27);
				corona.draw();
				//instrucciones.draw();
				
			case 2:
				corona.setPos(shapx * -29, shapy * 16);
				corona.draw();
				//instrucciones.draw();
			
			case 3:
				corona.setPos(shapx * -36, shapy * 5);
				corona.draw();
				//instrucciones.draw();
			
			case 4:
				corona.setPos(shapx * -36, shapy * -6);
				corona.draw();
				//instrucciones.draw();
				
			case 5:
				corona.setPos(shapx * -48, shapy * -17);
				corona.draw();
				//instrucciones.draw();
				
			case 6:
				corona.setPos(shapx * -22, shapy * -29);
				corona.draw();
				//instrucciones.draw();
				
			case 7:
				corona.setPos(shapx * -20, shapy * -40);
				corona.draw();
				//instrucciones.draw();
				


			}
		}
		if (menu_instrucciones == TEXTO_I) {
			switch (n_texto_ins) {
			case 0:
				//i_objetivo.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("OBJETIVO", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Dar Jaque Mate al", -60, 10);
				printxy("rey contrario", -62, 3);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 1:
				//i_enroque.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("ENROQUE", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Este movimiento permite poner al rey en una posicion mas segura", -60, 10);
				printxy("y sacar la torre de la esquina. El rey se mueve dos casillas", -62, 3);
				printxy("hacia el lado y la torrre se coloca al lado del rey en el lado opuesto", -60, -4);
				printxy("Condiciones:", -20, -11);
				printxy("1.- Debe ser el primer movimiento de ambas figuras", -50, -18);
				printxy("2.- No puede haber piezas entre el rey y la torre", -54, -25);
				printxy("No puede estar en jaque ni pasar por una casilla amenazada", -55, -32);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 2:
				//i_jaquemate.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("JAQUE MATE", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Se dice que un jugador esta en jaque cuando su rey esta siendo", -60, 10);
				printxy("atacado por una o dos piezas enemigas y seria posible para el rival", -62, 3);
				printxy("capturarlo en el siguiente turno.", -43, -4);
				printxy("Cuando el jugador no puede ejecutar ningun movimiento que lo resuelva", -63, -11);
				printxy("ha perdido la partida", -36, -18);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);

			case 3:
				//i_coronacion.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("CORONACION", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Cuando un peon llega a la ultima fila ha de ser cambiado por", -60, 10);
				printxy("un caballo, alfil, torre o dama, aunque el jugador ya posea esa pieza", -62, 3);
				printxy("Esta sustitucion esta incluida en el mismo turno del peon", -60, -4);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 4:
				//i_capturapaso.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("CAPTURA AL PASO", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Forma adicional de un PEON para capturar peones enemigos. Para ello:", -60, 10);
				printxy("-El peon original debe estar en su quinta fila", -47, 3);
				printxy("-El peon rival debe estar en su posicion inicial en una columna adyacente", -63, -4);
				printxy("-El rival debe avanzar dos pasos su peon de modo que ambos peones queden juntos en la misma fila", -70, -11);
				printxy("- En ese momento, puede capturar al enemigo como si solo se hubiera movido", -54, -18);
				printxy("una casilla desplazando el propio en diagonal a la fila siguiente y", -50, -25);
				printxy("retirando  al capturado", -20, -32);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);
			case 5:
				//i_tablas.draw();
				setTextColor(1, 1, 0);
				setFont("bin/fuentes/Bitwise.ttf", 50);
				printxy("TABLAS", -15, 20);
				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 30);
				printxy("Posibilidades:", -13, 10);
				printxy("-Un jugador que no esta en jaque no puede mover en su turno", -74, 3);
				printxy("-Por mutuo acuerdo", -35, -4);
				printxy("-Se ha producido la repeticion de la misma posicion 3 veces", -74, -11);
				printxy("-No existen suficientes piezas por ningun bando para forzar un jaque mate", -83, -18);
				printxy("-Se produce una secuencia de 50 jugadas de cada bando", -74, -25);
				printxy("sin captura o movimiento del peon", -44, -32);
				setFont("bin/fuentes/Bitwise.ttf", 45);
				setTextColor(1, 1, 1);
				printxy("atras", -70, -38);

			}
		}
	}
}