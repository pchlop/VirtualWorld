#pragma once
#include <iostream>
#include "swiat.h"

using namespace std;

class Organizm {
public:
    //KONSTRUKTORY
    Organizm(Swiat* world, int x, int y);
    Organizm(Swiat* world);

    //METODY WIRTUALNE DLA NASTEPNYCH ORGANIZMOW
    virtual void akcja() = 0;
    virtual void kolizja(Organizm* organizm, Organizm* przeciwnik) = 0;
    virtual char rysowanie() = 0;

    bool getCzyZyje();
    void setCzyZyje();
    void zamroz();
    void zmniejszZamrozenie();
    int getZamrozony();
    void setZamrozony(int);

    //GETTERy
    int getSila();
    int getInicjatywa();
    int getWiek();
    int getPolozenieX();
    int getPolozenieY();

    //SETTERy
    void setSila(int);
    void setInicjatywa(int);
    void setWiek(int);
    void setPozycja(int, int);
    void zwiekszWiek();
    Swiat* wirtualny_swiat;

protected:
    int sila;
    int inicjatywa;
    int pol_x;
    int pol_y;
    int wiek;
    bool czyZyje;
    int zamrozony;
};
