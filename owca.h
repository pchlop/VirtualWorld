#pragma once
#include "zwierze.h"

class Owca : public Zwierze {
public:
    Owca(Swiat* world);
    Owca(Swiat* world, int x, int y);
   
    char rysowanie();
};
