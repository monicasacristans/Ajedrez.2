//<iostream> en Basico.h
#include "Tablero.h"
#include "Usuario.h"
#include "Peon.h"
#include "Torre.h"
#include "Arzobispo.h"
#include "Caballo.h"
#include "Canciller.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"

using namespace std;

Tablero::Tablero() {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr; //Pieza crea una pieza vacia 
		}
	}
}


//Metodo para colocar una pieza en el tablero
//void Tablero::colocarPieza(int x, int y, Pieza p) {
//	if (x >= 0 && x < max_x && y >= 0 && y < max_y) {
//		tablero[y][x] = p; //Primero fila(y) y luego columna(x)
//	}
//	else {
//		std::cerr << "Posicion fuera de los límites del tablero" << std::endl;
//	}
//}

//void Tablero::piezasinicializa() {
//
//	colocarPieza(0, 0, Pieza(tipo::torre, color::negro));
//	colocarPieza(1, 0, Pieza(tipo::caballo, color::negro));
//	colocarPieza(2, 0, Pieza(tipo::canciller, color::negro));
//	colocarPieza(3, 0, Pieza(tipo::arzobispo, color::negro));
//	colocarPieza(4, 0, Pieza(tipo::rey, color::negro));
//	colocarPieza(5, 0, Pieza(tipo::reina, color::negro));
//	colocarPieza(6, 0, Pieza(tipo::arzobispo, color::negro));
//	colocarPieza(7, 0, Pieza(tipo::canciller, color::negro));
//	colocarPieza(8, 0, Pieza(tipo::caballo, color::negro));
//	colocarPieza(9, 0, Pieza(tipo::torre, color::negro));
//
//
//	for (int i = 0; i < 10; i++) {
//		colocarPieza(i, 1, Pieza(tipo::peon, color::negro));
//		//cin.sync();
//		//cin.clear();
//	}
//
//	colocarPieza(0, 7, Pieza(tipo::torre, color::blanco));
//	colocarPieza(1, 7, Pieza(tipo::caballo, color::blanco));
//	colocarPieza(2, 7, Pieza(tipo::canciller, color::blanco));
//	colocarPieza(3, 7, Pieza(tipo::arzobispo, color::blanco));
//	colocarPieza(4, 7, Pieza(tipo::rey, color::blanco));
//	colocarPieza(5, 7, Pieza(tipo::reina, color::blanco));
//	colocarPieza(6, 7, Pieza(tipo::arzobispo, color::blanco));
//	colocarPieza(7, 7, Pieza(tipo::canciller, color::blanco));
//	colocarPieza(8, 7, Pieza(tipo::caballo, color::blanco));
//	colocarPieza(9, 7, Pieza(tipo::torre, color::blanco));
//
//
//	for (int i = 0; i < 10; i++) {
//		colocarPieza(i, 6, Pieza(tipo::peon, color::blanco));
//		//cin.sync();
//		//cin.clear();
//	}
//
//}
//
//Dibuja el tablero MIRAR
//void Tablero::dibujar() {
//	Pieza ptr = *tablero[max_y][max_x];
//	for (int y = 0; y < max_y; y++) {
//		std::cout << y << "  "; //imprime el indice de la fila
//		for (int x = 0; x < max_x; x++) {
//			std::cout << ptr[y][x].obtenerRepresentacion() << " ";
//			std::cout << " "; // Un espacio entre cada pieza para alineación.
//
//		}
//		std::cout << std::endl;
//
//	}
//
//	std::cout << "   "; // Espacios para alinear con los índices de las filas si son de un dígito
//	for (int x = 0; x < max_x; ++x) {
//		std::cout << x << "  "; // Imprimir el índice de la columna
//	}
//	std::cout << std::endl;
//}


casilla Tablero::definirCoordenadasTablero(int button, int state, int x, int y){
	casilla cas{ 0,0 };
	movimiento mov;
	static int flag = 0;

	int screenX = x;
	int screenY = y;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la columna y fila en función de las coordenadas x e y
		int columna = ((x - 267) / 86.4) + ((x - 267) % 87 > 43.2 ? 1 : 0) + 1;//Conociendo las dimensiones y las coordenadas de la casilla, 
		//y si el resto obtenido al dividir entre 87 es mayor a 43.2(la mitad de 87)suma 1, y si no, suma 0.
		int fila = ((738 - y) / 86.4) + ((738 - y) % 87 > 43.2 ? 1 : 0);     

		// Verificar que las coordenadas estén dentro del tablero
		if (columna >= 1 && columna <= 10 && fila >= 1 && fila <= 8) {
			cas.x = columna;
			cas.y = fila;

			flag++;
			
			//Determinar casillas de origen y destino
			if (flag==2) {
				mov.origen = cas;
				std::cout << "Casilla origen: " << mov.origen << std::endl;
			}
			else if(flag==3){
				mov.destino = cas;
				flag = 1;
				std::cout << "Casilla destino: " << mov.destino << std::endl;
			}
		}
	}
	return cas;
}

bool Tablero::checkCasillaOcupada(int x, int y) {
	if (x >= 0 && x < max_x && y >= 0 && y < max_y) {  //Comprueba que estamos dentro del tablero
		
		Pieza mipieza = *tablero[y][x]; //Obtiene la pieza que hay en la casilla

		if (mipieza.getTipo() != tipo::vacio) {
			return true; //casilla ocupada
		}
	}
	return false; //casilla vacía
}



Pieza* Tablero::checkPiezaEnCasilla(casilla pos) {

	if (pos.x >= 0 && pos.x < max_x && pos.y >= 0 && pos.y < max_y) { //Comprueba que estamos dentro del tablero
		return tablero[pos.y][pos.x];  //Devuelve la pieza que hay en la casilla
	}
	else {
		// Si la casilla está fuera del tablero, devuelve una pieza vacía
		return nullptr;
	}
}

void Tablero::set_tablero() {

	//Piezas blancas
	Torre* tb1 = new Torre(tipo::torre, color::blanco);
	listapiezas.push_back(tb1);
	Alfil* ab1 = new Alfil(tipo::alfil, color::blanco);
	listapiezas.push_back(ab1);
	Caballo* cb1 = new Caballo(tipo::caballo, color::blanco);
	listapiezas.push_back(cb1);
	Arzobispo* zb1 = new Arzobispo(tipo::arzobispo, color::blanco);
	listapiezas.push_back(zb1);
	Rey* rb = new Rey(tipo::rey, color::blanco);
	listapiezas.push_back(rb);
	Reina* ryb = new Reina(tipo::reina, color::blanco);
	listapiezas.push_back(ryb);
	Canciller* nb1 = new Canciller(tipo::canciller, color::blanco);
	listapiezas.push_back(nb1);
	Caballo* cb2 = new Caballo(tipo::caballo, color::blanco);
	listapiezas.push_back(cb2);
	Alfil* ab2 = new Alfil(tipo::alfil, color::blanco);
	listapiezas.push_back(ab2);
	Torre* tb2 = new Torre(tipo::torre, color::blanco);
	listapiezas.push_back(tb2);

	//peones blancos
	Peon* pb1 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb1);
	Peon* pb2 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb2);
	Peon* pb3 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb3);
	Peon* pb4 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb4);
	Peon* pb5 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb5);
	Peon* pb6 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb6);
	Peon* pb7 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb7);
	Peon* pb8 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb8);
	Peon* pb9 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb9);
	Peon* pb10 = new Peon(tipo::peon, color::blanco);
	listapiezas.push_back(pb10);



	//peones negros
	Peon* pn1 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn1);
	Peon* pn2 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn2);
	Peon* pn3 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn3);
	Peon* pn4 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn4);
	Peon* pn5 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn5);
	Peon* pn6 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn6);
	Peon* pn7 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn7);
	Peon* pn8 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn8);
	Peon* pn9 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn9);
	Peon* pn10 = new Peon(tipo::peon, color::negro);
	listapiezas.push_back(pn10);
	//std::cout << listapiezas.size() << endl;

	//Piezas negras
	Torre* tn1 = new Torre(tipo::torre, color::negro);
	listapiezas.push_back(tn1);
	Alfil* an1 = new Alfil(tipo::alfil, color::negro);
	listapiezas.push_back(an1);
	Caballo* cn1 = new Caballo(tipo::caballo, color::negro);
	listapiezas.push_back(cn1);
	Arzobispo* zn1 = new Arzobispo(tipo::arzobispo, color::negro);
	listapiezas.push_back(zn1);
	Rey* rn = new Rey(tipo::rey, color::negro);
	listapiezas.push_back(rn);
	Reina* ryn = new Reina(tipo::reina, color::negro);
	listapiezas.push_back(ryn);
	Canciller* nn2 = new Canciller(tipo::canciller, color::negro);
	listapiezas.push_back(nn2);
	Caballo* cn2 = new Caballo(tipo::caballo, color::negro);
	listapiezas.push_back(cn2);
	Alfil* an2 = new Alfil(tipo::alfil, color::negro);
	listapiezas.push_back(an2);
	Torre* tn2 = new Torre(tipo::torre, color::negro);
	listapiezas.push_back(tn2);

	//Iniciar todo el tablero a nullptr
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr;
		}
	}

	if (listapiezas.size() >= 40) {

		//colocar y dibujar piezas blancas
		for (int i = 0; i < 10; i++) {
			tablero[0][i] = listapiezas[i];

		}
		cout << endl;
		// colocar y dibujar peones blancos
		for (int i = 0; i < 10; i++) {
			tablero[1][i] = listapiezas[i + 10];
			
		}
		cout << endl;

		//colocar y dibujar piezas negras
		for (int i = 0; i < 10; i++) {
			tablero[7][i] = listapiezas[i + 20];
			
		}
		cout << endl;

		// colocar y dibujar peones negros
		for (int i = 0; i < 10; i++) {
			tablero[6][i] = listapiezas[i + 30];
		
		}
		cout << endl;
	}
}

//void Tablero::ratonTablero(int button, int state, int x, int y) {
//	// Verificar si es el turno de las blancas
//	finturnonegro = 0;
//	if (turno == 1) {
//		std::cout << "JUEGAN LAS BLANCAS" << endl;
//		// Realizar acciones correspondientes al turno de las blancas
//		//jugadorblanco->dibujarcorona();
//		jugadorblanco->posicionarPieza(button, state, x, y);
//		
//
//		// Verificar si el turno de las blancas ha terminado
//		if (jugadorblanco->getFinTurno()) {
//			// Actualizar el estado de turno y reiniciar el estado de fin de turno para el siguiente turno
//			jugadorblanco->setFinTurno(false);
//			finturnoblanco = 1;
//			finturnonegro = 0;
//			turno = 0; return;
//		}
//	}
//	finturnoblanco = 0;
//	 if (turno == 0) {
//		 std::cout << "JUEGAN LAS NEGRAS" << endl;
//		// Realizar acciones correspondientes al turno de las negras
//		//jugadornegro->dibujarcorona();
//		jugadornegro->posicionarPieza(button, state, x, y);
//
//		// Verificar si el turno de las negras ha terminado
//		if (jugadornegro->getFinTurno()) {
//			// Actualizar el estado de turno y reiniciar el estado de fin de turno para el siguiente turno
//			jugadornegro->setFinTurno(false);
//			finturnonegro = 1;
//			finturnoblanco = 0;
//			turno = 1; return;
//
//		}
//	}
//}

//void Tablero::ratonTablero(int button, int state, int x, int y) {
//	finturnonegro = 0;
//	//std::cout << "JUEGAN LAS BLANCAS" << endl;
//	if (turno == 1) {
//		std::cout << "JUEGAN LAS BLANCAS" << endl;
//		//jugadorblanco->dibujarcorona();
//		jugadorblanco->posicionarPieza(button, state, x, y);
//		if (jugadorblanco->getFinTurno() == 1) {
//			finturnoblanco = 1;
//			finturnonegro = 0;
//			turno = 0; return;
//		}
//	}
//
//	finturnoblanco = 0;
//	if (turno == 0) {
//		//jugadornegro->dibujarcorona();
//		jugadornegro->posicionarPieza(button, state, x, y);
//		std::cout << "JUEGAN LAS NEGRAS" << endl;
//		if (jugadornegro->getFinTurno() == 1) {
//			finturnonegro = 1;
//			finturnoblanco = 0;
//			turno = 1;
//			return;
//		}
//	}
//}

//void Tablero::pintarCuadricula() {
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 8; j++) {
//			if ((i + j) % 2 == 0) {
//				glColor3ub(240, 240, 240); // gris claro
//				//tablero[i][j].obtenerRepresentacion();
//			}
//			else {
//				glColor3ub(130, 130, 130); // gris oscuro 
//				//tablero[i][j].obtenerRepresentacion();
//			}
//			glBegin(GL_POLYGON);
//			glVertex3f(10 * i - 48, 10 * j - 41, -2); //aumenta el tamaño del tablero multiplicando por 10, 
//			//ajusta las coordenadas para centrar el tablero en el centro
//			glVertex3f(10 * i - 48, 10 * (j + 1) - 41, -2);
//			glVertex3f(10 * (i + 1) - 48, 10 * (j + 1) - 41, -2);
//			glVertex3f(10 * (i + 1) - 48, 10 * j - 41, -2);
//			glEnd();
//		}
//	}
//	glEnable(GL_LIGHTING);
//
//	for (int y = 0; y < max_y; y++) {
//		for (int x = 0; x < max_x; x++) {
//			glPushMatrix();
//			glTranslatef(y * 87, x * 87, 0.1);
//			//tablero[y][x].draw();
//			glPopMatrix();
//		}
//	}
//}

//Tablero::Tablero() {
//
//    int inicial[8][10] = {
//                    {-1,-2,-3,-4,-5,-6,-4,-7,-2,-1},
//                    {-6,-6,-6,-6,-6,-6,-6,-6,-6,-6},
//                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
//                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
//                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
//                    {0, 0, 0, 0, 0, 0, 0, 0,0,0},
//                    {6, 6, 6, 6, 6, 6, 6, 6,6,6},
//                    {1, 2, 3, 4, 5,6,4, 7, 2, 1} };
//
//    // Inicializar el tablero con piezas vacías
//    for (int i = 0; i < 8; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            tablero[i][j] = NULL;
//        }
//    }
//}
//
//Tablero::~Tablero() {
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 10; j++) {
//            tablero[i][j]= NULL;
//        }
//    }
//}
//


void Tablero::setJugadorBlanco(Jugador* x) {
	jugadorblanco = x;
}


void Tablero::setJugadorNegro(Jugador* x) {
	jugadornegro = x;
}

//getters
bool Tablero::getFinTurnoNegro() {
	return finturnonegro;
}


bool Tablero::getFinTurnoBlanco() {
	return finturnoblanco;
}


bool Tablero::getTurno() {
	return turno;
}
//
//void Tablero::piezasdibujar() {
//   // glDisable(GL_LIGHTING);
//
//   //ector2D posTB1 = convertirTableroAPantalla(0, 0); // Esquina inferior izquierda para una torre blanca
//  //Vector2D posTB2 = convertirTableroAPantalla(7, 0); // Esquina inferior derecha para la otra torre blanca
//
//    //Creacion de peones blanco
//    Peon* p1b = new Peon(6);
//    Peon* p2b = new Peon(6);
//    Peon* p3b = new Peon(6);
//    Peon* p4b = new Peon(6);
//    Peon* p5b = new Peon(6);
//    Peon* p6b = new Peon(6);
//    Peon* p7b = new Peon(6);
//    Peon* p8b = new Peon(6);
//    Peon* p9b = new Peon(6);
//    Peon* p10b = new Peon(6);
//
//    //Creacion de peones negros
//    Peon* p1n = new Peon(-6);
//    Peon* p2n = new Peon(-6);
//    Peon* p3n = new Peon(-6);
//    Peon* p4n = new Peon(-6);
//    Peon* p5n = new Peon(-6);
//    Peon* p6n = new Peon(-6);
//    Peon* p7n = new Peon(-6);
//    Peon* p8n = new Peon(-6);
//    Peon* p9n = new Peon(-6);
//    Peon* p10n = new Peon(-6);
//
//    
//    //Creacion torres blancas
//    Torre* tb1 = new Torre(1);
//    Torre* tb2 = new Torre(1);
//
//    //Creacion torres negras
//    Torre* tn1 = new Torre(-1);
//    Torre* tn2 = new Torre(-1);
//
//    //Creacion caballos blancos
//    Caballo* cb1 = new Caballo(2);
//    Caballo* cb2 = new Caballo(2);
//
//    //Creacion caballos negros
//    Caballo* cn1 = new Caballo(-2);
//    Caballo* cn2 = new Caballo(-2);
//
//    //Creacion cancilleres
//    Canciller* cab = new Canciller(3);
//    Canciller* can = new Canciller(-3);
//
//    //Creacion alfiles blancos
//    Alfil* ab1 = new Alfil(4);
//    Alfil* ab2 = new Alfil(4);
//
//    //Creacion alfiles negros
//    Alfil* an1 = new Alfil(-4);
//    Alfil* an2 = new Alfil(-4);
//
//    //Creacion de reyes
//    Rey* ryb = new Rey(5);
//    Rey* ryn = new Rey(-5);
//
//    //Creacion de reinas
//    Reina* ryab = new Reina(6);
//    Reina* ryan = new Reina(-6);
//
//    //Creacion arzobispos
//    Arzobispo* arb = new Arzobispo(7);
//    Arzobispo* arn = new Arzobispo(-7);
//
//    //Colocacion piezas en la posicion inicial
//    p1b->setPos(-42.5, -24);
//    p2b->setPos(-32.5, -24);
//    p3b->setPos(-22.5, -24);
//    p4b->setPos(-12.5,-24);
//    p5b->setPos(-2.5, -24);
//    p6b->setPos(7, -24);
//    p7b->setPos(17, -24);
//    p8b->setPos(27, -24);
//    p9b->setPos(37, -24);
//    p10b->setPos(47, -24);
//
//    p1n->setPos(-42.5, 24);
//    p2n->setPos(-32.5, 24);
//    p3n->setPos(-22.5, 24);
//    p4n->setPos(-12.5, 24);
//    p5n->setPos(-2.5, 24);
//    p6n->setPos(7, 24);
//    p7n->setPos(17, 24);
//    p8n->setPos(27, 24);
//    p9n->setPos(37, 24);
//    p10n->setPos(47, 24);
//
//    tb1->setPos(-42.5, -35);
//    tb2->setPos(47, -35);
//
//    tn1->setPos(-42.5, 34);
//    tn2->setPos(47, 34);
//
//    cb1->setPos(-32, -35);
//    cb2->setPos(37, -35);
//
//    cn1->setPos(-32, 34.5);
//    cn2->setPos(36, 34.5);
//
//    cab->setPos(-22, -35);
//    can->setPos(42.5, -35);
//
//    ab1->setPos(-12.5,-35);
//    ab2->setPos(27, -35);
//
//    an1->setPos(-12.5, 34.5);
//    an2->setPos(27, 34.5);
//
//    ryb->setPos(-2.5, -35);
//    ryn->setPos(-2.5, 34.5);
//
//    ryab->setPos(7, -35);
//    ryan->setPos(7, 34.5);
//
//
//   //Dibujar las piezas
//    p1b->draw();
//    p2b->draw();
//    p3b->draw();
//    p4b->draw();
//    p5b->draw();
//    p6b->draw();
//    p7b->draw();
//    p8b->draw();
//    p9b->draw();
//    p10b->draw();
//
//    p1n->draw();
//    p2n->draw();
//    p3n->draw();
//    p4n->draw();
//    p5n->draw();
//    p6n->draw();
//    p7n->draw();
//    p8n->draw();
//    p9n->draw();
//    p10n->draw();
//
//    tb1->draw();
//    tb2->draw();
//    tn1->draw();
//    tn2->draw();
//
//    cb1->draw();
//    cb2->draw();
//    cn1->draw();
//    cn2->draw();
//
//    ab1->draw();
//    ab2->draw();
//    an1->draw();
//    an2->draw();
//
//    ryb->draw();
//    ryn->draw();
//
//    cab->draw();
//    can->draw();
//
//    arb->draw();
//    arn->draw();
//
//    ryab->draw();
//    ryan->draw();
//
//   // glEnable(GL_LIGHTING);  
//
//}
//
//// Función para convertir coordenadas del tablero a coordenadas de pantalla
//ETSIDI::Vector2D Tablero::convertirTableroAPantalla(float x, float y) {
//    float origenX = 684;
//    float origenY = 200;
//    int tamañoCasilla = 10;
//    float pantallaX = origenX + x * tamañoCasilla;
//    float pantallaY = origenY + y * tamañoCasilla;
//    return Vector2D(pantallaX, pantallaY);
//}
//
//
//
///*
//void Tablero::asignarPieza(int fila, int columna, char pieza) {
//    tablero[fila][columna] = pieza;
//}*/