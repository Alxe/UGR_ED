#include "VD.h"

#include <iostream>

int main() {
	VD<char> vec(100);

	char hw[] {'H', 'e', 'l', 'l', 'o', '\n', 'w', 'o', 'r', 'l', 'd', '!'};

	for(unsigned i = 0; i < 12; ++i) {
		vec.push_back(hw[i]);
	}
	std::cout << vec.size() << std::endl;

	vec.remove(vec.size()-1);

	std::cout << vec.size() << std::endl;

	for(unsigned i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << std::endl;
	}
}