
#include <iostream>
#include <string>
#include <sstream>

#include "Hospital.h"
#include "LectorPacientes.h"

using namespace std;

int main()
{
    // crear el lector y el hospital
    // el lector debe existir mientras el hospital
    // utilice los pacientes que fueron cargados.
    LectorPacientes lector;
    Hospital hospital;

    int opcion = -1;
    bool archivoCargado = false;

    do
    {
        // MENU PRINCIPAL
        cout << "\n===== HOSPITAL MARMAJA =====" << endl;
        cout << "1. Cargar pacientes desde archivo" << endl;
        cout << "2. Atender pacientes de la cola" << endl;
        cout << "3. Mostrar departamentos" << endl;
        cout << "4. Buscar paciente por ID" << endl;
        cout << "5. Buscar paciente por nombre" << endl;
        cout << "6. Eliminar paciente por ID" << endl;
        cout << "7. Consultar estado AVL de un servicio" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        string entrada;
        getline(cin, entrada);

        stringstream convertir(entrada);

        // Comprobar que la opcion sea un numero
        if (!(convertir >> opcion))
        {
            cout << "Opcion invalida." << endl;
            opcion = -1;
            continue;
        }

        char sobrante;

        if (convertir >> sobrante)
        {
            cout << "Ingrese solamente un numero." << endl;
            opcion = -1;
            continue;
        }

        // OPCION 1: CARGAR PACIENTES
        if (opcion == 1)
        {
            if (archivoCargado)
            {
                cout << "El archivo ya fue cargado." << endl;
            }
            else
            {
                int cantidad = lector.cargarArchivo( "data/pacientes.txt",hospital);

                if (cantidad > 0)
                {
                    archivoCargado = true;
                }
            }
        }

        // OPCION 2: ATENDER PACIENTES
        else if (opcion == 2)
        {
            cout << "\n=== ATENCION DE PACIENTES ===" << endl;

            hospital.atenderPacientes();
        }

        // OPCION 3: MOSTRAR DEPARTAMENTOS
        else if (opcion == 3)
        {
            hospital.mostrarDepartamentos();
        }

        // OPCION 4: BUSCAR POR ID
        else if (opcion == 4)
        {
            cout << "Ingrese ID: ";

            string textoId;
            getline(cin, textoId);

            stringstream convertirId(textoId);
            int id;
            char caracterExtra;

            if (!(convertirId >> id) || (convertirId >> caracterExtra))
            {
                cout << "ID invalido." << endl;
                continue;
            }

            Paciente* paciente = hospital.buscarPorId(id);

            if (paciente != nullptr)
            {
                cout << "Paciente encontrado: " << paciente->getNombre() << endl;
            }
            else
            {
                cout << "Paciente no encontrado." << endl;
            }
        }

        // OPCION 5: BUSCAR POR NOMBRE
        else if (opcion == 5)
        {
            cout << "Ingrese nombre: ";

            string nombre;
            getline(cin, nombre);

            Paciente* paciente = hospital.buscarPorNombre(nombre);

            if (paciente != nullptr)
            {
                cout << "Paciente encontrado. ID: " << paciente->getId() << endl;
            }
            else
            {
                cout << "Paciente no encontrado." << endl;
            }
        }

        // OPCION 6: ELIMINAR PACIENTE
        else if (opcion == 6)
        {
            cout << "\n=== ELIMINAR PACIENTE ===" << endl;
            cout << "Ingrese ID: ";

            string textoId;
            getline(cin, textoId);

            stringstream convertirId(textoId);
            int id;
            char caracterExtra;

            if (!(convertirId >> id) || (convertirId >> caracterExtra))
            {
                cout << "ID invalido." << endl;
                continue;
            }

            bool eliminado = hospital.eliminarPaciente(id);

            if (eliminado)
            {
                cout << "Paciente eliminado correctamente." << endl;
            }
            else
            {
                cout << "Paciente no encontrado." << endl;
            }
        }

        // OPCION 7: CONSULTAR ESTADO AVL
        else if (opcion == 7)
        {
            cout << "\n=== CONSULTAR ESTADO AVL ===" << endl;

            cout << "1. Urgencias" << endl;
            cout << "2. Medicina General" << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Neurologia" << endl;
            cout << "5. Traumatologia" << endl;
            cout << "6. Cirugia" << endl;
            cout << "7. Pediatria" << endl;
            cout << "8. Hospitalizacion" << endl;

            cout << "Seleccione un servicio: ";

            string entradaServicio;
            getline(cin, entradaServicio);

            stringstream convertirServicio(entradaServicio);

            int numeroServicio;
            char caracterExtra;

            if (!(convertirServicio >> numeroServicio) ||  (convertirServicio >> caracterExtra))
            {
                cout << "Servicio invalido." << endl;
                continue;
            }

            string servicio;

            if (numeroServicio == 1)
            {
                servicio = "Urgencias";
            }
            else if (numeroServicio == 2)
            {
                servicio = "Medicina General";
            }
            else if (numeroServicio == 3)
            {
                servicio = "Cardiologia";
            }
            else if (numeroServicio == 4)
            {
                servicio = "Neurologia";
            }
            else if (numeroServicio == 5)
            {
                servicio = "Traumatologia";
            }
            else if (numeroServicio == 6)
            {
                servicio = "Cirugia";
            }
            else if (numeroServicio == 7)
            {
                servicio = "Pediatria";
            }
            else if (numeroServicio == 8)
            {
                servicio = "Hospitalizacion";
            }
            else
            {
                cout << "Servicio no reconocido." << endl;
                continue;
            }

            // Mostrar los recorridos, altura y balance
            hospital.mostrarEstadoAVL(servicio);
        }

        // OPCION 0: SALIR
        else if (opcion == 0)
        {
            cout << "Saliendo del Hospital Marmaja..." << endl;
        }

       
        else
        {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
