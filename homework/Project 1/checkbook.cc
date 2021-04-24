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
    while (!ins.eof())
    {
        ins >> body;
        onecheck[holder] = body;
        cout << body;
        holder++;
    }
}
void checkbook::deposit(double deposit)
{
    balance = balance + deposit;
    cout << balance;
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
}
double checkbook::get_balance()
{
    return balance;
}
void checkbook::show_all(std::ostream &outs)
{
    for (size_t i = 0; i < holder; i++)
    {
        cout << onecheck[i] << endl;
    }
}
void checkbook::remove(int rmnum)
{
    Check make;
    for (size_t i = 0; i < holder; i++)
    {
        if (onecheck[i].get_num() == rmnum)
        {
            holder = holder - 1;

            for (size_t j = 0; j < holder; j++)
            {
                onecheck[j] = onecheck[j + 1];
            }
        }
    }
}
void checkbook::number_sort()
{
    int small;
    Check tmp;
    for (size_t i = 0; i < holder; i++)
    {
        small = i;
        for (size_t j = i + 1; j < holder; j++)
        {
            if (onecheck[j].get_num() < onecheck[small].get_num())
            {
                small = j;
            }
            tmp = onecheck[i];
            onecheck[i] = onecheck[j];
            onecheck[j] = tmp;
        }
    }
}
void checkbook::payto_sort(){
    int small;
    Check tmp;
    for (size_t i = 0; i < holder; i++)
    {
        small = i;
        for (size_t j = i + 1; j < holder; j++)
        {
            if (toupper(onecheck[j].get_payto().at(0)) < toupper( onecheck[small].get_payto().at(0)))
            {
                small = j;
            }
            tmp = onecheck[i];
            onecheck[i] = onecheck[j];
            onecheck[j] = tmp;
        }
    }

}
void checkbook::date_sort(){
    int small;
    Check tmp;
    for (size_t i = 0; i < holder; i++)
    {
        small = i;
        for (size_t j = i + 1; j < holder; j++)
        {
            if (onecheck[j].get_date() < onecheck[small].get_date())
            {
                small = j;
            }
            tmp = onecheck[i];
            onecheck[i] = onecheck[j];
            onecheck[j] = tmp;
        }
    }



}