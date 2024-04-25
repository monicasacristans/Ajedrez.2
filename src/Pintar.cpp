#include "Pintar.h"

void Pintar::setPos(float x, float y){
   
    c.x = x;
    c.y = y;
   
    peon_b.setPos(c.x, c.y);
    peon_n.setPos(c.x, c.y);
   /* caballo_b.setpos(pos.x, pos.y);
    caballo_n.setpos(pos.x, pos.y);
    torre_b.setpos(pos.x, pos.y); // actualiza la posición del sprite, si se quita sale en el centro
    torre_n.setpos(pos.x, pos.y);
    alfil_b.setpos(pos.x, pos.y);
    alfil_n.setpos(pos.x, pos.y);
    reina_b.setpos(pos.x, pos.y);
    reina_n.setpos(pos.x, pos.y);
    rey_b.setpos(pos.x, pos.y);
    rey_n.setpos(pos.x, pos.y);*/
    
}

void Pintar::draw(){}

void Pintar::pintarCuadricula() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3ub(240, 240, 240); // gris claro
            }
            else {
                glColor3ub(130, 130, 130); // gris oscuro 
            }
            glBegin(GL_POLYGON);
            glVertex3f(10 * i - 48, 10 * j - 41, -2); //Aumenta el tamaño del tablero multiplicando por 10, 
            //ajusta las coordenadas para centrar el tablero en el centro
            glVertex3f(10 * i - 48, 10 * (j + 1) - 41, -2);
            glVertex3f(10 * (i + 1) - 48, 10 * (j + 1) - 41, -2);
            glVertex3f(10 * (i + 1) - 48, 10 * j - 41, -2);
            glEnd();
        }
        glEnable(GL_LIGHTING);
    }
}

void Pintar::restringirCasilla() {
  
    // Tamaño de la ventana y de la cuadrícula
    int ventana_ancho = 1366; // Ancho de la ventana en píxeles
    int ventana_alto = 768; // Alto de la ventana en píxeles
    int cuadricula_ancho = 80; // Ancho de cada cuadrado de la cuadrícula en píxeles
    int cuadricula_alto = 60; // Alto de cada cuadrado de la cuadrícula en píxeles

    // Recorrer las casillas de la cuadrícula
    for (int fila = 0; fila < 8; ++fila) {
        for (int columna = 0; columna < 10; ++columna) {
            // Calcular las coordenadas de la esquina superior izquierda de la casilla
            int x = columna * cuadricula_ancho;
            int y = fila * cuadricula_alto;

            // Calcular las coordenadas de la esquina inferior derecha de la casilla
            int x2 = x + cuadricula_ancho;
            int y2 = y + cuadricula_alto;

            // Asignar las coordenadas de la casilla al elemento correspondiente en el tablero
            //tablero[fila][columna].asignarCoordenadas(x, y, x2, y2);
        }
    }
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
        int fila = ((y - 43) / 86.4) + ((y - 43) % 87 > 43.2 ? 1 : 0);

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

            //Convierto las coordenadas de la casilla 'glut' a una casilla normal
           // casilla cas = definirCoordenadasTablero(GLUT_LEFT_BUTTON, GLUT_DOWN, mouseX, mouseY);
            casilla cas = { x,y };
            // Obtengo la pieza que hay en la casilla anterior
            Pieza* pieza = tablero->checkPiezaEnCasilla(cas);
            
            // Verifico que hay una pieza en la casilla seleccionada
            if (pieza != nullptr) {

                if (pieza->getTipo() == tipo::peon && pieza->getColor() == color::blanco) {
                    peon_b.draw();
                }
                if (pieza->getTipo() == tipo::peon && pieza->getColor() == color::negro) {
                    peon_n.draw();
                }
            }
        }
    }
}