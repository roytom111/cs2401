#include<iostream>
#include "appointment.h"
#include <fstream>
#include "node.h"
#include<string>
#ifndef WAITING_H
#define WAITING_H


class Waiting{
    public:
    Waiting();


    void add(Appointment item);
    void display(std::ostream& outs);
    void remove(string name);
    int waiting();
    node* find(string name);
    unsigned longest_wait();
    unsigned average_wait();
    int oldest();
    int youngest();
    int average_age();
    void load(istream& ins);
    void save(ostream& outs);
    ~Waiting();
    Waiting(const Waiting& other);
    Waiting operator =(const Waiting& other);













    private:
    node *head;
    



};
#endif