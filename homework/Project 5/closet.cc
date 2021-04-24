#include "closet.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
void Shirt::input(istream &ins)
{
    if (&cin == &ins)
    {

        cout << "what is your shirt size?(please input using S, M  or L" << endl;
        cin >> shirt_size;
        if (shirt_size != 'S' && shirt_size != 's' && shirt_size != 'M' && shirt_size != 'm' && shirt_size != 'l' && shirt_size != 'L')
        {
            cout << "you did not enter a valid size, please try again" << endl;
        }

        cout << "what type of shirt do you want to wear today? do you want T-shirt or a longsleeve shirt? or any other shirt you have in mind?" << endl;
        cin >> shirt_type; 
    }
    else
    {
        ins >> shirt_size;
        ins >> shirt_type;
    }
    
}
void Shirt::output(ostream &out)
{
    if (&cout == &out)
    {

        out << "the shirt size you wanted was a " << shirt_size << endl;
        out << "The shirt you chose to wear today was a " << shirt_type << endl;
    }
    else
    {
        out << "1" << endl;
        out << shirt_size << endl;
        out << shirt_type << endl;
    }
    
}
void Pants::input(istream &ins)
{
    if (&cin == &ins)
    {

        cout << "can you please tell me what size pants your wear?(please input using S, M  or L" << endl;
        if (pants_size != 'S' && pants_size != 's' && pants_size != 'M' && pants_size != 'm' && pants_size != 'l' && pants_size != 'L')
            cin >> pants_size;
        {
            cout << "you did not enter a valid size, please try again" << endl;
        }
        cout << "what type of pants have you decided to wear today?" << endl;
        cin >> pants_type;
    }
    else
    {
        ins >> pants_size;
        ins >> pants_type;

    }
    
}
void Pants::output(ostream &out)
{
    if (&cout == &out)
    {
        out << "the pants size you chose was a " << pants_size << endl;
        out << "the pants you decided to wear was " << pants_type << endl;
    }
    else
    {
           out << "2" << endl;
        out << pants_size << endl;
        out << pants_type << endl;
    }
    
}
void Underwear::input(istream &ins)
{
    if (&cin == &ins)
    {

        cout << "what type of material do you want to wear for your boxers (like silk or cotton)" << endl;
        cin >> underwear_type;
    }
        else
    {
        ins >> underwear_type;
    }
}
void Underwear::output(ostream &out)
{
    if (&cout == &out)
    {
        out << "you have chose to wear " << underwear_type << "boxers" << endl;
    }
    else
    {
          out << "3" << endl;
        out << underwear_type << endl;
    }
    
}
void Shoes::input(istream &ins)
{
    if (&cin == &ins)
    {

        cout << "what brand of shoe do you want to wear" << endl;
        cin >> Brand;
        cout << "what gender is the shoe meant for?" << endl;
        cin >> gender;
        cout << "what shoe size do you need?" << endl;
        cin >> size;
    }
        else
    {
        ins >> Brand;
        ins >> gender;
        ins >> size;
    }
}
void Shoes::output(ostream &out)
{
    if (&cout == &out)
    {
        out << "the shoe brand: " << Brand << endl;
        out << "the specified gender for the shoe: " << gender << endl;
        out << "the chosen shoe size: " << size << endl;
    }
    else
    {
          out << "4" << endl;
        out << Brand << endl;
        out << gender << endl;
        out << size << endl;
    }
    
}
void Formal::input(istream &ins)
{
    if (&cin == &ins)
    {
        cout << "what is the special occasion for this outfit" << endl;
        cin >> occasion;
        cout << "do you need this to be a suit or a sweater? " << endl;
        cin >> style;
    }
}
void Formal::output(ostream &out)
{
    if (&cout == &out)
    {
        cout << "the special occasion you have chosen is " << occasion << endl;
        cout << "the style chosen is: " << style << endl;
    }
    else
    {
          out << "5" << endl;
        out << occasion << endl;
        out << style << endl;
    }
    
}
