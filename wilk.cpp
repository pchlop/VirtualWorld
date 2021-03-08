#include "wilk.h"

    Wilk::Wilk(Swiat* world) : Zwierze(world){
    sila = 9;
    inicjatywa = 5;
    cout << "powstal wilk na polu" << this->getPolozenieX() << this->getPolozenieY() << endl;
    }

    Wilk::Wilk(Swiat* world, int x, int y) : Zwierze(world, x, y) {
    sila = 9;
    inicjatywa = 5;
    cout << "powstal wilk na polu" << this->getPolozenieX() << this->getPolozenieY() << endl;
    }


    char Wilk::rysowanie() {
        return 'W';
    }
