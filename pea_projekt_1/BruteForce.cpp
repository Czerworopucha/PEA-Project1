#include "BruteForce.h"
#include <iostream>

//tablica 2 wymiarowa - macierz wag, -1 tam gdzie nie ma przejscia
//temp int waga drogi = 0
//int - najmniejsza waga drogi dotychczas = startowo maxint
//temp tablica droga dotychczas = pusta, rozmiar = ilosc miast
//tablica - sciezka z najmniejsza waga dotychczas, size = iloscMiast+1
//int ilosc miast = ? wczytywane z pliku
//tablica ktory wierzcholek zostal odwiedzony
//int dlugosc aktualnej drogi = 0

//dodajemy do temp drogi numer wierzchołka -> int[dlugosc drogi] = row, dlugosc aktualnej drogi++
//if dlugosc drogi < ilosc miast:
    //oznaczamy jako odwiedzony -> int[row] = 1 (nieodwiedzony = 0)
    //dla sasiadow for(column = 0; column<liczba miast; column++)
        //bierzemy pierwszego nieodwiedzonego if(tablicaOdwiedzonych[column] == 0)
            //temp waga drogi += macierz[row][column]
            //rekurencyjnie wywołujemy dla tego wierzchołka runBruteForce(column)
            //temp waga drogi -= macierz[row][column]
    //oznaczamy jako nieodwiedzony -> int[row] = 0
                                //chyba niepotrzebne - //else - jeśli dlugosc drogi = ilosc miast - musimy wrocic do miasta startowego macierz[row][0]
//temp waga drogi += waga drogi z ostatniego odwiedzonego do A -> macierz [row][0]
//jesli najkrotsza droga do tej pory if(temp waga drogi < najmniejsza waga drogi)
    //to przypisz -> najmniejsza droga = temp droga
    // i skopiuj sciezke -> for(int i = 0; i < ilosc miast; i++)
        //najkrotsza sciezka[i] = temp droga [i]
    //najkrotsza sciezka[ilosc miast] = 0
//temp waga drogi -= macierz[row][0]
//dlugosc aktualnej drogi--

///TODO:
// - Pomiar Czasu !!! - w mainie
// - Przekazanie jakos tej macierzy
// - Destruktor
// - Wyswietlenie dlugosci najkrotszej sciezki i drogi (wierzcholki odwiedzone w kolejnosci)

BruteForce::BruteForce(Matrix *macierzP) {
    BruteForce::iloscMiast = macierzP->iloscMiast;
    BruteForce::macierz = macierzP->macierz;
    BruteForce::tempWagaDrogi = 0;
    BruteForce::najmniejszaWagaDrogi = INT_MAX;
    BruteForce::tempDroga = new int[iloscMiast];
    BruteForce::najkrotszaDroga = new int[iloscMiast+1];
    BruteForce::odwiedzone = new int[iloscMiast];
    for(int i = 0; i < iloscMiast; i++){
        odwiedzone[i] = 0;
    }
    BruteForce::tempDlugoscDrogi = 0;
}

BruteForce::~BruteForce() {
    //Usuwa tablice
    delete []tempDroga;
    delete []najkrotszaDroga;
    delete []odwiedzone;

}

void BruteForce::runBruteForce(int rzad) {
    //int kolumna;
    tempDroga[tempDlugoscDrogi] = rzad;
    tempDlugoscDrogi++;
    if(tempDlugoscDrogi < iloscMiast){
        odwiedzone[rzad] = 1;
        for(int kolumna = 0; kolumna < iloscMiast; kolumna++){
            if(odwiedzone[kolumna] == 0 && macierz[rzad][kolumna] != -1){
                tempWagaDrogi += macierz[rzad][kolumna];
                runBruteForce(kolumna);
                tempWagaDrogi -= macierz[rzad][kolumna];
            }
        }
        odwiedzone[rzad] = 0;
    }
    else if(tempWagaDrogi + macierz[rzad][0] < najmniejszaWagaDrogi){
        tempWagaDrogi += macierz[rzad][0];
        najmniejszaWagaDrogi = tempWagaDrogi;
        for(int i = 0; i < iloscMiast; i++){
            najkrotszaDroga[i] = tempDroga[i];
        }
        najkrotszaDroga[iloscMiast] = 0;
        tempWagaDrogi -= macierz[rzad][0];
    }
    tempDlugoscDrogi--;
}

void BruteForce::displayResults() {
    std::cout << "Wyniki:" << std::endl;
    for(int i=0; i < iloscMiast + 1; i++){
        std::cout << "[" << najkrotszaDroga[i] << "] ";
    }
    std::cout << std::endl;
    std::cout << "Waga: " << najmniejszaWagaDrogi << std::endl;
}