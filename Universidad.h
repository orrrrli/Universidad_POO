#pragma once
#include<string>
#include<map>
#include"Alumno.h"
#include"Materia.h"
using std::string;
using std::map;

class Universidad
{
	string nombre;
	string cce; //clave de centro educativo
	map<int, Alumno *> alumnos;
	map<int, Materia *> materias;
	int cmatricula = 111111;
	int cmateria = 40000;
public:
	Universidad(string nombre = "UABC", string cce = "pirata");
	~Universidad();
	int RegistrarAlumno(string nombre, string DOB, string carrera);

	Alumno* GetAlumno(int matricula);
	string ReporteAlumnos();
	bool RegistrarCalificacion(int matricula, int cmateria, int valor);

	int RegistrarMateria(string nombre, int creditos);
	Materia* GetMateria(int clave);
	string ReporteMaterias();

};
	

