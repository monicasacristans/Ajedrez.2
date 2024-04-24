#include "Peon.h"
#include <iostream>
using namespace std;
Peon::Peon(tipo t, color c) :Pieza(t, c) {
	t = tipo::peon;
	c = color::blanco;
}

void Peon::dibuja() {
	
	cout << "PEON 1" << endl;
	
}
