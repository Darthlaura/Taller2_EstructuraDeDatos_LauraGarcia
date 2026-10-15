
#pragma once 
#include "NodoCola.h"



class   ColaPacientes {

 private: 

 NodoCola* frente; // puntero que guarda la direccion del primero de la cola
 NodoCola* final;  // puntero que guarda la direccion del ultimo en la cola 

 public : 
 //constructor 
 ColaPacientes(); 

// metodo encolar : Recibe un objeto de tipo paciente y lo incorpora al final de la cola 

void encolar(Paciente* paciente); 


Paciente* desencolar(); 


~ColaPacientes();

};

