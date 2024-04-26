#include "Canciller.h"
#include <iostream>


Canciller::Canciller(tipo t, color c) :Pieza(t, c) {
	t = tipo::canciller;
	c = color::blanco;
}

