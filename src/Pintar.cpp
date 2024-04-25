#include "Pintar.h"

void Pintar::setPos(float x, float y){
   
    c.x = x;
    c.y = y;
   
    peon_b.setPos(c.x, c.y);
    peon_n.setPos(c.x, c.y);
   /* caballo_b.setpos(pos.x, pos.y);
    caballo_n.setpos(pos.x, pos.y);
    torre_b.setpos(pos.x, pos.y); // actualiza la posici�n del sprite, si se quita sale en el centro
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
casilla Pintar::restringirCasilla(int x, int y) {
    
    casilla pix; 
    casilla cas;
    cas.x = x;
    cas.y = y;

    int ventana_ancho = 1366; // ancho de la ventana en p�xeles
    int ventana_alto = 768; // alto de la ventana en p�xeles
    int cuadricula_ancho = 80; // ancho de cada cuadrado de la cuadr�cula en p�xeles
    int cuadricula_alto = 60; // alto de cada cuadrado de la cuadr�cula en p�xeles

    pix.x = cas.x * cuadricula_ancho;
    pix.y = cas.y * cuadricula_alto;

    // Si quieres que el tablero est� centrado en la ventana, calcula el offset necesario
    int centro_x = (ventana_ancho - (max_x * cuadricula_ancho)) / 2;
    int centro_y = (ventana_alto - (max_y * cuadricula_alto)) / 2;

    // Aplica el offset a las coordenadas calculadas
    pix.x+= centro_x;
    pix.y += centro_y;

    return pix;
   
}

casilla Pintar::definirCoordenadasTablero(int button, int state, int x, int y) {
    casilla cas{ 0,0 };
    movimiento mov;
    static int flag = 0;

    int screenX = x;
    int screenY = y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Calcular la columna y fila en funci�n de las coordenadas x e y
        int columna = ((x - 267) / 86.4) + ((x - 267) % 87 > 43.2 ? 1 : 0)+1;//Conociendo las dimensiones y las coordenadas de la casilla, 
        //y si el resto obtenido al dividir entre 87 es mayor a 43.2(la mitad de 87)suma 1, y si no, suma 0.
        int fila = ((738 - y) / 86.4) + ((738 - y) % 87 > 43.2 ? 1 : 0);

        // Verificar que las coordenadas est�n dentro del tablero
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