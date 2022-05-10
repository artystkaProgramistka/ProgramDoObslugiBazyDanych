#include <iostream>
#include "osoba.h"
#include <vector>

using namespace std;

/// wsteo do menu
void start();

/// menu glowne
void display_menu();
void d_age_menu();

void info();
void statystyki(vector<osoba> *w);
bool wczytaj(vector<osoba> *w);
void wyswietlWszystkieRekordy(vector<osoba> *w);
void wyswietl_poradnia(vector<osoba> *w);
void wyswietl_orzeczenie(vector<osoba> *w);
void rysuj_wykres(vector<osoba> *w);
bool sortuj_po_imieniu(osoba osoba1, osoba osoba2);
bool sortuj_po_nazwisku(osoba osoba1, osoba osoba2);
void sortuj_nazwisko(vector<osoba> *w);
void sortuj_imie(vector<osoba> *w);


/// wiecej opcji
void check_password();
void display_more_options();

void wyswietlanIE(vector<osoba> *w, int j, int i);
bool czy_pesel(string p);
bool wyszukaj_po_nazwiskU(vector<osoba> *w); /// error- osoba was not declared in scope
void dodawanie_rekordu(vector<osoba> *w);
bool usuwanie_rekordu(vector<osoba> *w, string s);
void wyswietlWszystko(vector<osoba> *w);
void usuwanie(vector<osoba> *w);
bool edycja(vector<osoba> *w);
