#include "Peon.h"

using namespace std;
Peon::Peon(tipo t, color c) :Pieza(t, c) {
}

bool Peon::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
    // Solo avanza en vertical, 2 casillas si es su primer movimiento, 1 el resto de veces
    
    // Diferencia de columnas y filas 
    int movX = destino.x - origen.x;
    int movY = destino.y - origen.y;
    bool promocion = false;
    // Blancos
    if (tablero[origen.y][origen.x]->getColor() == color::blanco) {
        if (movX == 0 && movY != 0) {
            if (movY == 2 && origen.y == 1) {        // Primer movimiento
                return true;
            }
            else if (movY == 1) { 
                if (destino.y == 9) {
                    promocion = true;
                }
                return true;
            }
            else {
                return false;
            }
        }
    } 
    // Negros
    else if (tablero[origen.y][origen.x]->getColor() == color::negro) {
        if (movX == 0 && movY != 0) {
            if (movY == -2 && origen.y == 6) {      // Primer movimiento
                return true;
            }
            else if (movY == -1) {
                if (destino.y == 0) {
                    promocion = true;
                }
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }

    // Verificar si el movimiento es en diagonal para capturar una pieza
    if (abs(movX) == 1 && abs(movY) == 1) {
        if (tablero[destino.y][destino.x] != nullptr && tablero[destino.y][destino.x]->getColor() != this->getColor()) {

            return true; // Movimiento válido para capturar una pieza enemiga en diagonal
        }
        else {
            return false; // No hay pieza enemiga en diagonal para capturar
        }
    }
    return false;
}
    