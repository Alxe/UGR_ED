
#ifndef __VD_H
#define __VD_H

template<typename T>
class VD {
private:
	T *data = nullptr;
	unsigned length = 0;
	unsigned capacity = 0;

	void copy_from(const VD& o);

	void resize(const unsigned capacity);

public:
	VD(unsigned capacity);

	VD(const VD& o);

	~VD();

	VD& operator=(const VD& o);

	T& operator[](unsigned pos);

	const T& operator[](unsigned pos) const;

	inline unsigned size() const { return length; }

	void insert(unsigned pos, T value);

	inline void push_back(T value) { insert(length, value); }

	inline void push_front(T value) { insert(0, value); }

	void remove(unsigned pos);

	inline void trim() { resize(length); }

};

#include "VD.cpp"

#endif