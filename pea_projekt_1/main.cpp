#include <iostream>
#include "BruteForce.h"
#include "Matrix.h"
#include <chrono>
#include "Dynamic.h"

using namespace std;

int main() {

    auto *macierzP = new Matrix();
    int choice;
    string filename;

    do {
        cout << endl;
        cout << "==== MAIN MENU ====" << endl;
        cout << "1.Wczytaj dane z pliku" << endl;
        cout << "2.Wygeneruj losowe dane" << endl;
        cout << "3.Wyswietl Dane" << endl;
        cout << "4.Brute Force" << endl;
        cout << "5.Programowanie Dynamiczne" << endl;
        cout << "0.Exit" << endl;
        cout << "Wybor :" << endl;
        cin >> choice;


        switch (choice) {
            case 1:
                //Wczytywanie z pliku do dorobienia w klasie Matrix
                cout << "Podaj nazwe pliku: " << endl;
                cin >> filename;
                cout << endl;
                macierzP->LoadMatrixFromFile(filename);
                break;

            case 2:
                int iloscWierzcholkow;
                cout << "Podaj ilosc wierzcholkow: ";
                cin >> iloscWierzcholkow;
                //generacja losowa
                macierzP->GenerateRandomMatrix(iloscWierzcholkow);
                break;

            case 3:
                macierzP->DisplayMatrix();
                break;

            case 4: {
                BruteForce algorytmBT(macierzP);
                //pomiar
                auto start = chrono::high_resolution_clock::now();
                //algorytm
                algorytmBT.runBruteForce(0);
                //pomiar
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                //rezultat
                algorytmBT.displayResults();
                cout << "Czas wykonania algorytmu: " << duration.count() << " us" << endl;
                break;
            }

            case 5: {
                Dynamic algorytmDP(macierzP);
                //pomiar
                auto start = chrono::high_resolution_clock::now();
                //algorytm
                int wynik = algorytmDP.RunDynamic(0, 1);
                //pomiar
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                //wyswietlenie
                algorytmDP.DisplayResults();
                cout << "Waga: " << wynik << endl;
                cout << "Czas wykonania algorytmu: " << duration.count() << " us" << endl;
                break;
            }
        }
    }while(choice != 0);


    return 0;
}
