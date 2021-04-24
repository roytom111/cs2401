/*******************************************************************
    This is the implementation file for the Checkbook class. For more 
information about the class see checkbook.h.
	Roy Frimpong	Ohio University		Feburary 2021
******************************************************************/

#include "checkbook.h"
#include "check.h"
#include <cctype>
using namespace std;

checkbook::checkbook()
{
    holder = 0;
    balance = 0;
    checknum = 1;
}

void checkbook::load_from_file(ifstream &ins)
{
    Check body;

    ins >> balance;
    cout << balance << endl;
    ins >> checknum;
    ins >> body;
    while (!ins.eof())
    {
        onecheck[holder] = body;
        cout << body;
        holder++;
        ins >> body;
    }
}
void checkbook::deposit(double deposit)
{
    balance = balance + deposit;
    cout << balance << endl;
}
void checkbook::write_check(std::istream &ins)
{
    Check make;

    make.set_check_num(checknum);
    make.write_check(ins);
    onecheck[holder] = make;
    cout << onecheck[holder] << endl;
    holder++;
    checknum++;
    balance = balance - onecheck[holder].get_amount();
}
double checkbook::get_balance()
{
    return balance;
}
void checkbook::show_all(std::ostream &outs)
{
    for (int i = 0; i < holder; i++)
    {
        cout << onecheck[i] << endl;
    }
}
void checkbook::remove(int rmnum)
{
    Check make;
    for (int i = 0; i < holder; i++)
    {
        if (onecheck[i].get_num() == rmnum)
        {
            holder = holder - 1;

            for (int j = 0; j < holder; j++)
            {
                onecheck[j] = onecheck[j + 1];
            }
        }
    }
}
void checkbook::number_sort()
{

    bool done = false;
    int j;
    Check tmp;
    while (!done)
    {
        done = true;
        for (j = holder - 1; j > 0; --j)
        {
            if (onecheck[j].get_num() < onecheck[j - 1].get_num())
            {
                done = false;
                tmp = onecheck[j];
                onecheck[j] = onecheck[j - 1];
                onecheck[j - 1] = tmp;
            }
        }
    }
}
void checkbook::payto_sort()
{
    Check tmp;
    int j;
    bool done = false;
    while (!done)
    {
        done = true;
        for (j = holder - 1; j > 0; --j)
        {
            if (toupper(onecheck[j].get_payto().at(0)) < toupper(onecheck[j - 1].get_payto().at(0)))
            {
                done = false;
                tmp = onecheck[j];
                onecheck[j] = onecheck[j - 1];
                onecheck[j - 1] = tmp;
            }
        }
    }
}
void checkbook::date_sort()
{
    bool done = false;
    int j;
    Check tmp;
    while (!done)
    {
        done = true;
        for (j = holder - 1; j > 0; --j)
        {
            if (onecheck[j].get_date() < onecheck[j - 1].get_date())
            {
                done = false;
                tmp = onecheck[j];
                onecheck[j] = onecheck[j - 1];
                onecheck[j - 1] = tmp;
            }
        }
    }
}
void checkbook::show(string payto_find)
{
    double amount;
    for (int i = 0; i < holder; i++)
    {
        if (onecheck[i].get_payto() == payto_find)
        {
            amount += onecheck[i].get_amount();
            cout << onecheck[i];
        }
    }
}
double checkbook::average()
{
    double amount;
    double average;
    for (int i = 0; i < holder; i++)
    {
        amount += onecheck[i].get_amount();
    }
    average = amount / holder;
    return average;
}
void checkbook::save(std::ofstream &outs)
{
    outs << balance << endl;
    outs << checknum << endl;
    for (int i = 0; i < holder; i++)
    {
        outs << onecheck[i].get_amount() << endl;
        outs << onecheck[i].get_date() << endl;
        outs << onecheck[i].get_num() << endl;
        outs << onecheck[i].get_payto() << endl;
    }
}