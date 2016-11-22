#ifndef __PILA_MAXMIN_LISTA_H
#define __PILA_MAXMIN_LISTA_H

#include "lista.h"

class Pila_maxmin {
private:
    Lista<elemento> datos;

public:
    elemento tope() const;

    bool vacia() const;

    void poner(const int& v);

    void quitar();

    inline int size() const { return datos.size(); }

};

#endif