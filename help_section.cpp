#include <iostream>
#include <windows.h>
using namespace std;

class help
{
public:
    // void changeColor(int desiredColor)
    // {
    //     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
    // }

    void display_memberRegistration()
    {
        system("cls");
        //changeColor(12);
        cout<<"\n\n\n\t          Welcome to Member Registration Help Section"<<endl;
        cout << "\t    =======================================================" << endl;
        cout << "\n\n     -> This section can only be accessed by the admin and is encrypted \n        using a password." << endl;
        //changeColor(6);
        cout << "" << endl;
        cout << "     -> The member data, representative data, the voting result can be \n        altered by admins as they input the correct password. This is \n        the section from which the member data is added and removed to \n        and from the list of members eligible to vote." << endl;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        system("pause");
    }

    void display_registerRepresentative()
    {
        system("cls");
        //changeColor(6);
        cout<<"\n\n\n\t        Welcome to Register Representative Help Section"<<endl;
        cout << "\t=============================================================\n\n" << endl;
        cout << "     -> If you want to stand as representative candidate for the election,\n        you should be given a password by the admins beforehand to access\n        this section. Enter the password and gain access to this section." << endl;
        cout << "" << endl;
        cout << "     -> Note that you can only access this section if you have already been\n        added on the list of members eligible to vote by the admins. " << endl;
        cout << "" << endl;
        cout << "     -> A maximum of 10 candidates can stand for the post in the election\n        so, if you receive an error message regarding the same, the slots\n        for representative candidates registration have already been full.\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        system("pause");
    }

    void display_getCode()
    {
        system("cls");
        //changeColor(6);
        cout<<"\n\n\n\t\t       Welcome to Get Code Help Section"<<endl;
        cout << "\t=============================================================\n\n" << endl;
        cout << "     -> Enter your name and your roll number correctly." << endl;
        cout << "" << endl;
        cout << "     -> You will receive a unique code if your information has already\n        been registered by the admins into the list of members eligible\n        to vote." << endl;
        cout << "" << endl;
        cout << "     -> Note down your unique code as it is the password you will need to\n        input in order to vote.\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        system("pause");
    }

    void display_Vote()
    {
        system("cls");
        //changeColor(6);
        cout<<"\n\n\n\t\t     Welcome to Display Code Help Section"<<endl;
        cout << "\t=============================================================\n\n" << endl;
        cout << "     -> Enter your name and roll number correctly. Then enter the unique\n        code that you received from the Get Code section. " << endl;
        cout << "" << endl;
        cout << "     -> Next you can vote for your preferred representative candidate.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        system("pause");
    }

    void display_showResult()
    {
        system("cls");
        //changeColor(6);
        cout<<"\n\n\n\t\t     Welcome to Show Result Help Section"<<endl;
        cout << "\t=============================================================\n\n" << endl;
        cout << "     -> Choose this section to display the current number of votes of all\n        the representative candidates.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        system("pause");
    }
};

int main()
{
    system("cls");
    system("MODE CON COLS=77 LINES=30");
    system("COLOR 8F");
    starting:
    help h;
    char choose;
    system("cls");
    //h.changeColor(6);
    //while (1)
    //{
        system("cls");
        cout<<"\n\n\n\t\t\t         Welcome"<<endl;
        cout << "\t\t ==========================================" << endl;
        cout << "\n\t\t Which section are you having trouble with? " << endl;
        cout << "\t\t 1. Member Registration" << endl;
        cout << "\t\t 2. Register Representative" << endl;
        cout << "\t\t 3. Get code for voter" << endl;
        cout << "\t\t 4. Vote" << endl;
        cout << "\t\t 5. Show Result" << endl;
        cout << "\t\t 6. Exit" << endl;
        cout << "\t\t ==========================================" << endl;
        cout << "\n\n\t\t Enter your choice here>> ";
        cin >> choose;
        //switch (choose)
        //{
        //case 1:
        if(choose == '1'){    
            h.display_memberRegistration();
            goto starting;}
            //break;
        //case 2:
        else if(choose == '2'){    
            h.display_registerRepresentative();
            goto starting;}
            //break;
        //case 3:
        else if(choose == '3'){ 
            h.display_getCode();
            goto starting;}
            //break;
        //case 4:
        else if(choose == '4'){ 
            h.display_Vote();
            goto starting;}
            //break;
        //case 5:
        else if(choose == '5'){ 
            h.display_showResult();
            goto starting;}
            //break;
        /*case 6:
            return 0;
            break;
        default:*/
        else if(choose == '6'){ 
            exit(1);}
            
        else{
            system("COLOR 4F");
            cerr << "\a\n\n\t\t You Entered Invalid Option!\n\n\n\n\n\n\n\n\n" << endl;
            Sleep(1000);
            system("COLOR 8F");
            //break;
            goto starting;
            }
    //}
    return 0;
}