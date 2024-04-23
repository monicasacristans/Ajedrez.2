#include "Peon.h"

Peon::Peon() {
	if (obtenerRepresentacion() == 'P') {
		peon_n.draw();
	}
}