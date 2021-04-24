/*
Name: Braden Baker
Class: CS 2401
Date: 4/23/2017
Project: Project 6 Checkers Game
*/
#ifndef CHECKERS_H
#define CHECKERS_H
#include "game.h"
#include "colors.h"
#include "space.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <queue>

namespace main_savitch_14 
{
    class checkers : public game 
    {
      public: 
      
        checkers(){}
        
        static const int ROWS = 8;
        static const int COLUMNS = 8;
        
                    //virtual and overriden funcitons from game.h
        void display_status() const;//    display_status: Displays the pieces on the board
        void make_move(const std::string& move);//    make_move: Moves the pieces on the board based on the user input as long as its legal
        void restart();//    restart: Resets the board and puts all the peices back in there original places
        bool is_legal(const std::string& move) const;//    is_legal: Checks the move input by the users and makes sure that move is legal
        bool is_game_over() const;//    Is_game_over: Checks to see if the game is over by way of however many peices are left on the board
        who winning( ) const;//    winning: Keeps a tab on who is winning
        
       game* clone() const;
       void compute_moves(std::queue<std::string>& moves) const;   // Compute all the moves that the next player can make:
       int evaluate( ) const;     	 // Evaluate a board position: positive values are good for computer

      private:
                        
         space data[ROWS][COLUMNS];  //MAIN BOARD SPACE DATA
         
        bool is_jump_avail() const;//    is_jump_avail: Checks to see if a jump is available for a peice to make
        bool legaljumps(const string& move) const;  
        bool legalmoves(const string& move) const; 
        void movehelper(const string& move, int& i, int& j, int& x, int& y, int& c); //    movehelper: converts next 2 of string to [i][j] or [x][y]
        void additionaljumps(const string& move, int& x, int& y, int& c); 
        void getstartloc(const string& move, int& i, int& j); 
        void getmovetoloc(const string& move, int& x, int& y);  
        void getmovetoloc(const string& move, int& x, int& y) const; 
        void getstartloc(const string& move, int& i, int& j) const; 
        bool peice_king(const string& move) const; 
        bool startneutral(const string& move) const; 
        bool move2takenspot(const string& move) const;  //
        bool jumptopright(const string& move) const; //    jumptopright: Checks if peice can be jumped top right side
        bool jumptopleft(const string& move) const;//    jumptopleft: Checks if peice can be jumped top left side
        bool jumpbotright(const string& move) const;//    jumpbotright: Checks if peice can be jumped on the bottom right side
        bool jumpbotleft(const string& move) const;  //    jumpbotleft: Checks if peice can be jumped on the bottom left side
    };
}

#endif //CHECKERS_H