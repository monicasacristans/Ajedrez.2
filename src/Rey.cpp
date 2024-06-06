#include "Rey.h"

Rey::Rey(tipo t, color c) :Pieza(t, c) {}

bool Rey::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
    // Diferencia de columnas y filas
    int movX = abs(destino.x - origen.x);
    int movY = abs(destino.y - origen.y);

    if ((movX == 1 && movY == 0) ||         // Movimiento vertical
        (movX == 0 && movY == 1) ||          // Movimiento horizontal
        (movX == -3 && movY == 0) ||
        (movX == 3 && movY == 0) ||
        (movX == 1 && movY == 1)) {         // Movimiento diagonal

        // Verificar si la casilla de destino está ocupada
        if (tablero[destino.y][destino.x] != nullptr) {
            // El rey no puede comer ninguna pieza
            return false;
        }
        else {
            // Movimiento inválido para el rey
            return true;
        }
    }
    return false;
}
