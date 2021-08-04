// TryCrackMe Easy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;  

void printSlowCharacters(const char* strToPrint) { // Slowly print strings... A const char* is pretty much a string
    while (*strToPrint) {
        cout << *strToPrint++;
        Sleep(100);
    }
}

int main()
{
    int choice;
    string key = "342"; // Yes i know this could be a int but string obfuscation for the hard version doesn't work on ints oof
    string choiceofkey;

    cout << "George Says: Ah YES!! You've FINALLY released me! After all those years!" << endl;
    cout << "\n"; // Making another new line
    cout << "\n";
    cout << "Your Choices Of Speach Are" << endl;
    cout << "{1} Who are you? | {2} Can you fuck off? I'm trying to jerk off... | {3} How did you fit inside that tiny little exe file?\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        printSlowCharacters("\nYou say: Who are you?\n");
        printSlowCharacters("George Says: I'm george... Ho- How do you not know me? I'm a god... What has this world come too?\n");
        printSlowCharacters("George lifts his mighty lightning but... Misses you? He spared your life but gives you a puzzle you have to enter the correct number out of 500! Guess it to live guess wrong? You die! Guess corect? You live!\n");
        cin >> choiceofkey;
        if (choiceofkey == key)
        {
            printSlowCharacters("George Says: Welp, you got it right so uhm... Not sure what to do....");
            exit(5);
        }
        else {
            printSlowCharacters("George smites you and you die");
            exit(5);
        }
        break;
    case 2:
        printSlowCharacters("George Says: Oh shit oh fuck fuck no bro I'm so sorry! Oh my fucking god uhm I'm just going to leave now!!\nGeorge then proceeds to pull out a gun and kill himself.");
        Sleep(2000);
        exit(5);
        break;
 
    case 3:
        printSlowCharacters("George smites you and you die...");
        exit(5);
        break;
}
    return 0; // End Code

}
