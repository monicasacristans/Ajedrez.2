#include "Reina.h"
#include <iostream>



Reina::Reina(tipo t, color c) :Pieza(t, c) {
	t = tipo::reina;
	c = color::blanco;
}

