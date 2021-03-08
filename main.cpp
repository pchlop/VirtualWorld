#include <iostream>
#include "swiat.h"
#include <time.h>
#include <conio.h>
using namespace std;

int main()
{
    char a;
    cout << "NASTEPNA TURA: KLAWISZ 1" << endl << "ZAPISZ SWIAT: KLAWISZ 2" << endl << "WCZYTAJ SWIAT: KLAWISZ 2" << endl;
    
    srand(time(NULL));
    Swiat* swiat = new Swiat();
    while (cin >> a) {

        switch (a) {
        case 't':
            system("CLS");
            swiat->rysujSwiat();
            swiat->wykonajTure();
            break;
        case 'z':
            swiat->zapiszSwiat();
            break;
        case 'w':
           swiat->wczytajSwiat();
           system("CLS");
           swiat->rysujSwiat();
            break;
        default:
            //cout << "PODAJ PRAWIDLOWY ZNAK" << endl;
            break;
        }
    }

    return 0;
}
