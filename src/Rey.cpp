#include "Rey.h"
#include "Tablero.h"

Rey::Rey(int value) :value(value)
{
	int val;
	val = value;
}

void Rey::draw()
{

	if (value == -4) {
		rey_n.draw();
	}
	else if (value == 4) {
		rey_b.draw();
	}
}