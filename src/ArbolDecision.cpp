#include "ArbolDecision.h"
#include <stdexcept>
#include <iostream>
ArbolDecision::ArbolDecision()
{

    raiz = nullptr;
    construir();
}

void ArbolDecision::construir()
{

    // creamos los nodos de pregunta
    raiz = new NodoDecision("Edad menor a |14", ""); // este aputa al nodo de edad menor a 14
    NodoDecision *preguntaTrauma = new NodoDecision("Tiene trauma", "");

    // creamos las hojas con los servicion
    NodoDecision *pediatria = new NodoDecision("", "Pediatria");

    NodoDecision *traumatologia = new NodoDecision("", "traumatologia");

    NodoDecision *medicinaGeneral = new NodoDecision("", "Medicina General");

    // conectar los nodos izquierda y derecha

    raiz->setIzquierdo(pediatria);    // aca se conecta el nodo izquierdon con la decision de pediatra
    raiz->setDerecho(preguntaTrauma); // aca se conecta el nodo derecgo con la pregunta de si tiene o no trauma

    preguntaTrauma->setIzquierdo(traumatologia);
    preguntaTrauma->setDerecho(medicinaGeneral);
}

bool ArbolDecision::evaluarCondicion(const NodoDecision *nodo, const Paciente &paciente) const
{

    if (nodo->getPregunta() == "Edad menor que 14")
    {
        return paciente.getEdad() < 14;
    }
    if (nodo->getPregunta() == "Tiene trauma")
    {
        return paciente.getTrauma();
    }

    throw std::logic_error("Pregunta no reconocida");
}

string ArbolDecision::clasificar(const Paciente &paciente) const
{
    const NodoDecision *actual = raiz;

    while (actual != nullptr && !actual->esHoja()) // mientras exista un nodo y no sea una hoja seguira preguntando
    {

        if (evaluarCondicion(actual, paciente))
        {
            actual = actual->getIzquierdo();
        }
        else
        {
            actual = actual->getDerecho();
        }
    }

    if (actual == nullptr)
    {

        throw std::logic_error("El arbol tiene un camino incompleto");
    }
    if (actual->getServicio().empty())
    {
        throw std::logic_error("La hoja no tiene un servicio");
    }
    return actual->getServicio();
}

void ArbolDecision::mostrarPreorden() const
{

    preorden(raiz);
}

void ArbolDecision::preorden(const NodoDecision *nodo) const
{

    if (nodo == nullptr)
    {

        return;
    }

    // mostrar el nodo actual

    if (nodo->esHoja())
    {
        cout << "Servicio:" << nodo->getServicio() << endl;
    }
    else
    {

        cout << "Pregunta: " << nodo->getPregunta() << endl;
    }
    // recorrer los hijos

    preorden(nodo->getIzquierdo());
    preorden(nodo->getDerecho());
}

ArbolDecision::~ArbolDecision() {
    liberar(raiz);
}

void ArbolDecision::liberar(NodoDecision* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->getIzquierdo());
    liberar(nodo->getDerecho());

    delete nodo;
}