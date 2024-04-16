#include <gtest/gtest.h>
#include "Produs.h"
#include "Restaurant.h"
#include "Bauturi.h"
#include "Alcolice.h"
#include "NonAlcolice.h"

TEST(ProdusTest, ConstructorAndEgalitate) {
    Produs p1;
    EXPECT_EQ(p1.getNumeProdus(), "");
    EXPECT_EQ(p1.getCalorii(), 0);
    EXPECT_EQ(p1.getPret(), 0);

    Produs p2("Produs1", 100, 50);
    EXPECT_EQ(p2.getNumeProdus(), "Produs1");
    EXPECT_EQ(p2.getCalorii(), 100);
    EXPECT_EQ(p2.getPret(), 50);

    Produs p3("Produs1", 100, 50);
    Produs p4("Produs1", 100, 50);
    Produs p5("Produs2", 150, 60);
    EXPECT_TRUE(p3 == p4);
    EXPECT_FALSE(p3 == p5);
}

TEST(RestaurantTest, ConstructorAndAdauga) {
    Restaurant r1;
    EXPECT_EQ(r1.getNumeRestaurnat(), "");
    EXPECT_EQ(r1.getAnFinantare(), 0);

    Produs p1("Produs1", 100, 50);
    Produs p2("Produs2", 150, 60);

    r1.adaugaProdus(p1);
    r1.adaugaProdus(p2);
    EXPECT_EQ(r1.getMeniu().size(), 2);

    r1.stergeProdus(p1);
    EXPECT_EQ(r1.getMeniu().size(), 1);
}

TEST(AlcoliceTest, Constructor) {
    Alcolice a("Wine", 15, 12);
    EXPECT_EQ(a.getNume(), "Wine");
    EXPECT_EQ(a.getPret(), 15);
    EXPECT_EQ(a.getProcentAlcool(), 12);
}
TEST(NonAlcoliceTest, Constructor) {
    NonAlcolice n("Orange Juice", 8, "Orange");
    EXPECT_EQ(n.getNume(), "Orange Juice");
    EXPECT_EQ(n.getPret(), 8);
    EXPECT_EQ(n.getFlavour(), "Orange");
}