#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;
class check
{
    int count = 0;
    public:
    int getCount() { return count; }

    int countLines()
    {
        string line;
        ifstream myfile("representative.txt", ios::out | ios::app);
        if (myfile.is_open())
        {
            while (myfile.peek() != EOF)
            {
                getline(myfile, line);
                count++;
            }
        }
        myfile.close();
        return count;
    }  
};

class profile
{
    public:
    
    string name, roll_num, check_name, password;
    string fname, req_roll;
    
    void inputData()
    {
        
        cout << "\n\n\t\tEnter Full Name: ";
        getline(cin, name);
        cout << "\t\tEnter Roll Number: ";
        getline(cin,roll_num);
        check_name = name + "-" + roll_num;
   
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] != ' ')
            {
                fname += name[i];
            }
            else
                break;
        }
        int l = roll_num.length();
        for (int i = 9; i < l; i++)
        {
            req_roll += roll_num.at(i); 
        }
    }

    string createPassword()
    {
        check c1;
        int count = c1.getCount();
        string count_s;

        stringstream ss;
        ss << count;
        ss >> count_s;
        password = "#" + fname + req_roll + "_" + count_s;
        return password;
    }

    void printProfile()
    {
        system("cls");
        cout << "\n\n\n\t\t*****************************************" << endl;
        cout << "\t\tName: " << name  << endl;
        cout << "\t\tRoll Number: " << roll_num << endl;
        cout << "\t\t*****************************************" << endl;
    }

    void storeRecord()
    {
        fstream myfile;
        string fullname = name + "-" + roll_num;
        myfile.open("representative.txt", ios::app);
        myfile << fullname << endl;
        myfile.close();
    }
};

int main(){
    system("cls");
    system("MODE CON COLS=77 LINES=30");
    system("COLOR 8F");
    check c;
    profile prof;
    system("cls");
    int lines = c.countLines();
    string line, password;
    bool found_mem = 0, found_dup = 0; 

    fstream memberlist, representative;
    memberlist.open("memberlist.txt",ios::app|ios::out|ios::in);
    representative.open("representative.txt",ios::app|ios::out|ios::in);

    cout<<"\n\n\n\t\t\t         Welcome"<<endl;
    cout << "\t\t============================================" << endl;   
    
    if(lines < 10)
    {
        prof.inputData();
        while (getline(memberlist, line))
        {
            if (line.find(prof.check_name) != string::npos)
            {
                found_mem = 1;
                break;
            }
            else{
                found_mem = 0;
            }
        }
        memberlist.close();
        if(found_mem == 1)
        {
            while (getline(representative, line))
            {
                if (line.find(prof.check_name) != string::npos)
                {
                    found_dup = 1;
                    break;
                }
                else{
                    found_dup = 0;
                }
            }
            representative.close();
            if(found_dup == 0)
            {
                prof.printProfile();
                cout << "\n\n\t\tPlease note down the code!" << endl;
                cout << "\t\tPlease Wait! Generating Code..." << endl;
                password = prof.createPassword();
                Sleep(1000);
                cout << "\t\tPassword: " << password << endl;               
                prof.storeRecord();
                cout<<"\n\n\n\n\n\n\n\n\n\n";
                system("pause");
                exit(1);
            }
            else  
            {   
                system("COLOR 4F");
                cout<<"\a\n\n\t\tDuplicate Record Found!"<<endl;
                cout<<"\n\n\n\n\n\n\n\n\n\n";
                system("pause");
            }
        }
        else
        {
            system("COLOR 4F");
            cout<<"\a\n\n\t\tInvalid User"<<endl;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            system("pause");
        }
    }
    else
    {
        system("COLOR 4F");
        cout<<"\a\n\n\t\tSeats Occupied!"<<endl;
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        system("pause");
    }
    return 0;
}