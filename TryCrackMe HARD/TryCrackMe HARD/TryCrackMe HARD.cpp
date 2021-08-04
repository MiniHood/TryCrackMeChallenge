// TryCrackMe Easy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <tlhelp32.h>
#include <stdlib.h>
#include "obfuscate.h"
#include <time.h>
#include <fstream> // So I can make the ban file


using namespace std;

#pragma warning(disable : 4244)
#pragma warning(disable : 4002)
#pragma warning(disable : 4101)

void DetectDebuggerThread()
{
    BOOL result; //Create a result boolean for our result to be stored.
    LPCSTR DetectedWindows[] = { AY_OBFUSCATE("x64dbg", "IDA: Quick start", "IDA v6.8.150423", "dnSpy", "Microsoft Visual Studio", "Visual Studio", "Process Hacker", "Task Manager" )}; //Add your own debuggers!
    //Just finding windows may not be enough, so try to include your own process checker.

    while (1) //Enter our loop.
    {
        if (IsDebuggerPresent()) //Our first check, probably the simpliest.
        {
            system("cls");
            printf(AY_OBFUSCATE("Debugger found! Exiting...\n"));
            std::ofstream file{ "C:\\Users\\Public\\banned.txt" };
            Sleep(1500);
            exit(0);
        }
        CheckRemoteDebuggerPresent(GetCurrentProcess(), &result); //Get a handle to our current process and send our result to the our boolean.
        if (result || result == 1) //Check to see if our result is true.
        {
            system("cls");
            printf(AY_OBFUSCATE("Debugger found! Exiting...\n"));
            std::ofstream file{ "C:\\Users\\Public\\banned.txt" };
            Sleep(1500);
            exit(0);
        }
        SetLastError(0); //Set last error to 0 so it won't conflict with our check.
        OutputDebugStringA(AY_OBFUSCATE("Using a debugger?\n")); //Send a little message to the debugger.
        if (GetLastError() != 0) //If the message passed without error (Meaning it was sent to the debugger)
        {
            system("cls");
            printf(AY_OBFUSCATE("Debugger found! Exiting...\n"));
            std::ofstream file{ "C:\\Users\\Public\\banned.txt" };
            Sleep(1500);
            exit(0);
        }

        for (int i = 0; i < 10; i++) //Loop thru our array of detected debugger windows.
        {
            if (FindWindowA(0, DetectedWindows[i]) != 0) //Check to see if FindWindow found a debugger that matches our name.
            {
                system("cls");
                printf(AY_OBFUSCATE("Debugger found! Exiting...\n"));
                std::ofstream file{ "C:\\Users\\Public\\banned.txt" };
                Sleep(1500);
                exit(0);
            }
        }
    }
}

void printSlowCharacters(const char* strToPrint) { // Slowly print strings... A const char* is pretty much a string
    while (*strToPrint) {
        cout << *strToPrint++;
        Sleep(100);
    }
}

bool is_file_exist(const char* fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}


int main()
{
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DetectDebuggerThread, 0, 0, 0);

    if (is_file_exist("C:\\Users\\Public\\banned.txt"))
    {
        cout << "YOU ARE BANNED" << endl;
        Sleep(2000);
        return 0;
    }

    int choice;
    string choiceofkey;
    string str;

    cout << AY_OBFUSCATE("George Says: Ah YES!! You've FINALLY released me! After all those years!") << endl;
    cout << AY_OBFUSCATE("\n"); // Making another new line
    cout << AY_OBFUSCATE("\n");
    cout << AY_OBFUSCATE("Your Choices Of Speach Are") << endl;
    cout << AY_OBFUSCATE("{1} Who are you? | {2} Can you fuck off? I'm trying to jerk off... | {3} How did you fit inside that tiny little exe file?\n");
    cin >> choice;

    switch (choice)
    {
    case 1:
        printSlowCharacters(AY_OBFUSCATE("\nYou say: Who are you?\n"));
        printSlowCharacters(AY_OBFUSCATE("George Says: I'm george... Ho- How do you not know me? I'm a god... What has this world come too?\n"));
        printSlowCharacters(AY_OBFUSCATE("George lifts his mighty lightning but... Misses you? He spared your life but gives you a puzzle you have to enter the correct number out of 500000! Guess it to live guess wrong? You die! Guess corect? You live!\n"));
        int i, x;
        for (i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] - 2 - 55 - 215 - 616; // Decrypt number as str string 
        cin >> choiceofkey;

        if (choiceofkey == str)
        {
            printSlowCharacters(AY_OBFUSCATE("George Says: Welp, you got it right so uhm... Not sure what to do...."));
            exit(5);
        }
        else {
            printSlowCharacters(AY_OBFUSCATE("George smites you and you die"));
            exit(5);
        }
        break;
    case 2:
        printSlowCharacters(AY_OBFUSCATE("George Says: Oh shit oh fuck fuck no bro I'm so sorry! Oh my fucking god uhm I'm just going to leave now!!\nGeorge then proceeds to pull out a gun and kill himself."));
        Sleep(2000);
        exit(5);
        break;

    case 3:
        printSlowCharacters(AY_OBFUSCATE("George smites you and you die..."));
        exit(5);
        break;
    }
    return 0; // End Code

}
