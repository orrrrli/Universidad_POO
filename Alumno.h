#pragma once
#include<string>
#include"Kardex.h";
using std::string;
class Alumno
{
	int matricula;
	string nombre;
	string DOB = "";
	int semestre = 0;
	string carrera = "Tronco comun";
	Kardex kardex;
public:
	Alumno(int matricula, string nombre);
	//Getters y setters
	void SetNombre(string nm) { nombre = nm; };
	void SetDOB(string fn) { DOB = fn; };
	void SetSemestre(int s) { semestre = s; };
	void SetCarrera(string c) { carrera = c; };

	string GetNombre() { return nombre; };
	int GetMatricula() { return matricula; };
	Kardex& GetKardex() { return kardex; };
	int GetSemestre() { return semestre; };
	string GetCarrera() { return carrera; };
};

