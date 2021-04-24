#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "fbfriends.h"

using namespace std;

FBFriends::FBFriends()
{
    capacity = 5;
    used = 0;
    current_index = 0;
    data = new Friend[capacity];
}
void FBFriends::start()
{
    current_index = 0;
}
void FBFriends::advance()
{
    current_index++;
}
bool FBFriends::is_item()
{
    return current_index < used;
}
Friend FBFriends::current()
{
    return data[current_index];
}

void FBFriends::remove_current()
{
    if (!is_item())
    {
        return;
    }
    for (int i = current_index; i < used; i++)
    {
        data[i] = data[i + 1];
    }
        used--;
}
void FBFriends::insert(const Friend &f)
{
    if (used >= capacity)
    {
        resize();
    }
    if (!is_item())
    {
        current_index = 0;
    }
    for (int i = used; i > current_index; i--)
    {
        data[i] = data[i - 1];
    }
    data[current_index] = f;
    used++;
}
void FBFriends::attach(const Friend &f)
{
    if (used >= capacity)
    {
        resize();
    }
    if (!is_item())
    {
        current_index = used;
        data[current_index] = f;
        used++;
    }
    for (int i = used; i > current_index; i--)
    {
        data[i] = data[i - 1];
    }
    data[current_index + 1] = f;
    used++;
}
void FBFriends::show_all(std::ostream &outs) const
{
    for (int i = 0; i < used; i++)
    {
        outs << data[i] << endl;
    }
}
void FBFriends::bday_sort()
{
    bool done;
    int j;
    Friend tmp;
    while (!done)
    {
        done = true;
        for (j = used - 1; j > 0; j--)
        {
            if (data[j].get_bday() < data[j - 1].get_bday())
            {
                done = false;
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
}
Friend FBFriends::find_friend(const std::string &name) const
{
    for (int i = 0; i < capacity; i++)
    {
        if (data[i].get_name() == name)
        {
            return data[i];
        }
    }
}
bool FBFriends::is_friend(const Friend &f) const
{
    for (int i = 0; i < used; i++)
    {
        if (data[i].get_name() == f.get_name() && data[i].get_bday() == f.get_bday())
        {
            return true;
        }
    
    }
    return false;
}
void FBFriends::load(std::istream &ins)
{
    Friend tmp;
    while (!ins.eof())
    {
        if (used == capacity)
        {
            resize();
        }
        ins >> tmp;
        data[used] = tmp;
        used++;
    }
}

void FBFriends::save(std::ostream &outs)
{
    for (int i = 0; i < used; i++)
    {
        outs << data[i];
    }
}
void FBFriends::resize()
{
    Friend *ndata;
    ndata = new Friend[capacity + 5];
    for (int i = 0; i < capacity; i++)
    {
        ndata[i] = data[i];
    }
    capacity += 5;
    delete[] data;
    data = ndata;
}
FBFriends::~FBFriends()
{
    delete[] data;
}
FBFriends::FBFriends(const FBFriends &other)
{
    capacity = other.capacity;
    used = other.used;
    current_index = other.current_index;
    data = new Friend[capacity];
    for (int i = 0; i < capacity; i++)
    {
        data[i] = other.data[i];
    }
}