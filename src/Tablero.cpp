#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

Tablero::Tablero() {
    // Inicializar el tablero con piezas vac�as
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            tablero[i][j] = ' ';
        }
    }
}

void Tablero::dibujar() const {
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3ub(253, 253, 180); // marr�n claro
            }
            else {
                glColor3ub(150, 55, 0); // marr�n oscuro 
            }
            glBegin(GL_POLYGON);
            glVertex3f(10 * i - 40, 10 * j - 41, 0); //Aumenta el tama�o del tablero multiplicando por 10, 
            //ajusta las coordenadas para centrar el tablero en el centro
            glVertex3f(10 * i - 40, 10 * (j + 1) - 41, 0);
            glVertex3f(10 * (i + 1) - 40, 10 * (j + 1) - 41, 0);
            glVertex3f(10 * (i + 1) - 40, 10 * j - 41, 0);
            glEnd();
        }

    /*// Dibujar el tablero utilizando OpenGL
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(253, 253, 180); // marr�n claro
                glBegin(GL_POLYGON);
                glVertex3f(i + 1.5, j + 1.5, 0);
                glVertex3f(i + 1.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 1.5, 0);
                glEnd();
            }
            else {
                glColor3ub(150, 55, 0); // marr�n oscuro 
                glBegin(GL_POLYGON);
                glVertex3f(i + 1.5, j + 1.5, 0);
                glVertex3f(i + 1.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 1.5, 0);
                glEnd();
            }*/

        glEnable(GL_LIGHTING);
    }
}
/*
void Tablero::asignarPieza(int fila, int columna, char pieza) {
    tablero[fila][columna] = pieza;
}*/