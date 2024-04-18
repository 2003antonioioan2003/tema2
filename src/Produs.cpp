//
// Created by tabla on 4/13/2024.
//

#include "Produs.h"

Produs::Produs() : nume_produs(""), calorii(0), pret(0) {}

Produs::Produs(const std::string& numele, int caloriile, int pretul) : nume_produs(numele), calorii(caloriile), pret(pretul) {}

bool Produs::operator==(const Produs& produs) const {
    return (this->nume_produs == produs.nume_produs && this->calorii == produs.calorii && this->pret == produs.pret);
}

const std::string& Produs::getNumeProdus() const {
    return nume_produs;
}

int Produs::getCalorii() const {
    return calorii;
}

int Produs::getPret() const {
    return pret;
}

std::istream& operator>>(std::istream& in, Produs& produs) {
    std::cout << "Nume produs:" << std::endl;
    in.ignore();
    std::getline(in, produs.nume_produs);
    std::cout << std::endl;
    std::cout << "Calorii:" << std::endl;
    in >> produs.calorii;
    std::cout << "Pret:" << std::endl;
    in >> produs.pret;
    return in;
}

