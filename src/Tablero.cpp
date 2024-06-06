#include "Tablero.h"

using namespace std;

extern Usuario usuario;

Tablero::Tablero() {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr; //Pieza crea una pieza vacia 
		}
	}
}

Tablero::~Tablero(){}

void Tablero::definirCoordenadasTablero(int button, int state, int x, int y) {

	Pieza* p = checkPiezaEnCasilla(cas_origen);
	static int click = 0;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la columna y fila en función de las coordenadas x e y
		int columna = ((x - 283) / 80);
		int fila = ((y - 64) / 80);
		click++;

		if (columna < 0 || columna >= 10 || fila < 0 || fila >= 8) {
			cout << "Clic fuera de los limites del tablero." << endl;
		}

		if (!flag && click == 1) {
			cas_origen = { columna, fila };
			flag = true;
			cout << "Casilla de origen: (" << cas_origen.x << ", " << cas_origen.y << ")" << endl;
		}
		else if (click == 2) {
			cas_destino = { columna, fila };
			if (cas_origen.x == cas_destino.x && cas_origen.y == cas_destino.y) {
				cout << "Origen y destino son iguales, seleccione otra casilla." << endl;
				cas_destino = { -1, -1 }; // Reiniciar casilla destino si es igual al origen
			}
			cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << endl;
			flag = false;
			click = 0;

			realizarMovimiento(p, cas_origen, cas_destino); // Llama a la función para realizar el movimiento deseado

			//Después de mover se reinicia la casilla origen
			cas_origen = { -1,-1 };
			flag = false;
		}
	}
}

void Tablero::realizarMovimiento(Pieza* p, casilla cas_origen, casilla cas_destino) {
	bool mov_valido = false;
	
	Tablero tabl;
	GestionJugadas mijugada(&tabl);

	//Si el movimiento realizado es incorrecto no cambia de turno hasta que el movimiento sea valido
	while (!mov_valido && tablero[cas_origen.y][cas_origen.x] != nullptr) {
		if ((p->getColor() == color::blanco && turno == true) || (p->getColor() == color::negro && turno == false)) {
			mov_valido = moverPieza(cas_origen, cas_destino);
			if (!mov_valido) {
				cout << "Movimiento no valido, intenta de nuevo." << endl;
				break;
			}
			else {

				color colOponente = (p->getColor() == color::blanco) ? color::negro : color::blanco;
				// Verificar jaque y jaque mate
				if (mijugada.jaque(colOponente, tablero) == true) {
					std::cout << "REY " << (colOponente == color::blanco ? "BLANCO" : "NEGRO") << " EN JAQUE" << std::endl;
					flagJaque = true;

					if (mijugada.jaque_mate(colOponente, tablero) == true) {
						// Verificar jaque 
						std::cout << "JAQUE MATE AL REY " << (colOponente == color::blanco ? "BLANCO" : "NEGRO") << std::endl;
						flagJaque = false;
						flagPromocion = false;
						flagEnroque = false;
						flagJaqueM = true;// Fin del juego
					}
					else {
						flagJaqueM = false;
					}
				}
				else {
					flagJaque = false;
				}

				//Verificar si el movimiento saca al rey del jaque
				color colJugador = p->getColor();
				if (mijugada.jaque(colJugador, tablero) == true ) {
					if (mijugada.reySaleDeJaque(colJugador, tablero) == false) {
						cout << "Movimiento no valido, el rey sigue en jaque." << endl;
						// Revertir el movimiento
						tablero[cas_origen.y][cas_origen.x] = p;
						tablero[cas_destino.y][cas_destino.x] = nullptr;
						flagJaque = true;
						continue;
					}
					else {
						flagJaque = false;
						flagJaqueM = false;
					}
				}

				// Comprobar si el movimiento es un enroque
				if (p->getTipo() == tipo::rey && (cas_destino.x - cas_origen.x) == 3) {
					mijugada.realizarEnroqueDerecha(p->getColor(), tablero);
					if (!mov_valido) {
						std::cout << "ENROQUE REALIZADO CORRECTAMENTE" << std::endl;
						flagEnroque = false;
					}
					else {
						std::cout << "ENROQUE NO REALIZADO CORRECTAMENTE. VUELVE A INTENTARLO" << std::endl;
					}
				}
				if (p->getTipo() == tipo::rey && (cas_destino.x - cas_origen.x) == -3) {
					mijugada.realizarEnroqueIzquierda(p->getColor(), tablero);
					if (!mov_valido) {
						std::cout << "ENROQUE REALIZADO CORRECTAMENTE" << std::endl;
						flagEnroque = false;
					}
					else {
						std::cout << "ENROQUE NO REALIZADO CORRECTAMENTE. VUELVE A INTENTARLO" << std::endl;
					}
				}

				//Comprobar promocion 
				if (mijugada.peonFinal(cas_destino) == true && p->getTipo() == tipo::peon) {
					mijugada.setFlagPromocion(true);
					usuario.setEstadoJuego(Usuario::PROMOCION);
					setCasillaDestino(cas_destino);
					usuario.teclado(tipoPromocion);
				}
				else {
					mijugada.setFlagPromocion(false);
				}
			}
			turno = !turno;
		}
		break;
	}
}

bool Tablero::moverPieza(casilla origen, casilla destino) {
	// Mover la pieza
	Pieza* piezaMovida = tablero[origen.y][origen.x]; // Tomar la pieza en la casilla de origen

	if (piezaMovida->movimientoValido(origen, destino, tablero) == true) {
		eliminarPieza(destino);
		tablero[destino.y][destino.x] = piezaMovida; // Colocar la pieza en la casilla de destino
		tablero[origen.y][origen.x] = nullptr; // Dejar la casilla de origen vacía
		cout << "Movimiento realizado de (" << origen.x << ", " << origen.y << ") a (" << destino.x << ", " << destino.y << ")" << endl;
		flagMovInvalido = false;
		return true;
	}
	else {
		ETSIDI::play("bin/sonidos/error.mp3");
		flagMovInvalido = true;
		return false;
	}
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
	//Iniciar todo el tablero a nullptr
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr;
		}
	}
	//Piezas blancas
	tablero[0][0]= new Torre(tipo::torre, color::blanco);
	tablero[0][1] = new Caballo(tipo::caballo, color::blanco);
	tablero[0][2] = new Arzobispo(tipo::arzobispo, color::blanco);
	tablero[0][3] = new Alfil(tipo::alfil, color::blanco);
	tablero[0][4] = new Reina(tipo::reina, color::blanco);
	tablero[0][5] = new Rey(tipo::rey, color::blanco);
	tablero[0][6] = new Alfil(tipo::alfil, color::blanco);
	tablero[0][7] = new Canciller(tipo::canciller, color::blanco);
	tablero[0][8] = new Caballo(tipo::caballo, color::blanco);
	tablero[0][9] = new Torre(tipo::torre, color::blanco);
	//Peones blancos 
	for (int i = 0; i < 10; i++) {
		tablero[1][i] = new Peon(tipo::peon, color::blanco);

	}
	//Peones negros
	for (int i = 0; i < 10; i++) {
		tablero[6][i] = new Peon(tipo::peon, color::negro);
	}

	//Piezas negras
	tablero[7][0] = new Torre(tipo::torre, color::negro);
	tablero[7][1] = new Caballo(tipo::caballo, color::negro);
	tablero[7][2] = new Arzobispo(tipo::arzobispo, color::negro);
	tablero[7][3] = new Alfil(tipo::alfil, color::negro);
	tablero[7][4] = new Reina(tipo::reina, color::negro);
	tablero[7][5] = new Rey(tipo::rey, color::negro);
	tablero[7][6] = new Alfil(tipo::alfil, color::negro);
	tablero[7][7] = new Canciller(tipo::canciller, color::negro);
	tablero[7][8] = new Caballo(tipo::caballo, color::negro);
	tablero[7][9] = new Torre(tipo::torre, color::negro);
}

void Tablero::getTablero(Pieza* tableroActual[max_y][max_x]) {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tableroActual[y][x] = this->tablero[y][x];  // Asume que `this->tablero` es tu matriz de piezas actual
		}
	}
}

void Tablero::eliminarPieza(casilla destino) {
	Pieza* piezaComida = tablero[destino.y][destino.x];

	if (piezaComida != nullptr) {
		ETSIDI::play("bin/sonidos/comer.mp3");

		delete piezaComida; // Eliminar la pieza del destino
		tablero[destino.y][destino.x] = nullptr; // Marcar la casilla de destino como vacía
	
	}
}

