#include "lista.h"

#include <iostream>

int main() {
	long size = 10;
	Lista<int> l;

	for(unsigned i = 0; i < size; ++i) {
        l.insert(0, i);
	}

    std::cout << "size=" << l.size() << std::endl;

    for(unsigned i = 0; i < 5; ++i) {
        l.remove(l.size()-1);
    }

    std::cout << "size=" << l.size() << std::endl;

	for(unsigned i = 0; i < l.size(); ++i) {
		std::cout << l.peek(i) << std::endl;
	}
}