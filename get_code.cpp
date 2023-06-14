#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class check
{

    int value;
    string name;

public:
    check(string name) { this->name = name; }

    int keyword(fstream &stream, string name)
    {
        int found  ; 
        string line;
        while (getline(stream, line))
        {
            if (line.find(name) != string::npos)
            {
                found = 1;
                break;
                
            }
            else{
                found = 0;
            }
        }
        return found;
    }
};

void changeColor(int desiredColor) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); }

int main()
{
    system("cls");
    system("MODE CON COLS=77 LINES=30");
    system("COLOR 8F");
    fstream myfile;
    string fname, lname, name, cname, roll_num, password;
    string line;
    int ret_value;

    system("cls");

    cout << "\n\n\n\t\t\t       Welcome User!" << endl;
    cout << "\t\t\t==========================" << endl;
    cout << endl;

    cout << "\n\t\t\tEnter your First name: ";
    getline(cin, fname);
    cout << "\t\t\tEnter your Last name: ";
    getline(cin, lname);
    cout << "\t\t\tEnter your roll number: ";
    getline(cin, roll_num);
    name = fname + " " + lname + "-" + roll_num;
    myfile.open("getCodeCheck.txt", ios::out | ios::in);
    check c(name);
    ret_value = c.keyword(myfile, name);
    myfile.close();

    if (ret_value == true) // usko nam text file ma xa
    {

        string path = "getCodeCheck.txt"; // nam hataune
        ifstream fin;
        string eraseline = name;
        fin.open(path);
        ofstream temp;

        temp.open("temp.txt");
        while (getline(fin, line))
        {
            if (line != eraseline)
            {
                temp << line << endl;
            }
        }
        temp.close();
        fin.close();
        const char *p = path.c_str();
        remove(p);
        rename("temp.txt", p);

        password = fname + "_" + roll_num;
        cout << "\n\n\t    *****************************************************" << endl;
        cout << "\t\t      Please note this password properly!" << endl;
        cout << "\t\t*******************************************" << endl;
        cout << "\t    *****************************************************" << endl;
        cout << "\t\t   Your voting password is: " << password << endl;
        cout << "\t    *****************************************************\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        system("pause");
        return 0;
    }
    else
    {
        cout << "\n\n\t    *****************************************************" << endl;
        cout << "\a\t\t  Sorry! You can't have your password second time!" << endl;
        cout << "\t    *****************************************************" << endl;
        system("pause");
    }

    return 0;
}