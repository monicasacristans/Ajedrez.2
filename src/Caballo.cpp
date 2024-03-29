#include "Caballo.h"
#include "Tablero.h"

Caballo::Caballo(int value) :value(value)
{
	int val;
	val = value;
}

void Caballo::draw()
{

	if (value == -2) {
		caballo_n.draw();
	}
	else if (value == 2) {
		caballo_b.draw();
	}
}