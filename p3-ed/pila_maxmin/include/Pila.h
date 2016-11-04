
#define CUAL_COMPILA 1

typedef struct {
	int valor;
	int maximo;
	int minimo;
} elemento;

#if CUAL_COMPILA==1
#include "pila_maxmin_vd.h"

#elif CUAL_COMPILA==2
#include "pila_maxmin_list.h"

#else
#include "pila_maxmin_cola.h"

#endif