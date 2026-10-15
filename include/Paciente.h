#pragma once 
#include "Persona.h" 
#include <string>

using namespace std; 

class Paciente : public Perona {
privare: 
double temperatura; 
int presionArteruial; 
int dolor; 
string tipoDolor; 
bool trauma; 
bool sintomasNeurologicos; 
bool requiereCiruguia; 
int diasHospitalizacion;

public: 

Paciente(int id, string nombre, int edad, double temperatura, int presionArteruial, int dolor,
string tipoDolor, bool trauma, bool sintomasNeurologicos, bool requiereCiruguia, int diasHospitalizacion); 

double getTemperatura() const; // uso del metodo const para no modificar el objeto 
int getPresionAreterial() const; 
int getDolor() const; 
string getTipoDolor() const; 
bool getTrauma() const; 
bool getSintomasNeurologicos() const; 
bool getRequiereCirugia() const; 
int getDiasHospitalizacion() const; 


//sobreescribe el destructor de persona 
~Paciente() override; 




}