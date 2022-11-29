#include "Universidad.h"

Universidad::Universidad(string nombre, string cce)
{
	this->nombre = nombre;
	this->cce = cce;
}

Universidad::~Universidad()
{
	//borramos todos los alumnos que quedan en el mapa
	for (auto p : alumnos)
		delete p.second;
	for (auto p : materias)
		delete p.second;
}


int Universidad::RegistrarAlumno(string nombre, string DOB, string carrera)
{
	// TODO: Add your implementation code here.
	Alumno *al=new Alumno(cmatricula, nombre);
	al->SetDOB(DOB);
	al->SetCarrera(carrera);
	alumnos.insert(std::make_pair(cmatricula, al));
	cmatricula++;
	return cmatricula-1;
}

Alumno* Universidad::GetAlumno(int matricula)
{
	// TODO: Add your implementation code here.
	//Necesitas buscar al alumno en el mapa
	auto it=alumnos.find(matricula);
	if (it != alumnos.end()) {
		return (*it).second;
	}
	return nullptr;
}


string Universidad::ReporteAlumnos()
{
	// TODO: Add your implementation code here.
	string reporte = "Matricula\tNombre\n---------------------------------------------------\n";
	char mstr[1024];
	for (auto p : alumnos) {
		sprintf_s(mstr, 1023, "%d\t%s\n", p.first, p.second->GetNombre().c_str());
		reporte = reporte + string(mstr);
	}
	return reporte;
}


bool Universidad::RegistrarCalificacion(int matricula, int cmateria, int valor)
{
	// TODO: Add your implementation code here.
	//verificar si existe el alumno
	if (alumnos.find(matricula) == alumnos.end())
		//return false;
		throw "Alumno no existente";
	//verificar si existe la materia
	if (materias.find(cmateria) == materias.end())
		throw "Materia no existente";
	if (valor < 0)
		throw "Valor de calificacion no valido";
	Calificacion calif(materias[cmateria], valor, "2022-2");
	alumnos[matricula]->GetKardex().RegistrarCalificacion(calif);
	return true;
}

int Universidad::RegistrarMateria(string nombre, int creditos)
{
	Materia* materia = new Materia(cmateria, creditos, nombre);
	auto par = std::make_pair(cmateria, materia);
	materias.insert(par);
	cmateria++;
	return cmateria-1;
}

Materia* Universidad::GetMateria(int clave)
{
	auto it = materias.find(clave);
	if (it != materias.end()) {
		return materias[clave];
	}
	return nullptr;
}

string Universidad::ReporteMaterias()
{
	string rstr = "Clave\tCreditos\tNombre\n----------------------------------------------------\n";
	for (auto p : materias) {
		rstr = rstr + p.second->ToString() + "\n";
	}
	return rstr;
}
