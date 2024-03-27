#include "Usuario.h"
#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

// Definir el objeto corona fuera de las funciones

ETSIDI::Sprite corona{ "imagenes/corona.png", 0,0,10,5 };
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

		switch (menu_inicio) {
		case I:
			menuinicio.draw();
		case OPCIONES:
			corona.setPos(shapx * -52, shapy * 5);
			corona.draw();
			menuinicio.draw();
		case MODODEJUEGO:
			corona.setPos(shapx * -33, shapy * -14);
			corona.draw();
			menuinicio.draw();
		}
	}
	if (estado == MODOJUEGO) {
		tablero.dibujar();
	}

	if (estado == OP) {
		switch (opcion) {
		case O:
			opciones.draw();
		case AYUDA:
			corona.setPos(shapx * -32, shapy * 25);
			corona.draw();
			opciones.draw();
		case INSTRUCCIONES:
			corona.setPos(shapx * -64, shapy * 0);
			corona.draw();
			opciones.draw();
		case A_OPCION:
			corona.setPos(shapx * -28, shapy * -27);
			corona.draw();
			opciones.draw();

		}
	}

	if (estado == AYU) {
		if (menu_ayuda == H) {
			//ayudas.draw();
			switch (n_ayuda) {
			case 0:
				corona.setPos(shapx * -22, shapy * 17);
				corona.draw();
				ayudas.draw();
			case 1:
				corona.setPos(shapx * -21, shapy * 7);
				corona.draw();
				ayudas.draw();
			case 2:
				corona.setPos(shapx * -27, shapy * -3);
				corona.draw();
				ayudas.draw();
			case 3:
				corona.setPos(shapx * -18, shapy * -14);
				corona.draw();
				ayudas.draw();
			case 4:
				corona.setPos(shapx * -17, shapy * -25);
				corona.draw();
				ayudas.draw();
			case 5:
				corona.setPos(shapx * -22, shapy * -35);
				corona.draw();
				ayudas.draw();
			case 6:
				corona.setPos(shapx * -82, shapy * -40);
				corona.draw();
				ayudas.draw();
			case 7:
				ayudas.draw();
			}
		}
		if (menu_ayuda == TEXTO) {
			switch (n_texto_a) {
			case 0:
				a_torre.draw();
			case 1:
				a_peon.draw();
			case 2:
				a_caballo.draw();
			case 3:
				a_alfil.draw();
			case 4:
				a_rey.draw();
			case 5:
				a_reina.draw();
			}
		}

	}
	if (estado == INST) {
		if (menu_instrucciones == INS) {
			switch (n_inst) {
			case 0:
				instrucciones.draw();
			case 1:
				corona.setPos(shapx * -27, shapy * 27);
				corona.draw();
				instrucciones.draw();
			case 2:
				corona.setPos(shapx * -29, shapy * 16);
				corona.draw();
				instrucciones.draw();
			case 3:
				corona.setPos(shapx * -36, shapy * 5);
				corona.draw();
				instrucciones.draw();
			case 4:
				corona.setPos(shapx * -36, shapy * -6);
				corona.draw();
				instrucciones.draw();
			case 5:
				corona.setPos(shapx * -48, shapy * -17);
				corona.draw();
				instrucciones.draw();
			case 6:
				corona.setPos(shapx * -22, shapy * -29);
				corona.draw();
				instrucciones.draw();
			case 7:
				corona.setPos(shapx * -20, shapy * -40);
				corona.draw();
				instrucciones.draw();


			}
		}
		if (menu_instrucciones == TEXTO_I) {
			switch (n_texto_ins) {
			case 0:
				i_objetivo.draw();
			case 1:
				i_enroque.draw();
			case 2:
				i_jaquemate.draw();
			case 3:
				i_coronacion.draw();
			case 4:
				i_capturapaso.draw();
			case 5:
				i_tablas.draw();
			}
		}
	}
}