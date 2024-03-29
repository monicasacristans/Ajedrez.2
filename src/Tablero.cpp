#include "Tablero.h"
#include "freeglut.h"
#include <iostream>
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Rey.h"
#include "Reina.h"


Tablero::Tablero() {

    int inicial[8][8] = { 
                    {-1,-2,-3,-4,-5,-3,-2,-1},
                    {-6,-6,-6,-6,-6,-6,-6,-6},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {6, 6, 6, 6, 6, 6, 6, 6},
                    {1, 2, 3, 4, 5, 3, 2, 1} };

    // Inicializar el tablero con piezas vacías
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            tablero[i][j] = NULL;
        }
    }
}

Tablero::~Tablero() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j]= NULL;
        }
    }
}

void Tablero::dibujar() {
   
   for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3ub(240, 240, 240); // gris claro
            }
            else {
                glColor3ub(130, 130, 130); // gris oscuro 
            }
            glBegin(GL_POLYGON);
            glVertex3f(10 * i - 40, 10 * j - 41, -2); //Aumenta el tamaño del tablero multiplicando por 10, 
            //ajusta las coordenadas para centrar el tablero en el centro
            glVertex3f(10 * i - 40, 10 * (j + 1) - 41, -2);
            glVertex3f(10 * (i + 1) - 40, 10 * (j + 1) - 41, -2);
            glVertex3f(10 * (i + 1) - 40, 10 * j - 41, -2);
            glEnd();
        }


        glEnable(GL_LIGHTING);
    }  
   
}

void Tablero::piezasdibujar() {
   // glDisable(GL_LIGHTING);

    Peon* p1b = new Peon(6);
    Peon* p1n = new Peon(-6);

    Torre* tb = new Torre(1);
    Torre* tn = new Torre(-1);

    Caballo* cb = new Caballo(2);
    Caballo* cn = new Caballo(-2);

    Alfil* ab = new Alfil(3);
    Alfil* an = new Alfil(-3);

    Rey* ryb = new Rey(4);
    Rey* ryn = new Rey(-4);

    Reina* ryab = new Reina(5);
    Reina* ryan = new Reina(-5);

    p1b->draw();
    p1n->draw();
    tb->draw();
    tn->draw();
    cb->draw();
    cn->draw();
    ab->draw();
    an->draw();
    ryb->draw();
    ryn->draw();
    ryab->draw();
    ryan->draw();

   // glEnable(GL_LIGHTING);  

}


/*
void Tablero::asignarPieza(int fila, int columna, char pieza) {
    tablero[fila][columna] = pieza;
}*/