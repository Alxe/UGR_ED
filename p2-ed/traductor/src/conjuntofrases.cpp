#include <algorithm>
#include "conjuntofrases.h"

std::ostream &operator<<(std::ostream &os, const ConjuntoFrases &cf) {
    for (auto &&f : cf.GetFrases()) {
        for (auto &&fd : f.GetDestino()) {
            os << f.GetOrigen() << ";" << fd << std::endl;
        }
    }

    return os;
}

std::istream &operator>>(std::istream &is, ConjuntoFrases &cf) {
    while (is) {
        std::string origen, destino;
        std::getline(is, origen, ';');
        std::getline(is, destino, '\n');

        if(!(origen.empty()) && !(destino.empty())) {
            cf.AddFrase(origen, destino);
        }
    }

    return is;
}

bool ConjuntoFrases::Esta(const std::string &str) const {
    std::string str_lc(str);
    std::transform(str_lc.begin(), str_lc.end(), str_lc.begin(), ::toupper);

    for (auto it = frases.begin(); it != frases.end(); ++it) {
        std::string f_lc((*it).GetOrigen());
        std::transform(f_lc.begin(), f_lc.end(), f_lc.begin(), ::toupper);

        if (str_lc == f_lc) {
            return true;
        }
    }

    return false;
}

Frase& ConjuntoFrases::GetTraducciones(const std::string &str) {
    std::string str_lc(str);
    std::transform(str_lc.begin(), str_lc.end(), str_lc.begin(), ::toupper);

    for (auto it = frases.begin(); it != frases.end(); ++it) {
        std::string f_lc((*it).GetOrigen());
        std::transform(f_lc.begin(), f_lc.end(), f_lc.begin(), ::toupper);

        if (str_lc == f_lc) {
            return *(it);
        }
    }
    throw std::runtime_error("Se ha llamado a GetTraducciones sin comprobar que la cadena esté");
}

ConjuntoFrases ConjuntoFrases::Contenga(const std::string &sub_str) const {
    std::string str(sub_str);
    std::transform(sub_str.begin(), sub_str.end(), str.begin(), ::tolower);

    ConjuntoFrases cf;

    for(auto&& f : frases) {
        std::string f_str(f.GetOrigen());
        std::transform(f.GetOrigen().begin(), f.GetOrigen().end(), f_str.begin(), ::tolower);

        if(f_str.find(str) != std::string::npos) {
            for (auto && d : f.GetDestino()) {
                cf.AddFrase(f.GetOrigen(), d);
            }
        }
    }

    return cf;
}

const std::vector<Frase> &ConjuntoFrases::GetFrases() const {
    return frases;
}

void ConjuntoFrases::AddFrase(const std::string origen, const std::string destino) {
    if (Esta(origen)) {
        GetTraducciones(origen).AddDestino(destino);

    } else {
        Frase f(origen, destino);

        bool inserted = false;
        for (auto it = frases.begin(); it != frases.end(); ++it) {
            if (inserted) break;

            if (f < *(it)) {
                frases.insert(it, f);
                inserted = true;
            }
        }

        if (!inserted) {
            frases.push_back(f);
        }
    }
}