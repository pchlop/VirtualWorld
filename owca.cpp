#include "owca.h"

    Owca::Owca(Swiat* world) : Zwierze(world){
    sila = 4;
    inicjatywa = 4;
    }

    Owca::Owca(Swiat* world, int x, int y) : Zwierze(world, x, y) {
    sila = 4;
    inicjatywa = 4;
    }

    void kolizja();
    char Owca::rysowanie() {
        return 'O';
    }
