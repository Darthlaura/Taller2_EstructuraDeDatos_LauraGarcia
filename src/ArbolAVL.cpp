
#include "ArbolAVL.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// constructor
ArbolAVL::ArbolAVL()
{
    raiz = nullptr;
}

// insertar paciente
void ArbolAVL::insertar(Paciente* paciente)
{
    if (paciente == nullptr)
    {
        throw invalid_argument("Paciente nulo");
    }

    raiz = insertarRecursivo(raiz, paciente);
}

// insertar de forma recursiva
NodoAVL* ArbolAVL::insertarRecursivo(NodoAVL* nodo, Paciente* paciente)
{
    if (nodo == nullptr)
    {
        return new NodoAVL(paciente);
    }

    int idNuevo = paciente->getId();
    int idActual = nodo->getPaciente()->getId();

    if (idNuevo < idActual)
    {
        nodo->setIzquierdo(insertarRecursivo(nodo->getIzquierdo(), paciente)
        );
    }
    else if (idNuevo > idActual)
    {
        nodo->setDerecho(insertarRecursivo(nodo->getDerecho(), paciente)
        );
    }
    else
    {
        throw invalid_argument("ID duplicado");
    }

    // actualizar altura
    nodo->setAltura(1 + mayor(obtenerAltura(nodo->getIzquierdo()), obtenerAltura(nodo->getDerecho())
    ));

    int balance = obtenerBalance(nodo);

    // izquierda / izquierda
    if (balance > 1 && idNuevo < nodo->getIzquierdo()->getPaciente()->getId())
    {
        return rotarDerecha(nodo);
    }

    // derecha / derecha
    if (balance < -1 && idNuevo > nodo->getDerecho()->getPaciente()->getId())
    {
        return rotarIzquierda(nodo);
    }

    // izquierda / derecha
    if (balance > 1 && idNuevo > nodo->getIzquierdo()->getPaciente()->getId())
    {
        nodo->setIzquierdo(rotarIzquierda(nodo->getIzquierdo())
        );

        return rotarDerecha(nodo);
    }

    // derecha / izquierda
    if (balance < -1 && idNuevo < nodo->getDerecho()->getPaciente()->getId())
    {
        nodo->setDerecho( rotarDerecha(nodo->getDerecho())
        );

        return rotarIzquierda(nodo);
    }

    return nodo;
}

// altura del nodo
int ArbolAVL::obtenerAltura(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }

    return nodo->getAltura();
}

// obtener el mayor
int ArbolAVL::mayor(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

// obtener el balance
int ArbolAVL::obtenerBalance(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }

    int alturaIzquierda = obtenerAltura(nodo->getIzquierdo());
    int alturaDerecha = obtenerAltura(nodo->getDerecho());

    return alturaIzquierda - alturaDerecha;
}

// rotar a la derecha
NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* nodo)
{
    NodoAVL* izquierdo = nodo->getIzquierdo();
    NodoAVL* temporal = izquierdo->getDerecho();

    izquierdo->setDerecho(nodo);
    nodo->setIzquierdo(temporal);

    nodo->setAltura(1 + mayor( obtenerAltura(nodo->getIzquierdo()),obtenerAltura(nodo->getDerecho())  ));

    izquierdo->setAltura(1 + mayor( obtenerAltura(izquierdo->getIzquierdo()), obtenerAltura(izquierdo->getDerecho())));

    return izquierdo;
}

// rotar a la izquierda
NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* nodo)
{
    NodoAVL* derecho = nodo->getDerecho();
    NodoAVL* temporal = derecho->getIzquierdo();

    derecho->setIzquierdo(nodo);
    nodo->setDerecho(temporal);

    nodo->setAltura(1 + mayor( obtenerAltura(nodo->getIzquierdo()), obtenerAltura(nodo->getDerecho()) ));

    derecho->setAltura(1 + mayor( obtenerAltura(derecho->getIzquierdo()),  obtenerAltura(derecho->getDerecho()) ));

    return derecho;
}

// buscar un nodo por ID
NodoAVL* ArbolAVL::buscarRecursivo(NodoAVL* nodo, int id) const
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    int idActual = nodo->getPaciente()->getId();

    if (id == idActual)
    {
        return nodo;
    }

    if (id < idActual)
    {
        return buscarRecursivo(nodo->getIzquierdo(), id);
    }

    return buscarRecursivo(nodo->getDerecho(), id);
}

// buscar paciente por ID
Paciente* ArbolAVL::buscarPorId(int id) const
{
    NodoAVL* encontrado = buscarRecursivo(raiz, id);

    if (encontrado == nullptr)
    {
        return nullptr;
    }

    return encontrado->getPaciente();
}

// buscar paciente por nombre
Paciente* ArbolAVL::buscarPorNombre(const string& nombre) const
{
    return buscarNombreRecursivo(raiz, nombre);
}

// buscar de forma recursiva por nombre
Paciente* ArbolAVL::buscarNombreRecursivo(
    NodoAVL* nodo, const string& nombre) const
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    if (nodo->getPaciente()->getNombre() == nombre)
    {
        return nodo->getPaciente();
    }

    Paciente* encontrado = buscarNombreRecursivo(
        nodo->getIzquierdo(), nombre
    );

    if (encontrado != nullptr)
    {
        return encontrado;
    }

    return buscarNombreRecursivo(nodo->getDerecho(), nombre);
}

// eleminiar paciente por ID
void ArbolAVL::eliminar(int id)
{
    raiz = eliminarRecursivo(raiz, id);
}

// encontrar el nodo del menor por ID
NodoAVL* ArbolAVL::encontrarMinimo(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    while (nodo->getIzquierdo() != nullptr)
    {
        nodo = nodo->getIzquierdo();
    }

    return nodo;
}

// eliminacio de forma recursiva y balanceo
NodoAVL* ArbolAVL::eliminarRecursivo(NodoAVL* nodo, int id)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    int idActual = nodo->getPaciente()->getId();

    if (id < idActual)
    {
        nodo->setIzquierdo(
            eliminarRecursivo(nodo->getIzquierdo(), id)
        );
    }
    else if (id > idActual)
    {
        nodo->setDerecho(
            eliminarRecursivo(nodo->getDerecho(), id)
        );
    }
    else
    {
        // para el caso 1, sin hijos o con un solo hijo 
        if (nodo->getIzquierdo() == nullptr || nodo->getDerecho() == nullptr)
        {
            NodoAVL* hijo = nullptr;

            if (nodo->getIzquierdo() != nullptr)
            {
                hijo = nodo->getIzquierdo();
            }
            else
            {
                hijo = nodo->getDerecho();
            }

            delete nodo;
            return hijo;
        }

        // caso 3 nodo con dos hijos 
        NodoAVL* sucesor = encontrarMinimo( nodo->getDerecho()
        );

        // Guardamos los datos antes de eliminar el sucesor
        int idSucesor = sucesor->getPaciente()->getId();
        Paciente* pacienteSucesor = sucesor->getPaciente();

        // Reemplazamos la referencia al paciente
        nodo->setPaciente(pacienteSucesor);

        // Eliminamos el nodo sucesor
        nodo->setDerecho( eliminarRecursivo(nodo->getDerecho(), idSucesor)
        );
    }

    
    nodo->setAltura(1 + mayor(obtenerAltura(nodo->getIzquierdo()), obtenerAltura(nodo->getDerecho())  ));

   
    int balance = obtenerBalance(nodo);

 
    if (balance > 1 && obtenerBalance(nodo->getIzquierdo()) >= 0)
    {
        return rotarDerecha(nodo);
    }

  
    if (balance > 1 && obtenerBalance(nodo->getIzquierdo()) < 0)
    {
        nodo->setIzquierdo(rotarIzquierda(nodo->getIzquierdo())
        );

        return rotarDerecha(nodo);
    }

    
    if (balance < -1 && obtenerBalance(nodo->getDerecho()) <= 0)
    {
        return rotarIzquierda(nodo);
    }


    if (balance < -1 && obtenerBalance(nodo->getDerecho()) > 0)
    {
        nodo->setDerecho( rotarDerecha(nodo->getDerecho())
        );

        return rotarIzquierda(nodo);
    }

    return nodo;
}

// mostrar inorden
void ArbolAVL::mostrarInorden() const
{
    inorden(raiz);
}

// mostrar preorden
void ArbolAVL::mostrarPreorden() const
{
    preorden(raiz);
}

// mostrar postorden
void ArbolAVL::mostrarPostorden() const
{
    postorden(raiz);
}

// recorrido inorden
void ArbolAVL::inorden(NodoAVL* nodo) const
{
    if (nodo == nullptr)
    {
        return;
    }

    inorden(nodo->getIzquierdo());

    cout << "ID: " << nodo->getPaciente()->getId() << endl;

    inorden(nodo->getDerecho());
}

// recorriendo preorden
void ArbolAVL::preorden(NodoAVL* nodo) const
{
    if (nodo == nullptr)
    {
        return;
    }

    cout << "ID: " << nodo->getPaciente()->getId() << endl;

    preorden(nodo->getIzquierdo());
    preorden(nodo->getDerecho());
}

// recorrido postorden
void ArbolAVL::postorden(NodoAVL* nodo) const
{
    if (nodo == nullptr)
    {
        return;
    }

    postorden(nodo->getIzquierdo());
    postorden(nodo->getDerecho());

    cout << "ID: " << nodo->getPaciente()->getId() << endl;
}

// consultar la altura del arbol 
int ArbolAVL::getAlturaArbol()
{
    return obtenerAltura(raiz);
}

// consultar el factor de balance
int ArbolAVL::getBalanceRaiz()
{
    return obtenerBalance(raiz);
}


// liberar nodos del arbol 
void ArbolAVL::liberar(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }
    
    liberar(nodo->getIzquierdo());
    liberar(nodo->getDerecho());
    
    delete nodo;
}

// destructor
ArbolAVL::~ArbolAVL()
{
    liberar(raiz);
}