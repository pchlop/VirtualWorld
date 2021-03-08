#pragma once
#include "roslina.h"

class Trawa: public Roslina {
public:
    Trawa(Swiat* world);
    Trawa(Swiat* world, int x, int y);
    
    char rysowanie();
};
