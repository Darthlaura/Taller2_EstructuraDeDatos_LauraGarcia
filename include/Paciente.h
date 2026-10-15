#pragma once 
#include "Persona.h" 
#include <string>

using namespace std; 

class Paciente : public Persona {
private: 
double temperatura; // temperatura corporal
int presionArterial; // representar la presion  sintolica con un entero
int dolor;  // escala entre 0 y 10 
string tipoDolor;  // pecho, cabeza, abdomen, extremindad u otro
bool trauma; // 0 si no existe y 1 si existe
bool sintomasNeurologicos; // 0 si no existe y 2 si existe
bool requiereCiruguia; // 0 si no requiere 1 si requiere
int diasHospitalizacion; // catidasd estimada de dias 

public: 

Paciente(int id, string nombre, int edad, double temperatura, int presionArterial, int dolor,
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




};