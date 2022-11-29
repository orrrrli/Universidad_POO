#pragma once
#include<string>
#include"Materia.h"
using std::string;
class Calificacion
{
	int valor;
	string semestre;
	Materia* materia;
public:
	Calificacion(Materia *materia,int valor, string semestre); 
	//Setters y getters
	void SetValor(int nv) { valor = nv; };
	void SetSemestre(string sm) { semestre = sm; };
	int GetValor() { return valor; };
	string GetSemestre() { return semestre; };
	//
	string ToString();
};

