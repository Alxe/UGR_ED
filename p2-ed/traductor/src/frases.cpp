#include "frases.h"

void Frase::AddDestino(const std::string& translation) {
    destino.push_back(translation);
}

bool operator<(const Frase& lhs, const Frase& rhs) {
	return (lhs.GetOrigen() < rhs.GetOrigen());
}