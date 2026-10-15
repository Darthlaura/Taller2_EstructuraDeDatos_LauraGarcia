#pragma once
#include <string>
using manespace std; 

class Persona {
    protected: 

    int id; 
    string nombre; 
    int edad; 

    public: 
    Persona(int id, string nombre, int edad); 
    
    int getId() const; 
    string getNombre() const; 
    int getEdad() const; 


    virtual ~Persona(); 



}; 