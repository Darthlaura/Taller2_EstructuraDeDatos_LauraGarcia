# include "../include/Paciente.h"

Paciente::Paciente(int id, string nombre, int edad, double temperatura, int presionArterial, 
int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos, bool requiereCiruguia, int diasHospitalizacion): Persona(id, nombre, edad) {
   this->temperatura = temperatura; 
   this->presionArterial= presionArterial; 
   this->dolor=dolor; 
   this->tipoDolor = tipoDolor;
   this->trauma = trauma; 
   this->sintomasNeurologicos = sintomasNeurologicos; 
   this->requiereCiruguia = requiereCiruguia; 
   this->diasHospitalizacion= diasHospitalizacion; 
 



}


double Paciente:: getTemperatura() const {
    return temperatura; 


}
  
int Paciente:: getPresionAreterial() const {
    return presionArterial;

}

int Paciente:: getDolor() const {
    return dolor;

}

string Paciente:: getTipoDolor() const {
    return tipoDolor;

}

bool Paciente:: getTrauma() const {
     return trauma;

}

bool Paciente:: getSintomasNeurologicos() const {
    return sintomasNeurologicos;

}

bool Paciente:: getRequiereCirugia() const {
    return requiereCiruguia;

} 

int Paciente:: getDiasHospitalizacion() const {
    return diasHospitalizacion; 

}
Paciente::~Paciente() {


    
}