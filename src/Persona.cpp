#include "../include/Persona.h"

Persona::Persona(int id, string nombre, int edad) {
    this->id= id; 
    this->nombre= nombre; 
    this->edad= edad; 

}

int Persona:: getId() const {
    return id; 
}

string Persona::getNombre() const {
    return nombre; 

}

int Persona:: getEdad() const {
    return edad;

}


Persona::~Persona() {


    
}