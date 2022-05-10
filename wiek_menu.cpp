#include <iostream>
#include <windows.h>
#include "menu.h"//funkcja wczytaj
#include "wiek_menu.h"

using namespace std;

void d_age_menu(){ // wyswietla pod-menu oraz daje uzytkownikowy mozliwosc wybrania ktorejs z opcji

    string Menu[3] = {"sortuj rosnaco (od najmlodszych do najstarszych)", "sortuj malejaco (od najstarszych do najmladszych)", "\nWroc do menu glownego"};
    int pointer = 0;
    vector<osoba> w;
    if(!wczytaj(&w)) exit(-1);

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Sprecyzuj rodzaj sortowania ze wzgledu na wiek:\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Aby wybrac ktaras z opcji wcisnij strzalke w prawo (->)...\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		for (int i = 0; i < 3; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << Menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] << endl;
			}
		}

		while(true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0)
			{
				switch (pointer)
				{
					case 0:
					{
						system("cls");
						cout << "\nSortowanie uczniow rosnaco...\n\n"<<endl;
						sortuj_wiek_rosnaco(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
					} break;
					case 1:
					{
						system("cls");
						cout << "\nSortowanie uczniow malejaco...\n\n"<<endl;
						sortuj_wiek_malejaco(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
					} break;
					case 2:
                    {
                        Sleep(100);
                        display_menu();
                    }break;

				}
				break;
			}
			else if (GetAsyncKeyState(VK_ESCAPE) != 0){exit(0);}
		}

		Sleep(150);
	}

}

int miesiac(string p) // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_po wieku. zwraca liczbe bedaca miesiacem urodzenia uzytkownika
{
   int miesiac;
   miesiac=10*(p[2]-'0')+p[3]-'0';
   if (miesiac>20)
    {
        miesiac=miesiac-20;
    }
   return miesiac;
}

int rok(string p) // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_po wieku. zwraca liczbe bedaca rokiem urodzenia uzytkownika
{
   int rok;
   int miesiac;
   miesiac=10*(p[2]-'0')+p[3]-'0';
   if (miesiac>20)
    {
        rok=10*(p[0]-'0')+p[1]-'0'+2000;
    }
    else
        rok=10*(p[0]-'0')+p[1]-'0'+1900;
   return rok;
}

int dzien(string p) // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_po wieku.  zwraca liczbe bedaca dniem urodzenia uzytkownika
{
   int dzien;
   dzien=10*(p[4]-'0')+p[5]-'0';
   return dzien;
}

bool sortuj_po_wieku_malejaco(osoba A, osoba B) // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_wiek_malejaco
{
   if (rok(A.PESEL)==rok(B.PESEL))
   {
       if (miesiac(A.PESEL)==miesiac(B.PESEL))
       {
           if (dzien(A.PESEL)==dzien(B.PESEL))
                return A.nazwisko<B.nazwisko;
           else
                return dzien(A.PESEL)<dzien(B.PESEL);
       }
       return miesiac(A.PESEL)<miesiac(B.PESEL);
   }
   else
        return rok(A.PESEL)<rok(B.PESEL);
}

bool sortuj_po_wieku_rosnaco(osoba A, osoba B) // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_wiek_rosnaco
{
   if (rok(A.PESEL)==rok(B.PESEL))
   {
       if (miesiac(A.PESEL)==miesiac(B.PESEL))
       {
           if (dzien(A.PESEL)==dzien(B.PESEL))
                return A.nazwisko<B.nazwisko;
           else
                return dzien(A.PESEL)>dzien(B.PESEL);
       }
       return miesiac(A.PESEL)>miesiac(B.PESEL);
   }
   else
        return rok(A.PESEL)>rok(B.PESEL);
}

void wyswietlanie(vector<osoba> *w){ // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_wiek_malejaco i sortuj_wiek_rasnaco
    //wyswietla imie, nazwisko i date urodzenia oraz formy pomocy, z ktorych uczen korzysta. Nie wyswietla pesel'i uczniow.

    //wyswietlanie:
    int j=0;
    for(int i=0; i<w->size(); i++){
            if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
        cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko<<" "<<dzien((*w)[i].PESEL)<<" "<<miesiac((*w)[i].PESEL)<<" "<<rok((*w)[i].PESEL);
        if((*w)[i].opiniaIorzeczenie1=="1a"){
            cout<<"- posiada opinie z poradni psychologiczno-pedagogicznej";
        }else if((*w)[i].opiniaIorzeczenie1=="1b"){
            cout<<"- posiada orzeczenie o potrzebie dostosowania metod ksztalcenia";
        }

        if((*w)[i].nauczanie_indywidualne5 == '5'){
            cout<<" ; nauczanie indywidualne";
        }

        if((*w)[i].osrodki_socjoterapii11 == "11"){
            cout<<" ; korzysta z pomocy osrodka socjoterapii JEDRUS";
        }

        if((*w)[i].zDydaktycznoWyrownawcze16 == "16"){
            cout<<" ; uczeszcza na zajecia dydaktyczno-wyrownawcze";
        }

        if((*w)[i].zKorekcyjno_kompensacyjne17 == "17"){
            cout<<" ; uczeszcza na zajecia korekcyjno-kompensacyjne";
        }

        if((*w)[i].terapia18 == "18a"){
            cout<<" ; uczeszcza na zajecia z artterapii";
        }else if((*w)[i].terapia18 == "18k"){
            cout<<" ; KUP";
        }else if((*w)[i].terapia18 == "18r"){
            cout<<" ; uczeszcza na zajecia z rewalidacji";
        }else if((*w)[i].terapia18 == "18s"){
            cout<<" ; uczeszcza na zajecia z socjoterapii";
        }else if((*w)[i].terapia18 == "18p"){
            cout<<" ; spotkania indywidualne z psychologiem";
        }

        if((*w)[i].stypendiaIwyprawka19 == "19a"){
            cout<<" ; wyprawka";
        }else if((*w)[i].stypendiaIwyprawka19 == "19b"){
            cout<<" ; stypendia";
        }

        if((*w)[i].obiady21 == "21"){
            cout<<" ; obiady";
        }

        if((*w)[i].pomocRzeczowa22 == "22a"){
            cout<<" ; korzysta z form pomocy rzeczowej";
        }

        if((*w)[i].nadzorKuratoraSodawego24 == "24"){
            cout<<" ; korzysta z nadzoru kuratora sadawego";
        }

        if((*w)[i].zajeciaDCudzoziemcow25 == "25"){
            cout<<" ; uczeszcza na zejecia dla cudzoziemcow";
        }

        if((*w)[i].logopeda26 == "26"){
            cout<<" ; uczeszcza na zajecia logopedyczne";
        }
        cout<<endl<<endl;j++;

    }
}

void sortuj_wiek_rosnaco(vector<osoba> *w) // sortuje rosnaco; funkcja wywolywana z pod-menu
{
    // SORTOWANIE BABELKOWE
    for(int i=0; i<w->size(); i++){
        for(int j=w->size()-1; j>0; j--){

            if(!sortuj_po_wieku_rosnaco( (*w)[j-1], (*w)[j] )){
                osoba buf = (*w)[j-1];
                (*w)[j-1] = (*w)[j];
                (*w)[j] = buf;
            }
        }
    }wyswietlanie(w);
}

void sortuj_wiek_malejaco(vector<osoba> *w) // sortuje malejaco- od najstarszych do najmlodszych; funkcja wywolywana z pod-menu
{
    // SORTOWANIE BABELKOWE
    for(int i=0; i<w->size(); i++){
        for(int j=w->size()-1; j>0; j--){

            if(!sortuj_po_wieku_malejaco( (*w)[j-1], (*w)[j] )){
                osoba buf = (*w)[j-1];
                (*w)[j-1] = (*w)[j];
                (*w)[j] = buf;
            }
        }
    }wyswietlanie(w);
}
