//
// Created by tabla on 4/13/2024.
//

#ifndef UNTITLED2_NONALCOLICE_H
#define UNTITLED2_NONALCOLICE_H


#include "Bauturi.h"

class NonAlcolice : public Bauturi {
private:
    std::string flavour;

public:
    NonAlcolice();
    NonAlcolice(const std::string& nume, int pret, const std::string& aroma2);
    NonAlcolice(const NonAlcolice& nonAlcolice);
    NonAlcolice& operator=(const NonAlcolice& other);
    virtual ~NonAlcolice();

    void drink() const override;
    void aroma() const override;
    void citire(std::istream& in) override;
    void afisare(std::ostream& out) const override;

    const std::string &getFlavour() const;
};

#endif //UNTITLED2_NONALCOLICE_H
