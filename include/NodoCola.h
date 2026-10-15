#pragma once 
# include "Paciente.h"


class NodoCola {
   private: 
   Paciente* paciente;  //declarar  un puntero llamado paciente para almacenar la direccion del objeto paciente
   NodoCola* siguiente; 
   //constructor 
   public: NodoCola(Paciente* paciente); 

   //metodo para obtener la direccion del paciente almacenado en el nodo 
   Paciente* getPaciente();
   //falta el destructor 
   
   //metodo para obtener el siguiente nodo
   NodoCola* getSiguiente(); 

   //metodo para conectar un nodo con otro 
   void setSiguiente(NodoCola* siguiente); 



}

