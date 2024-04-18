//
// Created by tabla on 4/13/2024.
//

#ifndef UNTITLED2_PRODUS_H
#define UNTITLED2_PRODUS_H


#include <iostream>
#include <string>

class Produs {
private:
    std::string nume_produs;
    int calorii;
    int pret;

public:
    Produs();
    Produs(const std::string& numele, int caloriile, int pretul);
    bool operator==(const Produs& produs) const;
    const std::string& getNumeProdus() const;
    int getCalorii() const;
    int getPret() const;
    ~Produs() {}

    friend std::istream& operator>>(std::istream& in, Produs& produs);
};


#endif //UNTITLED2_PRODUS_H
