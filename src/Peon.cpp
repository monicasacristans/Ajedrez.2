#include "Peon.h"
#include <iostream>



Peon::Peon(tipo t, color c) :Pieza(t, c) {
	t = tipo::peon;
	c = color::blanco;
}

void Peon::dibuja() {

	std::cout << "P" ;
	
}
