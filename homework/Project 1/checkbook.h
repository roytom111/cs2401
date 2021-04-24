#include <iostream>
#include <fstream>
#include <ctype.h>
#include "check.h"

class checkbook
{
public:
    checkbook();
    void load_from_file(std::ifstream &ins);
    // Accessor functions
    void deposit(double deposit);
    void  write_check();
    void write_check(std::istream &ins);
    double get_balance();
    void show_all(std::ostream& cout);
    void remove(int rmnum);
    void number_sort();
    void payto_sort();
    void date_sort();
    void show(std:: istream payto_find);
    // Mutator function
    void set_deposit();
private:
    static const int checkbooksize = 200;
    Check onecheck[checkbooksize];
    int holder = 0;
    double balance = 0;
    int checknum = 1;
};