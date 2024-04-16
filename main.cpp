#include <iostream>
#include <vector>
#include <algorithm>
#include "Produs.h"
#include "Restaurant.h"

void afisare_meniu(){
    std::cout<<"0.Exit"<<std::endl;
    std::cout<<"1.Vizualizare restaurante"<<std::endl;
    std::cout<<"2.Adauga restaurant"<<std::endl;
    std::cout<<"3.Modifica restaurant"<<std::endl;
    std::cout<<"4.Intrare Restaurant"<<std::endl;
    std::cout<<"Alegere: ";
}

void modifica_restaurant(){
    std::cout<<"0.Exit"<<std::endl;
    std::cout<<"1.Adauga produs"<<std::endl;
    std::cout<<"2.Sterge produs"<<std::endl;
    std::cout<<"3.Adauga bautura alcolica"<<std::endl;
    std::cout<<"4.Adauga bautura nonalcolica"<<std::endl;
    std::cout<<"Alegere:"<<std::endl;
}

void prelucrare_restaurant(){
    std::cout<<"0.Exit"<<std::endl;
    std::cout<<"1.Vizualizare meniu"<<std::endl;
    std::cout<<"2.Pret average/per produs"<<std::endl;
    std::cout<<"3.Sortare meniu in functie de calorii"<<std::endl;
    std::cout<<"4.Creare meniu"<<std::endl;
    std::cout<<"5.Vizualizare meniu de bauturi"<<std::endl;
    std::cout<<"Alegere:";
}


int main() {
    std::vector<Restaurant> restaurante;
    int size = 0;
    int choice;
    bool display_menu = true;
    while (display_menu) {
        afisare_meniu();
        std::cin >> choice;
        switch (choice) {
            case 0 : {
                display_menu = false;
                break;
            }
            case 1 : {
                if(restaurante.size() == 0){
                    std::cout<<"Nu exista restaurante"<<std::endl;
                }
                int m = 0;
                for(auto& restaurant : restaurante){
                    std::vector<Produs>men = restaurant.getMeniu();
                    std::cout<<m<<"."<<restaurant<<" cu atatea produse:"<<men.size()<<std::endl;
                    m++;
                }
                break;
            }
            case 2 : {
                Restaurant res;
                std::cin>>res;
                restaurante.push_back(res);
                size = size + 1;
                break;
            }
            case 3 : {
                std::cout<<"Alege nr restaurantului pe care vrei sa l modifici:";
                int c;
                std::cin>>c;
                if(c>=size){
                    break;
                }
                bool t = true;
                while(t){
                    modifica_restaurant();
                    int i;
                    std::cin>>i;
                    switch (i) {
                        case 0 : {
                            t = false;
                            break;
                        }
                        case 1 : {
                            Produs produs;
                            std::cin>>produs;
                            restaurante[c].adaugaProdus(produs);
                            break;
                        }
                        case 2 : {
                            Produs produs;
                            std::cin>>produs;
                            restaurante[c].stergeProdus(produs);
                            break;
                        }
                        case 3 : {
                            Alcolice* alcolice = new Alcolice;
                            std::cin >> *alcolice;
                            restaurante[c].adauga_bautura(alcolice);
                            break;
                        }
                        case 4 : {
                            NonAlcolice* nonAlcolice = new NonAlcolice;
                            std::cin >> *nonAlcolice;
                            restaurante[c].adauga_bautura(nonAlcolice);
                            break;
                        }
                    }
                }
                break;
            }
            case 4 : {
                std::cout<<"Alege nr restaurantului pe care vrei sa l modifici:";
                int c;
                std::cin>>c;
                if(c>=size){
                    break;
                }
                bool b = true;
                while(b){
                    prelucrare_restaurant();
                    int j;
                    std::cin>>j;
                    switch (j) {
                        case 0 : {
                            b = false;
                            break;
                        }
                        case 1 : {
                            restaurante[c].afisare_meniu();
                            break;
                        }
                        case 2 : {
                            restaurante[c].average();
                            break;
                        }
                        case 3 : {
                            restaurante[c].sortare_calorii();
                            break;
                        }
                        case 4 : {
                            restaurante[c].creareMeniu();
                            break;
                        }
                        case 5 : {
                            restaurante[c].afisare_bauturi();
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}

