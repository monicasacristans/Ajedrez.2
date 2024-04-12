#include "Pieza.h"
#include <iostream>


char Pieza::obtenerRepresentacion() {
	if (colorPieza == color::blanco) {
		switch (tipoPieza) {
		case tipo::peon:
			return 'P';
			break;
		case tipo::torre:
			return 'T';
			break;
		case tipo::caballo:
			return 'C';
			break;
		case tipo::canciller:
			return 'N';
			break;
		case tipo::arzobispo:
			return 'A';
			break;
		case tipo::rey:
			return 'R';
			break;
		case tipo::reina:
			return 'I';
			break;
		default:
			return ' ';
		}
	}
	else {
		switch (tipoPieza) {
		case tipo::peon:
			return 'p';
			break;
		case tipo::torre:
			return 't';
			break;
		case tipo::caballo:
			return 'c';
			break;
		case tipo::canciller:
			return 'n';
			break;
		case tipo::arzobispo:
			return 'a';
			break;
		case tipo::rey:
			return 'r';
			break;
		case tipo::reina:
			return 'i';
			break;
		default:
			return ' ';
		}
	}
}
//Pieza::Pieza(){}
//
//
//void Pieza::draw() {};
//
//void Pieza::setPos(float x, float y){
//    pos.x = x;
//    pos.y = y;
//    torre_b.setPos(pos.x, pos.y); // Actualiza la posición del sprite, si se quita sale en el centro
//    torre_n.setPos(pos.x, pos.y);
//    peon_b.setPos(pos.x, pos.y);
//    peon_n.setPos(pos.x, pos.y);
//    caballo_b.setPos(pos.x, pos.y);
//    caballo_n.setPos(pos.x, pos.y);
//    alfil_b.setPos(pos.x, pos.y);
//    alfil_n.setPos(pos.x, pos.y);
//    reina_b.setPos(pos.x, pos.y);
//    reina_n.setPos(pos.x, pos.y);
//    rey_b.setPos(pos.x, pos.y);
//    rey_n.setPos(pos.x, pos.y);
//    
//}
