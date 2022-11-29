#pragma once
#include<list>
#include"Calificacion.h"

using std::list;
class Alumno;
class Kardex
{
	float promedio = 0.0f;
	//Lista de calificaciones
	list<Calificacion> califs;
	Alumno* prop=nullptr; //Propietario del kardex
public:

	void RegistrarCalificacion(Calificacion calif);
	float GetPromedio() { return promedio; };
	void SetPropietario(Alumno* pr) { prop = pr; };
	Alumno* GetPropietario() { return prop; };
	string ToString();
};

