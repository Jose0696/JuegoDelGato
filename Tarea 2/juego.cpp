#include "juego.h"

juego::juego(){
	j1 = new jugador();
	j2 = new jugador();
}

juego::~juego(){
	delete j1;
	delete j2;
	delete g;
}

void juego::iniciarJuego(){
	string x = "si";
	int numjuego = 1;
	instruccionesGato();
	system("pause");
	system("cls");
	simboloJugador();

	while (x == "si"){
		cout << endl << "----------------------------- Partida numero: " << numjuego << "-------------------------------" << endl;
		j1->setJuegosRealizados(numjuego);
		j2->setJuegosRealizados(numjuego);
		realizarMovimientos();
		cout << endl << "\t\tDesean jugar nuevamente si o no ";
		cin >> x;

		system("cls");
		numjuego++; 
	}
	mostrarInfo();
}

void juego::instruccionesGato(){
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\tJUEGO DEL GATO" << endl;
	cout << "\-------------------------INSTRUCCIONES--------------------------------------------------------------------" << endl;
	cout << "\tDigite cada numero del 0 al 2 en cada fila y columna" << endl;
	cout << "\tLa fila indica con el simbolo (->) " << endl;
	cout << "\tLa Columna indica con el simbolo (!) " << endl;
	cout << "\tGana el que logre formar tres simbolos en linea ya sea vertical, horizontal o diagonal." << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
}

void juego::simboloJugador(){
	string nombre;
	char op;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tJUGADORES" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\tNombre del jugador 1: ";
	cin >> nombre;
	cout << endl;
	j1->setNombre(nombre);
	cout << "\tNombre del jugador 2: ";
	cin >> nombre;
	j2->setNombre(nombre);

	system("cls");
	do {
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "\tSeleccione el simbolo que desee utilizar " << j1->getNombre() << endl;
		cout << "\t1. X" << endl;
		cout << "\t2. O" << endl;
		cout << "    Opcion: "; cin >> op;
		cout << endl;
		cin.clear();
		cin.ignore();
	} while (op != '1' && op != '2');
	if (op == '1') {
		j1->setSimbolo('X');
		j2->setSimbolo('O');
	}
	else {
		j1->setSimbolo('O');
		j2->setSimbolo('X');
	}
	system("cls");
}

void juego::realizarMovimientos() {
	enJuego = true; //es verdadero cuando el juego empieza
	turno = 1; //van contando los turnos al momento de inicializar una nueva partida
	string cambianombre= j1->getNombre(); //cambia de nombre por cada turno
	int fila, col;
	mg = new matrizGato(); //se crea el constructor de un matriz
	mg->mostrar(); //muestra el resultado vacio
	while (enJuego) {
		g = new gato(); //inserta cada objeto gato dentro de la matriz
		cout << "\t\tEl turno de: " << cambianombre << endl;
		cout << "\t\tDigite la posicion a  jugar (0 al 2): " << endl;
		cout << "\t\t(->) Fila:";
		cin >> fila;
		cout << "\t\t(!) Columna: ";
		cin >> col;
		while (!estaVacia(fila,col)){
			cout << endl << endl;
			cout << "\t\t---Digite una posicion que sea vacia---" << endl;
			cout << "\t\t(->) Fila:";
			cin >> fila;
			cout << "\t\t(!) Cloumna: ";
			cin >> col;

		}
		if (turno == 1) {
			g->setEstado(j1->getSimbolo());
			cambianombre = j2->getNombre();
			
		}
		else{
			g->setEstado(j2->getSimbolo());
			cambianombre = j1->getNombre();
			
		}
		system("cls");
		mg->setGato(fila, col, g);
		cambiarTurno();
		enJuego = !finalizarJuego();
		mg->mostrar();
	}
	int id = mg->ganador(j1->getSimbolo(), j2->getSimbolo());

	if (id == 1) {
		cout << "\t\tEl ganador es: " << j1->getNombre() << endl;
		j1->incrementarGanes();
		j2->incrementarDerrotas();
	}
	else if (id == 2) {
		cout << "\t\tEl ganador es: " << j2->getNombre() << endl;
		j2->incrementarGanes();
		j1->incrementarDerrotas();
	}
	else {
		cout << "\t\tEMPATE " << endl;
	}
}

bool juego::estaVacia(int fil, int col){
	if (mg->getGato(fil, col)->getEstado() == '_') {
		return true;
	}
	return false;
}

void juego::cambiarTurno(){
	if (turno == 1) {
		turno = 2;
	}
	else {
		turno = 1;
	}
}

bool juego::finalizarJuego(){
	if (mg->finalizar()) {
		return true;
	}

	if (mg->ganador(j1->getSimbolo(), j2->getSimbolo()) == 0) {
		return false;
	}

	return true;
}

void juego::mostrarInfo(){
	cout << "-Nombre:" << j1->getNombre() << endl;
	cout << "\t -Juegos realizados:" << j1->getJuegosRealizados() << endl;
	cout << "\t -Juegos ganados:" << j1->getJuegosGanados() << endl;
	cout << "\t -Juegos perdidos:" << j1->getJuegosPerdidos() << endl;
	cout << "\t -Juegos empatados: " << j1->Empates() << endl << endl;

	cout << "-Nombre:" << j2->getNombre() << endl;
	cout << "\t -Juegos realizados:" << j2->getJuegosRealizados() << endl;
	cout << "\t -Juegos ganados:" << j2->getJuegosGanados() << endl;
	cout << "\t -Juegos perdidos:" << j2->getJuegosPerdidos() << endl;
	cout << "\t -Juegos empatados: " << j1->Empates() << endl << endl;

	if (j1->getJuegosGanados() > j2->getJuegosGanados())
	{
		cout << "El ganador es: " << j1->getNombre() << endl;
	}
	else
	{
		if (j1->getJuegosGanados() < j2->getJuegosGanados())
		{
			cout << endl << "El ganador es: " << j2->getNombre() << endl;
		}
		else
		{
			cout << endl << "****ES UN EMPATE****" << endl;
		}
	}
	cin.get();
}
