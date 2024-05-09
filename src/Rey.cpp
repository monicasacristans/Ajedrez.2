#include "Rey.h"
#include <iostream>



Rey::Rey(tipo t, color c) :Pieza(t, c) {}

bool Rey::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

    //diferencia de columnas
    int movX = abs(destino.x - origen.x);
    //diferencia de filas
    int movY = abs(destino.y - origen.y);

    /////////MOVIMIENTO HORIZONTAL VERTICAL DIAGONAL /////////////

    if ((movX == 1 && movY == 0) ||         // Movimiento vertical
        (movX == 0 && movY == 1) ||         // Movimiento horizontal
        (movX == 1 && movY == 1)) {         // Movimiento diagonal
        // Verificar si hay una pieza en el destino y es del color opuesto
        if (tablero[destino.y][destino.x] != nullptr) {
            if (tablero[destino.y][destino.x]->getColor() != getColor()) {
                return true; // Movimiento válido (comer pieza del oponente)
            }
            else {
                return false; // Movimiento inválido (pieza del mismo color en el destino)
            }
        }
    }
    else {
        return false;
    }

    return true; 
}