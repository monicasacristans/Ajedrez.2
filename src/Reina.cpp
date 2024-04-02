#include "Reina.h"
#include "Tablero.h"

Reina::Reina(int value) :value(value)
{
	int val;
	val = value;
}

void Reina::draw()
{

	if (value == -6) {
		reina_n.draw();
	}
	else if (value == 6) {
		reina_b.draw();
	}
}