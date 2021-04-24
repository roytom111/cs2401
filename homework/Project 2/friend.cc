#include <iostream>
#include <fstream>
#include <cstdlib>
#include "friend.h"

using namespace std;

Friend::Friend()
{
    name = "name is not available";
    bday =  Date (00,0,00);
}
string Friend::get_name() const
{
    return name;
}
Date Friend::get_bday() const
{
    return bday;
}
 bool Friend::operator==(const Friend &other) const
{
    if (other.get_name() == name && other.get_bday() == bday)
    {
        return true;
    }
}

 bool Friend::operator!=(const Friend &other) const
{
    if (other.get_name() != name && other.get_bday() != bday)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Friend::input(std::istream &ins)
{
    string waste;
    if (&ins == &cin)
    {
        waste = getchar();
        cout << "Enter the name " << endl;
        getline(ins, name);
        cout << "Enter the Birthday for the name inputted" << endl;
        ins >> bday;
    }
    else
    {
        if (ins.peek() == '\n' || ins.peek()== '\r')
        {
            ins.ignore();
        }
        getline(ins, name);
        ins>> bday;
        
    }
    

}
 void Friend::output (std::ostream& outs)const{
    if (&outs == &cout)
    {
        outs<< "Name: \t\t" << name << endl;
		outs << "Birthday: \t\t" << bday << endl;
    }
    else
    {
        outs << name << endl;
		outs << bday << endl;
    }
    
}
ostream &operator<<(ostream &outs, const Friend &f)
{
	f.output(outs);
	return outs;
}
istream &operator>>(istream &ins, Friend &f)
{
	f.input(ins);
	return ins;
}