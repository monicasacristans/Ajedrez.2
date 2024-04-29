#include <iostream>
#include "Pintar.h"
#include "Usuario.h"
#include "Tablero.h"

Usuario usuario;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void mouseClick(int button, int state, int x, int y); //futuro raton
void mouse(int x, int y);
void reshape(int width, int height);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glViewport(0, 0, 1366, 768);
	glMatrixMode(GL_PROJECTION);

	glViewport(0, 0, 1366, 768);

	// se carga la matriz identidad
	glLoadIdentity();

	glOrtho(0, 1366, 0, 768, 0, 1.0);
	usuario.setReshape(1366, 768);
	// matriz de vista de modelo
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//Registrar los callbacks
	glutPassiveMotionFunc(mouse);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(mouseClick);
	glutReshapeFunc(reshape);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void mouse(int x, int y) {
	y = usuario.shapy -y;
	usuario.mouse(x, y);
	OnDraw();
	glutPostRedisplay;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glClearDepth(1.0);

	glClear(GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	//Para definir el punto de vista
	glLoadIdentity();
	glOrtho(0, 1366, 0,768, -1, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	usuario.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void mouseClick(int button, int state, int x, int y)
{
	y= usuario.shapy - y;
	usuario.raton(button, state, x, y);
	//tablero.definirCoordenadasTablero(button, state, x, y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int screenX = x;
		int screenY = y;
		std::cout << "Coordenadas del raton en la pantalla: (" << screenX << ", " << screenY << ")" << std::endl;

		glutPostRedisplay;
	}
}


void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	y_t = usuario.shapy - y_t;
	glutPostRedisplay();
}

void OnTimer(int value)
{
	//no borrar estas lineas
	glutTimerFunc(100, OnTimer, 0);
	glutPostRedisplay();
}


//Especifica como se debe ajustar la ventana cuando se redimensiona
// w y h representan los nuevos valores de ancho y alto
void reshape(int width, int height)
{
	usuario.setReshape(width, height);

}