#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class gato {
private:
	char estado;
public:
	gato();
	char getEstado();
	void setEstado(char);
	~gato();
};
