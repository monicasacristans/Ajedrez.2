#include "Alfil.h"
#include "Tablero.h"

Alfil::Alfil(int value) :value(value)
{
	int val;
	val = value;
}

void Alfil::draw()
{

	if (value == -4) {
		alfil_n.draw();
	}
	else if (value == 4) {
		alfil_b.draw();
	}
}