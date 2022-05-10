#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <winbase.h>
#include "menu.h"
#include "wiek_menu.h"
#include "klasa_menu.h"
#include "wyszukaj_rekord_menu.h"

using namespace std;

void display_menu(){ // wyswietla menu glowne oraz daje uzytkownikowy mozliwosc wybrania ktorejs z opcji

    vector<osoba> w;
    if(!wczytaj(&w)) {cout<<"Wystapil blad podczas otwierania pliku dane_.txt"; exit(-1);}

    string Menu[13] = {"Informacje o programie", "Wyswietl wszystkie rekordy bazy danych",
    "\nWyswietl wszystkich uczniow posiadajacych opinie z poradni psychologiczno-pedagogicznej", "Wyswietl wszystkich uczniow posiadajacych orzeczenia o potrzebie ksztalcenia specjalnego",
    "\nWyszukaj uczniow ze wzgledu na klase, do ktorej naleza", "Sortuj po imieniu", "Sortuj po nazwisku",
    "Sortuj po wieku", "Wyszukaj rekord w bazie danych",
    "Narysuj wykres obrazujacy ilu uczniow korzysta z kazdej z form pomocy", "Statystyki", "Wiecej opcji", "Wyjscie",};
    int pointer = 0;

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Menu glowne\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Aby wybrac ktoras z opcji wcisnij klawisz spacja...\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		for (int i = 0; i < 13; ++i)
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
					pointer = 12;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 13)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(0x20) != 0)
			{
				switch (pointer)
				{
					case 0:
					{
						system("cls");
						info();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore();
						display_menu();
					} break;
					case 1:
					{
						system("cls");
						cout << "\nWyswietlanie wszystkich rekordow bazy danych...\n\n"<<endl;
						wyswietlWszystkieRekordy(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore();
						display_menu();
					} break;
					case 2:
                    {
                        system("cls");
                        cout<< "\nWypisywanie uczniow posiadajacych opinie...\n\n\n"; /// Poprawic, aby uczniowie zostali wypisani w porzadku alfabetycznym
                        wyswietl_poradnia(&w);
                        cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore(); Sleep(100); display_menu();
					}break;
					case 3:
                    {
                        system("cls");
                        cout<< "\nWypisywanie uczniow posiadajacych orzeczenia...\n\n\n";
                        wyswietl_orzeczenie(&w);
                        cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore(); Sleep(100); display_menu();
                    }break;
                    case 4:
                    {
                        d_class_menu();
                        Sleep(1000);
                    }break;
					case 5:
                    {
                        system("cls");
						cout << "\nSortowanie po imieniu...\n\n"<<endl;
						sortuj_imie(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore(); Sleep(100); display_menu();
                    }break;
					case 6:
					{
						system("cls");
						cout << "\nSortowanie po nazwisku...\n\n"<<endl;
						//Sleep(1000);
						sortuj_nazwisko(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore(); Sleep(100); display_menu();
					} break;
					case 7:
                    {
                        d_age_menu();
                        Sleep(100);
                    }break;
					case 8:
                    {
                        record_menu();
                    } break;
                    case 9:
                    {
                        system("cls");
                        cout<< "\nRysowanie wykresu...\n\n\n";
                        rysuj_wykres(&w);
                        cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore(); Sleep(100); display_menu();
                    }break;
                    case 10:
                    {
                        system("cls");
                        statystyki(&w);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
                        cout<<endl<<endl<<"Wcisnij enter, aby powrocic do menu glownego...";
						cin.ignore();cin.ignore(); Sleep(100); display_menu();
                    }break;
                    case 11:
                    {
                        check_password();
                    }break;
                    case 12:
                    {
                        exit(0);
                    }break;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_ESCAPE) != 0){exit(0);}
		}

		Sleep(150);
	}

}

void statystyki(vector<osoba> *w){
    SYSTEMTIME st;
    GetSystemTime(&st);

    for(int i=0; i<w->size(); i++){
        for(int j=w->size()-1; j>0; j--){

            if(!sortuj_po_wieku_rosnaco( (*w)[j-1], (*w)[j] )){
                osoba buf = (*w)[j-1];
                (*w)[j-1] = (*w)[j];
                (*w)[j] = buf;
            }
        }
    }SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
    cout<<endl<<"Statystyki:                                                                                                             "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);cout<<endl;
    cout<<"Najmlodszy uczen w bazie danych: ";cout<<(*w)[0].imie<<" "<<(*w)[0].nazwisko;
    for(int i=1; i<w->size(); i++){
        if( dzien((*w)[i].PESEL)==dzien((*w)[0].PESEL)   &&   miesiac((*w)[i].PESEL)==miesiac((*w)[0].PESEL)   &&   rok((*w)[i].PESEL)==rok((*w)[0].PESEL)){
            cout<<", "<<(*w)[i].imie<<" "<<(*w)[i].nazwisko;
        }else if ( dzien((*w)[i].PESEL)!=dzien((*w)[0].PESEL)   ||   miesiac((*w)[i].PESEL)!=miesiac((*w)[0].PESEL)   ||   rok((*w)[i].PESEL)!=rok((*w)[0].PESEL)){
            break;
        }
    }
    cout<<endl; int j = w->size()-1;
    cout<<"Najstarszy uczen w bazie danych: "<<(*w)[j].imie<<" "<<(*w)[j].nazwisko;
    for(int i=w->size()-2; i>0; i--){
        if( dzien((*w)[i].PESEL)==dzien((*w)[j].PESEL)   &&   miesiac((*w)[i].PESEL)==miesiac((*w)[0].PESEL)   &&   rok((*w)[i].PESEL)==rok((*w)[0].PESEL)){
            cout<<", "<<(*w)[i].imie<<" "<<(*w)[i].nazwisko;
        }else if ( dzien((*w)[i].PESEL)!=dzien((*w)[0].PESEL)   ||   miesiac((*w)[i].PESEL)!=miesiac((*w)[0].PESEL)   ||   rok((*w)[i].PESEL)!=rok((*w)[0].PESEL)){
            break;
        }
    }
    cout<<endl;
    ///SREDNIA WIEKU//////////////////////////
    int srednia=0;
    for(int i=1; i<w->size(); i++){

        srednia+=(st.wYear - rok((*w)[i].PESEL));
    }
    srednia=srednia/w->size();
    cout<<"Sredni wiek uczniow w bazie danych: "<<srednia<<endl;
    cout<<"Liczba uczniow w bazie danych: "<<w->size();
    cout<<endl;
}

void info()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
    cout<<endl;
    cout<<"Glowne informacje o programie                                                                                          "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<endl;
    cout<<endl;
    cout<<"Program jest przeznaczony do korzystania przez pracownikow Szkoly Podstawowej nr 1 im. O. Palmego w Jozefowie.         "<<endl;
    cout<<"Obsluguje on baze danych uczniow z klas 0-8, wymagajacych specjalnych form pomocy psychologiczno-pedagogicznej."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Autorzy programu : Dominika Leczycka "<<endl;
    cout<<"                   Izabella Kaim "<<endl;
    cout<<"                   z klasy 2C, IX L.O. im. K. Hoffmanowej"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Program skompilowany zostal w Code::Blocks v17.12"<<endl;
    cout<<"Data powstania: maj 2020"<<endl;
    cout<<"Ostatnia edycja zaszla 17.05.2020"<<endl;
}

bool wczytaj(vector<osoba> *w){// wczytywanie danych z pliku

    fstream input;
    input.open("dane_.txt", ios::in);
    if(!input.good())return false;

    int i=0;
    osoba o;
    while(!input.eof()){
        input>>o.nazwisko; input>>o.imie;
        input>>o.klasa;
        input>>o.PESEL; input>>o.opiniaIorzeczenie1;
        input>>o.nauczanie_indywidualne5;
        input>>o.osrodki_socjoterapii11;
        input>>o.zDydaktycznoWyrownawcze16;
        input>>o.zKorekcyjno_kompensacyjne17;
        input>>o.terapia18;
        input>>o.stypendiaIwyprawka19;
        input>>o.obiady21; input>>o.pomocRzeczowa22;
        input>>o.nadzorKuratoraSodawego24;
        input>>o.zajeciaDCudzoziemcow25; input>>o.logopeda26;
        //w++:*/
        (*w).push_back(o);
        i++;
    }
    input.close();
    return true;
}

void wyswietlWszystkieRekordy(vector<osoba> *w){ // wyswietla wszystkie rekordy bazy danych (uczniow i formy pomocy, z ktorych korzystaja), ale bez pesel'i
    int j=0;
    for(int i=0; i<w->size(); i++){
        wyswietlaniE(w,j,i);j++;
    }

}

void wyswietl_poradnia(vector<osoba> *w){ // wyswietla wszystkich uczniow posiadajacych opinie z poradni psychologiczno-pedagogicznej

    string str; int j=0;
    for(int i=0; i<(*w).size(); i++){


            if((*w)[i].opiniaIorzeczenie1=="1a"){

                if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
                else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

                str=(*w)[i].imie+" "+(*w)[i].nazwisko;

                str=(*w)[i].imie+" "+(*w)[i].nazwisko;

                cout<<setw(30);cout<<str<<"     ";
                if(j%3==0){cout<<endl;}
                j++;
            }
    }
}

void wyswietl_orzeczenie(vector<osoba> *w){ // wyswietla wszystkich uczniow posiadajacych orzeczenie z poradni psychologiczno-pedagogicznej

    int j=0; string str;
    for(int i=0; i<(*w).size(); i++){


            if((*w)[i].opiniaIorzeczenie1=="1b"){

                if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
                else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

                cout<<setw(20);cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko<<"     ";
                if(j%3==0){cout<<endl;}
                j++;
            }
    }if(j==2){cout<<"W bazie danych nie ma uczniow posiadajacych orzeczenie o potrzebie ksztalcenia specjalnego.";}
}

bool sortuj_po_imieniu(osoba osoba1, osoba osoba2){ // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_imie
    string imie;
    if(osoba1.imie<=osoba2.imie){imie=osoba1.imie;}
    else {imie=osoba2.imie;}

    for(int i=0; i<imie.length(); i++){
        if(osoba1.imie[i]<osoba2.imie[i]){return true;}
        if(osoba1.imie[i]>osoba2.imie[i]){return false;}
    }
    return true;
}

bool sortuj_po_nazwisku(osoba osoba1, osoba osoba2){ // funkcja pomocnicza wywolywana z wewnatrz funkcji sortuj_nazwisko
    string nazwisko;
    if(osoba1.nazwisko<=osoba2.nazwisko){nazwisko=osoba1.nazwisko;}
    else {nazwisko=osoba2.nazwisko;}

    for(int i=0; i<nazwisko.length(); i++){
        if(osoba1.nazwisko[i]<osoba2.nazwisko[i]){return true;}
        if(osoba1.nazwisko[i]>osoba2.nazwisko[i]){return false;}
    }
    return sortuj_po_imieniu(osoba1, osoba2);
    return true;
}

void sortuj_nazwisko(vector<osoba> *w){  // funkcja wywolywana z menu glownego; sortuje uczniow w porzadku alfabetycznym ze wzgledy na nazwisko, a nastepnie wyswietla w konsoli wszystkie rekordy (bez pesel'i uczniow)

    sort((*w).begin(), (*w).end(), sortuj_po_nazwisku);

    //wyswietlanie:
    int j=0;
    for(int i=0; i<(*w).size(); i++){
            if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
        cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko<<" ";
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

void sortuj_imie(vector<osoba> *w){ // funkcja wywolywana z menu glownego; sortuje uczniow w porzadku alfabetycznym ze wzgledy na imie, a nastepnie wyswietla w konsoli wszystkie rekordy (bez pesel'i uczniow)

    sort((*w).begin(), (*w).end(), sortuj_po_imieniu);

    //wyswietlanie:
    int j=0;
    for(int i=0; i<(*w).size(); i++){
            if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
        cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko<<" ";
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

void rysuj_wykres(vector<osoba> *w){ // rysuje wykres obrazujacy ilu uczniow korzysta z kazdej z form pomocy

    short a1=0; short b1=0; short p5=0; short j11=0; short s16=0; short s17=0; short a18=0; short k18=0;
    short r18=0; short s18=0; short p18=0;
    short a19=0; short b19=0; short d21=0; short d22=0; short d24=0; short d25=0; short d26=0;

    for(int i=0; i<(*w).size(); i++){

        if((*w)[i].opiniaIorzeczenie1=="1a"){
            a1++;
        }else if((*w)[i].opiniaIorzeczenie1=="1b"){
            b1++;
        }

        if((*w)[i].nauczanie_indywidualne5 == '5'){
            p5++;
        }

        if((*w)[i].osrodki_socjoterapii11 == "11"){
            j11++;
        }

        if((*w)[i].zDydaktycznoWyrownawcze16 == "16"){
            s16++;
        }

        if((*w)[i].zKorekcyjno_kompensacyjne17 == "17"){
            s17++;
        }

        if((*w)[i].terapia18 == "18a"){
            a18++;
        }else if((*w)[i].terapia18 == "18k"){
            k18++;
        }else if((*w)[i].terapia18 == "18r"){
            r18++;
        }else if((*w)[i].terapia18 == "18s"){
            s18++;
        }else if((*w)[i].terapia18 == "18p"){
            p18++;
        }

        if((*w)[i].stypendiaIwyprawka19 == "19a"){
            a19++;
        }else if((*w)[i].stypendiaIwyprawka19 == "19b"){
            b19++;
        }

        if((*w)[i].obiady21 == "21"){
            d21++;
        }

        if((*w)[i].pomocRzeczowa22 == "22a"){
            d22++;
        }

        if((*w)[i].nadzorKuratoraSodawego24 == "24"){
            d24++;
        }

        if((*w)[i].zajeciaDCudzoziemcow25 == "25"){
            d25++;
        }

        if((*w)[i].logopeda26 == "26"){
            d26++;
        }
    }
        short i;

        cout<<"opinie:                     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        // aby wykres byl ladniejszy, w przypadku opinii liczba wyswietlanych gwiazdek bedzie zalezala od uczniow posiadajacych opinie
        //(poniewaz zawsze prawie wszyscy uczniowie w bazie danych posiadaja opinie z poradni psychologiczno-pedagogicznej i bez tego zastosowania wiersz gwiazdek moglby sie zrobic zbyt dlogi).
        // w przypadku innych slopkow nie ma takiej potrzeby, poniewaz uczniow w bazie danych nigdy nie uzbiera sie az tyle, aby bylo to uzyteczne.
            if(a1<=70){
                for(i=0;i<a1;i++){cout<<"*";}cout<<" "<<a1<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else if(a1<140){
                for(i=0;i<a1/2;i++){cout<<"*";}cout<<" "<<a1<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else if(a1<210){
                for(i=0;i<a1/3;i++){cout<<"*";}cout<<" "<<a1<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else if(a1<280){
                for(i=0;i<a1/4;i++){cout<<"*";}cout<<" "<<a1<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else {for(i=0;i<a1;i++){cout<<"*";}cout<<" "<<a1<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
        cout<<"orzeczenia:                 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<b1;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"nauczanie indywidualne:     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<p5;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"osrodki socjoterapii:       ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<j11;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"z dydaktyczno-wyrownawcze:  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<s16;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"z korekcyjno-kompensacyjne: ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<s17;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"artterapia:                 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<a18;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"KUP:                        ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<k18;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"rewalidacja:                ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<r18;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"socjoterapia:               ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<s18;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"psycholog:                  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<p18;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"wyprawka: :                 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<a19;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"stypendia:                  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<b19;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"obiady:                     ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<d21;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"pomoc rzeczowa:             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<d22;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"kurator sadowy:             ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<d24;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"z dla cudzoziemcow:         ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<d25;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"logopeda:                   ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<"|";
        for(i=0;i<d26;i++){cout<<"*";}cout<<" "<<i<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<endl<<endl;
}

///.///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// wiecej opcji///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///- pod-menu//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void check_password(){ // aby uzyskac dostep do pod menu nalezy podac haslo administratora bazy danych (haslo123)

    string *password = new string;
    string *password1 = new string;
    //string password1,
    *password = "haslo123";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Podaj haslo aministratora bazy danych, aby uzyskac dostep do dodatkowych opcji:" ;cin>>*password1;
    int left_attempts = 3;
    if (password1->compare(*password)==0) {
            cout<<endl<<"Podano prawidlowe haslo "<<endl;

            cin.ignore();
            Sleep(1000);
            display_more_options();
    }
    while(password1->compare(*password)!=0){
        left_attempts--;
        if(left_attempts>0){
            cout<<endl<<"Ups! podano nieprawidlowe haslo. Podaj prawidlowe haslo administratora bazy danych: ";cin>>*password1;
        }else {
            cout<<endl<<"Przekroczyles liczbe prob. Zaraz nastapi zamkniecie programu...";
            Sleep(1000);
            exit(0);
            }
    }
    cout<<endl<<"Podano prawidlowe haslo "<<endl;
    cin.ignore();
    Sleep(1000);
    delete password, delete password1;
    display_more_options();


}

void display_more_options(){ // wyswietla menu wiecej_opcji oraz daje uzytkownikowy mozliwosc wybrania ktorejs z opcji
    vector<osoba> w;
    if(!wczytaj(&w)) exit(-1);

    string Menu[8] = {"Wyszukaj i usun z bazy danych wybrany rekord", "Dodaj rekord do bazy danych", "Edytuj rekord znajdujacy sie w bazie danych", "usun baze danych",
    "Wyswietl zawartosc bazy danych razem z PESEL'ami uzytkownikow",
    "Wyswietl informacje o danym uzytkowniku razem z PESEL'em uzytkownika", "Wroc do menu glownego", "Wyjscie"};
    int pointer = 0;

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Dodatkowe funkcje dostepne dla administratora bazy danych - Menu\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Aby wybrac ktaras z opcji wcisnij strzalke w prawo (->)...\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		for (int i = 0; i < 8; ++i)
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
					pointer = 7;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 8)
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
						cout << "\nUsuwanie z bazy danych osoby o PESEL'u podanym przez uzytkownika...\n\n"<<endl;
						if(!usuwanie_rekordu(&w, "\nPodaj PESEL osoby, ktora chcesz usunac z bazy danych: ")){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"osoby o podanym PESEL'u nie ma w bazie danych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); cin.ignore(); break;
					} break;
					case 1:
					{
						system("cls");
						cout << "\nDodawanie rekordu do bazy danych...\n\n"<<endl;
						dodawanie_rekordu(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); cin.ignore(); break;
					} break;
					case 2:
					{
						system("cls");
						cout << "\nEdytowanie rekordu bazy danych...\n\n"<<endl;
						if(!edycja(&w))
                            {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"osoby o podanym PESEL'u nie ma w bazie danych.";}
                        else cout<<"\nWlasnie dokonales edycji bazy danych.\n\n";
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); cin.ignore(); break;
					} break;
					case 3:
					{
						system("cls");
						usuwanie(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); cin.ignore(); break;
					} break;
					case 4:
                    {
                        system("cls");
						cout << "\n\n\nWyswietlanie zawartosci bazy danych...\n\n"<<endl;
						wyswietlWszystko(&w);
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); cin.ignore(); break;
                    } break;
                    case 5:
                    {
                        system("cls");
						cout << "\nWyszukiwanie rekordu po nazwisku...\n\n"<<endl;
						if(!wyszukaj_po_nazwiskU(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"osoby o podanym nazwisku nie ma w bazie danych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); cin.ignore(); system("cls"); break;
                    }break;
                    case 6:
                    {
                        cout << "\n\n\nPowrot do menu glownego...";
                        Sleep(1000);
                        display_menu();
                    }break;
                    case 7:
                    {
                        exit(0);
                    }break;
				}
				break;
			}else if (GetAsyncKeyState(VK_ESCAPE) != 0){exit(0);}
		}

		Sleep(150);
	}

}

void wyswietlanIE(vector<osoba> *w, int j, int i){ // funkcja pomocnicza wywolywana z wewnatrz innych funkcji

            if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
        cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko<<" "<<(*w)[i].PESEL;
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
        }//cout<<" "<<*j;
        cout<<endl<<endl;return;
}

bool wyszukaj_po_nazwiskU(vector<osoba> *w){ // wyszukuje rekord po nazwisky i wypisuje z jakich form pomocy korzysta dany uczen

    cout<<"\nPodaj nazwisko: ";string *n = new string; cin>>*n;
    bool b = false;
    int j=0;

    for(int i=0; i<w->size(); i++){
        if((* w)[i].nazwisko.compare(*n)==0){ b=true;
        wyswietlanIE(w, j, i);j++;}}
    delete n;
    return b;
}

bool czy_pesel(string p) // funkcja pomocnicza, sprawdza, czy podany przez uzytkownika ciag znakow to pesel
{
    int suma;
    suma=((p[0]-'0'+p[4]-'0'+p[8]-'0')*9+(p[1]-'0'+p[5]-'0'+p[9]-'0')*7+(p[2]-'0'+p[6]-'0')*3+p[3]-'0'+p[7]-'0');
    if (suma%10==p[10]-'0')
        return true;
    else
        return false;
}

void dodawanie_rekordu(vector<osoba> *w){ // dodaje rekord do bazy danych
    osoba A;
    bool ok=1;

    do{
        cout<<"\nPodaj imie. Uwaga! nie uzywaj polskich znakow.: "; cin>>A.imie;
        if(A.imie.length()<3){cout<<"Popelniles blad przy podawaniu imienia, podany przez Ciebie ciag znakow jest zbyt krotki, sproboj jeszcze raz."; ok=0;}
        else ok=1;
    }while(ok==0);

    do{
        cout<<"\nPodaj nazwisko. Uwaga! nie uzywaj polskich znakow.: "; cin>>A.nazwisko;
        if(A.nazwisko.length()<2){cout<<"Popelniles blad przy podawaniu nazwiska, podany przez Ciebie ciag znakow jest zbyt krotki, sproboj jeszcze raz."; ok=0;}
        else ok=1;
    }while(ok==0);

    do{
        cout<<"\nPodaj klase: "; cin>>A.klasa;
        if(A.klasa.length()==2) ok=1;
        else if(A.klasa.length()>2){cout<<"Popelniles blad przy podawaniu klasy, podany przez Ciebie ciag znakow jest zbyt dlugi, sproboj jeszcze raz."; ok=0;}
        else if(A.klasa.length()<2){cout<<"Popelniles blad przy podawaniu klasy, podany przez Ciebie ciag znakow jest zbyt krotki, sproboj jeszcze raz."; ok=0;}
    }while(ok==0);
    do{
        cout<<"\nPodaj PESEL: ";cin>>A.PESEL;
        if(czy_pesel(A.PESEL))ok=1;
        else {ok=0; cout<<"Podany przez Ciebie ciag znakow to nie jest pesel! Sproboj jeszcze raz.";}
    }while(ok==0);

    string odp;
    do{
        cout<<"Czy podana przez Ciebie osoba posiada opinie, czy orzeczenie o potrzebie ksztalcenia zpecjalnego? (opinia/orzeczenie): ";
        cin>>odp;

        for(int i=0; i<odp.length(); i++){ // zamiana na male litery
            odp[i]=tolower(odp[i]);
        }
        if(odp=="opinia"){A.opiniaIorzeczenie1="1a"; ok=1;}
        else if(odp=="orzeczenie"){A.opiniaIorzeczenie1="1b"; ok=1;}
        else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz."; ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba posiada zaswiadczenie o potrzebie zastosowania indywidualnego trybu nauczania? (t/n): ";
        cin>>odp;
        if(odp=="t" || odp=="T"){
            A.nauczanie_indywidualne5='5'; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.nauczanie_indywidualne5='-'; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z pomocy osrodka socjoterapii JEDRUS? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.osrodki_socjoterapii11="11"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.osrodki_socjoterapii11="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia dydaktyczno-wyrownawcze? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.zDydaktycznoWyrownawcze16="16"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.zDydaktycznoWyrownawcze16="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia korekcyjno-kompensacyjne? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.zKorekcyjno_kompensacyjne17="17"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.zKorekcyjno_kompensacyjne17="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);
    bool ok2=1;
    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia terapeutyczne? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){

            do{
                cout<<"\nPodaj na jaki typ zajec terapeutycznych uczeszcza dziecko (artterapia/KUP/rewalidacja/socioterapia/psycholog): ";
                cin>>odp;

                for(int i=0; i<odp.length(); i++){ // zamiana na male litery
                odp[i]=tolower(odp[i]);
                }
                if(odp=="artterapia"){ok2=1; A.terapia18="18a";}
                else if(odp=="kup"){ok2=1; A.terapia18="18k";}
                else if(odp=="rewalidacja"){ok2=1; A.terapia18="18r";}
                else if(odp=="socjoterapia"){ok2=1; A.terapia18="18s";}
                else if(odp=="psycholog"){ok2=1; A.terapia18="18p";}
                else {ok2=0;cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";}
            }while(ok2==0);
        }
        else if(odp=="n" || odp=="N"){
            A.terapia18="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z ufundowanego przez pomoce socjalne stypendium lub wyprawki? (t/n): ";cin>>odp;

        if(odp=="t" || odp=="T"){ // korzysta
            do{
                cout<<"\nStypendium czy wyprawka? (stypendium/wyprawka): ";cin>>odp;

                for(int i=0; i<odp.length(); i++){ // zamiana na male litery
                    odp[i]=tolower(odp[i]);
                }
                if(odp=="stypendium"){
                    A.stypendiaIwyprawka19="19b";ok2=1;
                }else if(odp=="wyprawka"){
                    A.stypendiaIwyprawka19="19a"; ok2=1;
                }else{
                    ok2=0;cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";
                }
            }while(ok2==0);

        }else if(odp=="n" || odp=="N"){ // nie korzysta
            A.stypendiaIwyprawka19="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba posiada w szkole ufundowane obiady? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.obiady21="21"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.obiady21="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z form pomocy rzeczowej? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.pomocRzeczowa22="22a"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.pomocRzeczowa22="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z nadzoru kuratora sadowego? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.nadzorKuratoraSodawego24="24"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.nadzorKuratoraSodawego24="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia dla cudzoziemcow? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.zajeciaDCudzoziemcow25="25"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.zajeciaDCudzoziemcow25="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia logopedyczne? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.logopeda26="26"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.logopeda26="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);
    /// zapytanie uzytkownika, czy chce zarchiwizowac stara wersje bazy danych
    do{
        cout<< "\nCzy chcesz zarchiwizowac stara baze danych (sprzed dodania do niej nowego rekordu)? t/n\n Uwaga! jesli zaznaczysz nie, wersji bazy danych sprzed dodania nowego rekordu nie bedziesz mogl juz odzyskac!\nMiejsce na Twoja odpowiedz (t/n): ";
        cin>>odp;
        if(odp=="t" || odp=="T"){//kopiuje zawartosc bazy danych do nowego pliku txt
            setlocale( LC_ALL, "" );
            cout<<"\n Wybrales opcję zarchiwizowania bazy danych. Stara wersia bazy danych zostanie zapisana pod nazwa \"dane_zarchiwizowane.txt\"."
            <<"\nPo zakonczeniu operacji mozesz znalezc plik o powyzszej nazwie w plikach programu i zmienic dowolnie jego nazwe."<<
            "\nJesli tego nie zrobisz, kolejne, zarchiwizowanie bazy danych spowoduje nadpisanie pliku.";

            ///cout<<"Jak zyczysz sobie, zeby nazywala sie zrchiwizowana przez Ciebie baza danych? \n(Uwaga: wpisz nazwe, bez rozszeszenia, nie uzywaj spacji ani polskich znakow): ";
            //cin>>odp; odp+=".txt";
            //ok = static_cast<bool>(ofstream(odp).put('a')); // create file
            /*const char odp2[(odp.length())];
            for(int i=0; i<odp.length(); i++){
                odp2[i]
            }*/

            ofstream output("dane_zarchiwizowane.txt");
            //rename("dane_zarchiwizowane.txt", odp);
            //output.open(odp, fstream::out);

            if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie stworzenia dokumentu "+odp;
                cout<<odp;Sleep(1000);
                exit(-2);
            }
            //przepisywanie zawartosci pliku "dane_.txt" do nowo stworzonego pliku tekstowego
            for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();
            //rename("dane_.txt", "dane_zarchiwizowane.txt");ok=1;
            //remove("dane_.txt");
        }else if(odp!="n" && odp!="N"){cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}

    }while(ok==0);
        w->push_back(A);

        fstream output("dane_.txt");
        if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie otworzenia dokumentu dane_.txt";
                cout<<odp;Sleep(1000);
                exit(-4);
        }
        for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();
}

bool usuwanie_rekordu(vector<osoba> *w, string s){ // prosi uzytkownika o podanie pesel'u ucznia, ktorego chce usunac z bazy danych i usuwa wybrany rekord.
    bool b=false;
    string odp;
    bool ok=1;

    do{
        cout<<s; cin>>odp;
        if(!czy_pesel(odp)){cout<<"Popelniles blad przy podawaniu PESEL'u, sproboj jeszcze raz."; ok=0;}
        else ok=1;
    }while(ok==0);
    /// wyszukiwanie, ktory index w wektorze ma struktura o podanym pesel'u
    int index;
    for (int i=0; i<w->size();i++){

        if((*w)[i].PESEL.compare(odp)==0){index=i; b=true; break;}
        if(b==0)return b;
    }if(b==1){ /// jesli w bazie danych znaleziono rekord o podanym peselu

    /// zapytanie uzytkownika, czy chce zarchiwizowac stara wersje bazy danych
    do{
        cout<< "\nCzy chcesz zarchiwizowac stara bazę danych (sprzed dodania do niej nowego rekordu)? t/n\n Uwaga! jesli zaznaczysz nie, wersji bazy danych sprzed dodania nowego rekordu nie bedziesz mogl juz odzyskac!\nMiejsce na Twoja odpowiedz (t/n): ";
        cin>>odp;
        if(odp=="t" || odp=="T"){//kopiuje zawartosc bazy danych do nowego pliku txt

            cout<<"\n Wybrales opcję zarchiwizowania bazy danych. Stara wersia bazy danych zostanie zapisana pod nazwą \"dane_zarchiwizowane.txt\"."
            <<"\nPo zakonczeniu operacji mozesz znalezc plik o powyzszej nazwie w plikach programu i zmienic dowolnie jego nazwe."<<
            "\nJesli tego nie zrobisz, kolejne, zarchiwizowanie bazy danych spowoduje nadpisanie pliku.";

            ///cout<<"Jak zyczysz sobie, zeby nazywala sie zrchiwizowana przez Ciebie baza danych? \n(Uwaga: wpisz nazwe, bez rozszeszenia, nie uzywaj spacji ani polskich znakow): ";
            ofstream output("dane_zarchiwizowane.txt");

            if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie stworzenia zarchiwizowania dokumentu.";
                cout<<odp;Sleep(1000);
                exit(-5);
            }
            ///przepisywanie zawartosci pliku "dane_.txt" do nowo stworzonego pliku tekstowego
            for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();

        }else if(odp!="n" && odp!="N"){cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}

    }while(ok==0);
    /// nadpisywanie bazy danych- juz bez usinietego rekordu
        w->erase(w->begin()+index, w->begin()+index+1);

        fstream output("dane_.txt");
        if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie otworzenia dokumentu dane_.txt";
                cout<<odp;Sleep(1000);
                exit(-4);
        }
        for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();
    }return b;
}

void wyswietlWszystko(vector<osoba> *w){ // wyswietla wszystkie rekordy bazy danych, razem z peselami uzytkownikow

    int j=0;
    for(int i=0; i<w->size(); i++){
        wyswietlanIE(w, j, i);j++;
    }
}

void usuwanie(vector<osoba> *w){ // nieodwracalnie usuwa baze danych
    string odp;bool ok=1;
    do{
        cout<<"\nCzy napewno chcesz usunac baze danych? (t/n)";cin>>odp;
        if(odp=="n" || odp=="N"){cout<<"\nZgodnie z Twoim zadaniem baza danych nie zostanie usunieta.";Sleep(1000);return;}
        else if(odp!="t" && odp!="T"){cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    /// zapytanie uzytkownika, czy chce zarchiwizowac stara wersje bazy danych
    do{
        cout<< "\nCzy chcesz zarchiwizowac stara baze danych (sprzed dodania do niej nowego rekordu)? t/n\n Uwaga! jesli zaznaczysz nie, wersji bazy danych sprzed dodania nowego rekordu nie bedziesz mogl juz odzyskac!\nMiejsce na Twoja odpowiedz (t/n): ";
        cin>>odp;
        if(odp=="t" || odp=="T"){//kopiuje zawartosc bazy danych do nowego pliku txt

            cout<<"\n Wybrales opcję zarchiwizowania bazy danych. Stara wersia bazy danych zostanie zapisana pod nazwą \"dane_zarchiwizowane.txt\"."
            <<"\nPo zakonczeniu operacji mozesz znalezc plik o powyzszej nazwie w plikach programu i zmienic dowolnie jego nazwe."<<
            "\nJesli tego nie zrobisz, kolejne, zarchiwizowanie bazy danych spowoduje nadpisanie pliku.";

            ///cout<<"Jak zyczysz sobie, zeby nazywala sie zrchiwizowana przez Ciebie baza danych? \n(Uwaga: wpisz nazwe, bez rozszeszenia, nie uzywaj spacji ani polskich znakow): ";
            ofstream output("dane_zarchiwizowane.txt");

            if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie stworzenia zarchiwizowania dokumentu.";
                cout<<odp;Sleep(1000);
                exit(-5);
            }
            ///przepisywanie zawartosci pliku "dane_.txt" do nowo stworzonego pliku tekstowego
            for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();

        }else if(odp!="n" && odp!="N"){cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}

    }while(ok==0);

    remove("dane_.txt");
    cout<<"\n\nBaza danych zostala usunieta.";
}

bool edycja(vector<osoba> *w){
    bool b=false;
    string odp;
    bool ok=1;

    do{
        cout<<"\nPodaj PESEL osoby, o ktorej informacje chcesz zedytowac: "; cin>>odp;
        if(!czy_pesel(odp)){cout<<"Popelniles blad przy podawaniu PESEL'u, sproboj jeszcze raz."; ok=0;}
        else ok=1;
    }while(ok==0);string PESEL=odp;
    /// wyszukiwanie, ktory index w wektorze ma struktura o podanym pesel'u
    int index;
    for (int i=0; i<w->size();i++){

        if((*w)[i].PESEL.compare(odp)==0){index=i; b=true; break;}
    }
    if(b==0)return b;
    if(b==1){ /// jesli w bazie danych znaleziono rekord o podanym peselu

    /// zapytanie uzytkownika, czy chce zarchiwizowac stara wersje bazy danych
    do{
        cout<< "\nCzy chcesz zarchiwizowac stara baze danych (sprzed dodania do niej nowego rekordu)? t/n\n Uwaga! jesli zaznaczysz nie, wersji bazy danych sprzed dodania nowego rekordu nie bedziesz mogl juz odzyskac!\nMiejsce na Twoja odpowiedz (t/n): ";
        cin>>odp;
        if(odp=="t" || odp=="T"){//kopiuje zawartosc bazy danych do nowego pliku txt

            cout<<"\n Wybrales opcje zarchiwizowania bazy danych. Stara wersia bazy danych zostanie zapisana pod nazwa \"dane_zarchiwizowane.txt\"."
            <<"\nPo zakonczeniu operacji mozesz znalezc plik o powyzszej nazwie w plikach programu i zmienic dowolnie jego nazwe."<<
            "\nJesli tego nie zrobisz, kolejne, zarchiwizowanie bazy danych spowoduje nadpisanie pliku.";

            ///cout<<"Jak zyczysz sobie, zeby nazywala sie zrchiwizowana przez Ciebie baza danych? \n(Uwaga: wpisz nazwe, bez rozszeszenia, nie uzywaj spacji ani polskich znakow): ";
            ofstream output("dane_zarchiwizowane.txt");

            if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie stworzenia zarchiwizowania dokumentu.";
                cout<<odp;Sleep(1000);
                exit(-5);
            }
            ///przepisywanie zawartosci pliku "dane_.txt" do nowo stworzonego pliku tekstowego
            for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();

        }else if(odp!="n" && odp!="N"){cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}

    }while(ok==0);
    /// nadpisywanie bazy danych- juz bez usinietego rekordu
        w->erase(w->begin()+index, w->begin()+index+1);

        fstream output("dane_.txt");
        if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie otworzenia dokumentu dane_.txt";
                cout<<odp;Sleep(1000);
                exit(-4);
        }
        for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();
    }

    osoba A;

    do{
        cout<<"\n\nPodaj ponownie imie osoby, o ktorej informacje chcesz zedytowac. Uwaga! nie uzywaj polskich znakow.: "; cin>>A.imie;
        if(A.imie.length()<3){cout<<"Popelniles blad przy podawaniu imienia, podany przez Ciebie ciag znakow jest zbyt krotki, sproboj jeszcze raz."; ok=0;}
        else ok=1;
    }while(ok==0);

    do{
        cout<<"\nPodaj nazwisko. Uwaga! nie uzywaj polskich znakow.: "; cin>>A.nazwisko;
        if(A.nazwisko.length()<2){cout<<"Popelniles blad przy podawaniu nazwiska, podany przez Ciebie ciag znakow jest zbyt krotki, sproboj jeszcze raz."; ok=0;}
        else ok=1;
    }while(ok==0);

    do{
        cout<<"\nPodaj klase: "; cin>>A.klasa;
        if(A.klasa.length()==2) ok=1;
        else if(A.klasa.length()>2){cout<<"Popelniles blad przy podawaniu klasy, podany przez Ciebie ciag znakow jest zbyt dlugi, sproboj jeszcze raz."; ok=0;}
        else if(A.klasa.length()<2){cout<<"Popelniles blad przy podawaniu klasy, podany przez Ciebie ciag znakow jest zbyt krotki, sproboj jeszcze raz."; ok=0;}
    }while(ok==0);

    A.PESEL=PESEL;

    do{
        cout<<"Czy podana przez Ciebie osoba posiada opinie, czy orzeczenie o potrzebie ksztalcenia zpecjalnego? (opinia/orzeczenie): ";
        cin>>odp;

        for(int i=0; i<odp.length(); i++){ // zamiana na male litery
            odp[i]=tolower(odp[i]);
        }
        if(odp=="opinia"){A.opiniaIorzeczenie1="1a"; ok=1;}
        else if(odp=="orzeczenie"){A.opiniaIorzeczenie1="1b"; ok=1;}
        else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz."; ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba posiada zaswiadczenie o potrzebie zastosowania indywidualnego trybu nauczania? (t/n): ";
        cin>>odp;
        if(odp=="t" || odp=="T"){
            A.nauczanie_indywidualne5='5'; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.nauczanie_indywidualne5='-'; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z pomocy osrodka socjoterapii JEDRUS? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.osrodki_socjoterapii11="11"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.osrodki_socjoterapii11="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia dydaktyczno-wyrownawcze? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.zDydaktycznoWyrownawcze16="16"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.zDydaktycznoWyrownawcze16="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia korekcyjno-kompensacyjne? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.zKorekcyjno_kompensacyjne17="17"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.zKorekcyjno_kompensacyjne17="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);
    bool ok2=1;
    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia terapeutyczne? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){

            do{
                cout<<"\nPodaj na jaki typ zajec terapeutycznych uczeszcza dziecko (artterapia/KUP/rewalidacja/socioterapia/psycholog): ";
                cin>>odp;

                for(int i=0; i<odp.length(); i++){ // zamiana na male litery
                odp[i]=tolower(odp[i]);
                }
                if(odp=="artterapia"){ok2=1; A.terapia18="18a";}
                else if(odp=="kup"){ok2=1; A.terapia18="18k";}
                else if(odp=="rewalidacja"){ok2=1; A.terapia18="18r";}
                else if(odp=="socjoterapia"){ok2=1; A.terapia18="18s";}
                else if(odp=="psycholog"){ok2=1; A.terapia18="18p";}
                else {ok2=0;cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";}
            }while(ok2==0);
        }
        else if(odp=="n" || odp=="N"){
            A.terapia18="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z ufundowanego przez pomoce socjalne stypendium lub wyprawki? (t/n): ";cin>>odp;

        if(odp=="t" || odp=="T"){ // korzysta
            do{
                cout<<"\nStypendium czy wyprawka? (stypendium/wyprawka): ";cin>>odp;

                for(int i=0; i<odp.length(); i++){ // zamiana na male litery
                    odp[i]=tolower(odp[i]);
                }
                if(odp=="stypendium"){
                    A.stypendiaIwyprawka19="19b";ok2=1;
                }else if(odp=="wyprawka"){
                    A.stypendiaIwyprawka19="19a"; ok2=1;
                }else{
                    ok2=0;cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";
                }
            }while(ok2==0);

        }else if(odp=="n" || odp=="N"){ // nie korzysta
            A.stypendiaIwyprawka19="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba posiada w szkole ufundowane obiady? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.obiady21="21"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.obiady21="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z form pomocy rzeczowej? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.pomocRzeczowa22="22a"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.pomocRzeczowa22="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba korzysta z nadzoru kuratora sadowego? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.nadzorKuratoraSodawego24="24"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.nadzorKuratoraSodawego24="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia dla cudzoziemcow? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.zajeciaDCudzoziemcow25="25"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.zajeciaDCudzoziemcow25="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

    do{
        cout<<"Czy podana przez Ciebie osoba uczeszcza na zajecia logopedyczne? (t/n): ";cin>>odp;
        if(odp=="t" || odp=="T"){
            A.logopeda26="26"; ok=1;
        }else if(odp=="n" || odp=="N"){
            A.logopeda26="-"; ok=1;
        }else {cout<<"\nUdzieliles niepoprawnej odpowiedzi, sproboj jeszcze raz.";ok=0;}
    }while(ok==0);

        w->push_back(A);

        fstream output("dane_.txt");
        if(!output.good()){
                // jesli wystapi blad podczas tworzenia lub otwierania pliku
                odp="\nWystapil blad przy probie otworzenia dokumentu dane_.txt";
                cout<<odp;Sleep(1000);
                exit(-4);
        }
        for(int i=0; i<w->size(); i++){
                output<<(*w)[i].nazwisko<<" ";
                output<<(*w)[i].imie<<" ";
                output<<(*w)[i].klasa<<" ";
                output<<(*w)[i].PESEL<<" ";
                output<<(*w)[i].opiniaIorzeczenie1<<" ";
                output<<(*w)[i].nauczanie_indywidualne5<<" ";
                output<<(*w)[i].osrodki_socjoterapii11<<" ";
                output<<(*w)[i].zDydaktycznoWyrownawcze16<<" ";
                output<<(*w)[i].zKorekcyjno_kompensacyjne17<<" ";
                output<<(*w)[i].terapia18<<" ";
                output<<(*w)[i].stypendiaIwyprawka19<<" ";
                output<<(*w)[i].obiady21<<" ";
                output<<(*w)[i].pomocRzeczowa22<<" ";
                output<<(*w)[i].nadzorKuratoraSodawego24<<" ";
                output<<(*w)[i].zajeciaDCudzoziemcow25<<" ";
                output<<(*w)[i].logopeda26<<endl;
        }output.close();return b;
}
