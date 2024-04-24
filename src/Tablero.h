#pragma once
#include "Pieza.h"
#include <vector>
#include "Jugador.h"


#define max_x 10//columnas
#define max_y 8//filas

class Tablero {
	//const int max_x = 10;
	//const int max_y = 8;
	Pieza *tablero[max_y][max_x];
	std::vector<Pieza*> listapiezas;

	bool turno; //1 BLANCAS 0 NEGRAS
	bool finturno;
	bool finturnonegro;
	bool finturnoblanco;

	Jugador* jugadorblanco;
	Jugador* jugadornegro;
	
public:


	Tablero();
	//void colocarPieza(int x, int y, Pieza p);
	//void piezasinicializa();

	void ratonTablero(int button, int state, int x, int y);

	//setters
	void set_tablero();
	void setJugadorBlanco(Jugador* x);
	void setJugadorNegro(Jugador* x);

	//getters
	bool getFinTurnoNegro();
	bool getFinTurnoBlanco();
	bool getTurno();

	casilla definirCoordenadasTablero(int button, int state, int x, int y);
	bool checkCasillaOcupada(int x, int y);
	Pieza* checkPiezaEnCasilla(casilla pos);

	//void pintarCuadricula();
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