#pragma once
#include "zwierze.h"

class Jez : public Zwierze {
public:
    Jez(Swiat* world);
    Jez(Swiat* world, int x, int y);
    //void akcja();
    
    char rysowanie();
};
