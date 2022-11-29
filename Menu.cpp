#include "Menu.h"
#include<iostream>
#include<conio.h>
using std::endl;
using std::cout;

Menu::Menu(string titulo)
{
	this->titulo = titulo;
}


void Menu::AgregarOpcion(Opcion op)
{
	// TODO: Add your implementation code here.
	opciones.insert(std::make_pair(op.GetTecla(), op));
}

void Menu::Mostrar()
{
	// TODO: Add your implementation code here.
	//Mostramos el titulo, y despues las opciones
	cout << titulo << endl;
	for (auto par : opciones)
		par.second.Mostrar();
}



char Menu::SeleccionarOpcion()
{
	// TODO: Add your implementation code here.
	char opsel;
	while (true) {
		cout << "Selecciona una opcion: ";
		opsel = _getch();
		//Buscamos la opcion en el mapa
		auto itop = opciones.find(opsel);
		if (itop == opciones.end())
			cout << "Opcion no valida..."<<endl;
		else {
			(*itop).second.Ejecutar();
			return opsel;
		}
	}
	return opsel;
}


void Menu::Ejecutar()
{
	// TODO: Add your implementation code here.
	do {
		system("cls");
		Mostrar();
	} while (SeleccionarOpcion() != exit_key);
}
