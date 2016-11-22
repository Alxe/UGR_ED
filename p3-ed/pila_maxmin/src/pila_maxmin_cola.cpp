
#ifndef __PILA_MAXMIN_COLA_CPP
#define __PILA_MAXMIN_COLA_CPP

#include "pila_maxmin_cola.h"

elemento Pila_maxmin::tope() const {
    return datos.frente();
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

    Cola<elemento> c;

    c.poner(e);

    while(size() > 0) {
        c.poner(datos.frente());
        datos.quitar();
    }

    datos = c;
}

void Pila_maxmin::quitar() {
    datos.quitar();
}

#endif
