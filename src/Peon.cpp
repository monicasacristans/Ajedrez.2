#include "Peon.h"
#include <iostream>

using namespace std;
Peon::Peon(tipo t, color c) :Pieza(t, c) {
}

bool Peon::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

    int movX = destino.x - origen.x;
    int movY = destino.y - origen.y;




    if (getColor() == color::blanco) {
            // MOVIMIENTO 1 CASILLA ADELANTE
            if (movY == -1 && movX == 0 && tablero[destino.y][destino.x] == nullptr) {
                return true; 
            }

            // MOVIMIENTO DOS CASILLAS ADELANTE (primer movimiento)
            if (origen.y == 6 && movY == -2 && movX == 0 && tablero[5][origen.x] == nullptr && tablero[4][origen.x] == nullptr && tablero[3][origen.x] == nullptr) {
                return true; // Avance de dos casillas vacías desde la posición inicial del peón blanco
            }

            // CAPTURA DE PEON DIAGONAL
            if (abs(movY) == 1 && abs(movX) == 1 && tablero[destino.y][destino.x] != nullptr && tablero[destino.y][destino.x]->getColor() == color::negro) {
                return true; 
            }
        }

        // Movimiento válido para peón negro (hacia abajo)
    if (getColor() == color::negro) {
            // MOVIMIENTO 1 CASILLA ADELANTE
            if (movY == 1 && movX == 0 && tablero[destino.y][destino.x] == nullptr) {
                return true; 
            }

            //  MOVIMIENTO DOS CASILLAS ADELANTE (primer movimiento)
            if (origen.y == 1 && movY == 2 && movX == 0 && tablero[2][origen.x] == nullptr && tablero[3][origen.x] == nullptr && tablero[4][origen.x] == nullptr) {
                return true; 
            }

            // CAPTURA DE PEON DIAGONAL
            if (abs(movY) == 1 && abs(movX) == 1 && tablero[destino.y][destino.x] != nullptr && tablero[destino.y][destino.x]->getColor() == color::blanco) {
                return true; 
            }
        }
    std::cout << "MOVIMIENTO INVALIDO" << std::endl;
        return false; 
    }

