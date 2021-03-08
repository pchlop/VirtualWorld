#pragma once
#include <iostream>
#include "organizm.h"
using namespace std;

class Roslina :public Organizm {
public:
    Roslina(Swiat* world);
    Roslina(Swiat* world, int x, int y);
    void akcja();
    void kolizja(Organizm* organizm, Organizm* przeciwnik);
};
