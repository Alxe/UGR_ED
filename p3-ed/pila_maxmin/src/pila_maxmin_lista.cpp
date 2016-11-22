#ifndef __PILA_MAXMIN_LISTA_CPP
#define __PILA_MAXMIN_LISTA_CPP

#include "pila_maxmin_lista.h"

elemento Pila_maxmin::tope() const {
    if(datos.size() <= 0) {
        throw new std::out_of_range("0 <= pos < this->size()");
    }

    return datos.peek(datos.size()-1);
}

bool Pila_maxmin::vacia() const {
    return size() == 0;
}

void Pila_maxmin::poner(const int& v) {
    elemento e {v, v, v};

    if(size() > 0) {
        elemento t = tope();

        if(e.minimo > t.minimo) {
            e.minimo = t.minimo;
        }

        if(e.maximo < t.maximo) {
            e.maximo = t.maximo;
        }
    }

    datos.push_back(e);
}

void Pila_maxmin::quitar() {
    if(datos.size() <= 0) {
        throw new std::out_of_range("0 <= pos < this->size()");
    }

    datos.remove(datos.size()-1);
}

#endif