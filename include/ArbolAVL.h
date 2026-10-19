
#pragma once

#include "NodoAVL.h"

class ArbolAVL {

private:

    NodoAVL* raiz;

    
    NodoAVL* insertarRecursivo(NodoAVL* nodo, Paciente* paciente);

    // Altura y balance
    int obtenerAltura(NodoAVL* nodo);
    int obtenerBalance(NodoAVL* nodo);
    int mayor(int a, int b);

    // Rotaciones
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);

    // Recorridos
    void inorden(NodoAVL* nodo) const;
    void preorden(NodoAVL* nodo) const;
    void postorden(NodoAVL* nodo) const;

    // Liberar memoria
    void liberar(NodoAVL* nodo);

public:

    ArbolAVL();

    void insertar(Paciente* paciente);

    void mostrarInorden() const;
    void mostrarPreorden() const;
    void mostrarPostorden() const;

    ~ArbolAVL();
};
