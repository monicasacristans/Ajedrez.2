#include "Jugador.h"
#include "freeglut.h"

Jugador::Jugador() {
	getColorJugador();
	piezaEscogida = 0;
	finTurno = 0;
}

Jugador::Jugador(char colorJug) {
	colorJugador = colorJug;
}


void Jugador::posicionarPieza(int button, int state, int x, int y) {
	finTurno = 0;
	int i, j;
	int x_celda, y_celda;
	int x_tablero, y_tablero;
	int screenx, screeny;
	//escogerrey =0;
	//primerrey=0;

	// funciones de freeglut para saber la colocacion del tablero 
	//a la hora de hacer click

	float ratioy = glutGet(GLUT_WINDOW_HEIGHT) * 1.0 / 768;
	float ratiox = (glutGet(GLUT_WINDOW_HEIGHT) * 1.7786) / 1366;

	float ratio = glutGet(GLUT_WINDOW_WIDTH) * 1.0 / glutGet(GLUT_WINDOW_HEIGHT);
	screenx = x - (262 * ratiox) - (glutGet(GLUT_WINDOW_WIDTH) - (glutGet(GLUT_WINDOW_HEIGHT) * 1.7786)) / 2;
	screeny = y - (43 * ratioy);

	if (screenx < 0 || screeny < 0)return; // no estaria dentro del tablero

	x_celda = screenx / int(79 * ratioy);
	y_celda = screeny / int(79 * ratioy);

	switch (y_celda) {
	case 0:
		y_tablero = 7;
		break;
	case 1:
		y_tablero = 6;
		break;
	case 2:
		y_tablero = 5;
		break;
	case 3:
		y_tablero = 4;
		break;
	case 4:
		y_tablero = 3;
		break;
	case 5:
		y_tablero = 2;
		break;
	case 6:
		y_tablero = 1;
		break;
	case 7:
		y_tablero = 0;
		break;
	default:
		y_tablero = 8;
		break;
	}

	switch (x_celda) {
	case 0:
		x_tablero = 0;
		break;
	case 1:
		x_tablero = 1;
		break;
	case 2:
		x_tablero = 2;
		break;
	case 3:
		x_tablero = 3;
		break;
	case 4:
		x_tablero = 4;
		break;
	case 5:
		x_tablero = 5;
		break;
	case 6:
		x_tablero = 6;
		break;
	case 7:
		x_tablero = 7;
		break;
	case 8:
		x_tablero = 8;
		break;
	case 9:
		x_tablero = 9;
		break;
	default:
		x_tablero = 10;
		break;
	}

	if (x_tablero == 10 || y_tablero == 8)return; //si se va del tablero nada
}




char Jugador::getColorJugador() {
	return colorJugador;
}
bool Jugador::getFinTurno() {
	return finTurno;
}

void Jugador::setFinTurno(bool finT) {
	finTurno = finT;
}
void Jugador::setColorJugador(char color) {
	colorJugador = color;
}