
#ifndef __ELEMENTO_H
#define __ELEMENTO_H

#include <iostream>
#include <string>

struct elemento {
    int valor;
    int maximo;
    int minimo;

public:
    inline friend std::ostream& operator<<(std::ostream& os, const elemento& e) {
        return (os << "{valor=" << e.valor << ", maximo=" << e.maximo << ", minimo=" << e.minimo << "}");
    }
};

#endif