//
// Created by tabla on 4/13/2024.
//

#ifndef UNTITLED2_RESTAURANT_H
#define UNTITLED2_RESTAURANT_H


#include "Produs.h"
#include "Bauturi.h"
#include "Alcolice.h"
#include "NonAlcolice.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Restaurant {
private:
    std::string nume_restaurnat; //numele restaurantului
    int an_finantare;
    std::vector<Produs> meniu; //pt a folosi agregarea meniu va contine produse din clasa Produs
    std::vector<Bauturi*> bauturi;
    static const int maxim = 5;



public:
    const std::vector<Bauturi *> &getBauturi() const;

    Restaurant();
    Restaurant(const std::string& numele, int an);
    Restaurant(const Restaurant& alt);
    Restaurant& operator=(const Restaurant& restaurant);
    ~Restaurant();

    void adauga_bautura(Bauturi* bautura);
    void afisare_bauturi();
    void adaugaProdus(const Produs& produs);
    void stergeProdus(const Produs& produs);

    friend std::ostream& operator<<(std::ostream& out, const Restaurant& restaurant);
    friend std::istream& operator>>(std::istream& in, Restaurant& restaurant);
    Restaurant& operator+(const Restaurant& restaurant);
    friend Restaurant operator-(const Restaurant& res1, int nr);

    void creareMeniu();
    void average() const;
    void sortare_calorii();
    void afisare_meniu() const;

    const std::string& getNumeRestaurnat() const;
    int getAnFinantare() const;

    const std::vector<Produs> &getMeniu() const;
};


#endif //UNTITLED2_RESTAURANT_H
