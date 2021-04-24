#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include <cstdlib>
#include <string>



class pieces{
    public:
    bool is_white()const{
        if (white == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_green()const{
        if (green == true)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    bool is_king()const{
        return king;
    }
    bool is_empty()const{
        if (white == false && white == false)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        

    }
    void make_white(){
        white = true;
        green = false;
    }
    void make_green(){
        white = false;
        green = true;
    }
    void make_empty(){
        white = false;
        green = false;
    }
    void make_king(){
        king = true;


    }






    private:

    bool green;
    bool white;
    bool empty;
    bool king;
};

#endif