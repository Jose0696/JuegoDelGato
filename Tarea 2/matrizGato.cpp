#include "matrizGato.h"

matrizGato::matrizGato() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = new gato();
			matriz[i][j]->setEstado('_');
		}
	}
}

matrizGato::~matrizGato() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matriz[i][j] != nullptr) {
				delete matriz[i][j];
			}
		}
	}
}

void matrizGato::setGato(int i, int j, gato* g) {
	matriz[i][j] = g;
}

gato* matrizGato::getGato(int i, int j) {
	return matriz[i][j];
}

bool matrizGato::finalizar() {
	int f = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matriz[i][j]->getEstado() == '_') {
				return false;
			}
		}
	}
	return true;
}

int matrizGato::ganador(char a, char b) {
	int fi, col, dg1 = 0, dg2 = 0;
	for (int i = 0; i < 3; i++)
	{
		fi = 0;
		col = 0;
		if (matriz[i][i]->getEstado() == a)
			dg1++;
		if (matriz[2 - i][i]->getEstado() == a)
			dg2++;
		for (int j = 0; j < 3; j++)
		{
			if (matriz[i][j]->getEstado() == a)
				fi++;
			if (matriz[j][i]->getEstado() == a)
				col++;
			if (fi == 3)
				return 1;
			if (col == 3)
				return 1;
		}
	}
	if (dg1 == 3)
		return 1;
	if (dg2 == 3)
		return 1;

	dg1 = 0, dg2 = 0;
	for (int i = 0; i < 3; i++)
	{
		fi = 0;
		col = 0;
		if (matriz[i][i]->getEstado() == b)
			dg1++;
		if (matriz[2 - i][i]->getEstado() == b)
			dg2++;
		for (int j = 0; j < 3; j++)
		{
			if (matriz[i][j]->getEstado() == b)
				fi++;
			if (matriz[j][i]->getEstado() == b)
				col++;
			if (fi == 3)
				return 2;
			if (col == 3)
				return 2;
		}
	}
	if (dg1 == 3)
		return 2;
	if (dg2 == 3)
		return 2;

	return 0;
}

void matrizGato::mostrar() {
	cout << "\t\t\t\t\t ! ! !" << endl;
	cout << "\t\t\t\t\t _ _ _ " << endl;
	for (int i = 0; i < 3; i++) {

		cout << "\t\t\t\t     -> |";
		for (int j = 0; j < 3; j++) {
			cout << matriz[i][j]->getEstado() << "|";
		}
		cout << endl;
	}
}
