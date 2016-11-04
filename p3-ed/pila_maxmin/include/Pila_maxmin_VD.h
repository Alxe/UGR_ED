
#ifndef __PILA_MAXMIN_VD_H
#define __PILA_MAXMIN_VD_H

#include "VD.h"

class Pila {
private:
	VD<elemento> datos;

public:
	elemento tope() const;

	bool vacia() const;

	void poner(const T& v);

	void quitar();

	int size() const;

};

#endif