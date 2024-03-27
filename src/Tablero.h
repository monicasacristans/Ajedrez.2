#pragma once

class Tablero
{
private:
    char tablero[8][8]; // Matriz para representar el tablero de ajedrez

public:
    Tablero(); // Constructor
    void dibujar() const;
    //void asignarPieza(int fila, int columna, char pieza);
};