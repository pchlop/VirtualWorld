#pragma once
#include "zwierze.h"

class Slimak : public Zwierze {
public:
    Slimak(Swiat* world);
    Slimak(Swiat* world, int x, int y);
    void akcja();
   
    char rysowanie();
};
