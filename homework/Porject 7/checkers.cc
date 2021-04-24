/*
Name: Braden Baker
Class: CS 2401
Date: 4/23/2017
Project: Project 6 Checkers Game
Description: 
    restart: Resets the board and puts all the peices back in there original places
    display_status: Displays the pieces on the board
    is_legal: Checks the move input by the users and makes sure that move is legal
    make_move: Moves the pieces on the board based on the user input as long as its legal
    Is_game_over: Checks to see if the game is over by way of however many peices are left on the board
    winning: Keeps a tab on who is winning
    is_jump_avail: Checks to see if a jump is available for a peice to make
    jumptopright: Checks if peice can be jumped top right side
    jumptopleft: Checks if peice can be jumped top left side
    jumpbotright: Checks if peice can be jumped on the bottom right side
    jumpbotleft: Checks if peice can be jumped on the bottom left side
    peice_king: checks if current peice to move is a legal king
    movehelper: converts next 2 of string to [i][j] or [x][y]
*/
#include "checkers.h"
using namespace std;
namespace main_savitch_14 {
    
    void checkers::display_status() const {      
        int count = 1;
        cout << B_BLACK << "                                " << RESET << endl;
        cout << B_BLACK << "  " << B_RED << "   A  B  C  D  E  F  G  H   "  << B_BLACK << "  " << RESET << endl;
        for (int i = 0; i < ROWS; i++) {
            cout << B_BLACK << "  " << B_RED << count << " ";   
            for (int j = 0; j < COLUMNS; j++) {
                if (((j+i)%2) == 0) cout << B_WHITE << "   " << RESET;
                else if (!data[i][j].is_green() && !data[i][j].is_red()) cout << B_BLACK << "   " << RESET;  
                else if (data[i][j].is_red() && data[i][j].is_king()) cout << B_BLACK << RED << " K " << RESET;
                else if (data[i][j].is_red()) cout << B_BLACK << RED << " O " << RESET;
                else if (data[i][j].is_green() && data[i][j].is_king()) cout << B_BLACK << GREEN << " K " << RESET;
                else if (data[i][j].is_green()) cout << B_BLACK << GREEN << " O " << RESET; 
            }
            cout << B_RED << " " << count << B_BLACK << "  " << RESET << endl;
            count++;
        }
        cout << B_BLACK << "  " << B_RED << "   A  B  C  D  E  F  G  H   " << B_BLACK << "  " << RESET<< endl << B_BLACK << "                                " << RESET << endl;
    }

    bool checkers::is_game_over() const {    
        if (moves_completed() > 0 && moves_completed()%2 == 1) cout << B_GREEN << "Successful Move!" << RESET << " Checking if game is over...\n";
        else if (moves_completed() > 0 && moves_completed()%2 == 0)cout << B_RED << "Successful Move!" << RESET << " Checking if game is over...\n";
        else;
        int humancount = 0;
        int computercount = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (data[i][j].is_green()) humancount++;
                else if(data[i][j].is_red()) computercount++;              
                else;
            }
        }
        cout << GREEN << "Green" << RESET << " has " << humancount << " peices left.\n";
        cout << RED << "Red" << RESET << " has " << computercount << " peices left.\n";
        cout << "On turn " << moves_completed()+1 << ". ";
        if (moves_completed()%2 == 0) cout << GREEN << "Green Player's turn." << RESET<< endl;
        else cout << RED << "Red Player's turn." << RESET << endl;
        if (humancount == 0 || computercount == 0) return true; 
        else return false;
    }

    void checkers::compute_moves(queue<string>& moves) const {   
        string tmp = "a1b1";
        for (char uno = 'a'; uno < 'i'; uno++) {
            for(char dos = '1'; dos < '9'; dos++) {
                  for(char tres = 'a'; tres < 'i'; tres++) {
                       for(char quatro = '1'; quatro < '9'; quatro++) {
                            tmp[0] = uno;
                            tmp[1] = dos;
                            tmp[2] = tres;
                            tmp[3] = quatro;
                            if (is_legal(tmp)) moves.push(tmp);
                      }
                 }
             }
         }
    }

    int checkers::evaluate() const {   
        int cpuadvantage = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (data[i][j].is_green()) {
                    cpuadvantage--;
                    if (data[i][j].is_king()) cpuadvantage -= 4;
                }
                else if(data[i][j].is_red()) {
                    cpuadvantage++;
                    if (data[i][j].is_king()) cpuadvantage += 4;        
                }
                else;
            }
        }
        return cpuadvantage;
    }

    game* checkers::clone() const { return new checkers(*this); }  
    void checkers::restart() {  
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                
                if (i == 0 && (j == 1 || j == 3 || j == 5 || j == 7)) data[i][j].make_red();
                else if (i == 1 && (j == 0 || j == 2 || j == 4 || j == 6)) data[i][j].make_red();
                else if (i == 2 && (j == 1 || j == 3 || j == 5 || j == 7)) data[i][j].make_red();
                else if (i == 5 && (j == 0 || j == 2 || j == 4 || j == 6)) data[i][j].make_green();
                else if (i == 6 && (j == 1 || j == 3 || j == 5 || j == 7)) data[i][j].make_green();
                else if (i == 7 && (j == 0 || j == 2 || j == 4 || j == 6)) data[i][j].make_green();
                else data[i][j].make_neutral();
                if (data[i][j].is_king()) data[i][j].kingslayer();
            }
        }
        game::restart(); 
    }

    checkers::who checkers::winning() const {  
        int humancount = 0;
        int computercount = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (data[i][j].is_green()) humancount++;
                else if(data[i][j].is_red()) computercount++;              
                else;
            }
        }
        if (humancount == computercount) return NEUTRAL;
        return (humancount > computercount) ? HUMAN : COMPUTER ;
    }

    void checkers::make_move(const string& move) {   
        int i, j, x, y, c;
        i = j = x = y = c =0;  
        while (move[c] != '\0') {
                                  
            checkers::movehelper(move, i, j, x, y, c);  
            
            if (data[i][j].is_green() && (i - 1 == x || i + 1 == x) && (j + 1 == y || j - 1 == y) ) { 
                data[x][y].make_green();
                if (data[i][j].is_king()) data[x][y].make_king();  
                data[i][j].make_neutral();
                if (!data[x][y].is_king() && x == 0) data[x][y].make_king();  
                c += 2;
            }
            if (data[i][j].is_red() && (i - 1 == x || i + 1 == x) && (j + 1 == y || j - 1 == y) ) {  
                data[x][y].make_red();
                if (data[i][j].is_king()) data[x][y].make_king();  
                data[i][j].make_neutral();
                if (!data[x][y].is_king() && x == 7) data[x][y].make_king(); 
                c += 2;
            }
                                
            if (data[i][j].is_green() && (i - 2 == x) && (j + 2 == y) ) {  
                data[x][y].make_green();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j + 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  
                    data[x][y].make_king();
                    game::make_move(move); 
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            if (data[i][j].is_green() && (i - 2 == x) && (j - 2 == y) ) {  
                data[x][y].make_green();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  
                    data[x][y].make_king();
                    game::make_move(move); 
                    return;
                }
                 i = x;
                j = y;
                c += 2;
                continue;
            }
            if (data[i][j].is_red() && (i + 2 == x) && (j  + 2== y) ) {  
                data[x][y].make_red();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j + 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {  
                    data[x][y].make_king();
                    game::make_move(move); 
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            
            if (data[i][j].is_red() && (i + 2 == x) && (j - 2 == y) ) {  
                data[x][y].make_red();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {  
                    data[x][y].make_king();
                    game::make_move(move); 
                    return;
                }
                 i = x;
                j = y;
                c += 2;
                continue;
            }
                                
            if (data[i][j].is_red() && data[i][j].is_king() && (i - 2 == x) && (j + 2 == y) ) {  
                data[x][y].make_red();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j + 1].make_neutral();
                 if (!data[x][y].is_king() && x == 7) {  
                    data[x][y].make_king();
                    game::make_move(move); 
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            if (data[i][j].is_red() && data[i][j].is_king() && (i - 2 == x) && (j - 2 == y) ) {  
                data[x][y].make_red();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {    
                    data[x][y].make_king();
                    game::make_move(move);   
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            if (data[i][j].is_green() && data[i][j].is_king() && (i + 2 == x) && (j  + 2== y) ) {  
                data[x][y].make_green();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j + 1].make_neutral();
                 if (!data[x][y].is_king() && x == 0) {  
                    data[x][y].make_king(); 
                    game::make_move(move); 
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            if (data[i][j].is_green() && data[i][j].is_king() && (i + 2 == x) && (j - 2 == y) ) {  
                data[x][y].make_green();
                if (data[i][j].is_king()) data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  
                    data[x][y].make_king(); 
                    game::make_move(move); 
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
        }
        game::make_move(move); 
    }

    bool checkers::is_legal(const string& move) const {  
    
        if (move[1] < '1' || move[1] > '8') return false;
        if (move[3] < '1' || move[3] > '8') return false;  
        if (move[0] < 'a' || move[0] > 'h') return false;
        if (move[2] < 'a' || move[2] > 'h') return false;
        
        if (startneutral(move)) return false;
        if (move2takenspot(move)) return false;
        
        if (is_jump_avail()) {
            return (legaljumps(move));
        } else {
            return (legalmoves(move));
       }
    }
   
    bool checkers::is_jump_avail() const{
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (moves_completed()%2 == 0) {
                    if (data[i][j].is_green()) {
                        if (data[i-1][j-1].is_red() && data[i-2][j-2].is_neutral()) return true;
                        if (data[i-1][j+1].is_red() && data[i-2][j+2].is_neutral()) return true;
                        if (data[i][j].is_king()) {
                            if (data[i+1][j-1].is_red() && data[i+2][j-2].is_neutral()) return true;
                            if (data[i+1][j+1].is_red() && data[i+2][j+2].is_neutral()) return true;
                        }
                    }
                }
                if (moves_completed()%2 == 1) {
                    if (data[i][j].is_red()) {
                        if (data[i+1][j-1].is_green() && data[i+2][j-2].is_neutral()) return true;
                        if (data[i+1][j+1].is_green() && data[i+2][j+2].is_neutral()) return true;
                        if (data[i][j].is_king()) {
                            if (data[i-1][j-1].is_green() && data[i-2][j-2].is_neutral()) return true;
                            if (data[i-1][j+1].is_green() && data[i-2][j-2].is_neutral()) return true;
                        }
                   }
                }
            }
        }
        return false;  
    }

    bool checkers::legaljumps(const string& move) const {  
        if ( jumptopright(move) || jumptopleft(move) || jumpbotright(move) || jumpbotleft(move) ) return true;           
        else return false;
    }

    bool checkers::legalmoves(const string& move) const {
        int i, j, x, y;
        i = j = x = y = 0;
        getstartloc(move, i, j);
        getmovetoloc(move, x, y);
        if (moves_completed()%2 == 0) {
        if (data[i][j].is_green()) {
            if (i-1 == x) {
                if (data[i-1][j-1].is_neutral() && j-1 == y) return true;
                if (data[i-1][j+1].is_neutral() && j+1 == y) return true;
            }
            if (data[i][j].is_king()) {
                if (i+1 == x) {
                    if (data[i+1][j-1].is_neutral() && j-1 == y) return true;
                    if (data[i+1][j+1].is_neutral() && j+1 == y) return true;
                }
            }
        }
        }
        if (moves_completed()%2 == 1) {
        if (data[i][j].is_red()) {
            if (i+1 == x) {
                if (data[i+1][j-1].is_neutral() && j-1 == y) return true;
                if (data[i+1][j+1].is_neutral() && j+1 == y) return true;
            }
            if (data[i][j].is_king()) {
                if (i-1 == x) {
                    if (data[i-1][j-1].is_neutral() && j-1 == y) return true;
                    if (data[i-1][j+1].is_neutral() && j+1 == y) return true;
                }
            }
        }
    }
        return false;  
    }

    bool checkers::jumptopright(const string& move) const { 
        int i, j, x, y;
        i = j = x = y = 0;
        checkers::getstartloc(move, i, j);
        checkers::getmovetoloc(move, x, y);
        
        if (moves_completed()%2 == 0) {
            if (data[i][j].is_green()) {
                if (data[i - 1 ][j + 1].is_red()) { 
                    if (data[i - 2][j + 2].is_neutral()) {
                        if ( (i - 2) == x && (j + 2) == y) { return true; } 
                    }}}}
                        
        if (moves_completed()%2 == 1 && (data[i][j].is_king() && data[i][j].is_red()) && data[i - 1][j + 1].is_green() && data[i - 2][j + 2].is_neutral() && (i - 2) == x && (j + 2) == y ) return true; 
        return false;
    }

    bool checkers::jumptopleft(const string& move) const {  
        int i, j, x, y;
        i = j = x = y = 0;
        checkers::getstartloc(move, i, j);
        checkers::getmovetoloc(move, x, y);
        if (moves_completed()%2 == 0 && data[i][j].is_green() && data[i - 1][j - 1].is_red() && data[i - 2][j - 2].is_neutral() && ((i - 2) == x && (j - 2) ==y) ) return true;  
        else if (moves_completed()%2 == 1 && (data[i][j].is_king() && data[i][j].is_red()) && data[i - 1][j - 1].is_green() && data[i - 2][j - 2].is_neutral() && ((i - 2) == x && (j - 2) == y) ) return true; 
        else return false;
    }

    bool checkers::jumpbotright(const string& move) const {  
        int i, j, x, y;
        i = j = x = y = 0;
        checkers::getstartloc(move, i, j);
        checkers::getmovetoloc(move, x, y);
        if (moves_completed()%2 == 1 && data[i][j].is_red() && data[i + 1][j + 1].is_green() && data[i + 2][j + 2].is_neutral() && ((i + 2) == x && (j + 2) == y) ) return true;  
        else if (moves_completed()%2 == 0 && (data[i][j].is_king() && data[i][j].is_green()) && data[i + 1][j + 1].is_red() && data[i + 2][j + 2].is_neutral() && ((i + 2) == x && (j +2) ==y) ) return true; 
        else return false;    
    }

    bool checkers::jumpbotleft(const string& move) const {  
        int i, j, x, y;
        i = j = x = y = 0;
        checkers::getstartloc(move, i, j);
        checkers::getmovetoloc(move, x, y);
        if (moves_completed()%2 == 1 && data[i][j].is_red() && data[i + 1][j - 1].is_green() && data[i + 2][j - 2].is_neutral() && ((i + 2) == x && (j - 2) == y) ) return true;  
        else if (moves_completed()%2 == 0 && (data[i][j].is_king() && data[i][j].is_green()) && data[i + 1][j - 1].is_red() && data[i + 2][j - 2].is_neutral() && ((i + 2) == x && (j - 2) == y) ) return true; 
        else return false;    
    }

    bool checkers::startneutral(const string& move) const { 
        int i = 0, j = 0;
        checkers::getstartloc(move, i, j);
        return data[i][j].is_neutral();
    }
    
    bool checkers::move2takenspot(const string& move) const { 
        int x = 0, y = 0;
        checkers::getmovetoloc(move, x, y);
        return !data[x][y].is_neutral();
    }

    bool checkers::peice_king(const string& move) const { 
        int i = 0, j = 0;
        checkers::getstartloc(move, i, j);
        return data[i][j].is_king();
    }

    void checkers::movehelper(const string& move, int& i, int& j, int& x, int& y, int& c) {  
        if (c == 0) {  
            checkers::getstartloc(move, i, j);
            checkers::getmovetoloc(move, x, y);
            c += 2;
        } else {
            checkers::additionaljumps(move, x, y, c);
        }
    }

    void checkers::getstartloc(const string& move, int& i, int& j) const {
        for (int z = 0; z < 2; z++) {
            if (move[z] == 'a') j = 0;
            if (move[z] == 'b') j = 1;
            if (move[z] == 'c') j = 2;
            if (move[z] == 'd') j = 3;
            if (move[z] == 'e') j = 4;
            if (move[z] == 'f') j = 5;
            if (move[z] == 'g') j = 6;
            if (move[z] == 'h') j = 7;
            if (move[z] == '1') i = 0;
            if (move[z] == '2') i = 1;
            if (move[z] == '3') i = 2;
            if (move[z] == '4') i = 3;
            if (move[z] == '5') i = 4;
            if (move[z] == '6') i = 5;
            if (move[z] == '7') i = 6;
            if (move[z] == '8') i = 7;
        }
    }

    void checkers::getstartloc(const string& move, int& i, int& j) {
        for (int z = 0; z < 2; z++) {
            if (move[z] == 'a') j = 0;
            if (move[z] == 'b') j = 1;
            if (move[z] == 'c') j = 2;
            if (move[z] == 'd') j = 3;
            if (move[z] == 'e') j = 4;
            if (move[z] == 'f') j = 5;
            if (move[z] == 'g') j = 6;
            if (move[z] == 'h') j = 7;
            if (move[z] == '1') i = 0;
            if (move[z] == '2') i = 1;
            if (move[z] == '3') i = 2;
            if (move[z] == '4') i = 3;
            if (move[z] == '5') i = 4;
            if (move[z] == '6') i = 5;
            if (move[z] == '7') i = 6;
            if (move[z] == '8') i = 7;
        }
    }

    void checkers::getmovetoloc(const string& move, int& x, int& y) const {
        for (int z = 2; z < 4; z++) {
            if (move[z] == 'a') y = 0;
            if (move[z] == 'b') y = 1;
            if (move[z] == 'c') y = 2;
            if (move[z] == 'd') y = 3;
            if (move[z] == 'e') y = 4;
            if (move[z] == 'f') y = 5;
            if (move[z] == 'g') y = 6;
            if (move[z] == 'h') y = 7;
            if (move[z] == '1') x = 0;
            if (move[z] == '2') x = 1;
            if (move[z] == '3') x = 2;
            if (move[z] == '4') x = 3;
            if (move[z] == '5') x = 4;
            if (move[z] == '6') x = 5;
            if (move[z] == '7') x = 6;
            if (move[z] == '8') x = 7;
        }    
    }

    void checkers::getmovetoloc(const string& move, int& x, int& y) {
        for (int z = 2; z < 4; z++) {
            if (move[z] == 'a') y = 0;
            if (move[z] == 'b') y = 1;
            if (move[z] == 'c') y = 2;
            if (move[z] == 'd') y = 3;
            if (move[z] == 'e') y = 4;
            if (move[z] == 'f') y = 5;
            if (move[z] == 'g') y = 6;
            if (move[z] == 'h') y = 7;
            if (move[z] == '1') x = 0;
            if (move[z] == '2') x = 1;
            if (move[z] == '3') x = 2;
            if (move[z] == '4') x = 3;
            if (move[z] == '5') x = 4;
            if (move[z] == '6') x = 5;
            if (move[z] == '7') x = 6;
            if (move[z] == '8') x = 7;
        }    
    }
    
    void checkers::additionaljumps(const string& move, int& x, int& y, int& c) {
        for (int z = c; z < c+2; z++) {
            if (move[z] == 'a') y = 0;
            if (move[z] == 'b') y = 1;
            if (move[z] == 'c') y = 2;
            if (move[z] == 'd') y = 3;
            if (move[z] == 'e') y = 4;
            if (move[z] == 'f') y = 5;
            if (move[z] == 'g') y = 6;
            if (move[z] == 'h') y = 7;
            if (move[z] == '1') x = 0;
            if (move[z] == '2') x = 1;
            if (move[z] == '3') x = 2;
            if (move[z] == '4') x = 3;
            if (move[z] == '5') x = 4;
            if (move[z] == '6') x = 5;
            if (move[z] == '7') x = 6;
            if (move[z] == '8') x = 7;
        }    
    }
}