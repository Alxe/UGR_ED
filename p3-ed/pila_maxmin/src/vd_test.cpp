#include "vd.h"

#include <iostream>

int main() {
	long size = 100;
	VD<int> vec;

	for(unsigned i = 0; i < size; ++i) {
//		vec.insert(i % 6, i);
        vec.push_back(i);
	}

    std::cout << "size=" << vec.size() << std::endl;

    for(unsigned i = 0; i < size/2; ++i) {
        vec.remove(vec.size());
    }

    std::cout << "size=" << vec.size() << std::endl;

	for(unsigned i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << std::endl;
	}
}