#include <iostream>

using namespace std;

void d_age_menu();
void wyswietlanie(vector<osoba> *w);

int miesiac(string p);
int rok(string p);
int dzien(string p);
bool sortuj_po_wieku_rosnaco(osoba A, osoba B);
bool sortuj_po_wieku_malejaco(osoba A, osoba B);
void sortuj_wiek_malejaco(vector<osoba> *w);
void sortuj_wiek_rosnaco(vector<osoba> *w);
