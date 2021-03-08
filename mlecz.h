#pragma once
#include "roslina.h"

class Mlecz: public Roslina {
public:
    Mlecz(Swiat* world);
    Mlecz(Swiat* world, int x, int y);
    void akcja();
    char rysowanie();
};
