#pragma once
#include "matrizGato.h"
#include "jugador.h"

class juego{
private:
	jugador* j1;
	jugador* j2;
	matrizGato* mg;
	gato* g;
	bool enJuego; //el resultado es verdadero cuando el juego inicia
	int turno; //interactua los turnos

public:
	juego();
	~juego();
	void iniciarJuego(); //inicia las partidas la cantidad de n veces necesarias
	void instruccionesGato(); 
	void simboloJugador(); //llena los datos de los jugadores y el simbolo a escoger
	void realizarMovimientos(); //la interaccion y usabilidad del programa
	bool estaVacia(int, int); //inserta el estado cuando el resultado es verdadero 
	void cambiarTurno(); //cambia los turnos cada estado que se insertan
	bool finalizarJuego(); //llama a la matriz cuando el juego finaliza
	void mostrarInfo(); //la informacion de todas las partidas realizadas, victorias, derrotas y empates
};

