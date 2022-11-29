#include "Alumno.h"

Alumno::Alumno(int matricula, string nombre)
{
	this->matricula = matricula;
	this->nombre = nombre;
	kardex.SetPropietario(this);
}
