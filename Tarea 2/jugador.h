#pragma once
#include <string>

using namespace std;
class jugador {
private:
	string nombre;
	char simbolo;
	int juegosGanados;
	int juegosPerdidos;
	int juegoEmpates;
	int juegosRealizados;

public:
	jugador();
	jugador(string, char);
	~jugador();
	string getNombre();
	char getSimbolo();
	int getJuegosGanados();
	int getJuegosPerdidos();
	int getJuegosEmapatados();
	int getJuegosRealizados();

	void setNombre(string);
	void setSimbolo(char);
	void setJuegosRealizados(int);

	void incrementarGanes();
	void incrementarDerrotas();
	int Empates(); //solo cuando una partida queda en un empate
};
