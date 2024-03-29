#include "Peon.h"
#include "Tablero.h"

Peon::Peon(int value):value(value)
{
	int val;
	val=value;
}

void Peon::draw()
{

	if (value==-6) {
		peon_n.draw();
	}
	else if(value==6){
		peon_b.draw();

	}
}

