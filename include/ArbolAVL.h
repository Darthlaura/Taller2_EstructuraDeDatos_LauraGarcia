
#pragma once

#include "NodoAVL.h"
#include <string>

class ArbolAVL {

private:

    NodoAVL* raiz;

    // insercion
    NodoAVL* insertarRecursivo(NodoAVL* nodo, Paciente* paciente);

    // altura y balance
    int obtenerAltura(NodoAVL* nodo);
    int obtenerBalance(NodoAVL* nodo);
    int mayor(int a, int b);

    // rotaciones
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);

    // busquedas
    NodoAVL* buscarRecursivo(NodoAVL* nodo, int id) const;

    Paciente* buscarNombreRecursivo(
        NodoAVL* nodo, const std::string& nombre
    ) const;

    // eliminacion
    NodoAVL* eliminarRecursivo(NodoAVL* nodo, int id);
    NodoAVL* encontrarMinimo(NodoAVL* nodo);

    // recorridos
    void inorden(NodoAVL* nodo) const;
    void preorden(NodoAVL* nodo) const;
    void postorden(NodoAVL* nodo) const;

    // liberar memeoria
    void liberar(NodoAVL* nodo);

public:

    ArbolAVL();

    void insertar(Paciente* paciente);
    void eliminar(int id);

    Paciente* buscarPorId(int id) const;
    Paciente* buscarPorNombre(const std::string& nombre) const;

    void mostrarInorden() const;
    void mostrarPreorden() const;
    void mostrarPostorden() const;

    int getAlturaArbol();
    int getBalanceRaiz();

    ~ArbolAVL();
};
