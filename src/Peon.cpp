#include "Peon.h"
#include <iostream>

using namespace std;
Peon::Peon(tipo t, color c) :Pieza(t, c) {
	t = tipo::peon;
	peonMovido = false;
}

void Peon::dibuja() {
	
	cout << "PEON 1" << endl;
	
}

void Peon::moverPieza(casilla origen, casilla destino, Pieza *tablero[max_y][max_x]) {

	//caos, distinto el blanco del negro

	if (peonMovido == 0) {
		next(origen, direcciones::arriba);
		next(origen, direcciones::arriba);	//chapuza a solucionar checkCasillaOcupada no la puedo usar.

		peonMovido = 1;
	}
	else {
		/*if (Tablero::checkCasillaOcupada(origen.x, origen.y + 1) == 0) {
			next(origen, direcciones::arriba);
		}*/
	}
}