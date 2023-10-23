#include "Dynamic.h"

Dynamic::Dynamic(Matrix *macierzP) {
    iloscMiast = macierzP->iloscMiast;
    macierz = macierzP->macierz;

    wagi = new int *[1<<iloscMiast];
    for(int i = 0; i < (1<<iloscMiast); i++){
        wagi[i] = new int[iloscMiast];
    }
    for(int i = 0; i < (1<<iloscMiast); i++){
        for(int j = 0; j < iloscMiast; j++){
            wagi[i][j] = -1;
        }
    }

    sciezka = new int[iloscMiast+1];

    rodzice = new int *[1<<iloscMiast];
    for(int i = 0; i < (1<<iloscMiast); i++){
        rodzice[i] = new int[iloscMiast];
    }
    for(int i = 0; i < (1<<iloscMiast); i++){
        for(int j = 0; j < iloscMiast; j++){
            rodzice[i][j] = -1;
        }
    }

}

Dynamic::~Dynamic() {
    for (int i = 0; i < (1<<iloscMiast); i++) {
        delete[] wagi[i];

    }
    delete[] wagi;
}

//i - aktualne miasto
//S - zbior miast do odwiedzenia
//g - funkcja
//j - miasto wybrane ze zbioru do odwiedzenia
//macierz[i][j] - waga trasy od miasta i do j
//S - {j} - zbior minus odwiedzone wlasnie miasto - bitmaska zamiast tego
//g(i,S) = min (j E S) { macierz[i][j] + g( j, S - {j} )}
//

int Dynamic::RunDynamic(int aktualnyWierzcholek, int bitmaska) {

    //jesli S jest pusty (wszystkie miasta odwiedzone) to bierzemy wage od aktualnego (i) do startowego
    if(bitmaska == ((1<<iloscMiast)-1)){
        return macierz[aktualnyWierzcholek][0];
    }

    //sprawdzenie czy stan juz zostal policzony
    if(wagi[bitmaska][aktualnyWierzcholek] != -1){
        return wagi[bitmaska][aktualnyWierzcholek];
    }

    //na "schodzenie w dol", jak bedzie wracac w rekurencji to bedzie wynik = sumie wag od konca
    int wynik = INT_MAX;
    //
    for(int i = 0; i < iloscMiast; i++){
        if((bitmaska & (1<<i)) == 0){
            //poprzednia wersja, według wzoru, nie dzialalo przy tym wyswietlanie
            //wynik = std::min(wynik, macierz[aktualnyWierzcholek][i] + RunDynamic(i, bitmaska | (1<<i)));
            int waga = macierz[aktualnyWierzcholek][i] + RunDynamic(i, bitmaska | (1<<i));
            if(wynik > waga) {
                wynik = waga;
                //
                rodzice[bitmaska][aktualnyWierzcholek] = i;
            }
        }
    }

    //dodanie wagi wariantu sciezki do odpowiadającego jej miejsca w macierzy
    wagi[bitmaska][aktualnyWierzcholek] = wynik;
    return wynik;
}

void Dynamic::DisplayResults() {
//    for (int i = 0; i < (1<<iloscMiast); i++) {
//        std::cout << i << ": ";
//        for (int j = 0; j < iloscMiast; j++) {
//            std::cout << "[" << wagi[i][j] << "] ";
//        }
//        std::cout << std::endl;
//    }

    int wierzcholek = 0;
    int bitmaska = 1;
    for(int i = 0; i < iloscMiast; i++){
        sciezka[i] = wierzcholek;
        wierzcholek = rodzice[bitmaska][wierzcholek];
        bitmaska = bitmaska | (1<<wierzcholek);
        if(wierzcholek == -1){
            break;
        }
    }

    sciezka[iloscMiast] = 0;

    std::cout << "Sciezka:" << std::endl;
    for(int i = 0; i < iloscMiast + 1; i++){
        std::cout << "[" << sciezka[i] << "] ";
    }
    std::cout << std::endl;
}
