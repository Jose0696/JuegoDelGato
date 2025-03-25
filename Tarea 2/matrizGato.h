#pragma once
#include"gato.h"
class matrizGato {
private:
	gato* matriz[3][3];

public:
	matrizGato();
	~matrizGato();
	void setGato(int, int, gato*);
	gato* getGato(int, int);

	bool finalizar(); //la matriz termina de llenar cuando es verdadero
	int ganador(char, char); //insertan los simbolos
	void mostrar(); // muestra el resultado de cada movimiento 
};

