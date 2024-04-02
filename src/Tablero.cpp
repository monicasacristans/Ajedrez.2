#include "Tablero.h"
#include "freeglut.h"
#include <iostream>
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Rey.h"
#include "Reina.h"
#include "Canciller.h"
#include "Arzobispo.h"



Tablero::Tablero() {

    int inicial[8][10] = {
                    {-1,-2,-3,-4,-5,-6,-4,-7,-2,-1},
                    {-6,-6,-6,-6,-6,-6,-6,-6,-6,-6},
                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
                    {6, 6, 6, 6, 6, 6, 6, 6,6,6},
                    {1, 2, 3, 4, 5,6,4, 7, 2, 1} };

    // Inicializar el tablero con piezas vac�as
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 10; ++j) {
            tablero[i][j] = NULL;
        }
    }
}

Tablero::~Tablero() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            tablero[i][j]= NULL;
        }
    }
}

void Tablero::dibujar() {
   
   for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3ub(240, 240, 240); // gris claro
            }
            else {
                glColor3ub(130, 130, 130); // gris oscuro 
            }
            glBegin(GL_POLYGON);
            glVertex3f(10 * i - 48, 10 * j - 41, -2); //Aumenta el tama�o del tablero multiplicando por 10, 
            //ajusta las coordenadas para centrar el tablero en el centro
            glVertex3f(10 * i - 48, 10 * (j + 1) - 41, -2);
            glVertex3f(10 * (i + 1) - 48, 10 * (j + 1) - 41, -2);
            glVertex3f(10 * (i + 1) - 48, 10 * j - 41, -2);
            glEnd();
        }


        glEnable(GL_LIGHTING);
    }  
   
}

void Tablero::piezasdibujar() {
   // glDisable(GL_LIGHTING);

   //ector2D posTB1 = convertirTableroAPantalla(0, 0); // Esquina inferior izquierda para una torre blanca
  //Vector2D posTB2 = convertirTableroAPantalla(7, 0); // Esquina inferior derecha para la otra torre blanca

    //Creacion de peones blanco
    Peon* p1b = new Peon(6);
    Peon* p2b = new Peon(6);
    Peon* p3b = new Peon(6);
    Peon* p4b = new Peon(6);
    Peon* p5b = new Peon(6);
    Peon* p6b = new Peon(6);
    Peon* p7b = new Peon(6);
    Peon* p8b = new Peon(6);
    Peon* p9b = new Peon(6);
    Peon* p10b = new Peon(6);

    //Creacion de peones negros
    Peon* p1n = new Peon(-6);
    Peon* p2n = new Peon(-6);
    Peon* p3n = new Peon(-6);
    Peon* p4n = new Peon(-6);
    Peon* p5n = new Peon(-6);
    Peon* p6n = new Peon(-6);
    Peon* p7n = new Peon(-6);
    Peon* p8n = new Peon(-6);
    Peon* p9n = new Peon(-6);
    Peon* p10n = new Peon(-6);

    
    //Creacion torres blancas
    Torre* tb1 = new Torre(1);
    Torre* tb2 = new Torre(1);

    //Creacion torres negras
    Torre* tn1 = new Torre(-1);
    Torre* tn2 = new Torre(-1);

    //Creacion caballos blancos
    Caballo* cb1 = new Caballo(2);
    Caballo* cb2 = new Caballo(2);

    //Creacion caballos negros
    Caballo* cn1 = new Caballo(-2);
    Caballo* cn2 = new Caballo(-2);

    //Creacion cancilleres
    Canciller* cab = new Canciller(3);
    Canciller* can = new Canciller(-3);

    //Creacion alfiles blancos
    Alfil* ab1 = new Alfil(4);
    Alfil* ab2 = new Alfil(4);

    //Creacion alfiles negros
    Alfil* an1 = new Alfil(-4);
    Alfil* an2 = new Alfil(-4);

    //Creacion de reyes
    Rey* ryb = new Rey(5);
    Rey* ryn = new Rey(-5);

    //Creacion de reinas
    Reina* ryab = new Reina(6);
    Reina* ryan = new Reina(-6);

    //Creacion arzobispos
    Arzobispo* arb = new Arzobispo(7);
    Arzobispo* arn = new Arzobispo(-7);

    //Colocacion piezas en la posicion inicial
    p1b->setPos(-42.5, -24);
    p2b->setPos(-32.5, -24);
    p3b->setPos(-22.5, -24);
    p4b->setPos(-12.5,-24);
    p5b->setPos(-2.5, -24);
    p6b->setPos(7, -24);
    p7b->setPos(17, -24);
    p8b->setPos(27, -24);
    p9b->setPos(37, -24);
    p10b->setPos(47, -24);

    p1n->setPos(-42.5, 24);
    p2n->setPos(-32.5, 24);
    p3n->setPos(-22.5, 24);
    p4n->setPos(-12.5, 24);
    p5n->setPos(-2.5, 24);
    p6n->setPos(7, 24);
    p7n->setPos(17, 24);
    p8n->setPos(27, 24);
    p9n->setPos(37, 24);
    p10n->setPos(47, 24);

    tb1->setPos(-42.5, -35);
    tb2->setPos(47, -35);

    tn1->setPos(-42.5, 34);
    tn2->setPos(47, 34);

    cb1->setPos(-32, -35);
    cb2->setPos(37, -35);

    cn1->setPos(-32, 34.5);
    cn2->setPos(36, 34.5);

    cab->setPos(-22, -35);
    can->setPos(42.5, -35);

    ab1->setPos(-12.5,-35);
    ab2->setPos(27, -35);

    an1->setPos(-12.5, 34.5);
    an2->setPos(27, 34.5);

    ryb->setPos(-2.5, -35);
    ryn->setPos(-2.5, 34.5);

    ryab->setPos(7, -35);
    ryan->setPos(7, 34.5);


   //Dibujar las piezas
    p1b->draw();
    p2b->draw();
    p3b->draw();
    p4b->draw();
    p5b->draw();
    p6b->draw();
    p7b->draw();
    p8b->draw();
    p9b->draw();
    p10b->draw();

    p1n->draw();
    p2n->draw();
    p3n->draw();
    p4n->draw();
    p5n->draw();
    p6n->draw();
    p7n->draw();
    p8n->draw();
    p9n->draw();
    p10n->draw();

    tb1->draw();
    tb2->draw();
    tn1->draw();
    tn2->draw();

    cb1->draw();
    cb2->draw();
    cn1->draw();
    cn2->draw();

    ab1->draw();
    ab2->draw();
    an1->draw();
    an2->draw();

    ryb->draw();
    ryn->draw();

    cab->draw();
    can->draw();

    arb->draw();
    arn->draw();

    ryab->draw();
    ryan->draw();

   // glEnable(GL_LIGHTING);  

}

// Funci�n para convertir coordenadas del tablero a coordenadas de pantalla
ETSIDI::Vector2D Tablero::convertirTableroAPantalla(float x, float y) {
    float origenX = 684;
    float origenY = 200;
    int tama�oCasilla = 10;
    float pantallaX = origenX + x * tama�oCasilla;
    float pantallaY = origenY + y * tama�oCasilla;
    return Vector2D(pantallaX, pantallaY);
}



/*
void Tablero::asignarPieza(int fila, int columna, char pieza) {
    tablero[fila][columna] = pieza;
}*/