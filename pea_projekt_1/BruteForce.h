#ifndef PEA_PROJEKT_1_BRUTEFORCE_H
#define PEA_PROJEKT_1_BRUTEFORCE_H

#include "Matrix.h"

class BruteForce {
public:

    int iloscMiast;
    int **macierz;
    int tempWagaDrogi;
    int najmniejszaWagaDrogi;
    int *tempDroga;
    int *najkrotszaDroga;
    int *odwiedzone;
    int tempDlugoscDrogi;
    //zmienna czas

    //przyjmuje poprzednio wczytaną z pliku macierz wag, oraz ilosc miast
    BruteForce(Matrix*);
    ~BruteForce();
    void runBruteForce(int);
    void displayResults();
};


#endif //PEA_PROJEKT_1_BRUTEFORCE_H
