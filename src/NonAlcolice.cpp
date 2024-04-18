//
// Created by tabla on 4/13/2024.
//

#include "NonAlcolice.h"

NonAlcolice::NonAlcolice() : Bauturi("", 0), flavour("") {}

NonAlcolice::NonAlcolice(const std::string& nume, int pret, const std::string& aroma2) : Bauturi(nume, pret), flavour(aroma2) {}

NonAlcolice::NonAlcolice(const NonAlcolice& nonAlcolice) : Bauturi(nonAlcolice.getNume(), nonAlcolice.getPret()), flavour(nonAlcolice.flavour) {}

NonAlcolice& NonAlcolice::operator=(const NonAlcolice& other) {
    if (this != &other) {
        Bauturi::operator=(other);
        flavour = other.flavour;
    }
    return *this;
}

NonAlcolice::~NonAlcolice() {}

void NonAlcolice::drink() const {
    std::cout << "Aceasta bautura nu are alcool." << std::endl;
}

void NonAlcolice::aroma() const {
    std::cout << "Aceasta bautura are flavour de " << flavour << "! " << std::endl;
}

void NonAlcolice::citire(std::istream& in) {
    Bauturi::citire(in);
    std::cout << "Aroma : " << std::endl;
    in >> flavour;
}

void NonAlcolice::afisare(std::ostream& out) const {
    Bauturi::afisare(out);
    out << " + aroma :  " << flavour << std::endl;
}

const std::string &NonAlcolice::getFlavour() const {
    return flavour;
}

