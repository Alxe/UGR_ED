#include <iostream>
#include <fstream>

#include "conjunto_enteros.h"

int main(int argc, char *argv[]) {
	if(argc != 3) {
		std::cout << "Error" << std::endl;
	}

	std::ifstream ifs;

	ifs.open(argv[1]);
	if(!ifs) {
		std::cout << "Error" << std::endl;
	}

	ConjuntoEnteros c1;
	ifs >> c1;
	ifs.close();

	ifs.open(argv[2]);
	if(!ifs) {
		std::cout << "Error" << std::endl;
	}

	ConjuntoEnteros c2;
	ifs >> c2;
	ifs.close();

	std::cout << "Rango de conjunto1: " << c1.range() << std::endl;
	std::cout << "Rango de conjunto2: " << c2.range() << std::endl;

	std::cout << "conjunto1 " << ((c1 < c2) ? "es" : "no es") << " menor que el conjunto2" << std::endl;
	std::cout << "conjunto1 " << ((c1.contains(c2)) ? "contine" : "no contine") << " al conjunto2" << std::endl;
}