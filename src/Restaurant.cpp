//
// Created by tabla on 4/13/2024.
//

#include "Restaurant.h"

Restaurant::Restaurant() : nume_restaurnat(""), an_finantare(0) {}

Restaurant::Restaurant(const std::string& numele, int an) : nume_restaurnat(numele), an_finantare(an) {}

Restaurant::Restaurant(const Restaurant& alt) : nume_restaurnat(alt.nume_restaurnat), an_finantare(alt.an_finantare), meniu(alt.meniu) {}

Restaurant& Restaurant::operator=(const Restaurant& restaurant) {
    if (this != &restaurant) {
        nume_restaurnat = restaurant.nume_restaurnat;
        an_finantare = restaurant.an_finantare;
        meniu = restaurant.meniu;
    }
    return *this;
}

Restaurant::~Restaurant() {}

void Restaurant::adauga_bautura(Bauturi* bautura) {
    if (bauturi.size() < maxim) {
        bauturi.push_back(bautura);
    } else {
        std::cout << "Meniul de bauturi e plin" << std::endl;
    }
}

void Restaurant::afisare_bauturi() {
    std::cout << "Bauturile noastre : ..." << std::endl;
    for (int i = 0; (unsigned long long)i < bauturi.size(); ++i) {
        //Folosire downcasting
        if (Alcolice* alcolice = dynamic_cast<Alcolice*>(bauturi[i])) {
            std::cout << "***Bautura Alcoolica***" << std::endl;
            std::cout << *alcolice;
            std::cout << "Te imbeti de la atatea bauturi: ";
            std::cout << alcolice->betie(100) << std::endl;
        } else if (NonAlcolice* const nonalcolice = dynamic_cast<NonAlcolice*>(bauturi[i])) {
            std::cout << "***Bautura NonAlcoolica***" << std::endl;
            std::cout << *nonalcolice;
        }
        //Folosire upcasting
        bauturi[i]->drink();
        bauturi[i]->aroma();
    }
}

void Restaurant::adaugaProdus(const Produs& produs) {
    meniu.push_back(produs);
}

void Restaurant::stergeProdus(const Produs& produs) {
    for (auto elem = meniu.begin(); elem != meniu.end(); ++elem) {
        if (*elem == produs) {
            meniu.erase(elem);
            return;
        }
    }
    std::cout << "Nu exista acest produs" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Restaurant& restaurant) {
    out << "Nume restaurant : " << restaurant.nume_restaurnat << std::endl;
    out << "An finantare : " << restaurant.an_finantare << std::endl;
    out << "Meniul : ";
    for (auto& produs : restaurant.meniu) {
        out << produs.getNumeProdus() << " ,";
    }
    std::cout << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Restaurant& restaurant) {
    std::cout << "Nume restaurant:" << std::endl;
    in.ignore();
    std::getline(in, restaurant.nume_restaurnat);
    std::cout << "An finantare:" << std::endl;
    in >> restaurant.an_finantare;
    return in;
}

Restaurant& Restaurant::operator+(const Restaurant& restaurant) {
    this->nume_restaurnat += restaurant.nume_restaurnat;
    this->an_finantare = restaurant.an_finantare;
    this->meniu.insert(this->meniu.end(), restaurant.meniu.begin(), restaurant.meniu.end());
    return *this;
}

Restaurant operator-(const Restaurant& res1, int nr) {
    return Restaurant(res1.getNumeRestaurnat(), res1.getAnFinantare() - nr);
}

void Restaurant::creareMeniu() {
    std::cout << "Buna ziua , va vom crea un meniu personaliza" << std::endl;
    std::cout << "Va rog introduceti bugetul dvs : ";
    int buget;
    std::cin >> buget;
    int calorii;
    std::cout << "Care este numarul maxim de calorii pe care vreti sa il mancati :";
    std::cin >> calorii;
    std::vector<Produs> menu = meniu;
    std::sort(menu.begin(), menu.end(), [](const Produs& pr1, const Produs& pr2) {
        return pr1.getCalorii() > pr2.getCalorii();
    });
    std::vector<Produs> alegere;
    std::cout << "Va rog raspundeti cu 1 pt DA SAU 2 pt NU" << std::endl;
    for (const auto& produs : menu) {
        if (buget > 0) {}
        std::cout << "Vreti sa adaugam : " << produs.getNumeProdus() << " ?" << std::endl;
        int i;
        std::cin >> i;
        if (i == 1) {
            alegere.push_back(produs);
            buget = buget - produs.getPret();
        }
    }
    std::cout << "Meniul dvs arata asa : ";
    int i = 1;
    for (const auto& produs : alegere) {
        std::cout << i << "." << produs.getNumeProdus() << std::endl;
    }
}

void Restaurant::average() const {
    double suma = 0.0;
    for (const Produs& produs : meniu) {
        suma = suma + produs.getPret();
    }
    if (meniu.size() > 0) {
        std::cout << suma / meniu.size();
    }
    std::cout << 0.0;
}

void Restaurant::sortare_calorii() {
    std::sort(meniu.begin(), meniu.end(), [](const Produs& a, const Produs& b) {
        return a.getCalorii() < b.getCalorii();
    });
}

void Restaurant::afisare_meniu() const {
    std::cout << "Meniul arata in felul urmator : " << std::endl;
    int i = 1;
    for (const Produs& produs : meniu) {
        std::cout << i << "." << produs.getNumeProdus() << ":" << produs.getPret() << "lei :" << produs.getCalorii() << "calorii" << std::endl;
        i++;
    }
}

const std::string& Restaurant::getNumeRestaurnat() const {
    return nume_restaurnat;
}

int Restaurant::getAnFinantare() const {
    return an_finantare;
}

const std::vector<Produs> &Restaurant::getMeniu() const {
    return meniu;
}
