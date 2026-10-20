
#pragma once

#include "ColaPacientes.h"
#include "ArbolDecision.h"
#include "ArbolAVL.h"
#include "Paciente.h"

#include <string>

class Hospital
{
private:
    ColaPacientes cola;
    ArbolDecision decision;

    ArbolAVL urgencias;
    ArbolAVL medicinaGeneral;
    ArbolAVL cardiologia;
    ArbolAVL neurologia;
    ArbolAVL traumatologia;
    ArbolAVL cirugia;
    ArbolAVL pediatria;
    ArbolAVL hospitalizacion;

    ArbolAVL* obtenerArbol(const std::string& servicio);

public:
    Hospital();

    void agregarPaciente(Paciente* paciente);
    void atenderPacientes();
    void mostrarDepartamentos();

    Paciente* buscarPorId(int id);
    Paciente* buscarPorNombre(const std::string& nombre);
};
