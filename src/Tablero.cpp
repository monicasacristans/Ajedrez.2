//<iostream> en Basico.h
#include "Tablero.h"
#include "Usuario.h"
#include "Peon.h"
#include "Torre.h"
#include "Arzobispo.h"
#include "Caballo.h"
#include "Canciller.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"

using namespace std;

Tablero::Tablero() {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr; //Pieza crea una pieza vacia 
		}
	}
}



//
//Dibuja el tablero MIRAR
//void Tablero::dibujar() {
//	Pieza ptr = *tablero[max_y][max_x];
//	for (int y = 0; y < max_y; y++) {
//		std::cout << y << "  "; //imprime el indice de la fila
//		for (int x = 0; x < max_x; x++) {
//			std::cout << ptr[y][x].obtenerRepresentacion() << " ";
//			std::cout << " "; // Un espacio entre cada pieza para alineaci�n.
//
//		}
//		std::cout << std::endl;
//
//	}
//
//	std::cout << "   "; // Espacios para alinear con los �ndices de las filas si son de un d�gito
//	for (int x = 0; x < max_x; ++x) {
//		std::cout << x << "  "; // Imprimir el �ndice de la columna
//	}
//	std::cout << std::endl;
//}

void Tablero::definirCoordenadasTablero(int button, int state, int x, int y) {

	Pieza* p = checkPiezaEnCasilla(cas_origen);
	static int click = 0;

	int screenX = x;
	int screenY = y;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la columna y fila en funci�n de las coordenadas x e y
		int columna = ((x - 283) / 80);
		int fila = ((y - 64) / 80);
		//std::cout << "Clic en: x=" << x << ", y=" << y << " -> columna=" << columna << ", fila=" << fila << std::endl;
		click++;

		if (columna < 0 || columna >= 10 || fila < 0 || fila >= 8) {
			std::cout << "Clic fuera de los l�mites del tablero." << std::endl;
			return;
		}

		if (!flag && click == 2) {
			cas_origen = { columna, fila };
			flag = true;
			std::cout << "Casilla de origen: (" << cas_origen.x << ", " << cas_origen.y << ")" << std::endl;
		}
		else if(click == 3){
			cas_destino = { columna, fila };
			if (cas_origen.x == cas_destino.x && cas_origen.y == cas_destino.y) {
				std::cout << "Origen y destino son iguales, seleccione otra casilla." << std::endl;
				cas_destino = { -1, -1 }; // Reiniciar casilla destino si es igual al origen
				return;
			}
			std::cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << std::endl;
			flag = false;
			click = 1;
			moverPieza(cas_origen, cas_destino);
		}
	}
}


void Tablero::moverPieza(casilla origen, casilla destino) {

	// Mover la pieza
	Pieza *piezaMovida = tablero[origen.y][origen.x]; // Tomar la pieza en la casilla de origen

	if (piezaMovida->movimientoValido(origen, destino, tablero) == true) {
		tablero[destino.y][destino.x] = piezaMovida; // Colocar la pieza en la casilla de destino
		tablero[origen.y][origen.x] = nullptr; // Dejar la casilla de origen vac�a
		std::cout << "Movimiento realizado de (" << origen.x << ", " << origen.y << ") a (" << destino.x << ", " << destino.y << ")" << std::endl;
	}
	
}

bool Tablero::checkCasillaOcupada(int x, int y) {
	if (x >= 0 && x < max_x && y >= 0 && y < max_y) {  //Comprueba que estamos dentro del tablero
		
		Pieza *mipieza = tablero[y][x]; //Obtiene la pieza que hay en la casilla

		if (mipieza != nullptr) {
			return true; //casilla ocupada
		}
	}
	return false; //casilla vac�a
}

Pieza* Tablero::checkPiezaEnCasilla(casilla pos) {

	if (pos.x >= 0 && pos.x < max_x && pos.y >= 0 && pos.y < max_y) { //Comprueba que estamos dentro del tablero
		return tablero[pos.y][pos.x];  //Devuelve la pieza que hay en la casilla
	}
	else {
		// Si la casilla est� fuera del tablero, devuelve una pieza vac�a
		return nullptr;
	}
}

void Tablero::set_tablero() {

	//Iniciar todo el tablero a nullptr
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr;
		}
	}
	//Piezas blancas
	tablero[0][0]= new Torre(tipo::torre, color::blanco);
	tablero[0][1] = new Caballo(tipo::caballo, color::blanco);
	tablero[0][2] = new Arzobispo(tipo::arzobispo, color::blanco);
	tablero[0][3] = new Alfil(tipo::alfil, color::blanco);
	tablero[0][4] = new Rey(tipo::rey, color::blanco);
	tablero[0][5] = new Reina(tipo::reina, color::blanco);
	tablero[0][6] = new Alfil(tipo::alfil, color::blanco);
	tablero[0][7] = new Canciller(tipo::canciller, color::blanco);
	tablero[0][8] = new Caballo(tipo::caballo, color::blanco);
	tablero[0][9] = new Torre(tipo::torre, color::blanco);
	
	//Peones blancos 
	for (int i = 0; i < 10; i++) {
		tablero[1][i] = new Peon(tipo::peon, color::blanco);
	}

	//Peones negros
	for (int i = 0; i < 10; i++) {
		tablero[6][i] = new Peon(tipo::peon, color::negro);
	}

	//Piezas negras
	tablero[7][0] = new Torre(tipo::torre, color::negro);
	tablero[7][1] = new Caballo(tipo::caballo, color::negro);
	tablero[7][2] = new Arzobispo(tipo::arzobispo, color::negro);
	tablero[7][3] = new Alfil(tipo::alfil, color::negro);
	tablero[7][4] = new Rey(tipo::rey, color::negro);
	tablero[7][5] = new Reina(tipo::reina, color::negro);
	tablero[7][6] = new Alfil(tipo::alfil, color::negro);
	tablero[7][7] = new Canciller(tipo::canciller, color::negro);
	tablero[7][8] = new Caballo(tipo::caballo, color::negro);
	tablero[7][9] = new Torre(tipo::torre, color::negro);


}

//void Tablero::ratonTablero(int button, int state, int x, int y) {
//	// Verificar si es el turno de las blancas
//	finturnonegro = 0;
//	if (turno == 1) {
//		std::cout << "JUEGAN LAS BLANCAS" << endl;
//		// Realizar acciones correspondientes al turno de las blancas
//		//jugadorblanco->dibujarcorona();
//		jugadorblanco->posicionarPieza(button, state, x, y);
//		
//
//		// Verificar si el turno de las blancas ha terminado
//		if (jugadorblanco->getFinTurno()) {
//			// Actualizar el estado de turno y reiniciar el estado de fin de turno para el siguiente turno
//			jugadorblanco->setFinTurno(false);
//			finturnoblanco = 1;
//			finturnonegro = 0;
//			turno = 0; return;
//		}
//	}
//	finturnoblanco = 0;
//	 if (turno == 0) {
//		 std::cout << "JUEGAN LAS NEGRAS" << endl;
//		// Realizar acciones correspondientes al turno de las negras
//		//jugadornegro->dibujarcorona();
//		jugadornegro->posicionarPieza(button, state, x, y);
//
//		// Verificar si el turno de las negras ha terminado
//		if (jugadornegro->getFinTurno()) {
//			// Actualizar el estado de turno y reiniciar el estado de fin de turno para el siguiente turno
//			jugadornegro->setFinTurno(false);
//			finturnonegro = 1;
//			finturnoblanco = 0;
//			turno = 1; return;
//
//		}
//	}
//}

//void Tablero::ratonTablero(int button, int state, int x, int y) {
//	finturnonegro = 0;
//	//std::cout << "JUEGAN LAS BLANCAS" << endl;
//	if (turno == 1) {
//		std::cout << "JUEGAN LAS BLANCAS" << endl;
//		//jugadorblanco->dibujarcorona();
//		jugadorblanco->posicionarPieza(button, state, x, y);
//		if (jugadorblanco->getFinTurno() == 1) {
//			finturnoblanco = 1;
//			finturnonegro = 0;
//			turno = 0; return;
//		}
//	}
//
//	finturnoblanco = 0;
//	if (turno == 0) {
//		//jugadornegro->dibujarcorona();
//		jugadornegro->posicionarPieza(button, state, x, y);
//		std::cout << "JUEGAN LAS NEGRAS" << endl;
//		if (jugadornegro->getFinTurno() == 1) {
//			finturnonegro = 1;
//			finturnoblanco = 0;
//			turno = 1;
//			return;
//		}
//	}
//}


/*

void Tablero::setJugadorBlanco(Jugador* x) {
	jugadorblanco = x;
}


void Tablero::setJugadorNegro(Jugador* x) {
	jugadornegro = x;
}

//getters
bool Tablero::getFinTurnoNegro() {
	return finturnonegro;
}


bool Tablero::getFinTurnoBlanco() {
	return finturnoblanco;
}


bool Tablero::getTurno() {
	return turno;
}
*/

//// Funci�n para convertir coordenadas del tablero a coordenadas de pantalla
//ETSIDI::Vector2D Tablero::convertirTableroAPantalla(float x, float y) {
//    float origenX = 684;
//    float origenY = 200;
//    int tama�oCasilla = 10;
//    float pantallaX = origenX + x * tama�oCasilla;
//    float pantallaY = origenY + y * tama�oCasilla;
//    return Vector2D(pantallaX, pantallaY);
//}
//
//
//
