#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include<unistd.h>
#include<windows.h>
using namespace std;

class entry
{
public:
    bool checkName(string admin_name)
    {
        if (admin_name == "Aadarsha" || admin_name == "Anand" || admin_name == "Arnab" || admin_name == "Biplav")
            return 1;
        else
            return 0;
    }
    bool checkPassword(string admin_password)
    {
        if (admin_password == "vote_ware")
            return 1;
        else
            return 0;
    }
};

class choice
{
    string name, password, Address, roll_num,search;
    int option;
    fstream file;
    string fullname;
public:


    void viewMemberList()
    {
        char button;
        string text;
        cout << "\t\t\tDiplaying Record of the Members" << endl;
        cout << "\t\t=================================================" << endl;
        ifstream readFile("memberlist.txt");
        while (getline(readFile, text))
        {
            cout << "\t\t\t" << text << endl;
            Sleep(1);
        }
        cout<<"\n\n\n";
        system("pause");
        file.close();
    }

    void addMember()
    {
        fstream votelist, code1;
        code1.open("getCodeCheck.txt",ios::out|ios::app|ios::in);
        votelist.open("vote_list.txt", ios::out|ios::app|ios::in);
        file.open("memberlist.txt", ios::out | ios::app);
        cin.ignore();
        cout << "\t\tEnter Full Name: ";
        getline(cin, name);
        cout << "\t\tEnter Roll Number: ";
        cin >> roll_num;
        fullname = name+"-"+roll_num;
        file << fullname<< endl; 
        votelist << fullname<<endl;
        code1<<fullname<<endl;
        file.close();
        votelist.close();
        code1.close();
        cout << "\n\n\t\tStoring Data";
        for (int i = 0; i <= 6; i++)
        {
            Sleep(100);
            cout << ".";
        }
        cout << "\n\t\tData Loaded Succesfully!";
        Sleep(1000);
        cout<<"\n\n\n";
        system("pause");
    }

    void resetRecord()
    {
        cout << "\n\n\t\tDeleting Data";
        for (int i = 0; i <= 6; i++)
        {
            Sleep(100);
            cout << ".";
        }
        cout << "\n\t\tData deleted Succesfully!";
        Sleep(1000);
        cout<<"\n\n\n";
        system("pause");
        file.open("memberlist.txt", std::ofstream::out | std::ofstream::trunc);
        file.close();
    }
};

// void changeColor(int desiredColor) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); }

int main()
{
    system("cls");
    system("MODE CON COLS=77 LINES=30");
    system("COLOR 8F");
    choice c;
    string admin_password = "vote_ware", admin_name; //Admin ko lagi password ra usko nam ko lagi string banako xa
    int choice;
    starting:
    cout << "\n\n\n\t\t\tWelcome to Member Registration" << endl;
    cout << "\t\t\t==============================" << endl;
    cout << "\n\t\t\tEnter Admin Name: ";
    getline(cin, admin_name); //Admin ko name input ma linxa
    cout << "\t\t\tEnter Password: ";
    getline(cin, admin_password); //Admin ko password input ma linxa
    entry e1;
    if (e1.checkName(admin_name) == true)
    {
        if (e1.checkPassword(admin_password) == true)
        {
            starting123:
            system("cls");
            char option;
            cout << "\n\n\n\t\t=================================================" << endl;
            cout << "\t\tChoose the operation you want to perform: " << endl;
            cout << "\t\t1. View Member List" << endl;
            cout << "\t\t2. Add Member" << endl;
            cout << "\t\t3. Reset Record" << endl;
            cout << "\t\t4. Reset Votes" << endl;
            cout << "\t\t5. Exit" << endl;
            cout << "\t\t=================================================" << endl;
            cout << "" << endl;
            cout << "" << endl;

            cout << "\t\t\tEnter the answer here>> ";
            cin>>option;
            cout << "" << endl;
            cout << "" << endl;

                    if (option == '1')
                    {
                        c.viewMemberList();
                        goto starting123;}
                    else if (option == '2')
                    {
                        c.addMember();
                        goto starting123;}
                    else if (option == '3')
                    {
                        cout<<"\n\t\tAre you sure that you want to delete data?";
                        cout<<"\n\t\t1. Press 1 to accept";
                        cout<<"\n\t\t2. Press 2 to reject";
                        cout<<"\n\n\n\t\tEnter your option: ";
                        int wdasd;
                        cin>>wdasd;
                        if(wdasd == 1)
                        {
                            c.resetRecord();
                            goto starting123;}
                        else if(wdasd ==2)
                        {
                            goto starting123;
                        }
                        else{

                            system("COLOR 4F");
                            cout<<"\a\n\t\t\tYou entered invalid option";
                            Sleep(1);
                            system("cls");
                            system("COLOR 8F");
                            goto starting123;}
                    }

                    else if (option == '4')
                    {
                        goto starting123;
                    }
                    else if (option == '5')
                    {
                        exit(1);
                    }


                    else
                    {
                        system("COLOR 4F");
                        cout<< "\a\t\t\tYou entered invalid option";
                        Sleep(2);
                        system("COLOR 8F");

                        system("cls");
                        goto starting123;
                    }
        }

        else
        {
            system("COLOR 4F");
            cout << "\a\n\n\t\t\tWrong Password!" << endl;
            Sleep(1);
            system("COLOR 8F");
            system("cls");
            goto starting;
            return 0;
        }
    }

    else
    {
        system("COLOR 4F");
        cout << "\a\n\n\t\t\tInvalid User!" << endl;
        Sleep(1);
        system("COLOR 8F");
        system("cls");
        goto starting;
        return 0;
    }
}
