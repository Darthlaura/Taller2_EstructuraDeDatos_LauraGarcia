#include  "colaPacientes.h"



ColaPacientes:: ColaPacientes() {
      this->frente = nullptr; 
      this->final = nullptr;


}

void  ColaPacientes:: encolar(Paciente* paciente) {

     NodoCola* nuevo = new NodoCola(paciente);//declaracion de un nuevo puntero que contendra la referencia al paciente
     if (frente == nullptr) {

        frente = nuevo; 
        final = nuevo;

     } else {

        final->setSiguiente(nuevo); 
        final = nuevo; // el final ahora sera el nuevo paciente que llego
        }

     }

Paciente* ColaPaciente:: desencolar(Paciente* paciente) {

    //comprobar si la cola esta vacia
    if (frente == nullptr) {

        return =nullptr;
        
    }
    //guardar la direccion del primer nodo
    NodoCola* auxiiar = frente;   
    Paciente* paciente = auxiliar->getPaciente() //conservar el objeto Paciente para guardar su direccion antes de elminar el nodo;
    
    //avanzar al siguiente nodo
    frente = frente->getSiguiente(); 

    //si no quedan nodos, actualizar final
    if (frente ==nullptr) {
        final = nullptr;
    }

     delete auxiliar //eliminamos el nodo; 
     return paciente ;


}


ColaPaciente:: ~ColaPaciente() {

   while(frente != nullptr) {
     NodoCola* auxiiar = frente; 

     frente = frente->getSiguiente(); 

     delete auxiiar; 



   }
   final = nullptr; 


}


}