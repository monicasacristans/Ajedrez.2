#include "Rey.h"



Rey::Rey(tipo t, color c) :Pieza(t, c) {}

bool Rey::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

    // Diferencia de columnas y filas
    int movX = abs(destino.x - origen.x);
    int movY = abs(destino.y - origen.y);

    if ((movX == 1 && movY == 0) ||         // Movimiento vertical
        (movX == 0 && movY == 1) ||         // Movimiento horizontal
        (movX == -3 && movY == 0) ||
        (movX == 3 && movY == 0) ||
        (movX == 1 && movY == 1))      //Movimiento diagonal
    {         // Movimiento enroque

    // Verificar si la casilla de destino está ocupada
        if (tablero[destino.y][destino.x] != nullptr) {
            if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
                marcarComoMovido();
                return true; // Movimiento válido (comer pieza del oponente)
            }
            else {
                // El rey no puede comer ninguna pieza
                return false;
            }
        }
        else {
            marcarComoMovido();
            return true;
        }
    }

    return false;
}

    ////ENROQUE
    //else if (movX == 2 && movY == 0 && !haSidoMovido()) {
    //    // Verificar si se trata de un enroque corto (lado del rey)
    //    // Condiciones para el enroque corto: 
    //    // 1. El rey no ha realizado movimientos previos
    //    // 2. No hay piezas entre el rey y la torre
    //    if (origen.x < destino.x) { // Enroque corto hacia la derecha
    //        if (tablero[origen.y][origen.x + 1] == nullptr &&
    //            tablero[origen.y][origen.x + 2] == nullptr &&
    //            tablero[origen.y][origen.x + 3] != nullptr &&
    //            tablero[origen.y][origen.x + 3]->getTipo() == tipo::torre &&
    //            !tablero[origen.y][origen.x + 3]->haSidoMovido()) {
    //            std::cout << "ENROQUE CORTO" << std::endl;
    //            return true; // Enroque corto válido
    //        }
    //    }
    //}
    //else if (movX == 3 && movY == 0 && !haSidoMovido()) {
    //    // Verificar si se trata de un enroque largo (lado de la dama)
    //    // Condiciones para el enroque largo: 
    //    // 1. El rey no ha realizado movimientos previos
    //    // 2. No hay piezas entre el rey y la torre
    //    if (origen.x > destino.x) { // Enroque largo hacia la izquierda
    //        if (tablero[origen.y][origen.x - 1] == nullptr &&
    //            tablero[origen.y][origen.x - 2] == nullptr &&
    //            tablero[origen.y][origen.x - 3] == nullptr &&
    //            tablero[origen.y][origen.x - 4] != nullptr &&
    //            tablero[origen.y][origen.x - 4]->getTipo() == tipo::torre &&
    //            !tablero[origen.y][origen.x - 4]->haSidoMovido()) {
    //            std::cout << "ENROQUE LARGO" << std::endl;
    //            return true; // Enroque largo válido
    //        }
    //    }
    //}
    //else {
    //    return false;
    //}