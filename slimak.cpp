#include "slimak.h"

    Slimak::Slimak(Swiat* world) : Zwierze(world){
    sila = 1;
    inicjatywa = 1;
    }

    Slimak::Slimak(Swiat* world, int x, int y) : Zwierze(world, x, y) {
    sila = 1;
    inicjatywa = 1;
    }

    void kolizja();
    char Slimak::rysowanie() {
        return 'S';
    }

    void Slimak::akcja() {
        if (rand() % 10 == 0){
        if (zamrozony == 0) {
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

            if (wirtualny_swiat->mapa[nowy_x][nowy_y] == nullptr) {
                wirtualny_swiat->mapa[nowy_x][nowy_y] = wirtualny_swiat->mapa[pol_x][pol_y];
                wirtualny_swiat->mapa[pol_x][pol_y] = nullptr;
                this->setPozycja(nowy_x, nowy_y);
            }
            else {
                kolizja(this, wirtualny_swiat->mapa[nowy_x][nowy_y]);
            }
        }
        else {
            this->zmniejszZamrozenie();
        }
        }
    }
