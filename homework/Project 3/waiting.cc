using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "Waiting.h"
#include "node.h"
#include "appointment.h"

Waiting::Waiting()
{

    head = NULL;
}

Waiting::~Waiting()
{
    node *ptr;
    while (head != NULL)
    {
        ptr = head;
        head = head->link();
        delete ptr;
    }
}
Waiting Waiting::operator=(const Waiting &other)
{
    if (this == &other)
    {
        return *this;
    }
    if (other.head == NULL)
    {
        head = NULL;
    }
    else
    {
        head = new node(other.head->data());
        node *dest = other.head->link();
        node *source = head;
        while (dest != NULL)
        {
            source->set_link(new node(dest->data()));
            source = source->link();
            dest = dest->link();
        }
        delete dest;
    }
    return other;
}
Waiting::Waiting(const Waiting &other)
{
    if (other.head == NULL)
    {
        head = NULL;
    }
    else
    {
        node *ntmp, *dtmp;
        head = new node(other.head->data());
        while (ntmp != NULL)
        {
            dtmp->set_link(new node(ntmp->data()));
            dtmp = dtmp->link();
            ntmp = ntmp->link();
        }
    }
}
void Waiting::add(Appointment item)
{

    if (head == NULL)
    {
        head = new node(item);
    }
    else
    {
        node *tmp = head;
        while (tmp->link() != NULL)
        {
            if (tmp->link() == NULL)
            {
                node *mov = new node();
                mov->set_data(item);
                mov->set_link(NULL);
                tmp->set_link(mov);
                return;
            }
            else if (item.get_callin() < tmp->link()->data().get_callin())
            {
                node *mov = new node();
                mov->set_data(item);
                mov->set_link(tmp->link());
                tmp->set_link(mov);
                return;
            }
            tmp = tmp->link();
        }
        tmp->set_link(new node(item));
    }
}
void Waiting::display(std::ostream &outs)
{
    node *tmp = head;

    if (head == NULL)
    {
        cout << "there is not list" << endl;
    }
    while (tmp != NULL)
    {
        cout << tmp->data() << endl;
        tmp = tmp->link();
    }
}
unsigned Waiting::longest_wait()
{
    unsigned number;
    number = head->data().minutes_waiting();
    return number;
}
unsigned Waiting::average_wait()
{
    unsigned number = 0;
    unsigned people = 0;
    node *tmp = head;
    while (tmp != NULL)
    {
        number += tmp->data().minutes_waiting();
        people++;
        tmp = tmp->link();
    }
    number = number / people;
    return number;
}
int Waiting::waiting()
{
    node *tmp = head;
    int people = 0;
    if (tmp == NULL) // would return if the list is empty
    {
        return 0;
    }
    while (tmp != NULL)
    {
        tmp = tmp->link();
        people++;
    }
    return people;
}
node *Waiting::find(string name)
{
    node *cursor = head;
    while (cursor != NULL)
    {
        if (cursor->data().get_name() == name)
        {
            return cursor;
        }
        cursor = cursor->link();
    }
    return NULL;
}
void Waiting::remove(string name)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->data().get_name() == name)
    {
        node *tmp;
        tmp = head;
        head = head->link();
        delete tmp;
    }
    else
    {
        node *cursor = head->link();
        node *prev = head;
        while (cursor != NULL && cursor->data().get_name() != name)
        {
            prev = cursor;
            cursor = cursor->link();
        }
        if (cursor != NULL)
        {
            prev->set_link(cursor->link());
            delete cursor;
        }
    }
}
int Waiting::oldest()
{
    Date today;
    today.make_today();
    int old = INT_MIN;
    for (node *cursor = head; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data().age(today) > old)
        {
            old = cursor->data().age(today);
        }
    }
    return old;
}
int Waiting::youngest()
{
    Date today;
    today.make_today();
    int young = INT_MAX;
    for (node *cursor = head; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data().age(today) < young)
        {
            young = cursor->data().age(today);
        }
    }
    return young;
}
int Waiting::average_age()
{
    Date today;
    node *cursor = head;
    today.make_today();
    int avg = 0;
    int count = 0;
    while (cursor != NULL)
    {
        avg += cursor->data().age(today);
        count++;
        cursor = cursor->link();
    }
    avg = avg / count;
    return avg;
}
void Waiting::load(istream &ins)
{
    Appointment tmp;
    node *cursor;
    int i = 0;
    ins >> tmp;
    while (!ins.eof())
    {
        while (ins.peek() == '\r' || ins.peek() == '\n')
        {
            ins.ignore();
        }

        if (head == NULL)
        {
            head = new node;
            cursor = head;
            cursor->set_data(tmp);
        }
        else
        {
            cursor->set_link(new node);
            cursor = cursor->link();
            cursor->set_data(tmp);
        }
        ins >> tmp;
        i++;
    }
}
void Waiting::save(ostream &outs)
{
    node *cursor;
    cursor = head;
    if (head == NULL)
    {
        cout << "the list is empty" << endl;
    }
    while (cursor != NULL)
    {
        outs << cursor->data();
        cursor = cursor->link();
    }
}
