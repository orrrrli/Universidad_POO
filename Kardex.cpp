#include "Kardex.h"
#include"Alumno.h"

void Kardex::RegistrarCalificacion(Calificacion calif)
{
	promedio = (promedio * califs.size());
	promedio =   (promedio+ calif.GetValor()) / (califs.size() + 1);
	califs.push_back(calif);
	//calculamos el promedio
	/*float sum = 0;
	for (Calificacion& cal : califs)
		sum += cal.GetValor();
	promedio = sum / califs.size();
	*/
}

string Kardex::ToString()
{
	// TODO: Add your implementation code here.
	char aux[4096]="";
	if (prop != nullptr) {
		sprintf_s(aux,4095, "Matricula: %d\nNombre: %s\n Semestre: %d\nCarrera: %s\nPromedio: %.2f",
			prop->GetMatricula(), prop->GetNombre().c_str(),
			prop->GetSemestre(), prop->GetCarrera().c_str(),promedio);
	}
	string str(aux);
	str = str + "\nSem\tvalor\tclave\tnombre\n-------------------------------------------------\n";
	for(Calificacion &cal:califs){
		str = str + "\n" + cal.ToString();
	}
	return str;
}
