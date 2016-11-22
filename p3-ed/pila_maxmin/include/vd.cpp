
#ifndef __VD_CPP
#define __VD_CPP

#include "vd.h"

#include <stdexcept>

template<typename T>
void VD<T>::copy_from(const VD& o) {
	if(data != nullptr) delete[] data;

	this->capacity = o.capacity;
	this->data = new T[o.capacity];
	this->length = o.length;

	for(unsigned i = 0; i < o.length; ++i) {
		(*this)[i] = o[i];
	}
}

template<typename T>
void VD<T>::resize(const unsigned capacity) {
	if(capacity < 0) {
//		throw new std::out_of_range("0 <= pos < this->size()");
	}

	T *data_new = new T[capacity];

	if(data != nullptr) {
		for(unsigned i = 0; i < capacity; ++i) {
			data_new[i] = data[i];
		}

		delete[] this->data;
	}

	this->capacity = capacity;
	this->data = data_new;
	this->length = (length > capacity) ? capacity : length;
}

template<typename T>
VD<T>::VD(unsigned capacity) {
	this->capacity = capacity;
	this->data = new T[capacity];
	this->length = 0;
}


template<typename T>
VD<T>::VD(const VD& o) {
	copy_from(o);
}


template<typename T>
VD<T>::~VD() {
	if(data != nullptr) delete[] data;
}


template<typename T>
VD<T>& VD<T>::operator=(const VD& o) {
	if(&o != this) {
		copy_from(o);
	}
}


template<typename T>
const T& VD<T>::operator[](unsigned pos) const {
	if(pos < 0 || pos >= capacity) {
//		throw new std::out_of_range("0 <= pos < this->size()");
	}

	return data[pos];
}

template<typename T>
void VD<T>::insert(unsigned pos, T value) {
	if(pos < 0 || pos > size()) {
//		throw new std::out_of_range("0 <= pos < this->size()");
	}

	if (length == capacity) {
		resize(capacity+10);
	}

    for(unsigned i = length; i > pos; --i) {
        data[i] = data[i-1];
    }

	data[pos] = value;
	++(this->length);
}


template<typename T>
void VD<T>::remove(unsigned pos) {
	if(pos < 0 || pos > length) {
//		throw new std::out_of_range("0 <= pos < this->size()");
	}


    for(unsigned i = pos; i < length-1; ++i) {
        data[i] = data[i+1];
    }

    --(this->length);
}

 #endif