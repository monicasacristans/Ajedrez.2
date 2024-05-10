#pragma once
#include <iostream>

enum class direcciones { arriba, diag_sup_dcha, derecha, diag_inf_dcha, abajo, diag_inf_izq, izquierda, diag_sup_izq };
enum class color {ninguno,blanco, negro };
enum class tipo { vacio, peon, torre, caballo, canciller, arzobispo, alfil, rey, reina };
//                 0	  1		2		 3		  4			  5		   6	 7		8


struct casilla {
	int x; //columna
	int y; //fila
};


struct movimiento {
	casilla origen;
	casilla destino;
};

// Sobrecarga del operador <<
inline std::ostream& operator<<(std::ostream& os, const casilla& c) {
	os << "(" << c.x << ", " << c.y << ")";
	return os;
}

inline casilla next(casilla &casilla1, direcciones direc) {

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

	// Asegurar que las coordenadas están dentro de los límites del tablero de ajedrez 10x8.
	//if (casilla1.x < 0) casilla1.x = 0;
	//if (casilla1.x > 9) casilla1.x = 9; // Ahora x puede ir hasta 9 porque hay 10 columnas.
	//if (casilla1.y < 0) casilla1.y = 0;
	//if (casilla1.y > 7) casilla1.y = 7; // y va hasta 7 porque hay 8 filas.

	return casilla1;
	
}