#include "leniwiec.h"

    Leniwiec::Leniwiec(Swiat* world) : Zwierze(world){
    sila = 2;
    inicjatywa = 1;
    }

    Leniwiec::Leniwiec(Swiat* world, int x, int y) : Zwierze(world, x, y) {
    sila = 2;
    inicjatywa = 1;
    }

    void kolizja();
    char Leniwiec::rysowanie() {
        return 'L';
    }
