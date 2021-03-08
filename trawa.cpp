#include "trawa.h"

    Trawa::Trawa(Swiat* world) : Roslina(world){
    sila = 0;
    inicjatywa = 0;
    cout << "powstal trawa na polu" << this->getPolozenieX() << this->getPolozenieY() << endl;
    }

    Trawa::Trawa(Swiat* world, int x, int y) :Roslina(world, x, y) {
    sila = 0;
    inicjatywa = 0;
    }

    void kolizja();
    char Trawa::rysowanie() {
        return 't';
    }
