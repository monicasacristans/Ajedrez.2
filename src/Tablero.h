#pragma once
#include <vector>
#include <map>
#include "Pieza.h"

using namespace std;

class Tablero
{
private:
    char tablero[8][8]; // Matriz para representar el tablero de ajedrez
    map<int, Pieza*> mapaPiezas; //Mapa de enteros a punteros de Pieza
    //donde cada entero se asocia con un puntero Pieza

public:

    Tablero(); // Constructor
    ~Tablero(); //Destructor

    void dibujar() ;
    void piezasdibujar();

    //void asignarPieza(int fila, int columna, char pieza);

};