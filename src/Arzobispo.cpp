#include "Arzobispo.h"
#include "Tablero.h"

Arzobispo::Arzobispo(int value) :value(value)
{
	int val;
	val = value;
}

void Arzobispo::draw()
{

	if (value == -7) {
		//arzobispo_n.draw();
	}
	else if (value == 7) {
		//arzobispo_b.draw();
	}
}

