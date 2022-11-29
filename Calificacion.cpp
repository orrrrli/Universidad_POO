#include "Calificacion.h"

Calificacion::Calificacion(Materia* materia,int valor, string semestre)
{
	this->materia = materia;
	this->valor = valor;
	this->semestre = semestre;
}

string Calificacion::ToString()
{
	char str[1024];
	//Falta incluir informacion de la materia
	sprintf_s(str,1023, "%s\t%d\t%d\t%s", semestre.c_str(), 
		valor,materia->GetClave(),materia->GetNombre().c_str());
	return string(str);
}
