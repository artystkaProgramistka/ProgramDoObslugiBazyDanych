#include <iostream>
#include <windows.h>
#include "menu.h"

using namespace std;

void start()
{
    //string napis = "   ____________________________________________________\n   |____________________________________________________|\n   | __     __   ____   ___ ||  ____    ____     _  __  |\n   ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |\n   ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |\n   ||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |\n   ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|\n   ||_______________________||__________________________|\n   | _____________________  ||      __   __  _  __    _ |\n   ||=|=|=|=|=|=|=|=|=|=|=| __..\/ |  |_|  ||#||==|  / /|\n   || | | | | | | | | | | |/\ \  \\|++|=|  || ||==| / / |\n   ||_|_|_|_|_|_|_|_|_|_|_/_/\_.___\__|_|__||_||__|/_/__|\n   |____________________ /\~()/()~//\ __________________|\n   | __   __    _  _     \_  (_ .  _/ _    ___     _____|\n   ||~~|_|..|__| || |_ _   \ //\\ /  |=|__|~|~|___| | | |\n   ||--|+|^^|==|1||2| | |__/\ __ /\__| |==|x|x|+|+|=|=|=|\n   ||__|_|__|__|_||_|_| /  \ \  / /  \_|__|_|_|_|_|_|_|_|\n   |_________________ _/    \/\/\/    \_ _______________|\n   | _____   _   __  |/      \../      \|  __   __   ___|\n   ||_____|_| |_|##|_||   |   \/ __|   ||_|==|_|++|_|-|||\n   ||______||=|#|--| |\   \   o    /   /| |  |~|  | | |||\n   ||______||_|_|__|_|_\   \  o   /   /_|_|__|_|__|_|_|||\n   |_________ __________\___\____/___/___________ ______|\n   |__    _  /    ________     ______           /| _ _ _|\n   |\ \  |=|/   //    /| //   /  /  / |        / ||%|%|%|\n   | \/\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|\n   |  \/\|/   /(____|/ //                    /  /||~|~|~|\n   |___\_/   /________//   ________         /  / ||_|_|_|\n   |___ /   (|________/   |\_______\       /  /| |______|\n   /                  \|________)     /  / | |\n"
    string napis1 = "                                         .--.           .---.        .-.                                               \n";
    string napis2 = "                                     .---|--|   .-.     | A |  .---. |~|.---.--.                                       \n";
    string napis3 = "                                  .--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.                                   \n";
    string napis4 = "                                  |%%|NT2|oc|===| |~~|%%| C |--|   |_|~|CATS|  |___|-.                                 \n";
    string napis5 = "                                  |  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|                                 \n";
    string napis6 = "                                  |  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |                                 \n";
    string napis7 = "                                  |~~|===|--|===|~|~~|%%|~~~|--|:::|=|~|----|==|---|=|                                 \n";
    string napis8 = "                                  ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'                                 \n";



   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);

   //cout << "I take back my first post and ask you to search DaniWeb first!" << endl;


   /*for(int i=0; i<100; i++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout<<i<<" "<<napis<<endl;
   }*/

   cout<< "                                  ELEKTRONICZNY POMOCNIK DLA SZKOLNYCH SPECJALISTOW                                     "<<endl<<endl
   <<"- czyli program do obslugi szkolnego rejestru uczniow wymagajacych specjalnych form pomocy psychologiczno-pedagogicznej  "<<endl<<endl;

    for (int i = 0; i < napis1.length(); i+=4)
    {
        Sleep(1);
        cout << napis1[i]<<napis1[i+1]<< napis1[i+2]<<napis1[i+3];
    }
    for (int i = 0; i < napis2.length(); i+=4)
    {
        Sleep(1);
        cout << napis2[i]<<napis2[i+1]<< napis2[i+2]<<napis2[i+3];
    }
    for (int i = 0; i < napis3.length(); i+=4)
    {
        Sleep(1);
        cout << napis3[i]<<napis3[i+1]<< napis3[i+2]<<napis3[i+3];
    }
    for (int i = 0; i < napis4.length(); i+=4)
    {
        Sleep(1);
        cout << napis4[i]<<napis4[i+1]<< napis4[i+2]<<napis4[i+3];
    }
    for (int i = 0; i < napis5.length(); i+=4)
    {
        Sleep(1);
        cout << napis5[i]<<napis5[i+1]<< napis5[i+2]<<napis5[i+3];
    }
    for (int i = 0; i < napis6.length(); i+=4)
    {
        Sleep(1);
        cout << napis6[i]<<napis6[i+1]<< napis6[i+2]<<napis6[i+3];
    }
    for (int i = 0; i < napis7.length(); i+=4)
    {
        Sleep(1);
        cout << napis7[i]<<napis7[i+1]<< napis7[i+2]<<napis7[i+3];
    }
    for (int i = 0; i < napis8.length(); i+=4)
    {
        Sleep(1);
        cout << napis8[i]<<napis8[i+1]<< napis8[i+2]<<napis8[i+3];
    }


    cout<<endl<<endl<<"Aby przejsc do menu glownego, wcisnij Enter..."<<endl<<endl;
    cin.ignore();
    display_menu();

}
