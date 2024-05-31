#include "Pieza.h"

tipo Pieza::getTipo() {
	return tipoPieza;
}

color Pieza::getColor() {
	return colorPieza;
}

int Pieza::getFila() {
	return fila;
}

int Pieza::getColumna() {
	return columna;
}

// Métodos para controlar el estado de movimientos
bool Pieza::haSidoMovido() {
	return haMovido;
}
void Pieza::marcarComoMovido() { 
	haMovido = true; 
}

void Pieza::reiniciarMovimiento() { 
	haMovido = false; 

}
void Pieza::setEnroque(bool x) {
	enroque = true;
}

bool Pieza::getEnroque() {
	return enroque;
}


std::vector<casilla> Pieza::movDiagonal(casilla origen, Pieza* tablero[max_y][max_x]) {

    std::vector<direcciones> direccionesDiagonales = {
            direcciones::diag_sup_dcha,
            direcciones::diag_sup_izq,
            direcciones::diag_inf_dcha,
            direcciones::diag_inf_izq
    };

    // Recorrer cada dirección diagonal
    for (auto dir : direccionesDiagonales) {
        casilla actual = origen;

        while (true) {
            actual = siguienteCasilla(actual, dir);

            // Verificar si la nueva posición está dentro del tablero
            if (actual.x < 0 || actual.x >= max_y || actual.y < 0 || actual.y >= max_x) {
                break;
            }

            // Verificar si la casilla está ocupada
           if (tablero[actual.y][actual.x] != nullptr) {   
                if (tablero[actual.y][actual.x]->getColor() != this->getColor()) {  //ERROR !!
                    // La casilla está ocupada por una pieza del oponente, se puede capturar
                    casillasValidas.push_back(actual);
                }
                // Si está ocupada por una pieza del mismo color, no se puede mover más en esta dirección
                break;
           }

            // La casilla está vacía, se puede mover a ella
            casillasValidas.push_back(actual);
        }
    }

    return casillasValidas;
}

