#pragma once
#include "Paciente.h"

class NodoAVL {

private:

    Paciente* paciente;

    NodoAVL* izquierdo;
    NodoAVL* derecho;

    int altura; //variable para conocer la altura del arbol 

public:

    NodoAVL(Paciente* paciente);

    Paciente* getPaciente() const;

    NodoAVL* getIzquierdo() const;
    NodoAVL* getDerecho() const;

    int getAltura() const;

    void setIzquierdo(NodoAVL* izquierdo);
    void setDerecho(NodoAVL* derecho);

    void setAltura(int altura);

};
