#include "NodoCola.h"


NodoCola::NodoCola(Paciente* paciente) {
    this->paciente= paciente; 
    this->siguiente = nullptr; 


}


Paciente* NodoCola::getPaciente() {
   return paciente;


}

NodoCola* NodoCola::getSiguiente() {
   return siguiente; 

}


void NodoCola::setSiguiente(NodoCola* siguiente) {
     this->siguiente = siguiente; 


}