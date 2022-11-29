// ProyectoUniversidad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Menu.h"
#include"Universidad.h"
#include<conio.h>

using std::cout;
using std::cin;
using std::endl;

Universidad uni;
void Inicializar() {
    //Agregamos materias
    uni.RegistrarMateria("Calculo Diferencial", 7);
    uni.RegistrarMateria("Algebra Superior",7);
    uni.RegistrarMateria("Metodologia de la programacion",4);
    uni.RegistrarMateria("Comunicacion Oral y Escrita",5);
    uni.RegistrarMateria("Introduccion a la Ingenieria",4 );
    uni.RegistrarMateria("Ingles I",5);
    uni.RegistrarMateria("Programacion y metodos numericos",8);
    uni.RegistrarMateria("Calculo Integral",7);
    uni.RegistrarMateria("Mecanica vectorial",8);
    uni.RegistrarMateria("Quimica",6);
    uni.RegistrarMateria("Probabilidad y Estadistica",7);
    uni.RegistrarMateria("Ingles II",5);
    uni.RegistrarMateria("Programacion Estructurada",4);
    uni.RegistrarMateria("Matematicas Discretas",6);
    uni.RegistrarMateria("Organizacion de Computadoras",6);
    uni.RegistrarMateria("Lenguaje C",4);

    

    
    //Agregamos alumnos de prueba
    int m=uni.RegistrarAlumno("Espergencia McGregor", "NA", "Tronco Comun");
    uni.RegistrarCalificacion(m, 40000, 90);
    uni.RegistrarCalificacion(m, 40001, 100);
    uni.RegistrarCalificacion(m, 40002, 95);
    uni.RegistrarCalificacion(m, 40003, 99);

    uni.RegistrarAlumno("Sosimo Figueroa", "10/10/2002", "Ing. De Software");
    uni.RegistrarAlumno("Nicasio Perez", "01/02/2001", "Ing. Electronica");
}
void ConsultarAlumno() {
    int matricula;
    system("cls");
    cout << "Consultar alummo" << endl;
    cout << "Matricula: ";
    cin >> matricula;
    Alumno* al = uni.GetAlumno(matricula);
    if (al == nullptr) {
        cout << "No existe un alumno con la matricula " << matricula << endl;
        _getch();
        return;
    }
    //Imprimimos la informacion del alumno
    cout << "Matricula: " << matricula<<endl;
    cout << "Nombre: " << al->GetNombre() << endl;
    cout << "Carrera: " << al->GetCarrera() << endl;
    cout << "Semestre: " << al->GetSemestre()<<endl;
    cout << "Promedio: " << al->GetKardex().GetPromedio() << endl;
    _getch();

}

void ImprimirReporteAlumnos(){

    system("cls");
    cout << "Reporte de alumnos\n\n";
    cout << uni.ReporteAlumnos() << endl;
    _getch();
}
void ConsultarKardex() {
    int matricula;
    system("cls");
    cout << "Consultar kardex" << endl;
    cout << "Matricula: ";
    cin >> matricula;
    Alumno* al = uni.GetAlumno(matricula);
    if (al == nullptr) {
        cout << "No existe un alumno con la matricula " << matricula << endl;
        _getch();
        return;
    }
    cout << al->GetKardex().ToString() << endl;
    _getch();
}
void RegistrarCalif() {
    int matricula, cmateria, valor;
    system("cls");
    cout << "Matricula del estudiante: ";
    cin >> matricula;
    cout << "Clave de materia: ";
    cin >> cmateria;
    cout << "Calificacion: ";
    cin >> valor;
    try {
        uni.RegistrarCalificacion(matricula, cmateria, valor);
        cout << "Calificacion registrada" << endl;
    }
    catch (const char* err) {
        cout << "Error registrando calificacion: " << err << endl;
    }
    
    _getch();
}
void ImprimirReporteMaterias() {

    system("cls");
    cout << "Reporte de Materias\n\n";
    cout << uni.ReporteMaterias() << endl;
    _getch();
}
int main()
{
    Inicializar();
    Menu menu("Super sistema universitario");
    menu.AgregarOpcion(Opcion("Reporte de alumnos", '1', ImprimirReporteAlumnos));
    menu.AgregarOpcion(Opcion("Consultar alumno", '2', ConsultarAlumno));
    menu.AgregarOpcion(Opcion("Consultar kardex", '3', ConsultarKardex));
    menu.AgregarOpcion(Opcion("Registrar calificacion", '4', RegistrarCalif));
    menu.AgregarOpcion(Opcion("Reporte de materias", '5', ImprimirReporteMaterias));
    menu.AgregarOpcion(Opcion("Salir", 27, []() {cout << "Adios..." << endl; }));

    menu.Ejecutar();
    
}

