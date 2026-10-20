
#include <iostream>
#include "Paciente.h"
#include "Hospital.h"

using namespace std;

int main()
{
    cout << "===== HOSPITAL MARMAJA =====" << endl;

    Hospital hospital;

    // Crear pacientes de prueba
    Paciente ana(50, "Ana", 25, 37.0, 120, 3,
                 "otro", false, false, false, 0);

    Paciente pedro(30, "Pedro", 35, 39.0, 120, 8,
                   "cabeza", false, false, false, 0);

    Paciente maria(40, "Maria", 10, 36.5, 110, 2,
                   "otro", false, false, false, 0);

    // Agregar a la cola
    hospital.agregarPaciente(&ana);
    hospital.agregarPaciente(&pedro);
    hospital.agregarPaciente(&maria);

    // Procesar pacientes
    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;

    hospital.atenderPacientes();

    // Mostrar los ocho servicios
    hospital.mostrarDepartamentos();

    // Buscar paciente por ID
    cout << "\n=== BUSQUEDA POR ID ===" << endl;

    Paciente* encontrado = hospital.buscarPorId(30);

    if (encontrado != nullptr)
    {
        cout << "Paciente encontrado: "
             << encontrado->getNombre() << endl;
    }
    else
    {
        cout << "Paciente no encontrado" << endl;
    }

    // Buscar paciente por nombre
    cout << "\n=== BUSQUEDA POR NOMBRE ===" << endl;

    encontrado = hospital.buscarPorNombre("Maria");

    if (encontrado != nullptr)
    {
        cout << "ID encontrado: "
             << encontrado->getId() << endl;
    }
    else
    {
        cout << "Paciente no encontrado" << endl;
    }

    cout << "\n=== FIN DE PRUEBA HOSPITAL ===" << endl;

    return 0;
}
