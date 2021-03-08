#include "organizm.h"
#include "swiat.h"

Organizm::Organizm(Swiat* world, int x, int y) {

    sila = 0;
    inicjatywa = 0;
    pol_x = x;
    pol_y = y;
    wiek = 0;
    czyZyje = true;
    wirtualny_swiat = world;
    world->mapa[pol_x][pol_y] = this;
    world->zwiekszIloscOrganizmow();
    zamrozony = 0;
  
}


Organizm::Organizm(Swiat* world) : Organizm(world, rand() % N, rand() % N){
}

//GETTERy
    int Organizm::getSila(){
        return sila;
    }
    int Organizm::getInicjatywa(){
        return inicjatywa;
    }
    int Organizm::getWiek(){
        return wiek;
    }
    int Organizm::getPolozenieX(){
        return pol_x;
    }
    int Organizm::getPolozenieY(){
        return pol_y;
    }

    //SETTERy
    void Organizm::setSila(int x){
        sila = x;
    }
    void Organizm::setInicjatywa(int x){
        inicjatywa = x;
    }
    void Organizm::setWiek(int x){
        wiek = x;
    }
    void Organizm::setPozycja(int x, int y){
        pol_x = x;
        pol_y = y;
    }
    void Organizm::zwiekszWiek() {
        wiek = wiek + 1;
    }

    bool Organizm::getCzyZyje(){
        return czyZyje;
    }
    void Organizm::setCzyZyje() {
        czyZyje = false;
    }

    void Organizm::zamroz() {
        zamrozony = 2;
    }

    void Organizm::zmniejszZamrozenie() {
        zamrozony--;
    }

    int Organizm::getZamrozony() {
        return zamrozony;
    }

    void Organizm::setZamrozony(int x) {
        zamrozony = x;
    }