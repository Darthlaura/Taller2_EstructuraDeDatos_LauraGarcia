#include "NodoDecision.h"  



NodoDecision::NodoDecision(string pregunta, string servicio) {

    this->pregunta = pregunta; 
    this->servicio = servicio;

    izquierdo = nullptr; 
    derecho = nullptr; 

}
string NodoDecision:: getPregunta() const {
     return pregunta; 


}

string NodoDecision:: getServicio() const {
     return servicio; 


}

NodoDecision* NodoDecision:: getIzquierdo() const {
     return izquierdo;


}

NodoDecision* NodoDecision:: getDerecho() const {
     return derecho;


}
void NodoDecision:: setIzquierdo( NodoDecision* izquierdo){
      this->izquierdo = izquierdo;


}


void NodoDecision:: setDerecho( NodoDecision* derecho) {
      this->derecho = derecho; 


}

// comprobar si un nodo es hoja y ya no tiene mas ramificaciones 
bool NodoDecision:: esHoja() const {

    return izquierdo == nullptr && derecho == nullptr; 


}