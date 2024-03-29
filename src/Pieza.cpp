#include "Pieza.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <iostream>


Pieza::Pieza(){}


void Pieza::draw() {};

void Pieza::setPos(float x, float y){
    pos.x = x;
    pos.y = y;
    torre_b.setPos(pos.x, pos.y); // Actualiza la posición del sprite, si se quita sale en el centro
    torre_n.setPos(pos.x, pos.y);
    peon_b.setPos(pos.x, pos.y);
    peon_n.setPos(pos.x, pos.y);
    caballo_b.setPos(pos.x, pos.y);
    caballo_n.setPos(pos.x, pos.y);
    alfil_b.setPos(pos.x, pos.y);
    alfil_n.setPos(pos.x, pos.y);
    reina_b.setPos(pos.x, pos.y);
    reina_n.setPos(pos.x, pos.y);
    rey_b.setPos(pos.x, pos.y);
    rey_n.setPos(pos.x, pos.y);
    
}
