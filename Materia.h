#pragma once
#include<string>
using std::string;

class Materia
{
	int clave;
	int creditos;
	string nombre;
public:
	Materia(int clave, int creditos, string nombre);
    //Getters
	int GetClave() { return clave; };
	int GetCreditos() { return creditos; };
	string GetNombre() { return nombre; };
	string ToString();
};

