#include "Canciller.h"
#include "Tablero.h"

Canciller::Canciller(int value) :value(value)
{
	int val;
	val = value;
}

void Canciller::draw()
{

	if (value == -3) {
		//canciller_n.draw();
	}
	else if (value == 3) {
		//canciller_b.draw();
	}
}