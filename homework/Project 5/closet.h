#ifndef CLOSET_H
#define CLOSET_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class Closet{
    public:
    virtual void input(istream& ins) = 0;
    virtual void output(ostream& out) = 0;

    



    



};
class Shirt:public Closet{
    public:
    void input(istream& ins);
    void output(ostream& out);
    private:
    char shirt_size;
    string shirt_type;
    

};
class Pants:public Closet{
    public:
    void input(istream& ins);
    void output(ostream& out);
    char pants_size;
    string pants_type;






};
class Underwear:public Closet{
    public:
    void input(istream& ins);
    void output(ostream& out);
    private:
    string underwear_type;


};
class Shoes:public Closet{
    public:
    void input(istream& ins);
    void output(ostream& out);
    private:
    string Brand;
    string gender;
    double size;

};
class Formal:public Closet{
    public:
    void input(istream& ins);
    void output(ostream& out);
    private:
    string occasion;
    string style;
    


};

#endif