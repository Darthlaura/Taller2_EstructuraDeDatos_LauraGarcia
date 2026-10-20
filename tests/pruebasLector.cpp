#include <iostream>
#include "Hospital.h"
#include "LectorPacientes.h"

using namespace std;

int main()
{
    Hospital hospital;
    LectorPacientes lector;

    cout << "=== PRUEBA ARCHIVO INEXISTENTE ===" << endl;

    lector.cargarArchivo("data/archivo_inexistente.txt", hospital);

    cout << "El programa continua funcionando." << endl;

    return 0;
}