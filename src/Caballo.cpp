#include "Caballo.h"
#include <iostream>
#include <math.h>


Caballo::Caballo(tipo t, color c) :Pieza(t, c) {}

bool Caballo::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	//Diferencia de columnas
	int movX = abs(destino.y - origen.y);
	//Diferencia de filas 
	int movY = abs(destino.x - origen.x);

	//1(Si el caballo se mueve una casilla a la derecha/izquierda y dos arriba/abajo)
	//2(Si el caballo se mueve dos casillas a la derecha/izquierda y una arriba/abajo)
	if ((movX == 1 && movY == 2) || (movX == 2 && movY == 1)) {
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
				return true;//Puede comer
			}
			else
				return false;//No puede comer, pieza del mismo color
		}
	}
	else {
		return false;
	}
	
	return true;
}