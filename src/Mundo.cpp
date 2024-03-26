#include "Mundo.h"
#include "freeglut.h"
#include <math.h>


void Mundo::rotarOjo()
{
    float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
    float ang = atan2(z_ojo, x_ojo);
    ang += 0.05f;
    x_ojo = dist * cos(ang);
    z_ojo = dist * sin(ang);
}
void Mundo::dibuja()
{
   // <<<<<< < Updated upstream
    /*gluLookAt(0, 0, 120,  // posicion del ojo
        0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
        0.0, 1.0, 0.0);
            /*gluLookAt(5.5, 5.5, 12,  // posicion del ojo
                    5.5, 5.5, 0.0,      // hacia que punto mira  (0,0,0)
        >>>>>>> Stashed changes
                    0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
            */
            //aqui es donde hay que poner el codigo de dibujo
            
            //dibujo del suelo
            //glDisable(GL_LIGHTING);
    /*glBegin(GL_POLYGON);
        glColor3ub(255,0,0);
        glVertex3f(-5.0f,0,-5.0f);
        glVertex3f(-5.0f,0,5.0f);
        glColor3ub(255,255,0);
        glVertex3f(5.0f,0,5.0f);
        glVertex3f(5.0f,0,-5.0f);
    glEnd();*/
   
        //dibujo tablero


        gluLookAt(0, 0, 120,  // posicion del ojo
            0, 0, 0,      // hacia que punto mira  (0,0,0) 
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

       /* for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 0) {
                    glDisable(GL_LIGHTING);
                    glColor3ub(253, 253, 180); //marron claro
                    glBegin(GL_POLYGON);
                    glVertex3f(i + 1.5, j + 1.5, 0);
                    glVertex3f(i + 1.5, j + 2.5, 0);
                    glVertex3f(i + 2.5, j + 2.5, 0);
                    glVertex3f(i + 2.5, j + 1.5, 0);
                    glEnd();
                }
                else {
                    glColor3ub(150, 55, 0); //marron oscuro
                    glBegin(GL_POLYGON);
                    glVertex3f(i + 1.5, j + 1.5, 0);
                    glVertex3f(i + 1.5, j + 2.5, 0);
                    glVertex3f(i + 2.5, j + 2.5, 0);
                    glVertex3f(i + 2.5, j + 1.5, 0);
                    glEnd();
                }
                glEnable(GL_LIGHTING);
            }
        }*/
       
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
    x_ojo = 0;
    y_ojo = 10;
    z_ojo = 20;
}

void Mundo::tecla(unsigned char key)
{

}