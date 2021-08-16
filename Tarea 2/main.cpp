#include "juego.h"

int main() {
	juego* j = new juego;
	j->iniciarJuego();
	delete j;
	cin.get();
	return 0;
}

