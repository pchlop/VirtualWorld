#pragma once
#include "roslina.h"

class WilczeJagody: public Roslina {
public:
    WilczeJagody(Swiat* world);
    WilczeJagody(Swiat* world, int x, int y);
   // void akcja();
    
    char rysowanie();
};
