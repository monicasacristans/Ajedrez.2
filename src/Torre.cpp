#include "Torre.h"
#include "Tablero.h"

Torre::Torre(int value) :value(value)
{
	int val;
	val = value;
}

void Torre::draw()
{

	if (value == -1) {
		//torre_n.setPos(pos.x, pos.y);
		torre_n.draw();
		
	}
	else if (value == 1) {
	//orre_b.setPos(pos.x, pos.y);
		torre_b.draw();

	}
}



