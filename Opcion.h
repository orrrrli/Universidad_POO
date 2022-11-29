#pragma once
#include<string>
#include<functional>
using std::string;
using std::function;
class Opcion
{
	string nombre;
	char tecla;
	function<void()> accion;
public:
	Opcion(string nombre, char tecla, function<void()> accion);
	void Mostrar();
	void Ejecutar();
	//Implentacion "Inline" del
	//getter de tecla
	char GetTecla() { return tecla; };
};

