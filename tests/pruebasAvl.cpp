
#include <iostream>
#include "ArbolAVL.h"
#include "Paciente.h"

using namespace std;

// Prueba de una rotacion AVL
void probarRotacion(
    int id1,
    int id2,
    int id3,
    string nombrePrueba)
{
    cout << "\n============================" << endl;
    cout << "PRUEBA: " << nombrePrueba << endl;
    cout << "============================" << endl;

    // Crear tres pacientes
    Paciente paciente1(id1, "Paciente A", 30, 39.0, 120, 8, "cabeza", false, false, false, 0);

    Paciente paciente2(id2, "Paciente B", 30, 39.0, 120, 8, "cabeza", false, false, false, 0);

    Paciente paciente3(id3, "Paciente C", 30, 39.0, 120, 8, "cabeza", false, false, false, 0);

    // Crear un arbol nuevo para cada prueba
    ArbolAVL arbol;

    arbol.insertar(&paciente1);
    arbol.insertar(&paciente2);
    arbol.insertar(&paciente3);

    cout << "\nRecorrido inorden:" << endl;
    arbol.mostrarInorden();

    cout << "\nRecorrido preorden:" << endl;
    arbol.mostrarPreorden();

    cout << "\nRecorrido postorden:" << endl;
    arbol.mostrarPostorden();

    cout << "\nAltura: "
         << arbol.getAlturaArbol() << endl;

    cout << "Balance raiz: "
         << arbol.getBalanceRaiz() << endl;
}

int main()
{
    cout << "===== PRUEBAS DE ROTACIONES AVL =====" << endl;

    // LL: rotacion simple derecha
    probarRotacion(150, 140, 130, "LL");

    // RR: rotacion simple izquierda
    probarRotacion(130, 140, 150, "RR");

    // LR: rotacion doble izquierda-derecha
    probarRotacion(150, 130, 140, "LR");

    // RL: rotacion doble derecha-izquierda
    probarRotacion(130, 150, 140, "RL");

    cout << "\n=== FIN DE LAS PRUEBAS ===" << endl;

    return 0;
}
