#include "mlecz.h"

    Mlecz::Mlecz(Swiat* world) : Roslina(world){
    sila = 0;
    inicjatywa = 0;
    cout << "powstal mlecz na polu" << this->getPolozenieX() << this->getPolozenieY() << endl;
    }

    Mlecz::Mlecz(Swiat* world, int x, int y) :Roslina(world, x, y) {
    sila = 0;
    inicjatywa = 0;
    }

   void kolizja();
    char Mlecz::rysowanie() {
        return 'm';
    }

    void Mlecz::akcja() {
        Roslina::akcja();
        Roslina::akcja();
        Roslina::akcja();
    }