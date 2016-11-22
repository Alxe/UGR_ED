#ifndef __PILA_MAXMIN_CPP
#define __PILA_MAXMIN_CPP

#include "pila_maxmin.h"

#if CUAL_COMPILA == 1
#define CUAL_USA "Vector Dinamico"
#include "pila_maxmin_vd.cpp"

#elif CUAL_COMPILA == 2
#define CUAL_USA "Lista Enlazada"
#include "pila_maxmin_lista.cpp"

#else
#define CUAL_USA "Cola"
#include "pila_maxmin_cola.cpp"

#endif

#endif