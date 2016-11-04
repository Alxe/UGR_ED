
#ifndef __LISTA_H
#define __LISTA_H

template<typename T>
class Lista {
	struct Cell {
		T value;
		Cell* next;

		inline Cell(T value) { value = value; next = nullptr; }

		inline ~Cell() { if(next != nullptr) delete next; }
	};

private:
	Cell *origin;
	unsigned length;

	void copy_from(const Lista& o) const;

public:
	Lista();

	Lista(const Lista& o);

	~Lista();

	Lista& operator=(const Lista& o);

	inline unsigned size() const { return length; }

	void insert(unsigned pos, T value);

	void remove(unsigned pos);

	const T& peek(unsigned pos) const; /*< operator[] */

};

#include "Lista.cpp"

#endif