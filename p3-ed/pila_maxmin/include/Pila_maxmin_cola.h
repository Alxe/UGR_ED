
#ifndef __PILA_MAXMIN_COLA_H
#define __PILA_MAXMIN_COLA_H

#include "Cola.h"

class Pila {
private:
	Cola<elemento> datos;

public:
	elemento tope() const;

	bool vacia() const;

	void poner(const T& v);

	void quitar();

	int size() const;

};

#endif