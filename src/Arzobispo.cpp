#include "Arzobispo.h"
#include <iostream>



Arzobispo::Arzobispo(tipo t, color c) :Pieza(t, c) {
	t = tipo::arzobispo;
	c = color::blanco;
}

void Arzobispo::dibuja() {

	std::cout << "Z";

}
