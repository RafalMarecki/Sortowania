/*|===========================================================================================|*/
/*| KOMPILACJA KOMENDĄ: g++ losowanie.cpp losowanie.hh wiadomosc.cpp wiadomosc.hh driver.cpp  |*/
/*|===========================================================================================|*/
// DRIVER, Wywołujący wszystkie funkcje i metody klasy wiadomosc

#include "losowanie.hh"
#include "wiadomosc.hh"
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
using namespace std;

int main ()
{
    //==================================================
    // Nastepujace metody klasy wiadomosc: int podzial (wiadomosc &, int, int); oraz void sortowanie_szybkie (wiadomosc &, int, int); 
    // sluza do szybkiego sortowania i wywolywane sa w metodzie wiadomosc & odszyfruj (wiadomosc &); 
    //==================================================
    // nie mogę wywołać tu operatorów [], ponieważ do tego potrzebne mi jest użycie pól char *TEKST i int *KOLEJNOSC, które są polami private, klasy wiadomosc
    // operatory te, są jednak wykorzystywane w prawie kazdej metodzie klady wiadomosc.
    //==================================================

    srand(time(NULL));
    string tekst = "Ala ma kota";
    wiadomosc tmp; 
    int losowa;
    int rozmiar = 4, wylosowanych = 0;
    int wylosowane [rozmiar];

    //KONSTRUKTORY======================================
    wiadomosc X; // wiadomosc ();
    wiadomosc A (tekst); // wiadomosc (string);
    X = tekst; // wiadomosc & operator = (string);
    wiadomosc Y (X); // wiadomosc (const wiadomosc &);
    //==================================================
    tmp = X; // wiadomosc operator = (const wiadomosc &);
    //==================================================
    cout << "Test konstruktorow, metody wiadomosc wypisz() i wiadomosc operator = (const wiadomosc &)"<<endl;
    cout<<"X = "; X.wypisz(); cout<<endl; // wiadomosc wypisz();
    cout<<"tmp = "; tmp.wypisz(); cout<<endl<<endl;
    //==================================================
    cout << "Test metody wiadomosc zaszyfruj (wiadomosc), Y= Ala ma kota"<<endl;
    wiadomosc Z (Y.zaszyfruj(Y)); // wiadomosc zaszyfruj (wiadomosc);
    cout<<"wiadomosc Z (Y.zaszyfruj(Y)); Z = "; Z.wypisz(); cout<<endl<<endl; 
    //==================================================
    cout << "Test metody wiadomosc & odszyfruj (wiadomosc &);"<<endl;
    Z.odszyfruj(Z); // wiadomosc & odszyfruj (wiadomosc &); 
    cout<<"Z.odszyfruj(Z); Z = "; Z.wypisz(); cout<<endl<<endl;
    //==================================================
    cout << "Test funkcji int losuj (int) oraz bool czy_byla_wylosowana (int, int [], int);"<<endl;
    do 
    {
        losowa = losuj(rozmiar); // int losuj(int); czyli losowanie 
        cout<<"int losuj (rozmiar) = "<<losowa<<", czyli liczba losowa od 0 do rozmiar(4)"<<endl;
        cout <<" bool czy_byla_wylosowana(losowa, wylosowane, wylosowanych) = "<< czy_byla_wylosowana (losowa, wylosowane, wylosowanych) << endl << endl;
        if (czy_byla_wylosowana(losowa, wylosowane, wylosowanych)==false) // bool czy_byla_wylosowana (int, int [], int); jesli liczba byla juz wylosowana to nie jest zapisywana do tabeli
        {
            wylosowane [wylosowanych] = losowa;
            wylosowanych++;
        }
    } while (wylosowanych<rozmiar);
    cout << "Jesli liczba nie byla jeszcze wyloswoana, to zapisujemy je do tablicy wylosowane [rozmiar]"<<endl;
    cout << "wylosowane = ";
    for (int i=0; i<rozmiar; i++)
    {
        cout << wylosowane[i]<< " ";
    }
}


// while (dane.good())
//     {
//         for (int i=0; i<3; i++)
//         {
//             getline (dane, odczyt, ','); //odczytuję linię do przecinka

//             if (i==1) //podpisywanie tytułu
//             {
//                 this->TYTUL[j] = odczyt;
//             }

//             if (i==2) //podpisywanie oceny
//             {
//                 if (odczyt[1]=='.')
//                 {
//                     pomoc [0] = odczyt [0];
//                     this->OCENA[j] = stoi(pomoc);
//                     j++; //zwiększam licznik
//                 }
//                 if (odczyt[2]=='.')
//                 {
//                     this->OCENA[j] = 10;
//                     j++; //zwiększam licznik
//                 }          
//             }     
//         }
//     } 

// while (!dane.eof())
//     {
//         getline (dane, odczyt, ','); //odczytuję linię do przecinka
//         i++; // to, żeby ten pierwszy numer pominąć
//         if (i > 1) // o tutaj go pomijam i nie podpisuję do tytułu
//         {
//             this->TYTUL[j].append(odczyt); // podpisuję tytuł

//             bufor = dane.get(); 
//             if (bufor == '\n') // sprawdzam czy koniec linii
//             {
//                 if (odczyt.length() == 3) // jeśli odczytany pod koniec linii tekst ma długość 3 to jest formatu 1.0
//                 {
//                     pomoc [0] = odczyt [0];
//                     this->OCENA[j] = stoi(pomoc); // zamieniam na liczbę i podpisuję
//                     bufor = '!'; // resetuję bufor
//                     j++; // zmieniam na kolejny rekord
//                 }
//                 if (odczyt.length() == 4) // jeśli odczytany pod koniec linii tekst ma długość 4, to jest to liczba 10
//                 {
//                     this->OCENA[j] = 10;
//                     bufor = '!'; // resetuję bufor
//                     j++; // zmieniam na kolejny rekord
//                 }
//                 i = 0; // resetuję licznik, aby znów móc pominąć tę pierwszą liczbę z wiersza
//             }
//         }
//     }

// while (odcz_oceny.good() && odcz_tytulu.good())
//     {
//       getline(odcz_oceny, oceny, ';');
//       getline(odcz_tytulu, tytuly, ';');
//       if (stoi(oceny) != 0)
//       {
//         this->OCENA[j] = stoi(oceny); 
//         this->TYTUL[j] = tytuly;
//         cout << this->TYTUL[j] << " " << this->OCENA[j] <<endl;
//         j++;
//       }
//       for (int i = 0; i < 2; i++)
//       {
//         getline(odcz_oceny, oceny, ';');
//         getline(odcz_tytulu, tytuly, ';');
//       }
//     }  

    // ranking::ranking () //KONSTRUKTOR BEZARGUMENTOWY
    // {
    //     TYTUL = new string [ROZM];
    //     OCENA = new int [ROZM];
    // }

    // ranking::ranking (const ranking & X) // KONSTRUKTOR KOPIUJĄCY
    // {
    //     ROZM = X.ROZM;

    //     TYTUL = new char[strlen(X.TYTUL)+1];
    //     strcpy(TYTUL, X.TYTUL);
        
    //     OCENA = new int [ROZM = X.ROZM];
    //     for (int i=0; i<ROZM; i++)
    //     OCENA [i] = X.OCENA [i];
    // }