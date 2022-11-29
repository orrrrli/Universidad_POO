#include "Materia.h"

Materia::Materia(int clave, int creditos, string nombre)
{
	this->clave = clave;
	this->creditos = creditos;
	this->nombre = nombre;
}

string Materia::ToString()
{
	char matstr[1024];
	sprintf_s(matstr, 1023, "%d\t%d\t", clave, creditos);
	string mstr = string(matstr) + nombre;
	return mstr;
}
