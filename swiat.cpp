#include "swiat.h"
#include "wilk.h"
#include "owca.h"
#include "slimak.h"
#include "jez.h"
#include "wilczejagody.h"
#include "mlecz.h"
#include "trawa.h"

Swiat::Swiat() {

    ilosc_organizmow = 0;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++){
            mapa[i][j] = nullptr;
        }
    }
    /*
    for (int i = 0; i < 7; i++) Organizm* organizm = new Wilk(this);
    for (int i = 0; i < 11; i++) Organizm* organizm = new Jez(this);
    for (int i = 0; i < 4; i++) Organizm* organizm = new Mlecz(this);
    for (int i = 0; i < 8; i++) Organizm* organizm = new Trawa(this);
    */
    /*
    Organizm* organizm1 = new Wilk(this,1,1);
    Organizm* organizm2 = new Wilk(this,16,16);
    Organizm* organizm3 = new Wilk(this,14,14);
    Organizm* organizm4 = new Wilk(this,8,8);
    Organizm* organizm5 = new Wilk(this,9,11);
    Organizm* organizm6 = new Jez(this,0,0);
    Organizm* organizm7 = new Jez(this,2,2);
    Organizm* organizm8 = new Jez(this,2,1);
    Organizm* organizm9 = new Jez(this,1,2);
    Organizm* organizm10= new Jez(this,1,3);
    Organizm* organizm11 = new Trawa(this,19,19);
    Organizm* organizm12 = new Trawa(this, 18, 3);
    Organizm* organizm13 = new Trawa(this, 17, 3);
    Organizm* organizm14 = new Trawa(this, 16, 3);
    Organizm* organizm15 = new Trawa(this, 15, 3);
    Organizm* organizm16 = new Trawa(this, 18, 4);
    Organizm* organizm17 = new Trawa(this, 17, 4);
    Organizm* organizm18 = new Trawa(this, 16, 4);
    Organizm* organizm19 = new Trawa(this, 15, 4);
    Organizm* organizm20 = new Trawa(this, 18, 5);
    Organizm* organizm21 = new Trawa(this, 17, 5);
    for (int i=0; i < 100; i++)Organizm* organizm23 = new WilczeJagody(this);
    

    for (int i=0; i < 200; i++)Organizm* organizm22 = new Trawa(this);

  */

   
     Organizm* mlecz = new Mlecz(this);
     Organizm* wilcza = new WilczeJagody(this);
     Organizm* trawa = new Trawa(this);
 

}


void Swiat::rysujSwiat() {

    cout << " AUTOR: Piotr Chlopski, nr albumu 151635" << endl << endl;
    cout << "X X X X X X X X X X X X X X X X X X X X " << endl;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (mapa[i][j] != nullptr){
                cout << mapa[i][j]->rysowanie() << " ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
        }
    cout << "X X X X X X X X X X X X X X X X X X X X " << endl;
}
/*
Organizm* Swiat::zapiszMape(int i, int j) {
    return mapa[i][j];
}
*/

void Swiat::wykonajTure() {
    int licznik = 0;
    Organizm* posortowaneOrganizmy[400];
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (mapa[i][j] != nullptr) {
                posortowaneOrganizmy[licznik] = mapa[i][j];
                licznik++;
            }
        }
    }
    for (int k = 0; k < licznik; k++) {
        for (int l = 0; l < licznik - 1; l++) {
            if (posortowaneOrganizmy[l]->getInicjatywa() != posortowaneOrganizmy[l + 1]->getInicjatywa()) {
                if (posortowaneOrganizmy[l]->getInicjatywa() < posortowaneOrganizmy[l + 1]->getInicjatywa()) {
                    swap(posortowaneOrganizmy[l], posortowaneOrganizmy[l + 1]);
                }
            }
            else {
                if (posortowaneOrganizmy[l]->getWiek() < posortowaneOrganizmy[l + 1]->getWiek()) {
                    swap(posortowaneOrganizmy[l], posortowaneOrganizmy[l + 1]);
                }
            }
        }
    }

    for (int i = 0; i < licznik; i++) {
        if (posortowaneOrganizmy[i]->getCzyZyje() == true) {
            posortowaneOrganizmy[i]->akcja();
            posortowaneOrganizmy[i]->zwiekszWiek();
        }
        }
    }

void Swiat::zwiekszIloscOrganizmow() {
    ilosc_organizmow++;
}
void Swiat::zmnijeszIloscOrganizmow() {
    ilosc_organizmow--;
}

void Swiat::zapiszSwiat() {
    std::fstream plik;
    plik.open("plikSwiata.txt", std::ios::out);
    

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (mapa[i][j] != nullptr) {
                plik << mapa[i][j]->rysowanie() << " " << i << " " << j << " " << mapa[i][j]->getSila() << " " << mapa[i][j]->getInicjatywa() << " " << mapa[i][j]->getWiek() << " " << mapa[i][j]->getZamrozony();
            }
        }
    }
}

void Swiat::wczytajSwiat(){
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            mapa[i][j] = nullptr;
        }
    }
    std::fstream plik;
    plik.open("plikSwiata.txt", std::ios::in);
    char nazwa;
    int tura;
    int x, y, sila, inicjatywa, wiek, zamrozenie;
    


    while (!plik.eof())
    {
        plik >> nazwa;
        plik >> x;
        plik >> y;
        plik >> sila;
        plik >> inicjatywa;
        plik >> wiek;
        plik >> zamrozenie;

        Organizm* organizm = nullptr;

        switch (nazwa)
        {
        case 'W':
            organizm = new Wilk(this, x, y);
            break;
        case 'O':
            organizm = new Owca(this, x, y);
            break;
        case 'J':
            organizm = new Jez(this, x, y);
            break;
        case 'S':
            organizm = new Slimak(this, x, y);
            break;
        case 't':
            organizm = new Trawa(this, x, y);
            break;
        case 'b':
            organizm = new WilczeJagody(this, x, y);
            break;
        case 'm':
            organizm = new Mlecz(this, x, y);
            break;
        }

        organizm->setPozycja(x, y);
        organizm->setSila(sila);
        organizm->setInicjatywa(inicjatywa);
        organizm->setWiek(wiek);
        organizm->setZamrozony(zamrozenie);

        mapa[x][y] = organizm;

    }

}