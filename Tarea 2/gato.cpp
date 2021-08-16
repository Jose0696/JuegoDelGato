#include "gato.h"

gato::gato() {
	estado = '_';
}

char gato::getEstado() {
	return estado;
}

void gato::setEstado(char _estado) {
	estado = _estado;
}

gato::~gato() {}