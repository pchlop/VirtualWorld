#pragma once
#include "zwierze.h"

class Wilk : public Zwierze
{
public:
    Wilk(Swiat* world);
    Wilk(Swiat* world, int x, int y);
    
    char rysowanie();
    //void rozmnazanie();
};

