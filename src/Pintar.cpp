#include "Pintar.h"


void Pintar::draw() {}

//void Pintar::pintarCuadricula() {
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 8; j++) {
//            if ((i + j) % 2 == 0) {
//                glColor3ub(240, 240, 240); // gris claro
//            }
//            else {
//                glColor3ub(130, 130, 130); // gris oscuro 
//            }
//            glBegin(GL_POLYGON);
//            glVertex3f(10 * i - 48, 10 * j - 41, -2); //Aumenta el tamaño del tablero multiplicando por 10, 
//            //ajusta las coordenadas para centrar el tablero en el centro
//            glVertex3f(10 * i - 48, 10 * (j + 1) - 41, 0);
//            glVertex3f(10 * (i + 1) - 48, 10 * (j + 1) - 41, -2);
//            glVertex3f(10 * (i + 1) - 48, 10 * j - 41, -2);
//            glEnd();
//        }
//        glEnable(GL_LIGHTING);
//    }
//}

void Pintar::pintarCuadricula() {
    // Calcula las coordenadas para centrar el tablero
    int tableroWidth = 10 * 80; // Ancho total del tablero (10 columnas de cuadrados de 80 píxeles)
    int tableroHeight = 8 * 80; // Altura total del tablero (8 filas de cuadrados de 80 píxeles)
    int offsetX = (1366 - tableroWidth) / 2; // Desplazamiento horizontal para centrar el tablero
    int offsetY = (768 - tableroHeight) / 2; // Desplazamiento vertical para centrar el tablero

    // Configura la matriz de proyección
  /*  glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1366, 0, 768, -1, 1); // Establece el sistema de coordenadas en 2D (1336x768)
*/
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

/*
casilla Pintar::restringirCasilla(int x, int y) {

    casilla pix;
    casilla cas;
    cas.x = x;
    cas.y = y;

    int ventana_ancho = 1366; // ancho de la ventana en píxeles
    int ventana_alto = 768; // alto de la ventana en píxeles
    int cuadricula_ancho = 118; // ancho de cada cuadrado de la cuadrícula en píxeles
    int cuadricula_alto = 118; // alto de cada cuadrado de la cuadrícula en píxeles

    pix.x = cas.x * cuadricula_ancho;
    pix.y = cas.y * cuadricula_alto;

    // Si quieres que el tablero esté centrado en la ventana, calcula el offset necesario
    int centro_x = (ventana_ancho - (max_x * cuadricula_ancho)) / 10;//283
    int centro_y = (ventana_alto - (max_y * cuadricula_alto)) / 8;//84

    // Aplica el offset a las coordenadas calculadas
    pix.x += centro_x;
    pix.y += centro_y;

    pix.x /= 11.8;
    pix.y /= 6.48;
    /*
    //CUADRANTE II
    if (cas.x >= 0 && cas.x <= 4 && cas.y >= 4 && cas.y <= 7) {
        pix.x = (-pix.x);
    }
    //CUADRANTE III
    else if (cas.x >= 0 && cas.x <= 4 && cas.y >= 0 && cas.y <= 3) {
        pix.x = (-pix.x);
        pix.y = (-pix.y);
    }
    //CUADRANTE IV
    else if (cas.x >= 5 && cas.x <= 9 && cas.y >= 0 && cas.y <= 3) {
        pix.y = (-pix.y);
    }
   
    return pix;

}*/

casilla Pintar::restringirCasilla(int x, int y) {

    casilla pix;

    // Dimensiones del tablero
    int anchoTablero = 10 * 80; // 10 columnas de cuadrados de 80 píxeles
    int altoTablero = 8 * 80; // 8 filas de cuadrados de 80 píxeles

    // Coordenadas del centro del tablero
    int centro_x = 1366 / 2;
    int centro_y = 768 / 2;

    // Coordenadas de la esquina superior izquierda del tablero
    int esquinaSupDer_x = centro_x + anchoTablero / 2; //1083
    int esquinaSupDer_y = centro_x - altoTablero / 2;  //64

    // Convierte las coordenadas de la casilla a las coordenadas de la cuadrícula
    pix.x = esquinaSupDer_x - ((10 - x) * 80);
    pix.y = ((10 - y) * 80) - esquinaSupDer_y;

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
        int columna = ((x - 267) / 86.4) + ((x - 267) % 87 > 43.2 ? 1 : 0);//Conociendo las dimensiones y las coordenadas de la casilla, 
        //y si el resto obtenido al dividir entre 87 es mayor a 43.2(la mitad de 87)suma 1, y si no, suma 0.
        int fila = ((738 - y) / 86.4);

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
            }
        }
    }
}
