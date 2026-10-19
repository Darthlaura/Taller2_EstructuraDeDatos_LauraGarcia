
#include "ArbolAVL.h"
#include <iostream>
#include <stdexcept>

using namespace std;

ArbolAVL::ArbolAVL()
{
    raiz = nullptr;
}

void ArbolAVL::insertar(Paciente* paciente)
{
    if (paciente == nullptr)
    {
        throw std::invalid_argument("Paciente nulo");
    }

    raiz = insertarRecursivo(raiz, paciente);
}


NodoAVL* ArbolAVL::insertarRecursivo(
    NodoAVL* nodo,
    Paciente* paciente)
{
    // si encontramos un espacio vacío,
    // creamos un nodo nuevo.
    if (nodo == nullptr)
    {
        return new NodoAVL(paciente);
    }

    // si el ID es menor, avanzamos a la izquierda.
    if (paciente->getId() < nodo->getPaciente()->getId())
    {
        nodo->setIzquierdo(
            insertarRecursivo(nodo->getIzquierdo(), paciente)
        );
    }

    // si el ID es mayor, avanzamos a la derecha.
    else if (paciente->getId() > nodo->getPaciente()->getId())
    {
        nodo->setDerecho(
            insertarRecursivo(nodo->getDerecho(), paciente)
        );
    }
    else
    {
        throw std::invalid_argument("ID de paciente duplicado");
    }

    // Pendiente: actualizar altura y balancear.
    return nodo;
}
