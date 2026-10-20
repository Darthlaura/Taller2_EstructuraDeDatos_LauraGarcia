
#pragma once

#include "Paciente.h"
#include <string>
#include <vector>

class Hospital;

class LectorPacientes
{
private:
    // guarda los pacientes creados desde el archivo.
    std::vector<Paciente*> pacientes;

    // comprueba si un ID ya fue cargado.
    bool idRepetido(int id) const;

public:
    LectorPacientes();

    //lLee el archivo y agrega pacientes a la cola.
    int cargarArchivo(const std::string& ruta, Hospital& hospital);

    ~LectorPacientes();
};
