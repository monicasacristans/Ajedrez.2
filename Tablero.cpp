#include "Tablero.h"
#include "freeglut.h"
#include <iostream>

Tablero::Tablero() {
    // Inicializar el tablero con piezas vacías
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            tablero[i][j] = ' ';
        }
    }
}

void Tablero::dibujar() const {
    /*glMatrixMode(GL_PROJECTION); // Cambia la matriz actual a la matriz de proyección
    glLoadIdentity(); // Resetea la matriz de proyección a la identidad
    // Establece una proyección ortográfica
    glOrtho(-683, 683, -384, 384, 1, -1);*/

    //glMatrixMode(GL_MODELVIEW); // Cambia la matriz actual de vuelta a la matriz de modelo/vista

    gluLookAt(5.5, 5.5, 12,  // posicion del ojo
        5.5, 5.5, 0.0,      // hacia que punto mira  (0,0,0)
        0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
    
    // Dibujar el tablero utilizando OpenGL
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(253, 253, 180); // marrón claro
                glBegin(GL_POLYGON);
                glVertex3f(i + 1.5, j + 1.5, 0);
                glVertex3f(i + 1.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 1.5, 0);
                glEnd();
            }
            else {
                glColor3ub(150, 55, 0); // marrón oscuro 
                glBegin(GL_POLYGON);
                glVertex3f(i + 1.5, j + 1.5, 0);
                glVertex3f(i + 1.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 1.5, 0);
                glEnd();
            }
    /*for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3ub(253, 246, 227); // Un marrón claro más ajustado
            }
            else {
                glColor3ub(121, 68, 59); // Un marrón oscuro más ajustado
            }
            glBegin(GL_QUADS); // Usar GL_QUADS para simplicidad
            glVertex3f(i, j, 0);
            glVertex3f(i, j + 1, 0);
            glVertex3f(i + 1, j + 1, 0);*/
            
            glEnable(GL_LIGHTING);
        }
    }
}
/*
void Tablero::asignarPieza(int fila, int columna, char pieza) {
    tablero[fila][columna] = pieza;
}*/
