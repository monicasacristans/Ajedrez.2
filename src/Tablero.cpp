#include "Tablero.h"
#include "Usuario.h"


using namespace std;
extern Usuario usuario;



//GestionJugadas jugada;


Tablero::Tablero() {

	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tablero[y][x] = nullptr; //Pieza crea una pieza vacia 
		}
	}
}

void Tablero::getTablero(Pieza* tableroActual[max_y][max_x]) {
	for (int y = 0; y < max_y; y++) {
		for (int x = 0; x < max_x; x++) {
			tableroActual[y][x] = this->tablero[y][x];  // Asume que `this->tablero` es tu matriz de piezas actual
		}
	}
}

Tablero::~Tablero(){}

void Tablero::definirCoordenadasTablero(int button, int state, int x, int y) {

	Pieza* p = checkPiezaEnCasilla(cas_origen);
	static int click = 0;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Calcular la columna y fila en funci�n de las coordenadas x e y
		int columna = ((x - 283) / 80);
		int fila = ((y - 64) / 80);
		click++;

		if (columna < 0 || columna >= 10 || fila < 0 || fila >= 8) {
			cout << "Clic fuera de los limites del tablero." << endl;
		}

		if (!flag && click == 2) {
			cas_origen = { columna, fila };
			flag = true;
			cout << "Casilla de origen: (" << cas_origen.x << ", " << cas_origen.y << ")" << endl;
		}
		else if (click == 3) {
			cas_destino = { columna, fila };
			if (cas_origen.x == cas_destino.x && cas_origen.y == cas_destino.y) {
				cout << "Origen y destino son iguales, seleccione otra casilla." << endl;
				cas_destino = { -1, -1 }; // Reiniciar casilla destino si es igual al origen
			}
			cout << "Casilla de destino: (" << cas_destino.x << ", " << cas_destino.y << ")" << endl;
			flag = false;
			click = 1;

			realizarMovimiento(p, cas_origen, cas_destino); // Llama a la funci�n para realizar el movimiento deseado
		}
	}
}

void Tablero::realizarMovimiento(Pieza* p, casilla cas_origen, casilla cas_destino) {
	bool mov_valido = false;
	Tablero tab;
	GestionJugadas mijugada(&tab);

	cout << piezasB.size() << " , " << piezasN.size() << endl;
	//cout << piezaseliminadas.size() << endl;
	//Si el movimiento realizado es incorrecto no cambia de turno hasta que el movimiento sea valido
	while (!mov_valido && tablero[cas_origen.y][cas_origen.x] != nullptr) {
		if ((p->getColor() == color::blanco && turno == true) || (p->getColor() == color::negro && turno == false)) {

			
			mov_valido = moverPieza(cas_origen, cas_destino);
			cout << piezasEliminadasB.size() << ", " << piezasEliminadasN.size() << endl;	
			if (!mov_valido) {
				cout << "Movimiento no valido, intenta de nuevo." << endl;
				break;
			}
			else {
				//comprobar promocion 
				if (mijugada.peonFinal(cas_destino) == true && p->getTipo() == tipo::peon) {
					mijugada.promocion(cas_destino, tablero);
					flagPromocion = true;
					//break;
				}

			/*	if (p->getTipo() == tipo::rey && abs(cas_destino.x - cas_origen.x) == 4) {
					mov_valido = mijugada.enroque(cas_origen, cas_destino, tablero);
					if (!mov_valido) {
						flagEnroque = true;
						cout << "ENROQUE NO VALIDO INTENTA DE NUEVO" << endl;
						break;
					}

					else {
						flagEnroque = false;
						cout << "ENROQUE REALIZADO CORRECTAMENTE" << endl;
					}*/

				color colOponente = (p->getColor() == color::blanco) ? color::negro : color::blanco;
				color colJug = (p->getColor() == color::blanco) ? color::blanco : color::negro;

				//comprobar enroque
			
					if (mijugada.verificarEnroque(colJug, tablero) == true) {
						std::cout << "ENROQUE ENTRE REY Y TORRE" << (colOponente == color::blanco ? "NEGROS" : "BLANCOS") << std::endl;
						flagEnroque = true;
						if (usuario.getenroqueActivado()) {
							mijugada.realizarEnroque(colJug, tablero);
							std::cout << "realizando enroque" << std::endl;
						}
					}
					else {
						flagEnroque = false;
					}
				// Verificar jaque mate
				if (mijugada.jaque(colOponente, tablero) == true) {
					std::cout <<  "REY" << (colOponente == color::blanco ? "BLANCO" : "NEGRO") << " EN JAQUE" << std::endl;
					flagJaque = true;
					//return;

					if (mijugada.jaque_mate(colOponente, tablero) == true) {
						// Verificar jaque 
						std::cout << "JAQUE MATE AL REY" << (colOponente == color::blanco ? "BLANCO" : "NEGRO") << std::endl;
						flagJaqueM = true;// Fin del juego
					}
					
				}
				else {
					flagJaque = false;
					flagJaqueM = false;
				}
					
				//Verificar si el movimiento saca al rey del jaque
				color colJugador = p->getColor();
				if (mijugada.jaque(colJugador, tablero) == true) {
					if (mijugada.reySaleDeJaque(colJugador, tablero) == true) {
						cout << "Movimiento no valido, el rey sigue en jaque." << endl;
						// Revertir el movimiento
						tablero[cas_origen.y][cas_origen.x] = p;
						tablero[cas_destino.y][cas_destino.x] = nullptr;
						flagJaque = true;
						continue;
					}
				}

				//verificar si el movimiento saca al rey del enroque
				/*if (!getTurno() && mijugada.verificarEnroque(colJug, tablero) == true) {
					if (p->getTipo() == tipo::rey) {
					//	mijugada.realizarEnroque(cas_origen, cas_destino, tablero);
					}
				}*/
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
		tablero[origen.y][origen.x] = nullptr; // Dejar la casilla de origen vac�a
		cout << "Movimiento realizado de (" << origen.x << ", " << origen.y << ") a (" << destino.x << ", " << destino.y << ")" << endl;
		flagMovInvalido = false;
		return true;
	}
	else {

		flagMovInvalido = true;
		return false;
	}
}


bool Tablero::getFinTurnoB() {
	if (turno == true) {
		return finturnob;
	}
	else {
		return !finturnob;
	}
}

bool Tablero::getFinTurnoN() {
	if (turno == true) {
		return !finturnon;
	}
	else {
		return finturnon;
	}
}

bool Tablero::getTurno() {
	return turno;
}

bool Tablero::getFlagMovValido() { //Flag para pintar los avisos
	return flagMovInvalido;
}

bool Tablero::getFlagJaque() {
	return flagJaque;
}

bool Tablero::getFlagJaqueM() {
	return flagJaqueM;
}

bool Tablero::getFlagPromocion() {
	return flagPromocion;
}

bool Tablero::getFlagEnroque() {
	return flagEnroque;
}


Pieza* Tablero::checkPiezaEnCasilla(casilla pos) {

	if (pos.x >= 0 && pos.x < max_x && pos.y >= 0 && pos.y < max_y) { //Comprueba que estamos dentro del tablero
		return tablero[pos.y][pos.x];  //Devuelve la pieza que hay en la casilla
	}
	else {
		// Si la casilla est� fuera del tablero, devuelve una pieza vac�a
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
		piezasB.push_back(tablero[0][i]);
		piezasB.push_back(tablero[1][i]);
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

	for (int i = 0; i < 10; i++) {
		piezasN.push_back(tablero[6][i]);
		piezasN.push_back(tablero[7][i]);
	}
}

void Tablero::eliminarPieza(casilla destino) {
	Pieza* piezaComida = tablero[destino.y][destino.x];

	if (piezaComida != nullptr) {
		auto& listapiezas = (piezaComida->getColor() == color::blanco) ? piezasB : piezasN;

		auto p = std::find(listapiezas.begin(), listapiezas.end(), piezaComida);

		if (p != listapiezas.end() && listapiezas ==piezasB) {
			listapiezas.erase(p);
			piezasEliminadasB.push_back(piezaComida);
		}
		else if (p != listapiezas.end() && listapiezas == piezasN) {
			listapiezas.erase(p);
			piezasEliminadasN.push_back(piezaComida);
		}

		delete piezaComida; // Eliminar la pieza del destino
		tablero[destino.y][destino.x] = nullptr; // Marcar la casilla de destino como vac�a
	}
}

