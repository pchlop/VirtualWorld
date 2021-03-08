#include <iostream>
#include "roslina.h"
#include "mlecz.h"
#include "trawa.h"
#include "wilczejagody.h"
using namespace std;

    Roslina::Roslina(Swiat* world) : Organizm(world) {}
    Roslina::Roslina(Swiat* world, int x, int y) : Organizm(world, x, y) {}


void Roslina::akcja() {
    if (rand() % 100 < 25) {
        int nowy_x = this->pol_x;
        int nowy_y = this->pol_y;

        switch (rand() % 8) {
        case 0: nowy_y = nowy_y + 1; break;
        case 1: nowy_x = nowy_x + 1; nowy_y = nowy_y + 1; break;
        case 2: nowy_x = nowy_x + 1; break;
        case 3: nowy_x = nowy_x + 1; nowy_y = nowy_y - 1; break;
        case 4: nowy_y = nowy_y - 1; break;
        case 5: nowy_x = nowy_x - 1; nowy_y = nowy_y - 1; break;
        case 6: nowy_x = nowy_x - 1; break;
        case 7: nowy_x = nowy_x - 1; nowy_y = nowy_y + 1;  break;
        }

        if (nowy_x < 0) nowy_x = nowy_x + 2;
        if (nowy_x > 19) nowy_x = nowy_x - 2;
        if (nowy_y < 0) nowy_y = nowy_y + 2;
        if (nowy_y > 19) nowy_y = nowy_y - 2;

        if (wirtualny_swiat->mapa[nowy_x][nowy_y] == nullptr)
        {
            if (this->rysowanie() == 't') {
                Organizm* trawa = new Trawa(wirtualny_swiat, nowy_x, nowy_y);
            }
            if (this->rysowanie() == 'b') {
                Organizm* trawa = new WilczeJagody(wirtualny_swiat, nowy_x, nowy_y);
            }
            if (this->rysowanie() == 'm') {
                Organizm* trawa = new Mlecz(wirtualny_swiat, nowy_x, nowy_y);
            }
        }
    }
}

void Roslina::kolizja(Organizm* organizm, Organizm* przeciwnik) {

}

