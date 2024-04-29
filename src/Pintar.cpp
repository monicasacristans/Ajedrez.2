#include "Pintar.h"


void Pintar::draw() {}

void Pintar::pintarCuadricula() {
    // Calcula las coordenadas para centrar el tablero
    int offsetX = (1366 - anchoTablero) / 2; // Desplazamiento horizontal para centrar el tablero
    int offsetY = (768 - altoTablero) / 2; // Desplazamiento vertical para centrar el tablero

    // Cambia a la matriz de modelo-vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Dibuja la cuadrícula
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3ub(240, 240, 240); // gris claro
            }
            else {
                glColor3ub(130, 130, 130); // gris oscuro 
            }
            glBegin(GL_POLYGON);
            glVertex2f(offsetX + 80 * i, offsetY + 80 * j); // Ajusta las coordenadas para centrar el tablero
            glVertex2f(offsetX + 80 * i, offsetY + 80 * (j + 1));
            glVertex2f(offsetX + 80 * (i + 1), offsetY + 80 * (j + 1));
            glVertex2f(offsetX + 80 * (i + 1), offsetY + 80 * j);
            glEnd();
        }
    }
}

casilla Pintar::restringirCasilla(int x, int y) {

    casilla pix;

    // Coordenadas del centro del tablero
    int centro_x = 1366 / 2;
    int centro_y = 768 / 2;

    // Coordenadas de la esquina superior izquierda del tablero
    int esquinaInfIzq_x = centro_x - (anchoTablero / 2); //283
    int esquinaInfIzq_y = centro_y - (altoTablero / 2);  //64

    // Convierte las coordenadas de la casilla a las coordenadas de la cuadrícula
    pix.x = esquinaInfIzq_x + (x * 80) + 40;
    pix.y = esquinaInfIzq_y + (y * 80) + 40;

    return pix;
}

casilla Pintar::definirCoordenadasTablero(int button, int state, int x, int y) {
    casilla cas{ 0,0 };
    movimiento mov;
    static int flag = 0;

    int screenX = x;
    int screenY = y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Calcular la columna y fila en función de las coordenadas x e y
        int columna = ((x - 283) / 80);
        int fila = ((y - 64) / 80);

        // Verificar que las coordenadas estén dentro del tablero
        if (columna >= 0 && columna <= 9 && fila >= 0 && fila <= 7) {
            cas.x = columna;
            cas.y = fila;

            flag++;

            //Determinar casillas de origen y destino
            if (flag == 2) {
                mov.origen = cas;
                std::cout << "Casilla origen: " << mov.origen << std::endl;
            }
            else if (flag == 3) {
                mov.destino = cas;
                flag = 1;
                std::cout << "Casilla destino: " << mov.destino << std::endl;
            }
        }
    }
    return cas;
}

void Pintar::pintarPiezasTablero() {

    for (int y = 0; y < max_y; ++y) {
        for (int x = 0; x < max_x; ++x) {

            // Obtengo la pieza que hay en la casilla anterior
            Pieza* pieza = tablero->checkPiezaEnCasilla({ x,y });

            // Verifico que hay una pieza en la casilla seleccionada
            if (pieza != nullptr) {

                casilla cas = restringirCasilla(x, y);

                if (pieza->getTipo() == tipo::peon && pieza->getColor() == color::blanco) {
                    peon_b.setPos(cas.x, cas.y);
                    peon_b.draw();
                }
                if (pieza->getTipo() == tipo::peon && pieza->getColor() == color::negro) {
                    peon_n.setPos(cas.x, cas.y);
                    peon_n.draw();
                }
                if (pieza->getTipo() == tipo::torre && pieza->getColor() == color::blanco) {
                    torre_b.setPos(cas.x, cas.y);
                    torre_b.draw();
                }
                if (pieza->getTipo() == tipo::torre && pieza->getColor() == color::negro) {
                    torre_n.setPos(cas.x, cas.y);
                    torre_n.draw();
                }
                if (pieza->getTipo() == tipo::caballo && pieza->getColor() == color::blanco) {
                    caballo_b.setPos(cas.x, cas.y);
                    caballo_b.draw();
                }
                if (pieza->getTipo() == tipo::caballo && pieza->getColor() == color::negro) {
                    caballo_n.setPos(cas.x, cas.y);
                    caballo_n.draw();
                }
                if (pieza->getTipo() == tipo::alfil && pieza->getColor() == color::blanco) {
                    alfil_b.setPos(cas.x, cas.y);
                    alfil_b.draw();
                }
                if (pieza->getTipo() == tipo::alfil && pieza->getColor() == color::negro) {
                    alfil_n.setPos(cas.x, cas.y);
                    alfil_n.draw();
                }
                if (pieza->getTipo() == tipo::reina && pieza->getColor() == color::blanco) {
                    reina_b.setPos(cas.x, cas.y);
                    reina_b.draw();
                }
                if (pieza->getTipo() == tipo::reina && pieza->getColor() == color::negro) {
                    reina_n.setPos(cas.x, cas.y);
                    reina_n.draw();
                }
                if (pieza->getTipo() == tipo::rey && pieza->getColor() == color::blanco) {
                    rey_b.setPos(cas.x, cas.y);
                    rey_b.draw();
                }
                if (pieza->getTipo() == tipo::rey && pieza->getColor() == color::negro) {
                    rey_n.setPos(cas.x, cas.y);
                    rey_n.draw();
                }
            }
        }
    }
}
