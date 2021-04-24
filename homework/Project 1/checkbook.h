/***********************************************************************
    This is the header file for a check a checkbook class. this checkbook
    class hold all the information for a normal checkbook. specifically 
    this checkbook has a balance, holder and checknumber. the balance 
    would show how much you have in your checkbook. the holder would 
    keep track of how many have been written and the checknumber is given 
    by the computer and keeps track of the information written in those \
    checks.
    
  	Roy Frimpong	Ohio University		Feburary 2021
************************************************************************/



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
    void show(std::string payto_find);
    void save(std::ofstream& ofs);
    double average();

    // Mutator function
    void set_deposit();
private:
    static const int checkbooksize = 200;
    Check onecheck[checkbooksize];
    int holder = 0;
    double balance = 0;
    int checknum = 1;
};