#include <iostream>
#include "Usuario.h"
#include "Tablero.h"
#include "Pintar.h"

// Definir el objeto corona fuera de las funciones
ETSIDI::Sprite corona{ "bin/imagenes/corona.png", 0,0,10,5 };

Tablero tablero;
Pintar miPintura(&tablero);
bool juegoInicializado = false;

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

	miPintura.definirCoordenadasTablero(button, state, x, y);

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
	if (estado == MODOJUEGO) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			//if (estadodejuego == TURNO) {
			//	tablero.ratonTablero(button, state, x, y);

			//	//if (tablero.getFinTurnoNegro() == 1) {

			//	//}
			//	//if (tablero.getFinTurnoBlanco() == 1) {

			//	//}
			//}
		
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
		switch (menu_inicio) {
		case I:
			fondo.draw();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 80);
			printxy("CHEST GAME", -50, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 60);
			printxy("MODO DE JUEGO", -48, 2.5);
			printxy("OPCIONES", -29, -17.5);

		case OPCIONES:
			corona.setPos(shapx * -60, shapy * 5);
			corona.draw();
			fondo.draw();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 80);
			printxy("CHEST GAME", -50, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 60);
			printxy("MODO DE JUEGO", -48, 2.5);
			printxy("OPCIONES", -29, -17.5);

		case MODODEJUEGO:
			corona.setPos(shapx * -38, shapy * -14);
			corona.draw();
			fondo.draw();

			setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
			setFont("bin/fuentes/Bitwise.ttf", 80);
			printxy("CHEST GAME", -50, 20);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 60);
			printxy("MODO DE JUEGO", -48, 2.5);
			printxy("OPCIONES", -29, -17.5);
		}
	}
	if (estado == MODOJUEGO) {
		
		//tablero.piezasinicializa();
		//tablero.dibujar();

		miPintura.pintarCuadricula();
		miPintura.pintarPiezasTablero();

		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 20);
		printxy("JUGADOR", 57, 38);
		printxy("NEGRO", 60, 33);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 19);
		printxy("JUGADOR", -71, -25);
		printxy("BLANCO", -70, -30);

		if (!juegoInicializado) {

			tablero.set_tablero();
			//tablero.pintarCuadricula();
			cout<<miPintura.restringirCasilla(0,0);
			juegoInicializado = true;
		}
		
	}

		if (estado == OP) {
			switch (opcion) {
			case O:
				fondo.draw();

				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 65);
				printxy("AYUDA", -20, 20);
				printxy("INSTRUCCIONES", -48, -4);
				printxy("ATRAS", -20, -27);
				break;

			case AYUDA:
				corona.setPos(shapx * -32, shapy * 25);
				corona.draw();
				fondo.draw();

				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 65);
				printxy("AYUDA", -20, 20);
				printxy("INSTRUCCIONES", -48, -4);
				printxy("ATRAS", -20, -27);
				break;

			case INSTRUCCIONES:
				corona.setPos(shapx * -64, shapy * 0);
				corona.draw();
				fondo.draw();

				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 65);
				printxy("AYUDA", -20, 20);
				printxy("INSTRUCCIONES", -48, -4);
				printxy("ATRAS", -20, -27);
				break;

			case A_OPCION:
				corona.setPos(shapx * -28, shapy * -27);
				corona.draw();
				fondo.draw();

				setTextColor(1, 1, 1);
				setFont("bin/fuentes/Bitwise.ttf", 65);
				printxy("AYUDA", -20, 20);
				printxy("INSTRUCCIONES", -48, -4);
				printxy("ATRAS", -20, -27);
				break;
			}
		}

		if (estado == AYU) {
			if (menu_ayuda == H) {
				switch (n_ayuda) {
				case 0:
					corona.setPos(shapx * -22, shapy * 19);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;
				case 1:
					corona.setPos(shapx * -22, shapy * 8);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;
				case 2:
					corona.setPos(shapx * -27, shapy * -3);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;
				case 3:
					corona.setPos(shapx * -18, shapy * -14);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;

				case 4:
					corona.setPos(shapx * -17, shapy * -26);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;

				case 5:
					corona.setPos(shapx * -22, shapy * -37);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;

				case 6:
					corona.setPos(shapx * -82, shapy * -42);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;

				case 7:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);
					break;
				}
			}

			if (menu_ayuda == TEXTO) {
				switch (n_texto_a) {
				case 0:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("TORRE", -15, 20);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("Las torres pueden moverse tantas casillas como", -60, 10);
					printxy("quieran, pero en sentido vertical y horizontal, es", -61.5, 3);
					printxy("decir, arriba, abajo, derecha e izquierda", -53, -4);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					printxy("atras", -70, -38);

					break;
				case 1:
					fondo.draw();

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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 2:
					fondo.draw();

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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 3:
					fondo.draw();

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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;

				case 4:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("REY", -12.5, 20);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("El rey puede moverse solo una casilla", -45, 10);
					printxy("pero en cualquier direccion", -33, 0);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 5:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("REINA", -15, 20);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("La reina puede moverse tantas casillas como", -60, 10);
					printxy("quiera, incluso en cualquier direccion sin saltar", -62, 3);
					printxy("sobre las piezas de su mismo color", -46, -4);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;

				default:
					break;
				}
			}

		}
		if (estado == INST) {
			if (menu_instrucciones == INS) {
				switch (n_inst) {
				case 0:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);
				case 1:
					corona.setPos(shapx * -27, shapy * 27);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);

				case 2:
					corona.setPos(shapx * -29, shapy * 16);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);


				case 3:
					corona.setPos(shapx * -36, shapy * 5);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);

				case 4:
					corona.setPos(shapx * -36, shapy * -6);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);

				case 5:
					corona.setPos(shapx * -48, shapy * -17);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);

				case 6:
					corona.setPos(shapx * -22, shapy * -29);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);

				case 7:
					corona.setPos(shapx * -20, shapy * -40);
					corona.draw();
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
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
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -9, -37);
				}
			}

			if (menu_instrucciones == TEXTO_I) {
				switch (n_texto_ins) {
				case 0:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("OBJETIVO", -25, 20);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("Dar Jaque Mate al rey contrario", -45, 10);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 1:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("ENROQUE", -20, 25);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("Este movimiento deja colocar al rey en una posicion mas segura", -80, 15);
					printxy("y sacar la torre de la esquina. El rey se mueve dos casillas", -78, 8);
					printxy("lateralmente y la torre se sitúa al lado opuesto del rey", -71, 1);
					printxy("Condiciones:", -18, -6);
					printxy("1.- Debe ser el primer movimiento de ambas figuras", -70, -13);
					printxy("2.- No puede haber piezas entre el rey y la torre", -69, -20);
					printxy("No puede estar en jaque ni pasar por una casilla amenazada", -78, -27);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 2:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("JAQUE MATE", -30, 20);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("Un jugador esta en jaque cuando su rey esta siendo atacado por", -79, 10);
					printxy("una o dos piezas enemigas y seria posible para el rival", -70, 3);
					printxy("capturarlo en el siguiente turno.", -40, -4);
					printxy("Cuando el jugador no puede ejecutar ningun movimiento", -70, -11);
					printxy("que lo resuelva, ha perdido la partida", -49, -18);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;

				case 3:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("CORONACION", -33, 20);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 27);
					printxy("Cuando un peon llega a la ultima fila ha de ser cambiado por", -74, 10);
					printxy("un caballo, alfil, torre o dama, aunque el jugador ya posea esa pieza", -80, 3);
					printxy("Esta sustitucion esta incluida en el mismo turno del peon", -70, -4);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 4:
					fondo.draw();

					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("CAPTURA AL PASO", -40, 30);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 23);
					printxy("Forma adicional de un PEON para capturar peones enemigos:", -80, 20);
					printxy("El peon original debe estar en su quinta fila", -80, 13);
					printxy("El peon rival debe estar en su posicion inicial en una columna adyacente", -80, 6);
					printxy("El rival debe mover su peón dos pasos para que ambos peones queden en la misma fila", -80, -1);
					printxy("En ese momento, puede capturar al enemigo como si solo se hubiera movido", -80, -8);
					printxy("una casilla desplazando el propio en diagonal a la fila siguiente y", -80, -15);
					printxy("retirando  al capturado", -80, -22);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;
				case 5:
					fondo.draw();
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					setFont("bin/fuentes/Bitwise.ttf", 50);
					printxy("TABLAS", -20, 30);
					setTextColor(1, 1, 1);
					setFont("bin/fuentes/Bitwise.ttf", 30);
					printxy("Posibilidades:", -18, 20);
					printxy("Un jugador que no esta en jaque no puede mover en su turno", -79, 13);
					printxy("Por mutuo acuerdo", -79, 6);
					printxy("Se ha producido la repeticion de la misma posicion 3 veces", -79, -1);
					printxy("No hay suficientes piezas de ningún bando para hacer jaque mate", -79, -8);
					printxy("Se produce una secuencia de 50 jugadas de cada bando", -79, -15);
					printxy("sin captura o movimiento del peon", -79, -22);
					setFont("bin/fuentes/Bitwise.ttf", 45);
					setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
					printxy("atras", -70, -38);

					break;

				default:
					break;
				}
			}
		}
	}
