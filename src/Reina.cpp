#include "Reina.h"



Reina::Reina(tipo t, color c) :Pieza(t, c) {}

bool Reina::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
    
    // Determinar la dirección del movimiento
    int movX = ((destino.x- origen.x)==0) ? 0 : ((destino.x - origen.x) / abs(destino.x - origen.x));  // 0, 1 o -1
    int movY = ((destino.y - origen.y)==0) ? 0 : ((destino.y - origen.y) / abs(destino.y - origen.y));  // 0, 1 o -1

    // Comenzar a verificar desde la casilla siguiente a la origen hasta llegar a la casilla antes de la destino
    int x = origen.x + movX;
    int y = origen.y + movY;
    while (x != destino.x || y != destino.y) {
        if (tablero[y][x] != nullptr) {  
            return false;   // Hay una pieza en el camino
        }
        x += movX;
        y += movY;
    }

    // Verificar la casilla de destino
    if (tablero[destino.y][destino.x] != nullptr && tablero[destino.y][destino.x]->getColor() == this->getColor()) {
        return false;  // No se puede capturar una pieza del mismo color
    }

    return true;
}