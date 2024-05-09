#include "Canciller.h"
#include <iostream>


Canciller::Canciller(tipo t, color c) :Pieza(t, c) {}

bool Canciller::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	//Se mueve indistintamente como torre o caballo
	//MOVIMIENTO TORRE
	while (origen.x != destino.x && origen.y != destino.y) {
		//Movimiento horizontal
		if (origen.x == destino.x) {
			//Asegurarnos que no se puede comer una pieza del mismo color que el suyo
			if (tablero[destino.y][destino.x] != nullptr) {
				if (tablero[destino.y][destino.x]->getColor() != getColor()) {
					// Verificar si hay una pieza en el destino y es del color opuesto
					int movY = (destino.y > origen.y) ? 1 : -1;
					for (int i = origen.y + movY; i != destino.y; i += movY) {
						if (tablero[i][origen.x] != nullptr) {
							return false;
						}
					}
				}
				else {
					return false;
				}
			}
		}
		//Movimiento vertical
		else if (origen.y == destino.y) {
			// Asegurarnos que no se puede comer una pieza del mismo color que el suyo
			if (tablero[destino.y][destino.x] != nullptr) {
				if (tablero[destino.y][destino.x]->getColor() != getColor()) {
					// Verificar si hay una pieza en el destino y es del color opuesto
					int movX = (destino.x > origen.x) ? 1 : -1;
					for (int j = origen.x + movX; j != destino.x; j += movX) {
						if (tablero[origen.y][j] != nullptr) {
							return false;
						}
					}
				}
				else {
					return false;
				}
			}
		}
	}
	//MOVIMIENTO CABALLO
	//Diferencia de columnas
	int movX = abs(destino.y - origen.y);
	//Diferencia de filas 
	int movY = abs(destino.x - origen.x);

	//1(Si el caballo se mueve una casilla a la derecha/izquierda y dos arriba/abajo)
	//2(Si el caballo se mueve dos casillas a la derecha/izquierda y una arriba/abajo)
	if ((movX == 1 && movY == 2) || (movX == 2 && movY == 1)) {
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != getColor()) {
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