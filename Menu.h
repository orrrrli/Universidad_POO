#pragma once
#include"Opcion.h"
#include<map>
using std::map;

class Menu
{
	string titulo;
	map<char, Opcion> opciones;
	char exit_key = 27;
public:
	Menu(string titulo = "Menu");
	void AgregarOpcion(Opcion op);
	void Mostrar();
	char SeleccionarOpcion();
	void SetExitKey(char ek) { exit_key = ek; };
	void Ejecutar();
};

