#pragma once
#include <iostream>
#include "organizm.h"
using namespace std;

class Zwierze :public Organizm {

public:
    Zwierze(Swiat* world);
    Zwierze(Swiat* world, int x, int y);
    //virtual char rysowanie() = 0;
    void akcja();
    void kolizja(Organizm* organizm, Organizm* przeciwnik);
    void rozmnazanie(Organizm* organizm);
};


