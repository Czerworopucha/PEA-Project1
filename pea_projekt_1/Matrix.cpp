#include "Matrix.h"
#include <iostream>
#include <random>

using namespace std;

Matrix::Matrix() {
    iloscMiast = 0;
    macierz = nullptr;
}

Matrix::~Matrix() {
    for (int i = 0; i < iloscMiast; i++) {
        delete[] macierz[i];

    }
    delete[] macierz;
}

void Matrix::DisplayMatrix() {
    for (int i = 0; i < iloscMiast; i++) {
        for (int j = 0; j < iloscMiast; j++) {
            cout << "[" << macierz[i][j] << "] ";
        }
        cout << endl;
    }
}

void Matrix::GenerateRandomMatrix(int iloscWierzcholkow) {
    iloscMiast = iloscWierzcholkow;
    int value;

    macierz = new int *[iloscMiast];
    for (int i = 0; i < iloscMiast; i++) {
        macierz[i] = new int[iloscMiast];
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(1, 30);

    //wypełnienie macierzy liczbami wygenerowanymi losowo

    for (int i = 0; i < iloscMiast; i++) {
        for (int j = 0; j < iloscMiast; j++) {
            if (i == j){
                macierz[i][j] = -1;
                continue;
            }
            value = distribution(gen);
            macierz[i][j] = value;
        }
    }
}

//iloscMiast = odczytana
//stworzenie macierzy
//macierz = new int*[iloscMiast];
//wypełnienie macierzy liczbami z pliku
void Matrix::LoadMatrixFromFile(const string &filename) {
    int value;
    string line;
    ifstream file(filename);

    if (file.good()){
        file >> iloscMiast;

        macierz = new int *[iloscMiast];
        for (int i = 0; i < iloscMiast; i++) {
            macierz[i] = new int[iloscMiast];
        }

        for(int i = 0; i < iloscMiast; i++){
            for(int j = 0; j < iloscMiast; j++){
                file >> value;
                macierz[i][j] = value;
            }
        }
        file.close();
    }
    else {
        cout << "Blad wczytywania z pliku" << endl;
    }
}


