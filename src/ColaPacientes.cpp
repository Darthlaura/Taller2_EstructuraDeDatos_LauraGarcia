#include  "ColaPacientes.h"



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

Paciente* ColaPacientes:: desencolar() {

    //comprobar si la cola esta vacia
    if (frente == nullptr) {

        return nullptr;
        
    }
    //guardar la direccion del primer nodo
    NodoCola* auxiliar = frente;   
    Paciente* paciente = auxiliar->getPaciente(); //conservar el objeto Paciente para guardar su direccion antes de elminar el nodo;
    
    //avanzar al siguiente nodo
    frente = frente->getSiguiente(); 

    //si no quedan nodos, actualizar final
    if (frente ==nullptr) {
        final = nullptr;
    }

     delete auxiliar; //eliminamos el nodo; 
     return paciente ;


}


ColaPacientes:: ~ColaPacientes() {

   while(frente != nullptr) {
     NodoCola* auxiliar = frente; 

     frente = frente->getSiguiente(); 

     delete auxiliar; 



   }
   final = nullptr; 


}


