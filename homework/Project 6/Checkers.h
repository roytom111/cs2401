#ifndef CHECKERS_H
#define CHECKERS_H

#include "game.h"
#include "piece.h"
#include "colors.h"
#include <iostream>
#include <string>

namespace main_savitch_14{
class checkers: public game{
    public:
      checkers(){ };
     static const int row = 8;
     static const int col = 8;
   game* clone( ) const{ };
   void compute_moves(std::queue<std::string>& moves) const{ };
   void display_status( ) const;
  int evaluate( ) const{ };
  bool is_game_over()const;
  bool is_legal(const std::string& move) const;
  void make_move(const std::string& move);
  void restart();
  who winning() const;

private:

  pieces board[row][col];
  bool is_jump_available()const;
  bool legal_jumps(const string& move)const;
  bool legal_moves(const string& move)const;
  void getstartloc(const string& move, int& i, int& j)const; 
  void getmovetoloc(const string& move, int& x, int& y) const; 






};
}

#endif