#ifndef DLIST_H
#define DLIST_H
#include "Dnode.h"
#include "nodeiterator.h"
#include <string>
#include <cstdlib>

template <class T>
class dlist{
    public:


    dlist(){
        head = NULL;
        tail = NULL;
        count = 0;
    }
    dlist(const T& other);
    dlist operator = (const T& other);
    ~dlist();
    typedef node_iterator<T> iterator;
    iterator begin(){return iterator(head);}
    iterator end(){return iterator();}
    iterator r_begin(){return iterator(tail);}
    iterator r_end(){return iterator();}
    void remove(iterator object);
    void insert_before(iterator& object, T item);
    void insert_after(iterator& object, T item);

    void front_insert(T item);
    void front_remove();
    void rear_insert(T item);
    void rear_remove();
    void show();
    void reverse_show();
    int size(){
        return count;
    }
    private:
    dnode<T>*head;
    dnode <T>*tail;
    int count = 0;


};
#include "Dlist.template"
#endif