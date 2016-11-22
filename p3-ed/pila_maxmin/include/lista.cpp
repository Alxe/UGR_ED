
#ifndef __LISTA_CPP
#define __LISTA_CPP

#include "lista.h"

#include <stdexcept>

template<typename T>
Lista<T>::Cell::Cell(T value, Cell *next) {
	this->value = value;
	this->next = next;
}

//template<typename T>
//Lista<T>::Cell::Cell(const Cell& o) {
//    this->value = o.value;
//    this->next = o.next;
//}

template<typename T>
typename Lista<T>::Cell& Lista<T>::Cell::operator=(const Lista<T>::Cell& o) {
	if(this != &o) {
		this->value = o.value;
		this->next = o.next;
	}
}

template<typename T>
void Lista<T>::copy_from(const Lista<T>& o) {
	if(origin != nullptr) delete this->origin;

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
	if(&o != this) {
		copy_from(o);
	}
}

template<typename T>
void Lista<T>::insert(unsigned pos, T value) {
	if(pos < 0 || pos > length) {
		throw new std::out_of_range("0 <= pos < this->size()");
	}

	if(pos == 0) {
		origin = new Lista<T>::Cell(value, origin);

	} else {
		// Empezamos en el origen
		Lista<T>::Cell *c = origin;

		// Recorremos hasta obtener la posición buscada
		for(unsigned i = 1; i < pos; ++i) {
			c = c->next;
		}

		if(c->next == nullptr) {
			c->next = new Lista<T>::Cell(value);
		}
		else {
			// c almacena el valor de la posición buscada
			// c_tmp almacena la posible siguiente celda
			Lista<T>::Cell *c_tmp = (c->next);

			// Creamos una nueva celda y la asignamos a la posición siguiente
			c->next = new Lista<T>::Cell(value, c_tmp);
		}
	}

	// Acabamos incrementando el tamaño de nuestra lista.
	++(this->length);
}

template<typename T>
void Lista<T>::remove(unsigned pos) {
	if(pos < 0 || pos > length) {
		throw new std::out_of_range("0 <= pos < this->size()");
	}

	if(size() == 0) {
		throw new std::length_error("this->size() == 0");
	}

	if(size() == 1) {
		delete origin;

		origin = nullptr;

	} else {
		// Empezamos en el origen
		Lista<T>::Cell *c = origin;
		Lista<T>::Cell *c_tmp = nullptr;

		if(pos != 0) {
			// Recorremos hasta obtener la posición buscada
			for (unsigned i = 1; i < pos; ++i) {
				c = c->next;
			}
		}
			
		// c almacena el valor de la posición buscada
		// c_tmp almacena la posible siguiente celda
		c_tmp = c->next;

		// c.next = c.next.next
		if(pos != 0) {
			c->next = c_tmp->next;
		} else {
			origin = c_tmp->next;
		}

		c_tmp->next = nullptr;

		delete c_tmp;
	}

	// Acabamos decrementando el tamaño de nuestra lista.
	--(this->length);
}

template<typename T>
const T& Lista<T>::peek(unsigned pos) const {
	if(pos < 0 || pos > length) {
		throw new std::out_of_range("0 <= pos < this->size()");
	}

	// Empezamos en el origen
	Lista<T>::Cell *c = origin;

	// Recorremos hasta obtener la posición buscada
	for(unsigned i = 0; i < pos; ++i) {
		c = c->next;
	}

	return c->value;

}

#endif