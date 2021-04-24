#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "check.h"
#include "checkbook.h"

int main(){
    ifstream ins;
    Check test;
    checkbook book;
    double deposit;

    ins.open("roystester.txt");
    if (ins.fail())
    {
        cout << "this is failed" << endl;
    }
    
    book.load_from_file(ins);
    // cout << "how much do you want to add  " << endl;
    // cin >> deposit;
    // book.get_deposit(deposit);





    





}