#include "jugador.h"

jugador::jugador() : simbolo(' ') {
	nombre = "indef";
	juegosGanados = 0;
	juegosPerdidos = 0;
	juegoEmpates = 0;
	juegosRealizados = 0;
}

jugador::jugador(string _nombre, char _simbolo) {
	nombre = _nombre;
	simbolo = _simbolo;
}

jugador::~jugador() {}

string jugador::getNombre() {
	return nombre;
}

char jugador::getSimbolo() {
	return simbolo;
}

int jugador::getJuegosGanados() {
	return juegosGanados;
}

int jugador::getJuegosPerdidos() {
	return juegosPerdidos;
}

int jugador::getJuegosEmapatados() {
	return juegoEmpates;
}

int jugador::getJuegosRealizados() {
	return juegosRealizados;
}

void jugador::setNombre(string _nombre) {
	nombre = _nombre;
}

void jugador::setSimbolo(char _simbolo) {
	simbolo = _simbolo;
}

void jugador::setJuegosRealizados(int n) {
	juegosRealizados = n;
}

void jugador::incrementarGanes() {
	juegosGanados++;
}

void jugador::incrementarDerrotas() {
	juegosPerdidos++;
}

int jugador::Empates() {
	return juegoEmpates = getJuegosRealizados() - getJuegosGanados() - getJuegosPerdidos();
}
