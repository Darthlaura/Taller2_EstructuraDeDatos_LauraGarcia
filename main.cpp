//// Compilar y ejecutar:
// g++ -std=c++17 -Wall -Wextra main.cpp src/Persona.cpp src/Paciente.cpp -o taller && ./taller
#include <iostream>
//para mostrar  o leer informacion por consola
#include "include/Paciente.h"

using namespace std; 

int main() {



    Paciente paciente(1,"Ana", 25, 31.5,120,3,"cabeza", false, false, false,0); 


    cout << "=====DATOS DEL PACIENTE =====" << endl; 
   
    cout << "ID : " << paciente.getId() << endl; 
    cout << "Nomnre : " << paciente.getNombre() << endl; 
    cout << "Edad : " <<paciente.getEdad() << endl; 
    cout << "Temperatura : " <<paciente.getTemperatura() << endl; 
    cout << "Presion arterial : " <<paciente.getPresionAreterial() <<endl; 
    cout << "Dolor : " <<paciente.getTrauma() <<endl; 
    cout << "Tpo de dolor : " <<paciente.getTipoDolor() << endl; 
    cout << "Trauma: " << paciente.getTrauma() << endl; 
    cout << "Sintomas neurologicos : " << paciente.getSintomasNeurologicos() << endl; 
    cout << "Requiere cirugia : " << paciente.getRequiereCirugia() << endl; 
    cout << "Dias de hospitalizacion: "  << paciente.getDiasHospitalizacion() << endl; 
    
     return 0; 
}
