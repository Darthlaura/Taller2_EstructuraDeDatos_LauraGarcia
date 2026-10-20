#pragma once

#include "NodoDecision.h"
#include "Paciente.h"
#include <string>

using namespace std;

class ArbolDecision
{
private:
    NodoDecision *raiz; //putero para el nodo raiz del arbol 

    //crear las preguntas, las hojas y las conexiones
    void construir();

    //revisar si un paciente cumple con la condicion de un nodo
    bool evaluarCondicion( const NodoDecision *nodo, const Paciente &paciente) const;

    void preorden(const NodoDecision* nodo) const; 
    void inorden(const NodoDecision* nodo) const; 
    void postorden(const NodoDecision* nodo) const;   
    
    void liberar(NodoDecision* nodo);

public:
    ArbolDecision();

    string clasificar(const Paciente &paciente) const;

    void mostrarPreorden() const;
    void mostrarInorden() const;
    void mostrarPostorden() const;

    ~ArbolDecision();
};