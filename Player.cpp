//
//  Player.cpp
//  Mastermind Game
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//

#include "Player.hpp"

using namespace std;




Player::Player(string newName, string newGameLevel, int newNumberOfGamesPlayed, int newPointScored) {
    userName = new string(newName);
    userLevel = new string(newGameLevel);
    numberOfGamesPlayed = new int(newNumberOfGamesPlayed);
    pointScored = new int(newPointScored);

}



//Default Destructor
Player::~Player()
{
    delete userName;
    delete userLevel;
    delete numberOfGamesPlayed;
    delete pointScored;

}


//Accessors
string Player::getName() {
    return *userName;
}

string Player::getLevel() {
    return *userLevel;
}

int Player::getNumberOfGamesPlayed() {
    return *numberOfGamesPlayed;
}

int Player::getPointScored() {
    return *pointScored;
}




//Mutators
void Player::setName(string newName) {
    if (newName.length() > 0) {
        *userName = newName;
    }
}

void Player::setUserLevel(string newGameLevel) {
    if (newGameLevel == "G")
    {
        *userLevel = "Genin";
    }
    else if (newGameLevel == "C") {
        *userLevel = "Chunin";
    }
    else if (newGameLevel == "J") {
        *userLevel = "Jonin";
    }

}

void Player::setNumberOfGamesPLayed(int newNumberOfGamesPlayed) {
    if (newNumberOfGamesPlayed > 0) {
        *numberOfGamesPlayed = newNumberOfGamesPlayed;
    }
}

void Player::setPointScored(int newPointScored) {
    if (newPointScored > 0) {
        *pointScored = newPointScored;
    }
}
