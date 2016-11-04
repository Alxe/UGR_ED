
#ifndef __LISTA_CPP
#define __LISTA_CPP

#include "Lista.h"

template<typename T>
void Lista<T>::copy_from(const Lista<T>& o) const {
	if(origin != nullptr) delete origin;

	this->origin = o.origin;
	this->length = o.length;
}

template<typename T>
Lista<T>::Lista() {
	this->origin = nullptr;
	this->length = 0;
}

template<typename T>
Lista<T>::Lista(const Lista<T>& o) {
	copy_from(o);
}

template<typename T>
Lista<T>::~Lista() {
	if(origin != nullptr) delete origin;
}

template<typename T>
Lista<T>& Lista<T>::operator=(const Lista& o) {
	if(o != (*this)) {
		copy_from(o);
	}
}

template<typename T>
void Lista<T>::insert(unsigned pos, T value) {
	if(pos < 0 || pos >= size) {
		// error: throw exception?
	}

	Lista::Cell c = origin;

	for(unsigned i = 0; i < pos; ++i) {
		c = &(c.next);
	}

	Lista::Cell *c_tmp = c.next;
	c.next = new Lista::Cell;

	(*c.next).value = value;
	(*c.next).next = c_tmp;

	// Acabamos incrementando el tamaño de nuestra lista.
	++(this->length);
}

template<typename T>
void Lista<T>::remove(unsigned pos) {
	if(pos < 0 || pos >= size) {
		// error: throw exception?
	}

	Lista::Cell c = origin;

	for(unsigned i = 0; i < pos; ++i) {
		c = &(c.next);
	}

	Lista::Cell c_tmp = c.next;
	c.next = c_tmp.next;

	c_tmp.next = nullptr;
	delete &c;

	// Acabamos incrementando el tamaño de nuestra lista.
	--(this->length);
}

template<typename T>
const T& Lista<T>::peek(unsigned pos) const {
	if(pos < 0 || pos >= size) {
		// error: throw exception?
	}

	Lista::Cell c = origin;

	for(unsigned i = 1; i < pos; ++i) {
		c = &(c.next);
	}

	return c.value;
}

#endif