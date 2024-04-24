#include "Rey.h"
#include <iostream>



Rey::Rey(tipo t, color c) :Pieza(t, c) {
	t = tipo::rey;
	c = color::blanco;
}

void Rey::dibuja() {

	std::cout << "R";

}
