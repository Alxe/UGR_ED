
all: bin/orden

bin/orden: obj/conjunto_enteros.o src/orden.cpp
	g++ -Wall -std=gnu++11 -o bin/orden src/orden.cpp obj/conjunto_enteros.o -Iinclude

obj/conjunto_enteros.o: include/conjunto_enteros.h
	g++ -Wall -std=gnu++11 -c src/conjunto_enteros.cpp -o obj/conjunto_enteros.o -Iinclude
