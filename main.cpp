// Compilar y ejecutar:

// g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o taller && ./taller

#include <iostream>
// para mostrar  o leer informacion por consola
#include "include/Paciente.h"
#include "include/ColaPacientes.h"
#include "include/ArbolDecision.h"

using namespace std;

int main()
{

    Paciente paciente(1, "Ana", 25, 31.5, 120, 3, "cabeza", false, false, false, 0);

    Paciente paciente2(2, "Pedro", 32, 36.8, 120, 2, "otro", false, false, false, 0);

    Paciente paciente3(3, "Maria", 19, 37.0, 115, 4, "cabeza", false, false, false, 0);

    cout << "=====DATOS DEL PACIENTE =====" << endl;

    cout << "ID : " << paciente.getId() << endl;
    cout << "Nomnre : " << paciente.getNombre() << endl;
    cout << "Edad : " << paciente.getEdad() << endl;
    cout << "Temperatura : " << paciente.getTemperatura() << endl;
    cout << "Presion arterial : " << paciente.getPresionAreterial() << endl;
    cout << "Dolor : " << paciente.getDolor() << endl;
    cout << "Tpo de dolor : " << paciente.getTipoDolor() << endl;
    cout << "Trauma: " << paciente.getTrauma() << endl;
    cout << "Sintomas neurologicos : " << paciente.getSintomasNeurologicos() << endl;
    cout << "Requiere cirugia : " << paciente.getRequiereCirugia() << endl;
    cout << "Dias de hospitalizacion: " << paciente.getDiasHospitalizacion() << endl;

    // prueba de cola

    // Crear nuestra cola de pacientes
    ColaPacientes cola;

    // Agregar los pacientes a la cola
    cola.encolar(&paciente);
    cola.encolar(&paciente2);
    cola.encolar(&paciente3);

    cout << "Pacientes agregados a la cola" << endl;

    // Procesar los pacientes en orden FIFO
    while (true)
    {

        // Retirar al primer paciente
        Paciente *atendido = cola.desencolar();

        // Comprobar si la cola quedo vacia
        if (atendido == nullptr)
        {
            break;
        }

        // Mostrar al paciente retirado
        cout << "Paciente atendido: "
             << atendido->getNombre() << endl;
    }

    cout << "Todos los pacientes fueron retirados de la cola" << endl;

    ArbolDecision arbol;
    cout << "\nServicio de Ana: "
     << arbol.clasificar(paciente) << endl;
    cout << "=== RECORRIDO PREORDEN ===" << endl;
    arbol.mostrarPreorden();
    cout << "\n=== RECORRIDO INORDEN ===" << endl;
    arbol.mostrarInorden();

    cout << "\n=== RECORRIDO POSTORDEN ===" << endl;
    arbol.mostrarPostorden();

    Paciente pruebas[] = {
    Paciente(10, "Caso urgencias", 30, 39.0, 120,
             3, "otro", false, false, false, 0),

    Paciente(11, "Caso cirugia", 30, 37.0, 120,
             3, "otro", false, false, true, 0),

    Paciente(12, "Caso trauma", 30, 37.0, 120,
             3, "extremidad", true, false, false, 0),

    Paciente(13, "Caso neurologia", 30, 37.0, 120,
             3, "cabeza", false, true, false, 0),

    Paciente(14, "Caso cardiologia", 30, 37.0, 120,
             3, "pecho", false, false, false, 0),

    Paciente(15, "Caso pediatria", 10, 37.0, 120,
             3, "otro", false, false, false, 0),

    Paciente(16, "Caso hospitalizacion", 30, 37.0, 120,
             3, "otro", false, false, false, 3),

    Paciente(17, "Caso medicina general", 30, 37.0, 120,
             3, "otro", false, false, false, 0)
};

cout << "\n=== PRUEBAS DE CLASIFICACION ===" << endl;

for (int i = 0; i < 8; i++) {
    cout << pruebas[i].getNombre() << ": "
         << arbol.clasificar(pruebas[i]) << endl;
}

    return 0;
}
