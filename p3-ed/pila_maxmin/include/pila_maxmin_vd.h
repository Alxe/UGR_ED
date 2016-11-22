
#ifndef __PILA_MAXMIN_VD_H
#define __PILA_MAXMIN_VD_H

#include "vd.h"

class Pila_maxmin {
private:
	VD<elemento> datos;

public:
	elemento tope() const;

	bool vacia() const;

	void poner(const int& v);

	void quitar();

	inline int size() const { return datos.size(); }

};

#endif