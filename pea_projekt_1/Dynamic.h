#ifndef PEA_PROJEKT_1_DYNAMIC_H
#define PEA_PROJEKT_1_DYNAMIC_H

#include "Matrix.h"

class Dynamic {
public:
    int iloscMiast;
    int **macierz;
    int **wagi;
    int *sciezka;
    int **rodzice;

    explicit Dynamic(Matrix*);
    ~Dynamic();
    int RunDynamic(int, int);
    void DisplayResults();
};


#endif //PEA_PROJEKT_1_DYNAMIC_H
