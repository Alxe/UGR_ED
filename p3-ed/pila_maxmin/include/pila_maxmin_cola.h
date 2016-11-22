
#ifndef __PILA_MAXMIN_COLA_H
#define __PILA_MAXMIN_COLA_H

#include "cola.h"

class Pila_maxmin {
private:
	Cola<elemento> datos;

public:
	elemento tope() const;

	bool vacia() const;

	void poner(const int& v);

	void quitar();

	inline int size() const { return datos.num_elementos(); }

};

#endif