
#include "NodoAVL.h"

NodoAVL::NodoAVL(Paciente* paciente)
{
    this->paciente = paciente;

    izquierdo = nullptr;
    derecho = nullptr;

    altura = 1;
}


Paciente* NodoAVL::getPaciente() const
{
    return paciente;
}

NodoAVL* NodoAVL::getIzquierdo() const
{
    return izquierdo;
}

NodoAVL* NodoAVL::getDerecho() const
{
    return derecho;
}

int NodoAVL::getAltura() const
{
    return altura;
}

void NodoAVL::setIzquierdo(NodoAVL* izquierdo)
{
    this->izquierdo = izquierdo;
}

void NodoAVL::setDerecho(NodoAVL* derecho)
{
    this->derecho = derecho;
}

void NodoAVL::setAltura(int altura)
{
    this->altura = altura;
}

