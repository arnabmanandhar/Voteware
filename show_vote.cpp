#include <iostream>
#include <fstream>
#include<windows.h>
using namespace std;

int main()
{
    system("cls");
    system("MODE CON COLS=77 LINES=30");
    system("COLOR 8F");
    fstream myfile;
    string text;
    char ch;
    cout << "\n\n\n\t\t\t          Result" << endl;
    myfile.open("vote_details.txt", ios::app | ios::out | ios::in);
    cout << "\t\t=============================================="<< endl;
    ifstream readFile("vote_details.txt");
        while (getline(readFile, text))
        {
            cout << "\t\t" << text << endl;
        }
    cout << "\t\t==============================================\n\n\n\n\n\n\n\n" << endl;

    myfile.close();
    system("pause");
    return 0;
}