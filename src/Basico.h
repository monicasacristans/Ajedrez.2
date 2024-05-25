#pragma once
#include <iostream>
#include <math.h>

#define max_x 10//columnas
#define max_y 8//filas


enum class color {ninguno,blanco, negro };
enum class tipo { vacio, peon, torre, caballo, canciller, arzobispo, alfil, rey, reina };
//                 0	  1		2		 3		  4			  5		   6	 7		8

struct casilla {
	int x; //columna
	int y; //fila
};

// Sobrecarga del operador <<
inline std::ostream& operator<<(std::ostream& os, const casilla& c) {
	os << "(" << c.x << ", " << c.y << ")";
	return os;
}
