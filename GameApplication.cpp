//
//  GameApplication.cpp
//  Mastermind Game
//
//  Created by Ezazul Hoque on 22/8/20.
//  Copyright © 2020 Ezazul Hoque. All rights reserved.
//

#include "GameApplication.hpp"
int main() {
    //Run the program
    mainMenu();
    //Wait and exit
    system("PAUSE");
    return 0;
}



//Displays the mainMenu and asks the player for inputs to start the game, display the game information and exit the game
void mainMenu() {
    cout << "\n~~~~~~~~~~~~~~~~~~~~~ Mastermind (A Ninja Test) ~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "[1] Start" << endl << "[2] About" << endl << "[3] Quit";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    userAnswer = askForString("Please enter your choice: ");

    //Using if and else statements to validate that the user only uses 1, 2 or 3
    if (userAnswer == "1") {
        system("CLS");
        registerPlayer();

    }
    else if (userAnswer == "2") {
        //displayInformation();
        system("CLS");
        gameInfo();
    }
    else if (userAnswer == "3") {
        system("PAUSE");
    }
    else if (userAnswer == "Q") {
        system("PAUSE");
    }
    else {
        cout << "Please enter 1, 2 or 3";
        mainMenu();
    }
}



//AskForString
string askForString(string question) {
    string userInput = "";
    while (userInput == "") {
        cout << "\n " + question;
        getline(cin, userInput);
    }
    return userInput;
}



//This function initializes the player name, game level and board theme
void registerPlayer() {
    string userName;
    string gameLevel;
    string gameTheme;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    userName = askForString("Please enter your name: ");
    gameLevel = askForString("Which difficulty would you like to play in ? [G]enin, [C]hunin or [J]onin (Genin is the easiest difficulty with 4 inputs, Chunin is fair difficulty with 6 inputs and Jonin is the hardest difficulty with 8 inputs): ");
    gameTheme = askForString("What type of theme would you like to play in? [L]etters [C]olours [N]umbers: ");





    //This while loops are validating the user inputs, it will only accept certain characters.
    while (gameLevel != "G" && gameLevel != "C" && gameLevel != "J")
    {
        cout << "Please enter G, C or J" << endl;
        gameLevel = askForString("Which difficulty would you like to play in ? [G]enin, [C]hunin or [J]onin (Genin is the easiest difficulty and Jonin is the hardest difficulty: \n ");
    }
    while (gameTheme != "L" && gameTheme != "C" && gameTheme != "N") {
        cout << "Please enter L, C or N" << endl;
        gameTheme = askForString("What type of theme would you like to play in? [L]etters [C]olours [N]umbers: ");
    }
    //Storing into user nand board class
    player->setName(userName);
    player->setUserLevel(gameLevel);
    board->setBoardTheme(gameTheme);
    system("CLS");
    playGame();
    /**cout << player->getName() << endl << player->getLevel() << endl << board->getBoardTheme() << endl;
    system("PAUSE"); */
}




//initializing Difficulty Level
void difficultyLevel() {
    int rows = 0;
    int    columns = 0;
    if (player->getLevel() == "Genin") {
        rows = 4; // Now the user have to input four colours
        columns = 12; //NumberOfturns
    }
    else if (player->getLevel() == "Chunin") {
        rows = 6;
        columns = 10;
    }
    else if (player->getLevel() == "Jonin") {
        rows = 8;
        columns = 6;
    }
    else {

    }
    board->setNumOfColumns(columns);
    board->setNumOfRows(rows);
}


/**This function is pretty complicated, messy and unstable but it does compile. So in this code the secret code is an array of characters. TO generate the secret code I have used a for loop
which puts the value of the characters in different sequence inside the array. Next using a while loop I ask the user to input their code and inside the while loop there are multiple if and else
blocks to validate the user input and give hint and also display the board using the ASCII characters. The original code is from http://www.cplusplus.com/forum/beginner/43064/ but it is massively
modified.
                                                                                                                                                                        */
void mainGameColours() {
    //the string line code was obtained from lab week 8 and modified
    string line = "\n\t +---+---+---+---+";
    string line2 = "\n\t +---+---+---+---+---+---+";
    string line3 = "\n\t +---+---+---+---+---+---+---+---+";
    char colors[4];
    bool isGameOver = false;
    if (board->getNumOfRows() == 4) {
        char colors[4];

    }

    else if (board->getNumOfRows() == 6) {
        char colors[6];
    }

    else if (board->getNumOfRows() == 8) {
        char colors[8];
    }
    else {
        char colors[4];
    }


    srand(time(0));

    int randomint = (rand() % 5) + 1;

    //Generates Random Code
    for (int i = 0; i < board->getNumOfRows(); i++) {
        randomint = (rand() % 5) + 1;

        switch (randomint) {
        case 1:
            colors[i] = 'R';
            break;
        case 2:
            colors[i] = 'B';
            break;
        case 3:
            colors[i] = 'Y';
            break;
        case 4:
            colors[i] = 'P';
            break;
        case 5:
            colors[i] = 'G';
            break;
        }
    }

    string usercolors;


    cout << endl << endl;
    int turncounter = 0;

    while (turncounter != board->getNumOfColumns() && !isGameOver) {
        turncounter++;

        cout << "~~~~~~~~~~~~~~~~~~~" << "\tEntry Level Attempt #" << turncounter << "\t~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "What is your guess?(Only Input the first letter without spaces) " << "\n[R]ed [G]reen [B]lue [Y]ellow [P]urple \n";
        cin >> usercolors;

        while (usercolors.length() != board->getNumOfRows()) {
            cout << "Please input with no spaces" << endl;
            cout << "What is your guess? " << turncounter << ": " << "\n[R]ed [G]reen [B]lue [Y]ellow [P]urple \n";
            cin >> usercolors;
            system("CLS");
        }
        cout << endl;
        //Checks if the user's guess is equal to the secret code
        if (board->getNumOfRows() == 4 && usercolors[0] == colors[0] &&
            usercolors[1] == colors[1] &&
            usercolors[2] == colors[2] &&
            usercolors[3] == colors[3])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;
            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (board->getNumOfRows() == 6 && usercolors[0] == colors[0] &&
            usercolors[1] == colors[1] &&
            usercolors[2] == colors[2] &&
            usercolors[3] == colors[3] &&
            usercolors[4] == colors[4] &&
            usercolors[5] == colors[5])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;

            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (board->getNumOfRows() == 8 && usercolors[0] == colors[0] &&
            usercolors[1] == colors[1] &&
            usercolors[2] == colors[2] &&
            usercolors[3] == colors[3] &&
            usercolors[4] == colors[4] &&
            usercolors[5] == colors[5] &&
            usercolors[6] == colors[6] &&
            usercolors[7] == colors[7])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;
            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (turncounter == board->getNumOfColumns() && colors != usercolors) {
            cout << "You lost." << endl;
            mainMenu();
        }

        else {
            //Gives you feedback of your response and displays the ASCII Board and dpending on the number of rows it will show different elements
            cout << "Your previous guess was: " << usercolors
                << " " << endl;
            if (board->getNumOfRows() == 4) {
                cout << line << "\n\t | " << usercolors[0] << " | " << usercolors[1] << " | " << usercolors[2] <<
                    " | " << usercolors[3] << " |";
                cout << line << endl;
            }

            else if (board->getNumOfRows() == 6) {
                cout << line2 << "\n\t | " << usercolors[0] << " | " << usercolors[1] << " | " << usercolors[2] <<
                    " | " << usercolors[3] << " | " << usercolors[4] << " | " << usercolors[5] << " |";
                cout << line2 << endl;
            }

            else if (board->getNumOfRows() == 8) {
                cout << line3 << "\n\t | " << usercolors[0] << " | " << usercolors[1] << " | " << usercolors[2] <<
                    " | " << usercolors[3] << " | " << usercolors[4] << " | " << usercolors[5] << " | " << usercolors[6] << " | " << usercolors[7] << " |";
                cout << line3 << endl;
            }

            cout << "Hint: ";
            //Gives you a hint, O means right place right position and X means right place wrong position
            for (int i = 0; i < board->getNumOfRows(); i++) {
                if (usercolors[i] == colors[i])
                    cout << "O" << "-";
            }

            if (usercolors[0] == colors[1] ||
                usercolors[0] == colors[2] ||
                usercolors[0] == colors[3]) {
                cout << "X" << "-";
            }
            if (usercolors[1] == colors[0] ||
                usercolors[1] == colors[2] ||
                usercolors[1] == colors[3]) {
                cout << "X" << "-";
            }
            if (usercolors[2] == colors[0] ||
                usercolors[2] == colors[1] ||
                usercolors[2] == colors[3]) {
                cout << "X" << "-";
            }
            if (usercolors[3] == colors[0] ||
                usercolors[3] == colors[1] ||
                usercolors[3] == colors[2])
            {
                cout << "X" << "";
            }
            cout << endl << endl;
            cout << "Try Again!" << endl;

        }

    }

    system("PAUSE");
    //cin.get();
    //cin.get();
}

//The functionality in this function is the same as the main game colors with different values in the array of characters
void mainGameNumbers() {
    string line = "\n\t +---+---+---+---+";
    string line2 = "\n\t +---+---+---+---+---+---+";
    string line3 = "\n\t +---+---+---+---+---+---+---+---+";
    char numbers[4];
    bool isGameOver = false;
    if (board->getNumOfRows() == 4) {
        char numbers[4];

    }

    else if (board->getNumOfRows() == 6) {
        char numbers[6];
    }

    else if (board->getNumOfRows() == 8) {
        char numbers[8];
    }
    else {
        char numbers[4];
    }


    srand(time(0));

    int randomint = (rand() % 5) + 1;

    //Generates Random Code
    for (int i = 0; i < board->getNumOfRows(); i++) {
        randomint = (rand() % 5) + 1;

        switch (randomint) {
        case 1:
            numbers[i] = '1';
            break;
        case 2:
            numbers[i] = '2';
            break;
        case 3:
            numbers[i] = '3';
            break;
        case 4:
            numbers[i] = '4';
            break;
        case 5:
            numbers[i] = '5';
            break;
        }
    }

    string userInput;


    cout << endl << endl;
    int turncounter = 0;

    while (turncounter != board->getNumOfColumns() && !isGameOver) {
        turncounter++;

        cout << "~~~~~~~~~~~~~~~~~~~" << "\tEntry Level Attempt #" << turncounter << "\t~~~~~~~~~~~~~~~~~~~~~" << endl;


        cout << "What is your guess?(Only Input without spaces) " << "\n(1-5)\n";
        cin >> userInput;

        while (userInput.length() != board->getNumOfRows()) {
            cout << "Please input with no spaces" << endl;
            cout << "What is your guess? " << turncounter << ": " << "\n(1-5)\n";
            cin >> userInput;
            system("CLS");
        }
        cout << endl;
        //Checks if the user's code is equal to the secret code
        if (board->getNumOfRows() == 4 && userInput[0] == numbers[0] &&
            userInput[1] == numbers[1] &&
            userInput[2] == numbers[2] &&
            userInput[3] == numbers[3])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;
            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (board->getNumOfRows() == 6 && userInput[0] == numbers[0] &&
            userInput[1] == numbers[1] &&
            userInput[2] == numbers[2] &&
            userInput[3] == numbers[3] &&
            userInput[4] == numbers[4] &&
            userInput[5] == numbers[5])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;

            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (board->getNumOfRows() == 8 && userInput[0] == numbers[0] &&
            userInput[1] == numbers[1] &&
            userInput[2] == numbers[2] &&
            userInput[3] == numbers[3] &&
            userInput[4] == numbers[4] &&
            userInput[5] == numbers[5] &&
            userInput[6] == numbers[6] &&
            userInput[7] == numbers[7])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;
            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (turncounter == board->getNumOfColumns() && numbers != userInput) {
            cout << "You lost." << endl;
            mainMenu();
        }

        else {
            //Gives you feedback of your response and displays the ASCII Board and dpending on the number of rows it will show different elements
            cout << "Your previous guess was: " << userInput
                << " " << endl;
            if (board->getNumOfRows() == 4) {
                cout << line << "\n\t | " << userInput[0] << " | " << userInput[1] << " | " << userInput[2] <<
                    " | " << userInput[3] << " |";
                cout << line << endl;
            }

            else if (board->getNumOfRows() == 6) {
                cout << line2 << "\n\t | " << userInput[0] << " | " << userInput[1] << " | " << userInput[2] <<
                    " | " << userInput[3] << " | " << userInput[4] << " | " << userInput[5] << " |";
                cout << line2 << endl;
            }

            else if (board->getNumOfRows() == 8) {
                cout << line3 << "\n\t | " << userInput[0] << " | " << userInput[1] << " | " << userInput[2] <<
                    " | " << userInput[3] << " | " << userInput[4] << " | " << userInput[5] << " | " << userInput[6] << " | " << userInput[7] << " |";
                cout << line3 << endl;
            }

            cout << "Hint: ";
            //Gives you a hint, O means right place right position and X means right place wrong position
            for (int i = 0; i < board->getNumOfRows(); i++) {
                if (userInput[i] == numbers[i])
                    cout << "O" << "-";
            }

            if (userInput[0] == numbers[1] ||
                userInput[0] == numbers[2] ||
                userInput[0] == numbers[3]) {
                cout << "X" << "-";
            }
            if (userInput[1] == numbers[0] ||
                userInput[1] == numbers[2] ||
                userInput[1] == numbers[3]) {
                cout << "X" << "-";
            }
            if (userInput[2] == numbers[0] ||
                userInput[2] == numbers[1] ||
                userInput[2] == numbers[3]) {
                cout << "X" << "-";
            }
            if (userInput[3] == numbers[0] ||
                userInput[3] == numbers[1] ||
                userInput[3] == numbers[2])
            {
                cout << "X" << "";
            }
            cout << endl << endl;
            cout << "Try Again!" << endl;

        }

    }

    system("PAUSE");
    //cin.get();
    //cin.get();
}

//The functionality in this function is the same as the main game colors with different values in the array of characters
void mainGameLetters() {
    string line = "\n\t +---+---+---+---+";
    string line2 = "\n\t +---+---+---+---+---+---+";
    string line3 = "\n\t +---+---+---+---+---+---+---+---+";
    char letters[4];
    bool isGameOver = false;
    if (board->getNumOfRows() == 4) {
        char letters[4];

    }

    else if (board->getNumOfRows() == 6) {
        char letters[6];
    }

    else if (board->getNumOfRows() == 8) {
        char letters[8];
    }
    else {
        char letters[4];
    }


    srand(time(0));

    int randomint = (rand() % 5) + 1;

    //Generates Random Code
    for (int i = 0; i < board->getNumOfRows(); i++) {
        randomint = (rand() % 5) + 1;

        switch (randomint) {
        case 1:
            letters[i] = 'A';
            break;
        case 2:
            letters[i] = 'B';
            break;
        case 3:
            letters[i] = 'C';
            break;
        case 4:
            letters[i] = 'D';
            break;
        case 5:
            letters[i] = 'E';
            break;
        }
    }

    string userInput;


    cout << endl << endl;
    int turncounter = 0;

    while (turncounter != board->getNumOfColumns() && !isGameOver) {
        turncounter++;

        cout << "~~~~~~~~~~~~~~~~~~~" << "\tEntry Level Attempt #" << turncounter << "\t~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "What is your guess?(Only Input without spaces) " << "\n(A-E)\n";
        cin >> userInput;

        while (userInput.length() != board->getNumOfRows()) {
            cout << "Please input with no spaces" << endl;
            cout << "What is your guess? " << turncounter << ": " << "\n(A-E)\n";
            cin >> userInput;
            system("CLS");
        }
        cout << endl;
        //Checks if the user's code is equal to the secret code
        if (board->getNumOfRows() == 4 && userInput[0] == letters[0] &&
            userInput[1] == letters[1] &&
            userInput[2] == letters[2] &&
            userInput[3] == letters[3])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;
            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (board->getNumOfRows() == 6 && userInput[0] == letters[0] &&
            userInput[1] == letters[1] &&
            userInput[2] == letters[2] &&
            userInput[3] == letters[3] &&
            userInput[4] == letters[4] &&
            userInput[5] == letters[5])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;

            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (board->getNumOfRows() == 8 && userInput[0] == letters[0] &&
            userInput[1] == letters[1] &&
            userInput[2] == letters[2] &&
            userInput[3] == letters[3] &&
            userInput[4] == letters[4] &&
            userInput[5] == letters[5] &&
            userInput[6] == letters[6] &&
            userInput[7] == letters[7])
        {
            system("CLS");
            cout << "Congratulations " << player->getName() << " , you have passed the test in " << turncounter << " attempts!" << endl;
            isGameOver = true;
            system("PAUSE");
            displayCertificate();
        }
        else if (turncounter == board->getNumOfColumns() && letters != userInput) {
            cout << "You lost." << endl;
            mainMenu();
        }

        else {
            //Gives you feedback of your response and displays the ASCII Board and dpending on the number of rows it will show different elements
            cout << "Your previous guess was: " << userInput
                << " " << endl;
            if (board->getNumOfRows() == 4) {
                cout << line << "\n\t | " << userInput[0] << " | " << userInput[1] << " | " << userInput[2] <<
                    " | " << userInput[3] << " |";
                cout << line << endl;
            }

            else if (board->getNumOfRows() == 6) {
                cout << line2 << "\n\t | " << userInput[0] << " | " << userInput[1] << " | " << userInput[2] <<
                    " | " << userInput[3] << " | " << userInput[4] << " | " << userInput[5] << " |";
                cout << line2 << endl;
            }

            else if (board->getNumOfRows() == 8) {
                cout << line3 << "\n\t | " << userInput[0] << " | " << userInput[1] << " | " << userInput[2] <<
                    " | " << userInput[3] << " | " << userInput[4] << " | " << userInput[5] << " | " << userInput[6] << " | " << userInput[7] << " |";
                cout << line3 << endl;
            }

            cout << "Hint: ";
            //Gives you a hint, O means right place right position and X means right place wrong position
            for (int i = 0; i < board->getNumOfRows(); i++) {
                if (userInput[i] == letters[i])
                    cout << "O" << "-";
            }

            if (userInput[0] == letters[1] ||
                userInput[0] == letters[2] ||
                userInput[0] == letters[3]) {
                cout << "X" << "-";
            }
            if (userInput[1] == letters[0] ||
                userInput[1] == letters[2] ||
                userInput[1] == letters[3]) {
                cout << "X" << "-";
            }
            if (userInput[2] == letters[0] ||
                userInput[2] == letters[1] ||
                userInput[2] == letters[3]) {
                cout << "X" << "-";
            }
            if (userInput[3] == letters[0] ||
                userInput[3] == letters[1] ||
                userInput[3] == letters[2])
            {
                cout << "X" << "";
            }
            cout << endl << endl;
            cout << "Try Again!" << endl;

        }

    }

    system("PAUSE");
    //cin.get();
    //cin.get();
}


//Rins the whole game. Validates the themes and displays the main game function accordingly
void playGame() {
    difficultyLevel();
    if (board->getBoardTheme() == "C") {
        mainGameColours();
    }

    else if (board->getBoardTheme() == "N") {
        mainGameNumbers();
    }

    else if (board->getBoardTheme() == "L") {
        mainGameLetters();
    }
}


//Displays the player certificate at the end of the game
void displayCertificate() {
    //My original pointScored function should've been in the mainGame functions but my code kept crashing.
    int pointScored = 80;
    player->setPointScored(pointScored);
    cout << "Here is your certificate below." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Name: " << player->getName() << endl;
    cout << "Level: " << player->getLevel() << endl;
    cout << "Marks Achieved: " << player->getPointScored() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


}



//Displays the gameInfo
void gameInfo() {
    /* This function reads the data from GameInformation.txt file. Also the code was obtained from Lab 3 and some edits were made
    */

    // open file for reading
    ifstream fileToRead("GameInformation.txt");
    if (fileToRead.is_open()) {
        string line = "";
        while (!fileToRead.eof()) {
            getline(fileToRead, line);
            cout << line << "\n";
        }
    } //If the file is not available this message will pop up
    else {
        cout << "\n File not found!\n";
    }
    // remember to close the file
    fileToRead.close();
    //The system pauses and when pressed enter it goes back to the main menu
    system("PAUSE");
    system("CLS");
    mainMenu();
}
