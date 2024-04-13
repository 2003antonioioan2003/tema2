//
// Created by tabla on 4/13/2024.
//

#ifndef UNTITLED2_BAUTURI_H
#define UNTITLED2_BAUTURI_H


#include <iostream>
#include <string>
#include <stdexcept>

class Bauturi {
private:
    std::string nume;
    int pret;

public:
    Bauturi(const std::string& nume, int pret);
    virtual ~Bauturi();

    Bauturi& operator=(const Bauturi& other);

    virtual void drink() const = 0;
    virtual void aroma() const = 0;

    const std::string& getNume() const;
    int getPret() const;

    virtual void afisare(std::ostream& out) const;
    virtual void citire(std::istream& in);

    friend std::ostream& operator<<(std::ostream& out, const Bauturi& aux);
    friend std::istream& operator>>(std::istream& in, Bauturi& aux);
};

#endif //UNTITLED2_BAUTURI_H
