#include <iostream>
#include <fstream>
using namespace std;

class representative
{
protected:
    fstream file;
    string temp[15];
    string str;
    char ch;
    int i = 0, count = 0;

public:
    void returnRepresentatives()
    {
        file.open("representative.txt", ios::out | ios::in);
        while (!file.eof())
        {
            file >> noskipws >> ch;
            if (ch != '\n')
            {
                str += ch;
            }
            else
            {
                temp[i] = str;
                str.clear();
                i++;
            }
        }
        file.close();
        for (i = 0; i < count; i++)
        {
            cout <<"\t\t"<< i + 1 << ". " << temp[i] << endl;
        }
    }

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

class login
{
public:
    string name, roll_num, fname, checkname;
    string code, code_format;
    fstream myfile;

    void inputData()
    {
        cout<<"\n\n\n\t\t\t         Welcome"<<endl;
        cout << "\t\t===========================================\n" << endl;
        cout << "\t\tEnter Name: ";
        getline(cin, name);
        cout << "\t\tEnter Roll Number: ";
        cin >> roll_num;
        checkname = name + "-" + roll_num;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] != ' ')
            {
                fname += name[i];
            }
            else
                break;
        }
    }

    void displayData()
    {
        cout << "\n\n\n\t\t********************************************" << endl;
        cout << "\t\tName: " << name << endl;
        cout << "\t\tRoll Number: " << roll_num << endl;
        cout << "\t\t********************************************" << endl;
    }

    string getCodeFormat()
    {
        code_format = fname + "_" + roll_num;
        return code_format;
    }

    string inputCode()
    {
        cout << "\n\n\t\tEnter Code: ";
        cin >> code;
        return code;
    }

    bool check(fstream &stream)
    {
        string line;
        while (getline(stream, line))
        {
            if (line.find(checkname) != string::npos)
            {
                return true;
            }
            else
                return false;
        }
    }

    void removeName()
    {
        string line;
        ifstream fin;
        string eraseline = checkname;
        string path = "vote_list.txt";
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
    }
};

class votes
{
    string temp[15];
    string str, vote_str;
    char ch;
    int i = 0, count = 0, vote_count_req[10];
    fstream myfile, file;
    ofstream delfile;

public:
    void voteCounter(int choose, int vote_count[], int count)
    {
        switch (choose)
        {
        case 1:
            vote_count[0] += 1;
            break;
        case 2:
            vote_count[1] += 1;
            break;
        case 3:
            vote_count[2] += 1;
            break;
        case 4:
            vote_count[3] += 1;
            break;
        case 5:
            vote_count[4] += 1;
            break;
        case 6:
            vote_count[5] += 1;
            break;
        case 7:
            vote_count[6] += 1;
            break;
        case 8:
            vote_count[7] += 1;
            break;
        case 9:
            vote_count[8] += 1;
            break;
        case 10:
            vote_count[9] += 1;
        }

        delfile.open("vote_details.txt", ofstream::trunc);
        delfile.close();

        ofstream deletestore;
        deletestore.open("storevote1.txt", ofstream::trunc);

        file.open("representative.txt", ios::out | ios::in);

        while (!file.eof())
        {
            file >> noskipws >> ch;
            if (ch != '\n')
            {
                str += ch;
            }
            else
            {
                vote_str = to_string(vote_count[i]);
                temp[i] = str + "    No. of Votes:" + vote_str;
                str.clear();
                i++;
            }
        }
        file.close();

        fstream fn;
        fn.open("vote_details.txt", ios::app | ios::out | ios::in);
        for (i = 0; i < count; i++)
        {
            fn << temp[i] << endl;
        }

        fn.close();

        fstream store;
        store.open("storevote1.txt", ios::app | ios::out | ios::in);
        for (i = 0; i < 10; i++)
        {
            store << vote_count[i] << endl;
        }
        fn.close();
        // for(int i = 0;i<10;i++)
        // {
        //     cout<<vote_count[i]<<endl;
        // }
        // system("pause");
        store.close();
  
    }
    void getVote(int vote_count[], int size)
    {
        int i = 0;
        fstream get;
        get.open("storevote1.txt", ios::app | ios::out | ios::in);
        for (i = 0; i < 10; i++)
        {
            get >> vote_count[i];
        }
        get.close();
    }
};


int main()
{
    system("cls");
    system("MODE CON COLS=77 LINES=30");
    system("COLOR 8F");

    string line, line1;
    string fname, code, code_check;
    int count = 0, choose = 0, vote_count[10];
    int ret_value_member = 0;
    int ret_value_votelist = 0;
    fstream file;
    votes v1;
    login log;
    representative rep;

    count = rep.countLines();
    v1.getVote(vote_count, 10);

    log.inputData();

    file.open("memberlist.txt", ios::app | ios::out | ios::in);
    while (getline(file, line1))
    {
        if (line1.find(log.checkname) != string::npos)
        {
            ret_value_member=1;
            break;
        }
        else{
            ret_value_member=0;
        }    
    }
    file.close();
    
    ofstream f;
    f.open("store_votes.txt", ofstream::trunc);
    f.close();
    
    fstream votelist;
    votelist.open("vote_list.txt", ios::app | ios::out | ios::in);
    while (getline(votelist, line))
    {
        if (line.find(log.checkname) != string::npos)
        {
            ret_value_votelist = 1;
            break;
        }
        else
            ret_value_votelist = 0;
    }

    
    votelist.close();

    if (ret_value_member == true)
    {
        if (ret_value_votelist == true)
        {
            code = log.inputCode();
            code_check = log.getCodeFormat();

            if (code.compare(code_check) == 0)
            {
                system("cls");
                log.displayData();
                cout << "\n\n\n\t\tThe list of Representatives are:" << endl;
                cout << "\t\t********************************************" << endl;
                rep.returnRepresentatives();
                cout << endl
                     << "\t\tSelect your representative: ";
                cin >> choose;
                v1.voteCounter(choose, vote_count, count);
                cout << "\t\t****************************************" << endl;
                cout << "\t\tYour Vote Has been recorded! Thankyou" << endl;
                cout << "\t\t****************************************\n\n\n\n\n" << endl;
                log.removeName();
                system("pause");
                exit(1);
            }
            else
            {
                system("COLOR 4F");
                cout << "\a\n\n\t\tWrong Password!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
                system("pause");
                exit(1);
            }
        }
        else
        {
            system("COLOR 4F");
            cout << "\a\n\n\n\t\tYou cannot vote more than once!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
            system("pause");
            exit(1);
        }
    }
    else
    {
        system("COLOR 4F");
        cout << "\a\t\t\n\n\t\tInvalid User!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        system("pause");
    }
    return 0;
}