#include "wilczejagody.h"

    WilczeJagody::WilczeJagody(Swiat* world) : Roslina(world){
    sila = 0;
    inicjatywa = 0;
    }

    WilczeJagody::WilczeJagody(Swiat* world, int x, int y) :Roslina(world, x, y) {
    sila = 0;
    inicjatywa = 0;
    }

    //void kolizja();
    char WilczeJagody::rysowanie() {
        return 'b';
    }
