#pragma once
#include <string>
using namespace std;

class NodoDecision
{

private:
    string pregunta; // condicion
    string servicio; // resultante de la hoja

    NodoDecision *izquierdo;
    NodoDecision *derecho;

public:
    NodoDecision(string pregunta, string servicio);

    string getPregunta() const;
    string getServicio() const;

    NodoDecision* getIzquierdo() const;
    NodoDecision* getDerecho() const;

    void setIzquierdo(NodoDecision *izquierdo);
    void setDerecho(NodoDecision *derecho);

    bool esHoja() const;
};