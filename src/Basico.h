#pragma once
#include <iostream>
#include <math.h>

#define max_x 10//columnas
#define max_y 8//filas


enum class color {ninguno,blanco, negro };
enum class tipo { vacio, peon, torre, caballo, canciller, arzobispo, alfil, rey, reina };
//                 0	  1		2		 3		  4			  5		   6	 7		8
enum class direcciones { arriba, diag_sup_dcha, derecha, diag_inf_dcha, abajo, diag_inf_izq, izquierda, diag_sup_izq };

struct casilla {
	int x; //columna
	int y; //fila
};

// Sobrecarga del operador <<
inline std::ostream& operator<<(std::ostream& os, const casilla& c) {
	os << "(" << c.x << ", " << c.y << ")";
	return os;
}

inline casilla siguienteCasilla(casilla& casilla1, direcciones direc) {

	switch (direc) {
	case direcciones::arriba:
		casilla1.y++;
		break;
	case direcciones::diag_sup_dcha:
		casilla1.x++;
		casilla1.y++;
		break;
	case direcciones::derecha:
		casilla1.x++;
		break;
	case direcciones::diag_inf_dcha:
		casilla1.x++;
		casilla1.y--;
		break;
	case direcciones::abajo:
		casilla1.y--;
		break;
	case direcciones::diag_inf_izq:
		casilla1.x--;
		casilla1.y--;
		break;
	case direcciones::izquierda:
		casilla1.x--;
		break;
	case direcciones::diag_sup_izq:
		casilla1.x--;
		casilla1.y++;
		break;
	default:
		break;
	}

	return casilla1;
}