#include "checkers.h"
#include "colors.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
namespace main_savitch_14
{

    void checkers::display_status() const
    {
        int count = 1;
        cout << B_BLACK << "                                " << RESET << endl;
        cout << B_BLACK << "  " << B_BLUE << "   A  B  C  D  E  F  G  H   " << B_BLACK << "  " << RESET << endl;
        for (int i = 0; i < row; i++)
        {
            cout << B_BLACK << "  " << B_BLACK << count << " ";
            for (int j = 0; j < col; j++)
            {
                if (((j + i) % 2) == 0)
                    cout << B_RED << "   " << RESET;
                else if (!board[i][j].is_green() && !board[i][j].is_white())
                    cout << B_BLACK << "   " << RESET;
                else if (board[i][j].is_green() && board[i][j].is_king())
                    cout << B_BLACK << GREEN << " O " << RESET; 
                else if (board[i][j].is_white())
                    cout << B_BLACK << B_BLACK << " O " << RESET;
                else if (board[i][j].is_white() && board[i][j].is_king())
                    cout << B_BLACK << WHITE << " O " << RESET; 
                else if (board[i][j].is_green())
                    cout << B_BLACK << GREEN << " O " << RESET;
            }
            cout << B_BLACK << " " << count << B_BLACK << "  " << RESET << endl;
            count++;
        }
        cout << B_BLACK << "  " << B_BLUE << "   A  B  C  D  E  F  G  H   " << B_BLACK << "  " << RESET << endl
             << B_BLACK << "                                " << RESET << endl;
    }

    void checkers::restart()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && (j == 1 || j == 3 || j == 5 || j == 7))
                {
                    board[i][j].make_green();
                }
                else if (i == 1 && (j == 0 || j == 2 || j == 4 || j == 6))
                {
                    board[i][j].make_green();
                }
                else if (i == 2 && (j == 1 || j == 3 || j == 5 || j == 7))
                {
                    board[i][j].make_green();
                }
                else if (i == 5 && (j == 0 || j == 2 || j == 4 || j == 6))
                {
                    board[i][j].make_white();
                }
                else if (i == 6 && (j == 1 || j == 3 || j == 5 || j == 7))
                {
                    board[i][j].make_white();
                }
                else if (i == 7 && (j == 0 || j == 2 || j == 4 || j == 6))
                {
                    board[i][j].make_white();
                }
                else
                {
                    board[i][j].make_empty();
                }
            }
        }
    }
    bool checkers::is_legal(const string &move) const
    {
        int col_1 = (int)(toupper(move.at(0)) - 'A');
        int row_1 = (int)(move.at(1) - '1');
        int col_2 = (int)(toupper(move.at(2)) - 'A');
        int row_2 = (int)(move.at(3) - '1');
        cout << col_1 << " " << row_1 << " " << col_2 << " " << row_2 << endl;
        return true;

        if (col_1 < 0 || col_1 > 8)
        {
            return false;
        }
        if (row_1 < 0 || row_1 > 8)
        {
            return false;
        }
        if (col_2 < 0 || col_2 > 8)
        {
            return false;
        }
        if (row_2 < 0 || row_1 > 8)
        {
            return false;
        }
        if (row_1 != 5)
        {
            return true;
        }
        else if (col_1 % 2 != 0)
        {
            return true;
        }
        else if (row_2 != 4)
        {
            return true;
        }
        else if (col_2 % 2 != 1)
        {
            return true;
        }
        else
        {
            return true;
        }
        if (moves_completed() % 2 == 0)
        {
            if (board[row_1][col_1].is_white() == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (moves_completed() % 2 == 1)
        {
            if (board[row_1][col_1].is_green() == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    void checkers::make_move(const std::string &move)
    {
        int white_count = 0;
        int green_count = 0;

        int col_1 = (int)(toupper(move.at(0)) - 'A');
        int row_1 = (int)(move.at(1) - '1');
        int col_2 = (int)(toupper(move.at(2)) - 'A');
        int row_2 = (int)(move.at(3) - '1');

        board[row_1][col_1].make_empty();
        if (moves_completed() % 2 == 0)
        {
            board[row_2][col_2].make_white();
        }
        else if (moves_completed() % 2 == 1)
        {
            board[row_2][col_2].make_green();
        }
        game::make_move(move);

        if (col_1 == 0 && col_2 == 1)
        {

            board[row_2][col_2].make_white();
        }
        else if (col_1 == 2 && col_2 == 1)
        {
            board[row_2][col_2].make_white();
        }
        else if (col_1 == 2 && col_2 == 3)
        {
            board[row_2][col_2].make_white();
        }
        else if (col_1 == 4 && col_2 == 3)
        {
            board[row_2][row_2].make_white();
        }
        else if (col_1 == 4 && col_2 == 5)
        {
            board[row_2][col_2].make_white();
        }
        else if (col_1 == 6 && col_2 == 5)
        {
            board[row_2][col_2].make_white();
        }
        else if (col_1 == 6 && col_2 == 7)
        {
            board[row_2][col_2].make_white();
        }

        if (col_1 == 1 && col_2 == 0)
        {

            board[row_2][col_2].make_green();
        }
        else if (col_1 == 1 && col_2 == 2)
        {
            board[row_2][col_2].make_green();
        }
        else if (col_1 == 3 && col_2 == 2)
        {
            board[row_2][col_2].make_green();
        }
        else if (col_1 == 3 && col_2 == 4)
        {
            board[row_2][col_2].make_green();
        }
        else if (col_1 == 5 && col_2 == 4)
        {
            board[row_2][col_2].make_green();
        }
        else if (col_1 == 5 && col_2 == 6)
        {
            board[row_2][col_2].make_green();
        }
        else if (col_1 == 7 && col_2 == 6)
        {
            board[row_2][col_2].make_green();
        }
    }

    checkers::who checkers::winning() const
    {
        int hcount = 0;
        int ccount = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j].is_green())
                {
                    hcount++;
                }
                else if (board[i][j].is_white())
                {
                    ccount++;
                }
                else
                {
                    ;
                }
            }
        }
        if (hcount == ccount)
        {
            return NEUTRAL;
        }
        else if (hcount > ccount)
        {
            return HUMAN;
        }
        else if (hcount < ccount)
        {
            return COMPUTER;
        }
    }

    bool checkers::is_game_over() const
    {
        int hcount = 0;
        int ccount = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j].is_green())
                {
                    hcount++;
                }
                else if (board[i][j].is_white())
                {
                    ccount++;
                }
                else
                {
                    ;
                }
            }
        }
        if (hcount == 0)
        {
            return true;
        }
        else if (ccount == 0)
        {
            return true;
        }
        else
        {
            true;
        }
    }
    bool checkers::is_jump_available() const
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (moves_completed() % 2 == 0)
                {
                    if (board[i][j].is_green())
                    {
                        if (board[i - 1][j - 1].is_white() && board[i - 2][j - 2].is_empty())
                            return true;
                        if (board[i - 1][j + 1].is_white() && board[i - 2][j + 2].is_empty())
                            return true;
                        if (board[i][j].is_king())
                        {
                            if (board[i + 1][j - 1].is_white() && board[i + 2][j - 2].is_empty())
                                return true;
                            if (board[i + 1][j + 1].is_white() && board[i + 2][j + 2].is_empty())
                                return true;
                        }
                    }
                }
                if (moves_completed() % 2 == 1)
                {
                    if (board[i][j].is_white())
                    {
                        if (board[i + 1][j - 1].is_green() && board[i + 2][j - 2].is_empty())
                            return true;
                        if (board[i + 1][j + 1].is_green() && board[i + 2][j + 2].is_empty())
                            return true;
                        if (board[i][j].is_king())
                        {
                            if (board[i - 1][j - 1].is_green() && board[i - 2][j - 2].is_empty())
                                return true;
                            if (board[i - 1][j + 1].is_green() && board[i - 2][j - 2].is_empty())
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    void checkers::getstartloc(const string &move, int &i, int &j) const
    {
        for (int z = 0; z < 2; z++)
        {
            if (move[z] == 'a')
                j = 0;
            if (move[z] == 'b')
                j = 1;
            if (move[z] == 'c')
                j = 2;
            if (move[z] == 'd')
                j = 3;
            if (move[z] == 'e')
                j = 4;
            if (move[z] == 'f')
                j = 5;
            if (move[z] == 'g')
                j = 6;
            if (move[z] == 'h')
                j = 7;
            if (move[z] == '1')
                i = 0;
            if (move[z] == '2')
                i = 1;
            if (move[z] == '3')
                i = 2;
            if (move[z] == '4')
                i = 3;
            if (move[z] == '5')
                i = 4;
            if (move[z] == '6')
                i = 5;
            if (move[z] == '7')
                i = 6;
            if (move[z] == '8')
                i = 7;
        }
    }
    void checkers::getmovetoloc(const string &move, int &x, int &y) const
    {
        for (int z = 2; z < 4; z++)
        {
            if (move[z] == 'a')
                y = 0;
            if (move[z] == 'b')
                y = 1;
            if (move[z] == 'c')
                y = 2;
            if (move[z] == 'd')
                y = 3;
            if (move[z] == 'e')
                y = 4;
            if (move[z] == 'f')
                y = 5;
            if (move[z] == 'g')
                y = 6;
            if (move[z] == 'h')
                y = 7;
            if (move[z] == '1')
                x = 0;
            if (move[z] == '2')
                x = 1;
            if (move[z] == '3')
                x = 2;
            if (move[z] == '4')
                x = 3;
            if (move[z] == '5')
                x = 4;
            if (move[z] == '6')
                x = 5;
            if (move[z] == '7')
                x = 6;
            if (move[z] == '8')
                x = 7;
        }
    }

    bool checkers::legal_moves(const string &move) const
    {
        int i, j, x, y;
        i = j = x = y = 0;
        getstartloc(move, i, j);
        getmovetoloc(move, x, y);
        if (moves_completed() % 2 == 0)
        {
            if (board[i][j].is_green() || board[i][j].is_white())
            {
                if (i - 1 == x)
                {
                    if (board[i - 1][j - 1].is_empty() && j - 1 == y)
                        return true;
                    if (board[i - 1][j + 1].is_empty() && j + 1 == y)
                        return true;
                }
                if (board[i][j].is_king())
                {
                    if (i + 1 == x)
                    {
                        if (board[i + 1][j - 1].is_empty() && j - 1 == y)
                            return true;
                        if (board[i + 1][j + 1].is_empty() && j + 1 == y)
                            return true;
                    }
                }
            }
        }
        if (moves_completed() % 2 == 1)
        {
            if (board[i][j].is_white() || board[i][j].is_green())
            {
                if (i + 1 == x)
                {
                    if (board[i + 1][j - 1].is_empty() && j - 1 == y)
                        return true;
                    if (board[i + 1][j + 1].is_empty() && j + 1 == y)
                        return true;
                }
                if (board[i][j].is_king())
                {
                    if (i - 1 == x)
                    {
                        if (board[i - 1][j - 1].is_empty() && j - 1 == y)
                            return true;
                        if (board[i - 1][j + 1].is_empty() && j + 1 == y)
                            return true;
                    }
                }
            }
        }
        return false;
    }

}
