#include "Usuario.h"
#include "Pintar.h"

Tablero tablero;
GestionJugadas miJugada(&tablero);
Pintar miPintura(&tablero);

bool juegoInicializado = false;
bool clicInicializado = false;

struct OPCION {
	int x, y, w, h;
	int sel;
	const char* texto;
};

OPCION MENU_INI[]{ {401,390,561,60,1,"MODO JUEGO"},{455,230,404,60,2, "OPCIONES"} };
OPCION MENU_OPC[]{ {478,500,561,60,1,"AYUDA"} ,{320,350,561,60,2,"INSTRUCCIONES"} ,{478,200,561,60,3,"ATRAS"} };
OPCION MENU_AYUDA[]{ {520,550,561,60,1,"Torre"} ,{529,487,561,60,2,"Peon"} ,{489,424,561,60,3,"Caballo"} ,{554,360,561,60,4,"Alfil"} ,{551,294,561,60,5,"Rey"} ,{515,230,561,60,6,"Reina"},{440,168,561,60,7,"Arzobispo"},{480,100,561,60,8,"Canciller"},{110,60,261,20,9,"atras"} };
OPCION TEXTOTORRE[]{ {110,60,261,20,1,"atras"} }; //0
OPCION TEXTOPEON[]{ {110,60,261,20,1,"atras"} }; //1
OPCION TEXTOCABALLO[]{ {110,60,261,20,1,"atras"} }; //2
OPCION TEXTOALFIL[]{ {110,60,261,20,1,"atras"} }; //3
OPCION TEXTOREY[]{ {110,60,261,20,1,"atras"} }; //4
OPCION TEXTOREINA[]{ {110,60,261,20,1,"atras"} }; //5 
OPCION TEXTOARZOBISPO[]{ {110,60,261,20,1,"atras"} }; //6
OPCION TEXTOCANCILLER[]{ {110,60,261,20,1,"atras"} }; //7

OPCION MENU_INST[]{ {510,530,561,60,1,"Objetivo"} ,{509,455,561,60,2,"Enroque"} ,{449,380,561,60,3,"Jaque Mate"} ,{461,305,561,60,4,"Promocion"},{520,80,561,60,7,"Atras"} };

OPCION TEXTOOBJETIVO[]{ {110,60,261,20,1,"atras"} }; //0
OPCION TEXTOENROQUE[]{ {110,60,261,20,1,"atras"} }; //1
OPCION TEXTOJAQUEMATE[]{ {110,60,261,20,1,"atras"} }; //2
OPCION TEXTOPROMOCION[]{ {110,60,261,20,1,"atras"} }; //3

OPCION M_FINAL[]{ 590,400,561,60,1,"REVANCHA" ,570,330,561,60,2,"ABANDONAR" };


Usuario::Usuario() {

	estado = INICIO;
	estadodejuego = TURNO;
	seleccion_ini = 0;
	seleccion_estado = estado;
	opcion = O;
	n_ayuda = 0;
	n_inst = 0;
	n_texto_a = 0;
	n_texto_ins = 0;
	menu_ayuda = H;
	menu_instrucciones = INS;
}

Usuario:: ~Usuario() {}


void Usuario::mouse(int x, int y) {
	OPCION* menu = nullptr;
	int menu_size = 0;

	if (estado == INICIO) {
		menu = MENU_INI;
		menu_size = sizeof(MENU_INI) / sizeof(MENU_INI[0]);
	}
	else if (estado == OP) {
		menu = MENU_OPC;
		menu_size = sizeof(MENU_OPC) / sizeof(MENU_OPC[0]);
	}
	else if (estado == AYU && menu_ayuda == H) {
		menu = MENU_AYUDA;
		menu_size = sizeof(MENU_AYUDA) / sizeof(MENU_AYUDA[0]);
	}
	else if (estado == AYU && menu_ayuda == TEXTO) {
		switch (n_ayuda) {
		case 0: menu = TEXTOTORRE; break;
		case 1: menu = TEXTOPEON; break;
		case 2: menu = TEXTOCABALLO; break;
		case 3: menu = TEXTOALFIL; break;
		case 4: menu = TEXTOREY; break;
		case 5: menu = TEXTOREINA; break;
		case 6: menu = TEXTOARZOBISPO; break;
		case 7: menu = TEXTOCANCILLER; break;
		}
		menu_size = 1; // Solo hay una opción de "atras" en cada menú de texto
	}

	else if (estado == INST && menu_ayuda == INS) {
		menu = MENU_INST;
		menu_size = sizeof(MENU_INST) / sizeof(MENU_INST[0]);
	}

	else if (estado == INST && menu_ayuda == TEXTO_I) {
		switch (n_inst) {
		case 0: menu = TEXTOOBJETIVO; break;
		case 1: menu = TEXTOENROQUE; break;
		case 2: menu = TEXTOJAQUEMATE; break;
		case 3: menu = TEXTOPROMOCION; break;
		}
		menu_size = 1; // Solo hay una opción de "atras" en cada menú de texto
	}

	if (menu) {
		for (int i = 0; i < menu_size; ++i) {
			if (x < menu[i].x + menu[i].w && x > menu[i].x && y < menu[i].y + menu[i].h && y > menu[i].y) {
				seleccion_ini = menu[i].sel;
				break;
			}
		}
	}
}


void Usuario::teclado(unsigned char key) {
	
	if (estado == MODOJUEGO) {
		if (estadodejuego == PROMOCION) {

			if (key>='1' && key<='6') { // Verificar que la tecla sea un número válido para la promoción
				int tipoPieza = key - '0'; // Convertir el char a int restando '0'

				miJugada.promocion(tablero.getCasillaDestino(), tablero.tablero, tipoPieza);
				estadodejuego = TURNO; // Volver al estado de turno después de la promoción
			}
		}
	}
}

void Usuario::raton(int button, int state, int x, int y) {
	int screenX = x;
	int screenY = y;

	// Actualizar las coordenadas del objeto en el juego
	std::cout << "Coordenadas del raton en la pantalla: (" << screenX << ", " << screenY << ")" << std::endl;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		switch (estado) {
		case INICIO:
			pantallaInicio(x, y);
			break;

		case MODOJUEGO:
			if (estadodejuego == TURNO) {
				tablero.definirCoordenadasTablero(button, state, x, y);
				Pieza* tableroActual[max_y][max_x];
				tablero.getTablero(tableroActual);

				if (tablero.getFinTurnoN() == true) {
					if (miJugada.jaque_mate(color::blanco, tableroActual) == true) {
						ETSIDI::play("bin/sonidos/ganador.mp3");
						ganador = false;//Ganan negras
						estado = FINAL;
						return;
					}
				}
				else if (tablero.getFinTurnoB() == true) {
					if (miJugada.jaque_mate(color::negro, tableroActual) == true) {
						ETSIDI::play("bin/sonidos/ganador.mp3");
						ganador = true;//Ganan blancas
						estado = FINAL;
						return;
					}
				}
			}
			if (estadodejuego == PROMOCION) {
				teclado(tipoPieza);
			}
			break;

		case OP:
			pantallaOpciones(x, y);
			break;

		case AYU:
			pantallaAyuda(x, y);
			break;

		case TEXTO_A:
			subpantallasAyuda(x, y);
			break;

		case INST:
			pantallaInstrucciones(x, y);
			break;

		case TEXTO_IN:
			subpantallasInstrucciones(x, y);
			break;

		case FINAL:
			pantallaFinal(x, y);
			break;
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

	switch (estado) {
	case INICIO:
		dibujaFondo();
		textoInicio();
		break;

	case MODOJUEGO:
		ETSIDI::stopMusica();
		if (estadodejuego == TURNO) {
			if (!juegoInicializado) {
				tablero.set_tablero();
				juegoInicializado = true;
			}
			miPintura.pintarPiezasTablero();

			glutPostRedisplay();
			miPintura.pintarCuadricula();
			miPintura.pintarCorona();
			miPintura.pintarError();
			miPintura.pintarJaque();
		}

		if (estadodejuego == PROMOCION) {
			miPintura.pintarPiezasTablero();

			glutPostRedisplay();
			miPintura.pintarCuadricula();
			miPintura.pintarCorona();
			miPintura.pintarError();
			miPintura.pintarJaque();
			miPintura.pintarPromocion();
		}
		break;
	case OP:
		dibujaFondo();
		textoOpciones();
		break;

	case AYU:
		dibujaFondo();
		textoAyuda();
		break;

	case TEXTO_A:
		textoSubpantallasAyuda();
		break;

	case INST:
		dibujaFondo();
		textoInstrucciones();
		break;

	case TEXTO_IN:
		textoSubpantallasInstrucciones();
		break;

	case FINAL:
		miPintura.pintarPantallaFinal();
		textoFinal();
		miPintura.pintarPiezasTablero();
		glutPostRedisplay();
		miPintura.pintarCuadricula();
		break;
	}
}

void Usuario::pantallaInicio(int x, int y) {
	for (const auto& m : MENU_INI) {
		if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
			for (int i = INICIO; i <= TEXTO_IN; i++) {
				if (m.sel == 1) estado = MODOJUEGO;
				if (m.sel == 2) estado = OP;
			}
		}
	}
}

void Usuario::pantallaOpciones(int x, int y) {
	for (const auto& m : MENU_OPC) {
		if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
			for (int i = INICIO; i <= TEXTO_IN; i++) {
				if (m.sel == 1) estado = AYU;
				if (m.sel == 2) estado = INST;
				if (m.sel == 3) estado = INICIO;
			}
		}
	}
}

void Usuario::pantallaAyuda(int x, int y) {
	for (const auto& m : MENU_AYUDA) {
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

void Usuario::subpantallasAyuda(int x, int y) {
	switch (n_ayuda) {
	case 0:
		for (const auto& m : TEXTOTORRE) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 1:
		for (const auto& m : TEXTOPEON) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 2:
		for (const auto& m : TEXTOCABALLO) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 3:
		for (const auto& m : TEXTOALFIL) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 4:
		for (const auto& m : TEXTOREY) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 5:
		for (const auto& m : TEXTOREINA) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 6:
		for (const auto& m : TEXTOARZOBISPO) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	case 7:
		for (const auto& m : TEXTOCANCILLER) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = AYU;
				}
			}
		}
		break;
	}
}

void Usuario::pantallaInstrucciones(int x, int y) {
	for (const auto& m : MENU_INST) {
		if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
			for (int i = INICIO; i <= TEXTO_IN; i++) {
				if (m.sel == 1) n_inst = 0;  estado = TEXTO_IN;
				if (m.sel == 2) n_inst = 1;  estado = TEXTO_IN;
				if (m.sel == 3) n_inst = 2; estado = TEXTO_IN;
				if (m.sel == 4) n_inst = 3;  estado = TEXTO_IN;
				if (m.sel == 7) estado = OP;
			}
		}
	}
}

void Usuario::subpantallasInstrucciones(int x, int y) {
	switch (n_inst) {
	case 0:
		if (n_inst == 0) {
			for (const auto& m : TEXTOOBJETIVO) {
				if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
					for (int i = INICIO; i <= TEXTO_IN; i++) {
						if (m.sel == 1)  estado = INST;
					}
				}
			}
		}
		break;
	case 1:
		for (const auto& m : TEXTOENROQUE) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = INST;
				}
			}
		}
		break;
	case 2:
		for (const auto& m : TEXTOJAQUEMATE) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = INST;
				}
			}
		}
		break;
	case 3:
		for (const auto& m : TEXTOPROMOCION) {
			if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
				for (int i = INICIO; i <= TEXTO_IN; i++) {
					if (m.sel == 1)  estado = INST;
				}
			}
		}
		break;
	}
}

void Usuario::pantallaFinal(int x, int y) {
	for (const auto& m : M_FINAL) {
		if (x<m.x + m.w && x>  m.x && y<m.y + m.h && y> m.y) {
			for (int i = INICIO; i <= TEXTO_IN; i++) {
				if (m.sel == 1) estado = MODOJUEGO;
				//Reiniciar el tablero
				tablero.set_tablero();
				tablero.set_turno(true);

				if (m.sel == 2) estado = INICIO;
				tablero.set_tablero();
				tablero.set_turno(true);
			}
		}
	}
}

void Usuario::textoInicio() {
	setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
	setFont("bin/fuentes/Bitwise.ttf", 80);
	printxy("CHESS GAME", 300, 525);
	setTextColor(1, 1, 1);
	setFont("bin/fuentes/Bitwise.ttf", 60);

	for (const auto& m : MENU_INI) {
		printxy(m.texto, m.x, m.y);
		if (m.sel == seleccion_ini) {
			corona.setPos(m.x - 60, m.y + 25);
			corona.draw();
		}
	}
}

void Usuario::textoOpciones() {
	for (const auto& m : MENU_OPC) {
		printxy(m.texto, m.x, m.y);
		if (m.sel == seleccion_ini) {
			corona.setPos(m.x - 60, m.y + 25);
			corona.draw();
		}
	}
}

void Usuario::textoAyuda() {
	setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
	setFont("bin/fuentes/Bitwise.ttf", 70);
	printxy("AYUDA", 450, 620);
	setTextColor(1, 1, 1);
	setFont("bin/fuentes/Bitwise.ttf", 50);

	for (const auto& m : MENU_AYUDA) {
		printxy(m.texto, m.x, m.y);
		if (m.sel == seleccion_ini) {
			corona.setPos(m.x - 60, m.y + 25);
			corona.draw();
		}
	}
}

void Usuario::textoSubpantallasAyuda() {
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

		for (const auto& m : TEXTOTORRE) {
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
		printxy("La captura es en diagonal y si una pieza", 170, 277);
		printxy("esta frente a ellos no podran avanzar", 180, 212);
		setFont("bin/fuentes/Bitwise.ttf", 45);

		for (const auto& m : TEXTOPEON) {
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

		for (const auto& m : TEXTOCABALLO) {
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
		for (const auto& m : TEXTOALFIL) {
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

		for (const auto& m : TEXTOREY) {
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
		printxy("quiera en cualquier direccion, pero sin saltar", 210, 407);
		printxy("sobre las piezas de su mismo color", 270, 342);

		for (const auto& m : TEXTOREINA) {
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
		printxy("Combina lo poderes del alfil y el caballo", 210, 472);
		printxy("Puede moverse como lo haria un alfil o un", 210, 407);
		printxy("caballo, segun quiera el jugador", 220, 342);

		for (const auto& m : TEXTOARZOBISPO) {
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
		printxy("Combina lo poderes de la torre y el caballo", 210, 472);
		printxy("Puede moverse como lo haria una torre o un", 210, 407);
		printxy("caballo, segun quiera el jugador", 220, 342);

		for (const auto& m : TEXTOCANCILLER) {
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

void Usuario::textoInstrucciones() {
	setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
	setFont("bin/fuentes/Bitwise.ttf", 70);
	printxy("INSTRUCCIONES", 250, 600);
	setTextColor(1, 1, 1);
	setFont("bin/fuentes/Bitwise.ttf", 50);

	for (const auto& m : MENU_INST) {
		printxy(m.texto, m.x, m.y);
		if (m.sel == seleccion_ini) {
			corona.setPos(m.x - 60, m.y + 25);
			corona.draw();
		}
	}
}

void Usuario::textoSubpantallasInstrucciones() {
	switch (n_inst) {
	case 0:
		dibujaFondo();

		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 50);
		printxy("OBJETIVO", 480, 579);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 30);
		printxy("Dar Jaque Mate al rey contrario", 320, 497);

		for (const auto& m : TEXTOOBJETIVO) {
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

		for (const auto& m : TEXTOENROQUE) {
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
		for (const auto& m : TEXTOJAQUEMATE) {
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
		printxy("PROMOCION", 400, 577);
		setTextColor(1, 1, 1);
		setFont("bin/fuentes/Bitwise.ttf", 27);
		printxy("Cuando un peon llega a la ultima fila ha de ser cambiado por", 90, 497);
		printxy("un caballo, alfil, torre o dama, aunque el jugador ya posea esa pieza", 29, 432);
		printxy("Esta sustitucion esta incluida en el mismo turno del peon", 99, 367);
		for (const auto& m : TEXTOPROMOCION) {
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

void Usuario::textoFinal() {
	if (getGanador() == true) {
		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 30);
		printxy("JAQUE MATE", 540, 525);
		printxy("GANADOR BLANCO", 480, 470);
		setFont("bin/fuentes/Bitwise.ttf", 22);
		setTextColor(1, 1, 1);
		for (const auto& m : M_FINAL) {
			printxy(m.texto, m.x, m.y);
			if (m.sel == seleccion_ini) {
				corona.setPos(m.x - 60, m.y + 25);
				corona.draw();
			}
		}
	}
	else if (getGanador() == false) {
		setTextColor(51 / 255.0, 202 / 255.0, 255 / 255.0);
		setFont("bin/fuentes/Bitwise.ttf", 30);
		printxy("JAQUE MATE", 540, 525);
		printxy("GANADOR NEGRO", 490, 470);
		setFont("bin/fuentes/Bitwise.ttf", 22);
		setTextColor(1, 1, 1);
		for (const auto& m : M_FINAL) {
			printxy(m.texto, m.x, m.y);
			if (m.sel == seleccion_ini) {
				corona.setPos(m.x - 60, m.y + 25);
				corona.draw();
			}
		}
	}
}