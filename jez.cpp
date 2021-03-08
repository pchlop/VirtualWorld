#include "jez.h"

    Jez::Jez(Swiat* world) : Zwierze(world){
    sila = 2;
    inicjatywa = 3;
    cout << "powstal jez na polu" << this->getPolozenieX() << this->getPolozenieY() << endl;
    }

    Jez::Jez(Swiat* world, int x, int y) : Zwierze(world, x, y) {
    sila = 2;
    inicjatywa = 3;
    cout << "powstal jez na polu" << this->getPolozenieX() << this->getPolozenieY() << endl;
    }

   void kolizja();
    char Jez::rysowanie() {
        return 'J';
    }
