#include "Rey.h"
#include <iostream>

Rey::Rey(tipo t, color c) :Pieza(t, c) {}

bool Rey::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

    // Diferencia de columnas y filas
    int movX = abs(destino.x - origen.x);
    int movY = abs(destino.y - origen.y);

    if ((movX == 1 && movY == 0) ||         // Movimiento vertical
        (movX == 0 && movY == 1) ||         // Movimiento horizontal
        (movX == 1 && movY == 1)||// Movimiento diagonal
        (movX == 0 && movY == 0)) {         // posicion actual sin moverse
        
        if (tablero[destino.y][destino.x] != nullptr) {
            if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
                marcarComoMovido();
                return true; // Movimiento v�lido (comer pieza del oponente)
            }
            else {
                return false; // Movimiento inv�lido (pieza del mismo color en el destino)
            }
        }
        else {
            marcarComoMovido();
            return true;
        }
    }

    return false;
}