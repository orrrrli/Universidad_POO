#include "Opcion.h"
#include<iostream>
using std::cout;
using std::endl;

Opcion::Opcion(string nombre, char tecla, function<void()> accion)
{
	this->nombre = nombre;
	this->tecla = tecla;
	this->accion = accion;
}
void Opcion::Mostrar()
{
	// TODO: Add your implementation code here.
	if (tecla == 27)
		cout << "Esc";
	else
		cout << tecla;
	cout<< ") " << nombre << endl;
}

void Opcion::Ejecutar()
{
	// TODO: Add your implementation code here.
    //Ejecutamos la accion asociada
	accion();
}
