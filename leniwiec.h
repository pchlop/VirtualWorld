#pragma once
#include "zwierze.h"

class Leniwiec : public Zwierze {
public:
    Leniwiec(Swiat* world);
    Leniwiec(Swiat* world, int x, int y);
    //void akcja();
  
    char rysowanie();
};
