
#include "Hospital.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Hospital::Hospital()
{
}

// Seleccionar el AVL correspondiente
ArbolAVL *Hospital::obtenerArbol(const string &servicio)
{
    if (servicio == "Urgencias")
    {
        return &urgencias;
    }

    if (servicio == "Medicina General")
    {
        return &medicinaGeneral;
    }

    if (servicio == "Cardiologia")
    {
        return &cardiologia;
    }

    if (servicio == "Neurologia")
    {
        return &neurologia;
    }

    if (servicio == "Traumatologia")
    {
        return &traumatologia;
    }

    if (servicio == "Cirugia")
    {
        return &cirugia;
    }

    if (servicio == "Pediatria")
    {
        return &pediatria;
    }

    if (servicio == "Hospitalizacion")
    {
        return &hospitalizacion;
    }

    throw logic_error("Servicio no reconocido");
}

// Agregar paciente a la cola
void Hospital::agregarPaciente(Paciente *paciente)
{
    if (paciente == nullptr)
    {
        throw invalid_argument("Paciente nulo");
    }

    cola.encolar(paciente);
}

// atender pacientes en orden FIFO
void Hospital::atenderPacientes()
{
    Paciente *paciente = cola.desencolar();

    while (paciente != nullptr)
    {
        string servicio = decision.clasificar(*paciente);

        ArbolAVL *arbol = obtenerArbol(servicio);

        arbol->insertar(paciente);

        cout << "Paciente: " << paciente->getNombre() << endl;

        cout << "Servicio asignado: " << servicio << endl;

        cout << "Insertado en el AVL de " << servicio << endl;

        cout << "------------------------" << endl;

        paciente = cola.desencolar();
    }
}

// mostrar departamentos
void Hospital::mostrarDepartamentos()
{
    cout << "\n=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;

    cout << "\nUrgencias:" << endl;
    urgencias.mostrarInorden();

    cout << "\nMedicina General:" << endl;
    medicinaGeneral.mostrarInorden();

    cout << "\nCardiologia:" << endl;
    cardiologia.mostrarInorden();

    cout << "\nNeurologia:" << endl;
    neurologia.mostrarInorden();

    cout << "\nTraumatologia:" << endl;
    traumatologia.mostrarInorden();

    cout << "\nCirugia:" << endl;
    cirugia.mostrarInorden();

    cout << "\nPediatria:" << endl;
    pediatria.mostrarInorden();

    cout << "\nHospitalizacion:" << endl;
    hospitalizacion.mostrarInorden();
}

// buscar por ID en todos los servicios
Paciente *Hospital::buscarPorId(int id)
{
    Paciente *paciente = nullptr;

    paciente = urgencias.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }

    paciente = medicinaGeneral.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }
    paciente = cardiologia.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }
    paciente = neurologia.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }

    paciente = traumatologia.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }
    paciente = cirugia.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }
    paciente = pediatria.buscarPorId(id);
    if (paciente != nullptr)
    {
        return paciente;
    }

    return hospitalizacion.buscarPorId(id);
}

// Buscar por nombre en todos los servicios
Paciente *Hospital::buscarPorNombre(const string &nombre)
{
    Paciente *paciente = nullptr;

    paciente = urgencias.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }
    paciente = medicinaGeneral.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }

    paciente = cardiologia.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }
    paciente = neurologia.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }

    paciente = traumatologia.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }

    paciente = cirugia.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }

    paciente = pediatria.buscarPorNombre(nombre);
    if (paciente != nullptr)
    {
        return paciente;
    }

    return hospitalizacion.buscarPorNombre(nombre);
}
