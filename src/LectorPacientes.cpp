
#include "LectorPacientes.h"
#include "Hospital.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

// Convertir un string a entero y verificar que
// todo el texto corresponda a un numero valido.
bool convertirEntero(const string& texto, int& numero)
{
    try
    {
        size_t posicion = 0;

        numero = stoi(texto, &posicion);

        if (posicion != texto.length())
        {
            return false;
        }

        return true;
    }
    catch (const exception&)
    {
        return false;
    }
}

// Convertir un string a decimal.
// Rechazar letras adicionales y valores infinitos.
bool convertirDecimal(const string& texto, double& numero)
{
    try
    {
        size_t posicion = 0;

        numero = stod(texto, &posicion);

        if (posicion != texto.length())
        {
            return false;
        }

        if (!isfinite(numero))
        {
            return false;
        }

        return true;
    }
    catch (const exception&)
    {
        return false;
    }
}

// Constructor
LectorPacientes::LectorPacientes()
{
}

// Verificar si el ID de un paciente ya fue cargado.
bool LectorPacientes::idRepetido(int id) const
{
    for (int i = 0; i < (int)pacientes.size(); i++)
    {
        if (pacientes[i]->getId() == id)
        {
            return true;
        }
    }

    return false;
}

// Cargar pacientes desde el archivo.
int LectorPacientes::cargarArchivo(
    const string& ruta,
    Hospital& hospital)
{
    ifstream archivo(ruta);

    // Verificar que el archivo exista.
    if (!archivo.is_open())
    {
        cout << "ERROR: No se pudo abrir "
             << ruta << endl;

        return 0;
    }

    string linea;
    int cargados = 0;
    int numeroLinea = 0;

    // Leer el archivo linea por linea.
    while (getline(archivo, linea))
    {
        numeroLinea++;

        // Eliminar retorno de carro si existe.
        if (!linea.empty() && linea.back() == '\r')
        {
            linea.pop_back();
        }

        // Ignorar lineas vacias.
        if (linea.empty())
        {
            continue;
        }

        // Arreglo para almacenar las partes de la linea.
        string partes[11];

        // Permite separar el texto de la linea.
        stringstream separador(linea);

        // Variable temporal para cada parte.
        string parte;

        int cantidad = 0;

        // Separar utilizando el caracter ';'.
        while (getline(separador, parte, ';'))
        {
            if (cantidad < 11)
            {
                partes[cantidad] = parte;
            }

            cantidad++;
        }

        // Contar el campo final vacio si termina en ';'.
        if (linea.back() == ';')
        {
            cantidad++;
        }

        // Cada paciente debe tener exactamente 11 partes.
        if (cantidad != 11)
        {
            cout << "Linea " << numeroLinea
                 << ": cantidad incorrecta de partes"
                 << endl;

            continue;
        }

        // Variables del paciente.
        int id = 0;
        int edad = 0;
        int presion = 0;
        int dolor = 0;
        int traumaNumero = 0;
        int neurologicoNumero = 0;
        int cirugiaNumero = 0;
        int dias = 0;

        double temperatura = 0.0;

        string nombre = partes[1];
        string tipoDolor = partes[6];

        // Comprobar las conversiones numericas.
        bool datosValidos = true;

        if (!convertirEntero(partes[0], id))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[2], edad))
        {
            datosValidos = false;
        }

        if (!convertirDecimal(partes[3], temperatura))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[4], presion))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[5], dolor))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[7], traumaNumero))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[8], neurologicoNumero))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[9], cirugiaNumero))
        {
            datosValidos = false;
        }

        if (!convertirEntero(partes[10], dias))
        {
            datosValidos = false;
        }

        if (!datosValidos)
        {
            cout << "Linea " << numeroLinea
                 << ": datos numericos invalidos"
                 << endl;

            continue;
        }

        // Validar los valores permitidos.
        if (id <= 0 ||
            nombre.empty() ||
            tipoDolor.empty() ||
            edad < 0 ||
            temperatura <= 0 ||
            presion <= 0 ||
            dolor < 0 ||
            dolor > 10 ||
            dias < 0)
        {
            cout << "Linea " << numeroLinea
                 << ": datos fuera de rango"
                 << endl;

            continue;
        }

        // Los indicadores solamente permiten 0 o 1.
        if ((traumaNumero != 0 && traumaNumero != 1) ||
            (neurologicoNumero != 0 && neurologicoNumero != 1) ||
            (cirugiaNumero != 0 && cirugiaNumero != 1))
        {
            cout << "Linea " << numeroLinea
                 << ": los indicadores deben ser 0 o 1"
                 << endl;

            continue;
        }

        // Evitar ID duplicados.
        if (idRepetido(id) ||
            hospital.buscarPorId(id) != nullptr)
        {
            cout << "Linea " << numeroLinea
                 << ": ID duplicado " << id
                 << endl;

            continue;
        }

        // Convertir los indicadores a bool.
        bool trauma = traumaNumero == 1;
        bool neurologico = neurologicoNumero == 1;
        bool cirugia = cirugiaNumero == 1;

        // Crear el paciente.
        Paciente* nuevo = new Paciente(
            id,
            nombre,
            edad,
            temperatura,
            presion,
            dolor,
            tipoDolor,
            trauma,
            neurologico,
            cirugia,
            dias
        );

        // Guardar el paciente en el lector.
        try
        {
            pacientes.push_back(nuevo);
        }
        catch (...)
        {
            delete nuevo;
            throw;
        }

        // Agregar el paciente a la cola del hospital.
        try
        {
            hospital.agregarPaciente(nuevo);
        }
        catch (...)
        {
            pacientes.pop_back();
            delete nuevo;
            throw;
        }

        cargados++;

        cout << "Paciente cargado: "
             << nombre
             << " (ID " << id << ")"
             << endl;
    }

    cout << "\nTotal de pacientes cargados: "
         << cargados << endl;

    return cargados;
}

// Liberar los objetos Paciente creados por el lector.
LectorPacientes::~LectorPacientes()
{
    for (int i = 0; i < (int)pacientes.size(); i++)
    {
        delete pacientes[i];
    }
}

