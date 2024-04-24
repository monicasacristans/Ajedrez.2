#include "Torre.h"
#include <iostream>


Torre::Torre(tipo t, color c) :Pieza(t, c) {
	t = tipo::torre;
	c = color::blanco;
}

void Torre::dibuja() {

std:: cout << "T";

}
