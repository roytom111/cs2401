#include "closet.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <list>
using namespace std;

int menu();

int main()
{
    ifstream ins;
    ofstream out;
    string username;
    int code;

    cout << "what is your username" << endl;
    getline(cin, username);
    username += ".txt ";
    ins.open(username.c_str());
    if (ins.fail())
    {
        cout << "creating a spot for " << username << endl;
    }
    int choice;
    choice = menu();
    Closet *tmp;
    list<Closet *> closet;
    if (!ins.fail())
    {
        while (ins >> code)
        {
            switch (code)
            {
            case 1:
            {
                tmp = new Shirt;
                tmp->input(ins);
                closet.push_back(tmp);
            }
            break;
            case 2:
            {
                tmp = new Pants;
                tmp->input(ins);
                closet.push_back(tmp);
            }
            break;
            case 3:
            {
                tmp = new Underwear;
                tmp->input(ins);
                closet.push_back(tmp);
            }
            break;
            case 4:
            {
                tmp = new Shoes;
                tmp->input(ins);
                closet.push_back(tmp);
            }
            break;
            case 5:
            {
                tmp = new Formal;
                tmp->input(ins);
                closet.push_back(tmp);
            }
            break;
            default: ins.ignore();
            }
        }
    }

    while (choice != 7)
    {
        if (choice == 1)
        {
            tmp = new Shirt;
            tmp->input(cin);
            closet.push_back(tmp);
        }
        else if (choice == 2)
        {
            tmp = new Pants;
            tmp->input(cin);
            closet.push_back(tmp);
        }
        else if (choice == 3)
        {
            tmp = new Underwear;
            tmp->input(cin);
            closet.push_back(tmp);
        }
        else if (choice == 4)
        {
            tmp = new Shoes;
            tmp->input(cin);
            closet.push_back(tmp);
        }
        else if (choice == 5)
        {
            tmp = new Formal;
            tmp->input(cin);
            closet.push_back(tmp);
        }
        else if (choice == 6)
        {
            list<Closet *>::iterator it;
            it = closet.begin();
            while (it != closet.end())
            {
                cout << endl;
                (*it)->output(cout);
                it++;
            }
        }
        choice = menu();
    }
    out.open(username.c_str());
    list<Closet *>::iterator it;
    it = closet.begin();
    while (it != closet.end())
    {
        cout << endl;
        (*it)->output(out);
        it++;
    }
}
int menu()
{
    int ans;
    cout << "Enter 1 for Shirts" << endl;
    cout << "Enter 2 for Pants" << endl;
    cout << "Enter 3 for Underwear" << endl;
    cout << "Enter 4 for Shoes" << endl;
    cout << "Enter 5 for Formal" << endl;
    cout << "Enter 6 to show all" << endl;
    cout << "Enter 7 for Exit /Save" << endl;
    cin >> ans;
    return ans;
}