#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "menu.h"//funkcja wczytaj
#include "wyszukaj_rekord_menu.h"

using namespace std;

void record_menu(){ // wyswietla pod-menu oraz daje uzytkownikowy mozliwosc wybrania ktorejs z opcji

    vector<osoba> w;
    if(!wczytaj(&w)) exit(-1);

    string Menu[13] = {"Wyszukaj rekord po nazwisku",
    "Wyszukaj uczniow korzystajacych z indywidualnych form nauczania",
    "Wyszukaj uczniow koszystajacych z osrodkow Socjoterapii JEDRUS",
    "Wyszukaj uczniow uczeszczajacych na zajecia dydaktyczno– wyrownawcze",
    "Wyszukaj uczniow uczeszczajacych na zajacia korekcyjno- kompensacyjne",
    "Wyszukaj uczniow korzystajacych z pomocy socjalnych",
    "Wyszukaj uczniow korzystajacych z pomocy rzeczowej",
    "Wyszukaj uczniow korzystajacych z nadzoru kuratora sadowego",
    "Wyszukaj uczniow uczeszczajacych na zajecia terapeutyczne",
    "Wyszukaj uczniow uczeszczajacych na zejecia logopedyczne",
    "Wyszukaj uczniow majacych w szkole ufundowane obiady",
    "Wyszukaj uczniow korzystajacych z specjalnych form nauczania dla cudzoziemcow",

    "\nWroc do menu glownego"};
    int pointer = 0;

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Sprecyzuj ze wzgledu na jakie kryterium chcesz wyszukac uczniow:\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Aby wybrac ktaras z opcji wcisnij strzalke w prawo (->)...\n\n";
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
			else if (GetAsyncKeyState(VK_RIGHT) != 0)
			{
                switch (pointer)
				{
					case 0:
					{
						system("cls");
						cout << "\nWyszukiwanie rekordu po nazwisku...\n\n"<<endl;
						if(!wyszukaj_po_nazwisku(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"osoby o podanym nazwisku nie ma w bazie danych.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore(); Sleep(100); getch();system("cls"); break;//display_menu();//return;///////////////////////
					} break;
					case 1:
					{
					    system("cls");
						cout << "\nWyszukiwanie uczniow korzystajacych z indywidualnych form nauczania...\n\n"<<endl;
						if(!wyszukaj_indywidualne(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore korzystalyby z indywidualnych form nauczania.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;//display_menu();//record_menu();
					} break;
					case 2:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow koszystajacych z osrodkow Socjoterapii JERDUS...\n\n"<<endl;
						if(!w_osrodkiSocjoterapii(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore korzystalyby z pomocy osrodkow socjoterapii JEDRUS.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
					}break;
					case 3:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow uczeszczajacych na zajecia dydaktyczno– wyrownawcze...\n\n"<<endl;
						if(!w_wyrownawcze(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore uczeszczalyby na zajecia dydaktyczno-wyrownawcze.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
					case 4:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow uczeszczajacych na zajacia korekcyjno-kompensacyjne...\n\n"<<endl;
						if(!w_korekcyjne(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore uczeszczalyby na zajecia korekcyjno-kompensacyjne.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
                    case 5:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow korzystajacych z pomocy socjalnych...\n\n"<<endl;
						if(!w_pomoce_socjalne(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore korzystalyby ze stypendiow socjalnych.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
					case 6:
					{
					    system("cls");
						cout << "\nWyszukiwanie uczniow korzystajacych z form pomocy rzeczowej...\n\n"<<endl;
						if(!w_pomoc_rzeczowa(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore korzystalyby z form pomocy rzeczowej.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
					} break;
					case 7:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow korzystajacych z nadzoru kuratora sadowego...\n\n"<<endl;
						if(!w_kurator(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore korzystalyby z nadzoru kuratora sadowego.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
					case 8:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow uczeszczajacych na zajecia terapeutyczne...\n\n"<<endl;
						if(!w_terapia(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktorzy uczeszczaliby na zajecia terapeutyczne.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    } break;
                    case 9:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow uczeszczajacych na zajecia logopedyczne...\n\n"<<endl;
						if(!w_logopeda(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktorzy uczeszczaliby na zajecia logopedyczne.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
                    case 10:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow mających w szkole ufundowane obiady...\n\n"<<endl;
						if(!w_obiady(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore mialyby w szkile ufundowane obiady.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
                    case 11:
                    {
                        system("cls");
						cout << "\nWyszukiwanie uczniow korzystajacych z specjalnych form nauczania dla cudzoziemcow....\n\n"<<endl;
						if(!w_cudzoziemcy(&w)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma osob, ktore korzystalyby z specjalnych form nauczania dla cudzoziemcow.";};
						cout<<endl<<endl<<"Wcisnij i przytrzymaj przez chwile enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); Sleep(100); break;
                    }break;
                    case 12:
                    {
                        Sleep(100);
                        return;
                    }break;
				}
				break;
			}else if (GetAsyncKeyState(VK_ESCAPE) != 0){exit(0);}//wyjscie awaryjne
		}

		Sleep(150);
	}

}

void wyswietlaniE(vector<osoba> *w, int j, int i){ // funkcja pomocnicza wywolywana z wewnatrz innych funkcji (takrze z wewnatrz tych bedacych czescia menu glownego i klasa_menu)

            if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
        cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko;
        if((*w)[i].opiniaIorzeczenie1=="1a"){
            cout<<"- posiada opinie z poradni psychologiczno-pedagogicznej";
        }else if((*w)[i].opiniaIorzeczenie1=="1b"){
            cout<<"- posiada orzeczenie o potrzebie dostosowania metod ksztalcenia";
        }

        if((*w)[i].nauczanie_indywidualne5 == '5'){
            cout<<" ; nauczanie indywidualne";
        }

        if((*w)[i].osrodki_socjoterapii11 == "11"){
            cout<<" ; korzysta z pomocy osrodka socjoterapii JENDRUS";
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
        cout<<endl<<endl;
}

bool wyszukaj_po_nazwisku(vector<osoba> *w){ // prosu uzytkownika o podanie nazwiska i wyswietla informacje z jakich form pomocy korzysta uczen (lub uczniowie, jesli o podanym nazwisku jest ich wiecej)

    cout<<"Podaj nazwisko: ";string n; cin>>n;
    bool b = false;
    int j=0;

    for(int i=0; i<w->size(); i++){
        if((* w)[i].nazwisko.compare(n)==0){ b=true;
        wyswietlaniE(w, j, i);j++;}}
    return b;
}

bool wyszukaj_indywidualne(vector<osoba> *w){ // wypisuje imie, nazwisko i klase kazdego z uczniow w przypadku ktorych stosowane jest nauczanie indywidualne

    bool b = false;
    string str;

    int j=0;
    for(int i=0; i<w->size(); i++){

        if((* w)[i].nauczanie_indywidualne5=='5'){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_osrodkiSocjoterapii(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow korzystajacych z pomocy osrodka JEDRUS
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){
        if((* w)[i].osrodki_socjoterapii11=="11"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_wyrownawcze(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow uczeszczajacych na zajecia dydaktyczno-wyrownawcze
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){
        if((* w)[i].zDydaktycznoWyrownawcze16=="16"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_korekcyjne(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow uczeszczajacych na zajecia korekcyjno-kompensacyjne
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].zKorekcyjno_kompensacyjne17=="17"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

            str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_pomoce_socjalne(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow korzystajacych z wyprawki lub ze stypendium socjalnego
    int j=0;
    bool b = false;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].stypendiaIwyprawka19=="19a"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - wyprawka\n";
        }else if((* w)[i].stypendiaIwyprawka19=="19b"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - stypendium\n";
        }j++;
    }
    cout<<endl<<endl; return b;
}

bool w_pomoc_rzeczowa(vector<osoba> *w){ // wypisuje imie, nazwisko i klase kazdego z uczniow korzystajacych z form pomocy rzeczowej
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].pomocRzeczowa22=="22a"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_kurator(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow objetych opiekom kuratora sadowego
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].nadzorKuratoraSodawego24=="24"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_cudzoziemcy(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow uczeszczajacych na zajecia dla cudzoziemcow
    int j=0;
    bool b = false;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].zajeciaDCudzoziemcow25=="25"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        cout<<setw(20);cout<<(*w)[i].imie<<" "<<(*w)[i].nazwisko<<"     ";
                if(j%3==0){cout<<endl;}
                j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_terapia(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow uczeszczajacych na zejecia terapeutyczne i wypisuje jakie sa to konkretnie zajecia
    int j=0;
    bool b = false;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].terapia18!="-"){b=true;

            if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}


            if((* w)[i].terapia18=="18a"){

                cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - artterapia\n";
            }
            else if((* w)[i].terapia18=="18k"){

                cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - KUP\n";
            }
            else if((* w)[i].terapia18=="18r"){

                cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - rewalidacja\n";

            }else if((* w)[i].terapia18=="18s"){

                cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - socjoterapia\n";

            }else if((* w)[i].terapia18=="18p"){

                cout<<(* w)[i].imie<<" "<<(* w)[i].nazwisko<<" "<<(* w)[i].klasa<<" - spotkania indywidualne z psychologiem\n";
            }

            j++;
        }
    }
    cout<<endl<<endl; return b;
}

bool w_logopeda(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow uczeszczajacych na zejecia logopedyczne
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].logopeda26=="26"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}

bool w_obiady(vector<osoba> *w){// wypisuje imie, nazwisko i klase kazdego z uczniow majacych w szkole ufundowane obiady
    int j=0;
    bool b = false;
    string str;

    for(int i=0; i<w->size(); i++){

        if((* w)[i].obiady21=="21"){ b=true;

        if(j%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}
            else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

        str=(*w)[i].imie+" "+(*w)[i].nazwisko;

        cout<<setw(30);cout<<str<<"     ";
        if(j%3==0){cout<<endl;}
        j++;
    }}
    cout<<endl<<endl; return b;
}
