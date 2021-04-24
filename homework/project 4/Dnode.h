#include <iostream>
#include <cstdlib>
#include <string>

template <class T>
class dnode
{

public:
    dnode(T d, dnode *p = NULL, dnode *n = NULL)
    {
        datafield = d;
        previousptr = p;
        nextptr = n;
    }
    T data()const
    {
        return datafield;
    }
    dnode *previous()const
    {
        return previousptr;
    }
    dnode *next()const
    {
        return nextptr;
    }
    void set_data(T d)
    {
        datafield = d;
    }
    void set_previous(dnode *p)
    {
        previousptr = p;
    }
    void set_next(dnode *n)
    {
        nextptr = n;
    }

private:
    T datafield;
    dnode *nextptr;
    dnode *previousptr;
};
