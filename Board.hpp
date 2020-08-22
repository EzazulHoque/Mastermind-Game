//
//  Board.hpp
//  Mastermind Game
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//

#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;
class Board
{
public:
    //Default Constructor
    Board();

    //Overload Constructor
    Board(int newNumOfColumns, int newNumOfRows, string newBoardTheme);

    //Accessors
    int getNumOfRows();
    int getNumOfColumns();
    string getBoardTheme();
    char resetBoard();
    //Mutators
    void setNumOfRows(int newNumOfRows);
    void setNumOfColumns(int newNumOfColumns);
    void setBoardTheme(string newBoardTheme);
    //Destructor
    ~Board();

private:
    //Declaring local variables and initializing them
    int *numOfRows;
    int *numOfColumns;
    string *boardTheme;


};




#endif

