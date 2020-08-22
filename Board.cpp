//
//  Board.cpp
//  Mastermind Game
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//

#include "Board.hpp"

using namespace std;


//Constructor
Board::Board(int newNumOfColumns, int newNumOfRows, string newBoardTheme) {
    numOfColumns = new int(newNumOfColumns);
    numOfRows = new int(newNumOfRows);
    boardTheme = new string(newBoardTheme);
}




//Accessors
int Board::getNumOfColumns() {
    return *numOfColumns;
}
int Board::getNumOfRows() {
    return *numOfRows;
}
string Board::getBoardTheme() {
    return *boardTheme;
}

//Destructor
Board::~Board() {
    delete numOfRows;
    delete numOfColumns;
}

//Mutators
void Board::setNumOfRows(int newNumOfRows) {
    if (newNumOfRows > 0) {
        *numOfRows = newNumOfRows;
    }

}
void Board::setNumOfColumns(int newNumOfColumns) {
    if (newNumOfColumns > 0) {
        *numOfColumns = newNumOfColumns;
    }

}
void Board::setBoardTheme(string newTheme) {
    if (newTheme.length() > 0) {
        *boardTheme = newTheme;
    }
}
