#include <iostream>
#include <windows.h>
#include "menu.h"//funkcja wczytaj
#include "klasa_menu.h"
#include "wyszukaj_rekord_menu.h" // aby uzyskac dostep do funkcji wyswietlaniE

void d_class_menu(){ // wyswietla pod-menu oraz daje uzytkownikowy mozliwosc wybrania ktorejs z opcji

string Menu[10] = {"Wyszukaj uczniow oddzialow przedszkolnych (0)", "Wyszukaj uczniow klas pierwszych (1)",
     "Wyszukaj uczniow klas drugich (2)", "Wyszukaj uczniow klas trzecich (3)", "Wyszukaj uczniow klas czwartych (4)",
    "Wyszukaj uczniow klas piatych (5)", "Wyszukaj uczniow klas szostych (6)",
    "Wyszukaj uczniow klas siodmych (7)", "Wyszukaj uczniow klas osmych (8)", "\nWroc do menu glownego",};
    int pointer = 0;
    vector<osoba> w;
    if(!wczytaj(&w)) exit(-1);

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Sprecyzuj uczniow ktorych klas chcesz wyszukac:\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Aby wybrac ktaras z opcji wcisnij strzalke w prawo (->)...\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		for (int i = 0; i < 10; ++i)
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
					pointer = 9;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 10)
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
						cout << "\nWypisywanie zerowkowiczow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'0')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow przedszkolnych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
					} break;
					case 1:
					{
					    system("cls");
						cout << "\nWypisywanie pierwszoklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'1')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas pierwszych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); system("cls"); break;
					} break;
					case 2:
                    {
                        system("cls");
						cout << "\nWypisywanie drugoklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'2')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas drugich.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
                    }break;
					case 3:
					{
						system("cls");
						cout << "\nWypisywanie trzecioklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'3')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas trzecich.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
					} break;
					case 4:
                    {
                        system("cls");
						cout << "\nWypisywanie czwartoklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'4')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas czwartych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
                    }break;
					case 5:
                    {
                        system("cls");
						cout << "\nWypisywanie piatoklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'5')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas piatych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); system("cls"); break;
                    } break;
                    case 6:
                    {
                        system("cls");
						cout << "\nWypisywanie szostoklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'6')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas szostych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
                    }break;
                    case 7:
                    {
                        system("cls");
						cout << "\nWypisywanie siodmoklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'7')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas siodmych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
                    }break;
                    case 8:
                    {
                        system("cls");
						cout << "\nWypisywanie osmioklasistow...\n\n"<<endl;
						//Sleep(1000);
						if(!wyszukaj(&w,'8')){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout<<endl<<"w bazie danych nie ma uczniow oddzialow klas osmych.";};
						cout<<endl<<endl<<"Wcisnij enter, aby powrocic do pod-menu wyszukiwania uczniow...";
						cin.ignore();cin.ignore(); break;
                    }
                    case 9:
                    {
                        cout<< "\n\n\nWroc do menu glownego";
                        Sleep(100);
                        display_menu();
                    }break;
				}
				break;
			}else if (GetAsyncKeyState(VK_ESCAPE) != 0){exit(0);}
		}

		Sleep(150);
	}

}

bool wyszukaj(vector<osoba> *w, char klasa){// wypisuje uczniow danych klas razem z formami pomocy z ktorych kazdy z nich korzysta (bez pesel'i)
    bool b= false; int j=0;
    for(int i=0; i<w->size(); i++){
        if((* w)[i].klasa[0]==klasa){ b=true;
            wyswietlaniE(w,j,i);j++;
        }
    }return b;
}
