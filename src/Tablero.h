#pragma once
#include "Pieza.h"
#include "freeglut.h"

#define max_x 10
#define max_y 8

class Tablero {
	//const int max_x = 10;
	//const int max_y = 8;
	Pieza tablero[max_y][max_x];

public:

	Tablero();
	void colocarPieza(int x, int y, Pieza p);
	void piezasinicializa();
	casilla definirCoordenadasTablero(int button, int state, int x, int y);
	void pintarCuadricula();
	void dibujar();
};
//class Tablero
//{
//private:
//    char tablero[8][10]; // Matriz para representar el tablero de ajedrez
//    map<int, Pieza*> mapaPiezas; //Mapa de enteros a punteros de Pieza
//    //donde cada entero se asocia con un puntero Pieza
//
//public:
//
//    Tablero(); // Constructor
//    ~Tablero(); //Destructor
//
//    void dibujar() ;
//    void piezasdibujar();
//    ETSIDI::Vector2D convertirTableroAPantalla(float x, float y);
//
//
//    //void asignarPieza(int fila, int columna, char pieza);
//
//};