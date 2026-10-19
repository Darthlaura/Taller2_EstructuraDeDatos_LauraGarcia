#include "ArbolDecision.h"
#include <stdexcept>
#include <iostream>
ArbolDecision::ArbolDecision()
{

    raiz = nullptr;
    construir();
}
void ArbolDecision::construir() {
    // Nodos de pregunta
    raiz = new NodoDecision("Tiene fiebre alta o dolor intenso", "");

    NodoDecision* cirugia =
        new NodoDecision("Requiere cirugia", "");

    NodoDecision* trauma =
        new NodoDecision("Tiene trauma", "");

    NodoDecision* neurologia =
        new NodoDecision("Tiene sintomas neurologicos", "");

    NodoDecision* pecho =
        new NodoDecision("Tiene dolor de pecho", "");

    NodoDecision* edad =
        new NodoDecision("Edad menor que 14", "");

    NodoDecision* hospitalizacion =
        new NodoDecision("Necesita hospitalizacion", "");

    // Sí: servicio correspondiente. No: siguiente pregunta.
    raiz->setIzquierdo(new NodoDecision("", "Urgencias"));
    raiz->setDerecho(cirugia);

    cirugia->setIzquierdo(new NodoDecision("", "Cirugia"));
    cirugia->setDerecho(trauma);

    trauma->setIzquierdo(new NodoDecision("", "Traumatologia"));
    trauma->setDerecho(neurologia);

    neurologia->setIzquierdo(new NodoDecision("", "Neurologia"));
    neurologia->setDerecho(pecho);

    pecho->setIzquierdo(new NodoDecision("", "Cardiologia"));
    pecho->setDerecho(edad);

    edad->setIzquierdo(new NodoDecision("", "Pediatria"));
    edad->setDerecho(hospitalizacion);

    hospitalizacion->setIzquierdo(
        new NodoDecision("", "Hospitalizacion")
    );

    hospitalizacion->setDerecho(
        new NodoDecision("", "Medicina General")
    );
}


bool ArbolDecision::evaluarCondicion( const NodoDecision* nodo, const Paciente& paciente) const {
    string pregunta = nodo->getPregunta();

    if (pregunta == "Tiene fiebre alta o dolor intenso") {
        return paciente.getTemperatura() >= 38.5
            || paciente.getDolor() >= 8;
    }

    if (pregunta == "Requiere cirugia") {
        return paciente.getRequiereCirugia();
    }

    if (pregunta == "Tiene trauma") {
        return paciente.getTrauma();
    }

    if (pregunta == "Tiene sintomas neurologicos") {
        return paciente.getSintomasNeurologicos();
    }

    if (pregunta == "Tiene dolor de pecho") {
        return paciente.getTipoDolor() == "pecho";
    }

    if (pregunta == "Edad menor que 14") {
        return paciente.getEdad() < 14;
    }

    if (pregunta == "Necesita hospitalizacion") {
        return paciente.getDiasHospitalizacion() >= 2;
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

ArbolDecision::~ArbolDecision()
{
    liberar(raiz);
}

void ArbolDecision::liberar(NodoDecision *nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    liberar(nodo->getIzquierdo());
    liberar(nodo->getDerecho());

    delete nodo;
}

void ArbolDecision::mostrarInorden() const
{

    inorden(raiz);
}

void ArbolDecision::inorden(const NodoDecision *nodo) const
{
    if (nodo == nullptr)
    {

        return;
    }

    inorden(nodo->getIzquierdo());
    if (nodo->esHoja())
    {

        cout << "Servicio: " << nodo->getServicio() << endl;
    }
    else
    {

        cout << "Pregunta: " << nodo->getPregunta() << endl;
    }

    inorden(nodo->getDerecho());
}

void ArbolDecision::mostrarPostorden() const
{
    postorden(raiz);
}

void ArbolDecision::postorden(const NodoDecision *nodo) const
{

    if (nodo == nullptr)
    {

        return;
    }

    postorden(nodo->getIzquierdo());
    postorden(nodo->getDerecho());
    if (nodo->esHoja())
    {

        cout << "Servicio: " << nodo->getServicio() << endl;
    }
    else
    {

        cout << "Pregunta: " << nodo->getPregunta() << endl;
    }
}