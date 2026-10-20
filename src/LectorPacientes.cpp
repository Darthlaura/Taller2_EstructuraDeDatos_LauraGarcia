
#include "LectorPacientes.h"
#include "Hospital.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

LectorPacientes::LectorPacientes()
{
}

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

int LectorPacientes::cargarArchivo( const string& ruta,Hospital& hospital)
{
    ifstream archivo(ruta);

    if (!archivo.is_open())
    {
        cout << "ERROR: No se pudo abrir " << ruta << endl;
        return 0;
    }

    string linea;
    int cargados = 0;
    int numeroLinea = 0;

    while (getline(archivo, linea))
    {
        numeroLinea++;

        if (linea.empty())
        {
            continue;
        }

        string campos[11];
        stringstream separador(linea);
        string campo;

        int cantidad = 0;

        while (getline(separador, campo, ';'))
        {
            if (cantidad < 11)
            {
                campos[cantidad] = campo;
            }

            cantidad++;
        }

        if (cantidad != 11)
        {
            cout << "Linea " << numeroLinea << ": cantidad incorrecta de campos"  << endl;
            continue;
        }

        try
        {
            int id = stoi(campos[0]);
            string nombre = campos[1];
            int edad = stoi(campos[2]);
            double temperatura = stod(campos[3]);
            int presion = stoi(campos[4]);
            int dolor = stoi(campos[5]);
            string tipoDolor = campos[6];

            // Las condiciones booleanas usan 0 o 1.
            int traumaNumero = stoi(campos[7]);
            int neurologicoNumero = stoi(campos[8]);
            int cirugiaNumero = stoi(campos[9]);

            int dias = stoi(campos[10]);

            if (id <= 0 || nombre.empty() || edad < 0 || temperatura <= 0 || presion <= 0 || dolor < 0 || dolor > 10 || dias < 0)
            {
                cout << "Linea " << numeroLinea << ": datos fuera de rango"  << endl;
                continue;
            }

            if ((traumaNumero != 0 && traumaNumero != 1) || (neurologicoNumero != 0 && neurologicoNumero != 1) || (cirugiaNumero != 0 && cirugiaNumero != 1))
            {
                cout << "Linea " << numeroLinea << ": los indicadores deben ser 0 o 1" << endl;
                continue;
            }

            if (idRepetido(id) || hospital.buscarPorId(id) != nullptr)
            {
                cout << "Linea " << numeroLinea << ": ID duplicado " << id << endl;
                continue;
            }

            bool trauma = traumaNumero == 1;
            bool neurologico = neurologicoNumero == 1;
            bool cirugia = cirugiaNumero == 1;

            Paciente* nuevo = new Paciente( id,nombre,edad,temperatura,presion,dolor,tipoDolor,trauma,neurologico, cirugia, dias );

            
            try
            {
                pacientes.push_back(nuevo);
            }
            catch (...)
            {
                delete nuevo;
                throw;
            }

            hospital.agregarPaciente(nuevo);

            cargados++;

            cout << "Paciente cargado: " << nombre << " (ID " << id << ")" << endl;
        }
        catch (const invalid_argument&)
        {
            cout << "Linea " << numeroLinea  << ": numero invalido" << endl;
        }
        catch (const out_of_range&)
        {
            cout << "Linea " << numeroLinea << ": numero fuera de rango" << endl;
        }
    }

    cout << "\nTotal de pacientes cargados: " << cargados << endl;

    return cargados;
}

LectorPacientes::~LectorPacientes()
{
    for (int i = 0; i < (int)pacientes.size(); i++)
    {
        delete pacientes[i];
    }
}
