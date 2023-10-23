#ifndef PEA_PROJEKT_1_MATRIX_H
#define PEA_PROJEKT_1_MATRIX_H

#include "fstream"
#include "iostream"

class Matrix {
public:

    int iloscMiast;
    int **macierz;

    Matrix();
    ~Matrix();
    void DisplayMatrix();
    void GenerateRandomMatrix(int);
    void LoadMatrixFromFile(const std::string &filename);
};


#endif //PEA_PROJEKT_1_MATRIX_H
