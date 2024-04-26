#include "Alfil.h"
#include <iostream>

Alfil::Alfil(tipo t, color c) :Pieza(t, c) {
	t = tipo::alfil;
	c = color::blanco;
}

