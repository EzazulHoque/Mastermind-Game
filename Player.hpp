//
//  Player.hpp
//  Mastermind Game
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;


class Player
{
public:
    //Default Constructor
    Player(string newName);
    //Overload Constructor
    Player(string newName, string newGameLevel, int newNumberOfGamesPlayed, int newPointScored);
    //Destructor
    ~Player();

    //Accessors
    string getName();
    string getLevel();
    int getNumberOfGamesPlayed();
    int getPointScored();


    //Mutators
    void setName(string newName);
    void setUserLevel(string newGameLevel);
    void setNumberOfGamesPLayed(int newNumberOfGamesPlayed);
    void setPointScored(int newPointScored);
private:
    //Declaring the variables and initializing them
    string *userName;
    string *userLevel;
    int *numberOfGamesPlayed;
    int *pointScored;

};

#endif
 /* Player_hpp */
