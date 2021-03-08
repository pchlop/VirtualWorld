#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>


#define N 20

class Organizm;

using namespace std;

class Swiat {

public:
    Swiat();
    void wykonajTure();
    void rysujSwiat();
    void zapiszSwiat();
    void wczytajSwiat();
    Organizm* mapa[N][N];
    void zwiekszIloscOrganizmow();
    void zmnijeszIloscOrganizmow();
protected:
    
    int ilosc_organizmow;
    int tura; 
};
