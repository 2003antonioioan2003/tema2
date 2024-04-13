//
// Created by tabla on 4/13/2024.
//

#include "Alcolice.h"

Alcolice::Alcolice() : Bauturi("", 0), procent_alcool(0) {}

Alcolice::Alcolice(const std::string& nume, int pret, int procentAlcool) : Bauturi(nume, pret), procent_alcool(procentAlcool) {}

Alcolice::Alcolice(const Alcolice& alcolice) : Bauturi(alcolice.getNume(), alcolice.getPret()), procent_alcool(alcolice.procent_alcool) {}

Alcolice& Alcolice::operator=(const Alcolice& other) {
    if (this != &other) {
        Bauturi::operator=(other);
        procent_alcool = other.procent_alcool;
    }
    return *this;
}

Alcolice::~Alcolice() {}

void Alcolice::drink() const {
    std::cout << getNume() << " are procentul de alcolemie: " << procent_alcool << "%!" << std::endl;
}

void Alcolice::aroma() const {
    std::cout << "Bauturile alcolice au 95% flavour de tarie!" << std::endl;
}

int Alcolice::betie(int procent) {
    int i = 100;
    int count = 0;
    while (i > 0) {
        i = i / procent;
        count = count + 1;
    }
    return count;
}

void Alcolice::citire(std::istream& in) {
    Bauturi::citire(in);
    try {
        std::cout << "Procent alcool : " << std::endl;
        in >> procent_alcool;
        if (in.fail()) {
            in.clear();
            while (in.get() != '\n') continue;
            throw std::invalid_argument("TREBUIE NUMAR!");
        }
    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << std::endl;
    }
}

void Alcolice::afisare(std::ostream& out) const {
    Bauturi::afisare(out);
    out << " + procent de alcool :  " << procent_alcool << std::endl;
}

