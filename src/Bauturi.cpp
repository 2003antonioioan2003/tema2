//
// Created by tabla on 4/13/2024.
//

#include "Bauturi.h"

Bauturi::Bauturi(const std::string& nume, int pret) : nume(nume), pret(pret) {}

Bauturi::~Bauturi() {}

Bauturi& Bauturi::operator=(const Bauturi& other) {
    if (this != &other) {
        nume = other.nume;
        pret = other.pret;
    }
    return *this;
}

const std::string& Bauturi::getNume() const {
    return nume;
}

int Bauturi::getPret() const {
    return pret;
}

void Bauturi::afisare(std::ostream& out) const {
    out << "Nume:" << nume << " + pret: " << pret;
}

void Bauturi::citire(std::istream& in) {
    std::cout << "Nume bautura : " << std::endl;
    in.ignore();
    std::getline(in, nume);
    try {
        std::cout << "Pret Bautura:" << std::endl;
        in >> pret;
        if (in.fail()) {
            in.clear();
            while (in.get() != '\n') continue;
            throw std::invalid_argument("TREBUIE NUMAR!");
        }
    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bauturi& aux) {
    aux.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Bauturi& aux) {
    aux.citire(in);
    return in;
}

