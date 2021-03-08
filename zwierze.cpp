#include <iostream>
#include "zwierze.h"
#include "jez.h"
#include "owca.h"
#include "wilk.h"
#include "slimak.h"

using namespace std;

    Zwierze::Zwierze(Swiat* world) : Organizm(world) {}
    Zwierze::Zwierze(Swiat* world, int x, int y) : Organizm(world, x, y) {}


void Zwierze::akcja(){
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

void Zwierze::kolizja(Organizm* organizm, Organizm* przeciwnik) {
    if (organizm->rysowanie() != przeciwnik->rysowanie()) {
        if (organizm->getSila() >= przeciwnik->getSila()) {
            if ((przeciwnik->rysowanie() == 'S') && (organizm->getSila() > 4)){
                if (rand() % 10 > 6) {
                    organizm->akcja();
                    cout << "smilak spierdolil" << endl;
                }
            }
            if (przeciwnik->rysowanie() != 'J') {}
            else {
                organizm->zamroz();
            }

            if (przeciwnik->rysowanie() != 'b'){
                int px = przeciwnik->getPolozenieX();
                int py = przeciwnik->getPolozenieY();
                int ax = organizm->getPolozenieX();
                int ay = organizm->getPolozenieY();

                wirtualny_swiat->mapa[px][py]->setCzyZyje();
                wirtualny_swiat->mapa[px][py] = wirtualny_swiat->mapa[ax][ay];
                wirtualny_swiat->mapa[px][py]->setPozycja(px, py);
                wirtualny_swiat->mapa[ax][ay] = nullptr;
            }
            else {
                organizm->wirtualny_swiat->mapa[organizm->getPolozenieX()][organizm->getPolozenieY()] = nullptr;
                przeciwnik->wirtualny_swiat->mapa[przeciwnik->getPolozenieX()][przeciwnik->getPolozenieY()] = nullptr;
            }
            
        }



        else {
            if (organizm->rysowanie() != 'J') {}
            else {
                przeciwnik->zamroz();
            }
            organizm->wirtualny_swiat->mapa[organizm->getPolozenieX()][organizm->getPolozenieY()] = nullptr;
            wirtualny_swiat->zmnijeszIloscOrganizmow();
            cout << przeciwnik->rysowanie() << " zjadl " << organizm->rysowanie() << endl;
        }
    }
    else {
        rozmnazanie(przeciwnik);
    }
}

void Zwierze::rozmnazanie(Organizm* organizm) {
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
        if (this->rysowanie() == 'W') {
            Organizm* trawa = new Wilk(wirtualny_swiat, nowy_x, nowy_y);
        }
        if (this->rysowanie() == 'S') {
            Organizm* trawa = new Slimak(wirtualny_swiat, nowy_x, nowy_y);
        }
        if (this->rysowanie() == 'J') {
            Organizm* trawa = new Jez(wirtualny_swiat, nowy_x, nowy_y);
        }
        if (this->rysowanie() == 'O') {
            Organizm* trawa = new Owca(wirtualny_swiat, nowy_x, nowy_y);
        }
    }
}