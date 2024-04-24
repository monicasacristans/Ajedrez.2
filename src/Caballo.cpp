#include "Caballo.h"
#include <iostream>



Caballo::Caballo(tipo t, color c) :Pieza(t, c) {
	t = tipo::caballo;
	c = color::blanco;
}

void Caballo::dibuja() {

	std::cout << "C";

}
