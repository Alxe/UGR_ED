#ifndef __PILA_MAXMIN_H
#define __PILA_MAXMIN_H

#define CUAL_COMPILA 3

#include "elemento.h"

#if CUAL_COMPILA == 1
#define CUAL_USA "Vector Dinamico"
#include "pila_maxmin_vd.h"

#elif CUAL_COMPILA == 2
#define CUAL_USA "Lista Enlazada"
#include "pila_maxmin_lista.h"

#else
#define CUAL_USA "Cola"
#include "pila_maxmin_cola.h"

#endif

#endif