//
//  GameApplication.hpp
//  Mastermind Game
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
//Global variables
string userAnswer;

//Initialzing a player object
Player *player = new Player("", "", 0, 0);
Board *board = new Board(0, 0, "");
//Functions
void mainMenu();
void gameInfo();
void registerPlayer();
void difficultyLevel();
void mainGameNumbers();
void mainGameLetters();
void mainGameColours();
void playGame();
void test();
void displayCertificate();
string askForString(string question);


#endif
 /* GameApplication_hpp */
