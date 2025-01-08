/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on November 15, 2023, 7:36 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Global Variable:
const int COLUMN =3;

//PROTOTYPES:

//Tic-Tac-Toe Prototypes:
void pVSp(int &playerOne, int &numGame, double &totWin);
int pvspChoices(int a[][COLUMN], int rows, int first, int player);
void game(int a[][COLUMN], int row, int choice, int player);
void output(int a[][COLUMN], int rows);
bool winChecker (int a[][COLUMN], int row);
void pVSDAI(int &playerOn, int &playerWon, double &totWinDAI);
int pvsDumAiChoice(int a[][COLUMN], int rows, int first, int player);
void dumbAI(int a[][COLUMN], int row,  int player);
void perfectAI(int a[][COLUMN], int row);
void pVPAI(int &playerGame, int &playWin, double &perctWon);
int pvsPAIChoice(int a[][COLUMN], int rows, int first, int player);
void dVSd();
int dumbChoice(int a[][COLUMN], int rows,  int first, int player);
void outputToStream(int &playerOne, int &numGame, double &totWin, int &playerOn, int &playerWon, double &totWinDAI, int &playerGame, int &playWin, double &perctWon, ostream& out);
void outputToFile(int &playerOne, int &numGame, double &totWin, int &playerOn, int &playerWon, double &totWinDAI, int &playerGame, int &playWin, double &perctWon, string fileName);
void saveFile(int a[][COLUMN], int rows);
void outputToF(int a[][COLUMN], int rows, string fileName);
void outputToS(int a[][COLUMN], int rows, ostream& out);


//Hangman prototypes:
void hangMan(int &pOWins, int &pTWins);
int answer(string a[], int size, int numTry);
void outputPicture(string p[][COLUMN], int row, int numTry);
void outputDIMArray(string a[][COLUMN], int row);
void outputFlatArray(string a[], int size);
void fillArray(string a[], int size);
void fillDIMArray(string a[][COLUMN], int row);
void outputV(const vector<string>& v);
void hangManStats(int &pOWins, int &pTWins, ostream& out);
void fileHangMan(int &pOWins, int &pTWins, string fileName);
void randomWord(string &word, string &hint);
int hangGame(string a[], int size, int tries, string &hint, int &player);
void randomHangMan(int &pOWins, int &pTWins);


/*
 * 
 */
int main(int argc, char** argv) 
{
    srand(time(0));
    
    int game = 0;
    
    //Player Vs Player Stats
    int playerOne = 0;
    int playerTwo = 0;
    int totWin = 0;
    double numGame = 0;
    
    //Player Vs DAI Stats
    int playerOn = 0;
    int playerWon = 0;
    double totWinDAI = 0;
    
    //Player VS Perfect AI Stats
    int playerGame = 0;
    int playWin = 0;
    double perctWon = 0;
    
    
    //HangMan Stats:
    int pOWins = 0;
    int pTWins = 0;
    
    string menuAgain;
    
    do
    {
        cout << "Hello, Welcome to The Game Board!" << endl;
        cout << "Please choose a game you would like to play!" << endl;
        cout << "1.) Tic-Tac-Toe" << endl;
        cout << "2.) Tic-Tac-Toe Stats" << endl;
        cout << "3.) HangMan" << endl;
        cout << "4.) HangMan Stats" << endl; 
        
        int choice;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                
                cout << "Great! Now pick a mode" << endl;
                cout << "1.) Player Vs Player" << endl;
                cout << "2.) Player Vs Dumb AI" << endl;
                cout << "3.) Player Vs Perfect AI" << endl;
                cout << "4.) Dumb AI vs Dumb AI" << endl;
                
                int mode;
                cin >> mode;
                
                switch(mode)
                {
                    case 1:
                    {
                        pVSp(playerOne, totWin, numGame);
                        break;
                    }
                    case 2: 
                    {
                        pVSDAI(playerOn, playerWon, totWinDAI);
                        break;
                    }
                    case 3:
                    {
                        pVPAI(playerGame, playWin, perctWon);
                        break;
                    } 
                    case 4:
                    {
                        dVSd();
                        break;  
                    }
                    default:
                        cout << "Invalid Input!" << endl;
                }
                break;
            }
            case 2:
            {
                outputToFile(playerOne, totWin, numGame, playerOn, playerWon, totWinDAI, playerGame, playWin, perctWon, "saveSTATS.txt");
                break;
            }
            case 3:
            {
                cout << "You chose HANGMAN !" << endl;
                cout << "Please pick a mode" << endl;
                cout << "1.) One Guesser" << endl;
                cout << "2.) Two Guessers" << endl;
                
                int type;
                cin >> type;
                
                switch(type)
                {
                    case 1:
                    {
                        hangMan(pOWins, pTWins);
                        break;
                    }
                    case 2:
                    {
                       randomHangMan(pOWins, pTWins); 
                       break; 
                    }
                    default: 
                        cout << "Invalid Input!" << endl;
                        
                }
                
                break;
            }
            case 4:
            {
                fileHangMan(pOWins, pTWins, "hangmanStats.txt");
                break;
            }    
            default :
                cout << "Not a valid option" << endl;
        }
        
        cout << endl << "Would you like to back to game menu?" << endl;
        cin >> menuAgain;
        
    }while(tolower(menuAgain[0]) == 'y');
    
    
    return 0;
}

//Tic-Tac-Toe functions start here: 

/**
 * This functions allows the player vs player game to start.
 * It picks a random player to go and then contains a function that switches the turns of each player
 * When someone wins, it displays it and acts the user if they want to save the game to a file]of their choice
 * @param playerOne: the user (you)
 * @param numGame: the number of games played
 * @param totWin: the total amount of wins you won
 */
void pVSp(int &playerOne, int &numGame, double &totWin)
{
    string pAgain;
    
    do
    {
    
        cout << "Welcome To Tic-Tac-Toe Player 1 & Player 2!" << endl;

        cout << "Now choosing which player goes first . . ." << endl;
        int first = rand() % 2;
        cout << "Player " << first << " goes first!" << endl;
        cout << "Remember, Player 1 is 'X' and Player Two is 'O' !" << endl;

        int rows = 3;
        int player = 2;

        int a[rows][COLUMN];

        for(int i = 0;  i < rows; i++)
        {
            cout << endl << " -------------  " << endl;

            for(int j = 0; j < COLUMN; j++)
            {
                a[i][j] = i * rows + j + 1;
                cout << " | " << a[i][j] ;      
            }  

            cout << " |";
        } 
        cout << endl << " -------------  " << endl;

        player = pvspChoices(a, rows, first, player);

        if(player == 0)
        {
            cout << "Player Two Won!" << endl;
            numGame++;
        }
        else if(player == 1)
        {
            cout << "Player One Won!" << endl;
            playerOne++;
            numGame++;
        }
        else if (player == 2)
        {
            cout << "It's a draw! No one wins!" << endl;
            numGame++;
        }

        totWin = (playerOne/numGame) * 100; 

        cout << "Games played: " << numGame << endl;
        cout << "Games Won: " << playerOne << endl;
        cout << "Win Rate %: " << totWin << "%" << endl;

        
        //Saving your current game to a file of choice or existing fie
        string saveChoice;
        cout << "Would you like to save this Game from a file? " << endl;
        cin >> saveChoice;

        if (tolower(saveChoice[0]) == 'y')
        {
           saveFile(a, rows); 
        }
        
        cout << "Would you like to do PLAYER vs PLAYER Again?" << endl;
        cin >> pAgain;
        
    } while(tolower(pAgain[0]) == 'y');
    
}

/**
 * This function allows the each player to take turns depending on
 * who was chosen first. It also contains other functions
 * that display the game and checks if anyone won.
 * @param a: the array
 * @param rows: the number of rows
 * @param first: the player chosen to go first
 * @param player: the number to determine who wins
 * @return return which player won (player one = 10 & player two = 0)
 */
int pvspChoices(int a[][COLUMN], int rows, int first, int player)
{
    if (first == 1)
    {
        int playerOne = 10;
        int playerTwo = 0;
        player = 2;
        
        cout << "Pick a spot to place your 'X'" << endl;
        int choice;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return playerTwo;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
    }
    else if (first == 0)
    {
        int player = 2;
        int playerOne = 10;
        int playerTwo = 0;
        
        cout << "Pick a spot to place your 'O'" << endl;
        int choice;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
            player = 0;
            return player;  
        }
        
        if(player == 2)
        {
            return player;
        }
        
    }
}

/**
 * This function allows the user's piece to be displayed 
 * on the board
 * @param a: the array 
 * @param row: the number of rows
 * @param choice: where the user chose to place their piece
 * @param player: which player went
 */
void game(int a[][COLUMN], int row, int choice, int player)
{
    
    for(int i = 0;  i < row; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
           if (a[i][j] == choice) 
           {
               a[i][j] = player;
           }
        }  
        
    } 
}

/**
 * This function outputs the multi-dim array 
 * @param a: the array
 * @param rows: the number of arrays
 */
void output(int a[][COLUMN], int rows)
{
    for(int i = 0;  i < rows; i++)
    {
        cout << endl << " -------------  " << endl;
        
        for(int j = 0; j < COLUMN; j++)
        {   
            if(a[i][j] == 0) 
            {
                cout << " | " << "O";
            }
            else if(a[i][j] == 10)
            {
                cout << " | " << "X";
            }
            else
            {
                cout << " | " << a[i][j];
            }
            
        }  
        
        cout << " |";
    } 
    cout << endl << " -------------  " << endl;
}

/**
 * This functions checks if there are any winner once each person takes
 * a turn
 * @param a: the array
 * @param row: the number of rows
 * @return returns true or false
 */
bool winChecker (int a[][COLUMN], int row)
{
    
    bool winChecker = true;
    
    
    if (a[0][0] == a[0][1] && a[0][0] == a[0][2]) 
    {
        winChecker = true;
    }
    else if(a[1][0] == a[1][1] && a[1][0] == a[1][2])
    {
        winChecker = true; 
    }
    else if(a[2][0] == a[2][1] && a[2][0] == a[2][2])
    {
        winChecker = true; 
    }
    else if(a[0][1] == a[1][1] && a[0][1] == a[2][1])
    {
        winChecker = true; 
    }
    else if(a[0][2] == a[1][2] && a[0][2] == a[2][2])
    {
        winChecker = true;
    }
    else if(a[0][2] == a[1][2] && a[0][2] == a[2][2])
    {
      winChecker = true;
    }
    else if(a[0][0] == a[1][1] && a[0][0] == a[2][2])
    {
        winChecker = true;
    }
    else if(a[2][0] == a[1][1] && a[2][0] == a[0][2])
    {
        winChecker = true;
    }
    else if(a[0][0] == a[1][0] && a[0][0] == a[2][0])
    {
       winChecker = true; 
    }
    else
    {
        winChecker = false;
    }
    
    return winChecker;    
        
}

/**
 * This function allows the player vs dumb AI to start. It chooses
 * the player who goes first and contains functions that lets each player take turns
 * and checks the winner. once the game is finished it displays the stats and asks the user if they
 * would like to save the game to a file of choice
 * @param playerOn: the user (you)
 * @param playerWon: the amount of times you won against dumb AI
 * @param totWinDAI: The total wins against dumb ai
 */
void pVSDAI(int &playerOn, int &playerWon, double &totWinDAI)
{
    string dAgain;
    
    do
    {
        int player = 2;

        cout << "Welcome To Tic-Tac-Toe Player 1 & Player 2!" << endl;
        cout << "Remember, Player 1 is 'X' and Player Two is 'O' !" << endl;
        cout << "You are Player 1 and Dumb AI Is Player 2" << endl;
        cout << "Now choosing which player goes first . . ." << endl;
        int first = rand() % (2 - 1 + 1) + 1;

        int rows = 3;

        int a[rows][COLUMN];

        for(int i = 0;  i < rows; i++)
        {
            cout << endl << " -------------  " << endl;

            for(int j = 0; j < COLUMN; j++)
            {
                a[i][j] = i * rows + j + 1;
                cout << " | " << a[i][j] ;      
            }  

            cout << " |";
        } 
        cout << endl << " -------------  " << endl;  

        player = pvsDumAiChoice(a, rows, first, player);

        if(player == 2)
        {
            cout << "DUMB AI Won!" << endl;
            playerOn++;  
        }
        else if(player == 1)
        {
            cout << "Player One Won!" << endl;
            playerOn++;
            playerWon++;
        }
        else if(player == 0)
        {
            cout << "It's a draw" << endl;
            playerOn++;
        }    

        totWinDAI = (playerOn/playerWon) * 100;

        cout << "Games played with Dumb AI: " << playerOn << endl;
        cout << "Games Won against Dumb Ai: " << playerWon << endl;
        cout << "Win rate with Dumb AI: " << totWinDAI << "%" << endl;

        string saveChoice;
        cout << "Would you like to save this Game from a file? " << endl;
        cin >> saveChoice;

        if (tolower(saveChoice[0]) == 'y')
        {
           saveFile(a, rows); 
        }
        
        cout << "Would you like to go against DUMB AI Again?" << endl;
        cin >> dAgain;
        
    }while(tolower(dAgain[0]) == 'y');    
}

/**
 * This functions allows the player an dumb ai 
 * to take turns depending who was chosen to go first. It also
 * checks who won and allows the game to be displayed.
 * @param a: the array
 * @param rows: the number of  rows
 * @param first: the player chosen to go first
 * @param player: the person who won 
 * @return return which player wins
 */
int pvsDumAiChoice(int a[][COLUMN], int rows, int first, int player)
{
    if (first == 1)
    {
        int playerOne = 10;
        int playerTwo = 0;
        
        cout << "Pick a spot to place your 'X'" << endl;
        int choice;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;
          return playerTwo;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        if(player == 0)
        {
            player = 0;
            return player;
        }
        
    }
    else if (first == 2)
    {
        int playerOne = 10;
        int playerTwo = 0;
        player = 0;
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;
          return playerTwo;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        int choice;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 2;  
          return player;  
        }
        
        if(player == 0)
        {
            player = 0;
            return player;
        }
        
    }
}

void dumbAI(int a[][COLUMN], int row,  int player)
{
    int redo = 0;

    do
    {    
        int choice = rand() %( 9 - 1 + 1) +1;
        
        for(int i = 0;  i < row; i++)
        {
            for(int j = 0; j < COLUMN; j++)
            {
               if (a[i][j] == choice) 
               {
                   a[i][j] = player;
                   redo++;
               } 

            }
        } 
        
    }while (redo != 1); 
    

}

/**
 * This function allows a player to play with a perfect AI
 * @param playerGame: the amount of times the player played
 * @param playWin: the amount of times the user won
 * @param perctWon: the percent rate of wins
 */
void pVPAI(int &playerGame, int &playWin, double &perctWon)
{
    string againP;
    
    do
    {
        int player = 2;

        cout << "Welcome To Tic-Tac-Toe Player 1 & Player 2!" << endl;
        cout << "Remember, Player 1 is 'X' and Player Two is 'O' !" << endl;
        cout << "Your Player 1 and Perfect AI is Player Two" << endl;
        cout << "Now choosing which player goes first . . ." << endl;
        int first = rand() % 2;

        int rows = 3;

        int a[rows][COLUMN];

        for(int i = 0;  i < rows; i++)
        {
            cout << endl << " -------------  " << endl;

            for(int j = 0; j < COLUMN; j++)
            {
                a[i][j] = i * rows + j + 1;
                cout << " | " << a[i][j] ;      
            }  

            cout << " |";
        } 
        cout << endl << " -------------  " << endl;

        player = pvsPAIChoice(a, rows, first, player);

        if(player == 0)
        {
            cout << "Player Two Won!" << endl;
            playerGame++;
        }
        else if(player == 1)
        {
            cout << "Player One Won!" << endl;
            playWin++;
            playerGame++;
        }
        else if (player == 2)
        {
            cout << "It's a draw" << endl;
            playerGame++;
        }

        perctWon = (playWin/playerGame) * 100;

        cout << "Games played with Smart Ai: " << playerGame << endl;
        cout << "Games won with Smart Ai: " << playWin << endl;
        cout << "Win rate with Smart Ai: " << perctWon << "%" << endl;

        string saveChoice;
        cout << "Would you like to save this Game from a file? " << endl;
        cin >> saveChoice;

        if (tolower(saveChoice[0]) == 'y')
        {
           saveFile(a, rows); 
        }
        
        cout << "Would you like to play against PERFECT AI again?" << endl;
        cin >> againP;
        
    }while(tolower(againP[0]) == 'y');
}

/**
 * This functions allows the perfect AI and user to take turns
 * for whoever was chosen to go first, while display the game board
 * and checking for winners
 * @param a: the array
 * @param rows: the number of rows
 * @param first: the player chosen to go first
 * @param player: the player who won
 * @return the player who won
 */
int pvsPAIChoice(int a[][COLUMN], int rows, int first, int player)
{
      if (first == 1)
    {
        int playerOne = 10;
        int playerTwo = 0;
        player = 0;
        
        cout << "Pick a spot to place your 'X'" << endl;
        int choice;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;
          return playerTwo;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        if(player == 2)
        {
            player = 2;
            return player;
        }
        
    }
    else if (first == 0)
    {
        int player = 0;
        int playerOne = 10;
        int playerTwo = 0;
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        int choice;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        cin >> choice;
        
        game (a, rows, choice, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        perfectAI(a, rows);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        if(player == 2)
        {
            player = 2;
            return player;
        }
        
    }
}

/**
 * This functions codes the moves for the perfect AI
 * depending the different winning strategies given 
 * @param a: the array
 * @param row: the number rows
 */
void perfectAI(int a[][COLUMN], int row)
{
   if(a[0][1] == a[0][0] && a[0][2] ==  3)
   {
      a[0][2] = 0; 
   }
   else if(a[0][0] == a[0][2] && a[0][1] == 2)
   {
      a[0][1] = 0;
   }
   else if(a[0][1] == a[0][2] && a[0][0] == 1)
   {
      a[0][0] = 0;
   } 
   else if(a[1][0] == a[1][1] && a[1][2] == 6)
   {
       a[1][2] = 0;
   }
   else if(a[1][0] == a[1][2] && a[1][1] == 5)
   {
       a[1][1] = 0;
   }
   else if(a[1][1] == a[1][2] && a[1][0] == 4)
   {
       a[1][0] = 0;
   }
   else if(a[2][0] == a[2][1] && a[2][2] == 9)
   {
       a[2][2] = 0;
   }
   else if(a[2][0] == a[2][2] && a[2][1] == 1)
   {
       a[2][1] = 0;
   }
   else if(a[2][1] == a[2][2] && a[2][0] == 7)
   {
       a[2][0] = 0;
   } 
   else if(a[0][0] == a[1][0] && a[2][0] == 7)
   {
       a[2][0] = 0;
   }
   else if(a[0][0] == a[2][0] && a[1][0] == 4)
   {
       a[1][0] = 0;
   }
   else if (a[1][0] == a[2][0] && a[0][0] == 1)
   {
       a[0][0] = 0;
   }
   else if(a[0][1] == a[1][1] && a[2][1] == 8)
   {
       a[2][1] = 0;
   }
   else if(a[0][1] == a[2][1] && a[1][1] == 5)
   {
       a[1][1] = 0;
   }
   else if (a[1][1] == a[2][1] && a[0][1] == 2)
   {
       a[0][1] = 0;
   }
   else if(a[0][2] == a[1][2] && a[2][2] == 9)
   {
       a[2][2] = 0;
   }
   else if(a[0][2] == a[2][2] && a[1][2] == 6)
   {
       a[1][2] = 0;
   }
   else if (a[1][2] == a[2][2] && a[0][2] == 3)
   {
       a[0][2] = 0; 
   }
   else if((a[0][0] == a[2][2] || a[2][0] == a[0][2]) && a[1][1] == 5)
   {
       a[1][1] = 0;
       
   }
   else if((a[0][0] == a[2][2] || a[2][0] == a[0][2]) && a[1][1] == 10)
   {
      if (a[0][1] == 2)
      {
          a[0][1] = 0;
      } 
      else if (a[1][0] == 4)
      {
          a[1][0] = 0;
      }
      else if (a[1][2] == 6)
      {
          a[1][2] = 0;
      }
      else if (a[2][1] == 8)
      {
          a[2][1] = 0;
      }
   }        
   else if(a[0][0] == 10 && a[2][2] == 9)
   {
       a[2][2] = 0;
   }
   else if(a[0][2] == 10 && a[2][0] == 7)
   {
       a[2][0] = 0;
   }
   else if(a[2][0] == 10 && a[0][2] == 3)
   {
       a[0][2] = 0;
   }    
   else if(a[2][2] == 10  && a[0][0] == 1) 
   {
       a[0][0] = 0;
   }
   else if(a[0][0] == 0 && a[2][2] == 9)
   {
       a[2][2] = 0;
   }
   else if(a[0][2] == 0 && a[2][0] == 7)
   {
       a[2][0] = 0;
   }
   else if(a[2][0] == 0 && a[0][2] == 3)
   {
       a[0][2] = 0;
   }
   else if(a[2][2] == 0 && a[0][0] == 1)
   {
       a[0][0] = 0;
   }
   else if(a[0][0] == 1)
   {
       a[0][0] = 0; 
   }
   else if(a[0][2] == 3)
   {
       a[0][2] = 0;
   }
   else if(a[2][0] == 7)
   {
       a[2][0] = 0;
   }
   else if(a[2][2] == 9)
   {
       a[2][2] = 0;
   }
   else if(a[1][1] == 5)
   {
       a[1][1] = 0;
   }
   else if(a[0][1] == 2)
   {
       a[0][1] = 0;
   }
   else if(a[1][0] == 4)
   {
       a[1][0] = 0;
   }
   else if(a[1][2] == 6)
   {
       a[1][2] = 0;
   }
   else if(a[2][1] == 8)
   {
       a[2][1] = 0;
   }
   
}

/**
 * This allows two dumb AI to start a game. Each player is randomly chosen
 * and the game starts. Each Ai takes turn and the winner is determined and stats are displayed.
 * It then asks the user if they would like to save the game to a file of choice
 */
void dVSd()
{
    string ddAgain;
    
    do
    {
        cout << "Welcome To Tic-Tac-Toe Player 1 & Player 2!" << endl;
        cout << "Remember, Player 1 is 'X' and Player Two is 'O' !" << endl;
        cout << "You are Player 1 and Dumb AI Is Player 2" << endl;
        cout << "Now choosing which player goes first . . ." << endl;
        int first = rand() % (2 - 1 + 1)+1;

        int rows = 3;
        int player = 2;
        int a[rows][COLUMN];

        for(int i = 0;  i < rows; i++)
        {
            cout << endl << " -------------  " << endl;

            for(int j = 0; j < COLUMN; j++)
            {
                a[i][j] = i * rows + j + 1;
                cout << " | " << a[i][j] ;      
            }  

            cout << " |";
        } 
        cout << endl << " -------------  " << endl; 

        player = dumbChoice(a, rows, first, player);

        if (player == 2)
        {
            cout << "Its a Draw! " << endl;
        }
        else if (player == 1)
        {
            cout << "Dumb Ai Player One Won!" << endl;
        }
        else if (player == 0)
        {
            cout << "Dumb Ai Player Two Won!" << endl;
        }

        string saveChoice;
        cout << "Would you like to save this Game to a file? " << endl;
        cin >> saveChoice;

        if (tolower(saveChoice[0]) == 'y')
        {
           saveFile(a, rows); 
        }
    
        cout << "Would you like the DUMB AIs to go play again?" << endl;
        cin >> ddAgain;
        
    }while(tolower(ddAgain[0]) == 'y');
}

/**
 * This function codes the dumb to chose a random place
 * on the board that's not already chosen
 * @param a: the array
 * @param rows: the number of rows 
 * @param first: the player chosen to go first
 * @param player: the person who won
 * @return return the player who won
 */
int dumbChoice(int a[][COLUMN], int rows, int first, int player)
{
  if(first == 1)
    {
        int playerOne = 10;
        int playerTwo = 0;
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
    }
    else if (first == 2)
    {
        int playerOne = 10;
        int playerTwo = 0;
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        dumbAI(a, rows, playerOne);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'X'" << endl;
        
        if (winChecker(a, rows))
        {
          player = 1;  
          return player;  
        }
        
        cout << "Pick a spot to place your 'O'" << endl;
        
        dumbAI(a, rows, playerTwo);
        output(a, rows);
        if (winChecker(a, rows))
        {
          player = 0;  
          return player;  
        }
        
        if (player == 2)
        {  
          return player;  
        }
        
    }  
}


/**
 * This allows the stats in the file to be outputted into the stream
 * @param playerOne: the amount of games won by the user
 * @param numGame: the total number of game played against another player
 * @param totWin: the percent rate which player won against another player
 * @param playerOn: the number games played against Dumb AI
 * @param playerWon: the number of games won against Dumb AI
 * @param totWinDAI: the percent rate of wins against Dumb AI
 * @param playerGame: the number of games played against Smart AI
 * @param playWin: the amount of times the player won against Smart AI
 * @param perctWon: the win percentage rate against Smart AI
 * @param out
 */
void outputToStream(int &playerOne, int &numGame, double &totWin, int &playerOn, int &playerWon, double &totWinDAI, int &playerGame, int &playWin, double &perctWon, ostream& out)
{
   cout << "Total Games Played: " << numGame << endl;
   cout << "Total Games Won: " << playerOne << endl;
   cout << "Total Win Rate %: " << totWin << "%" << endl << endl;
   
   cout << "Total Games Played vs. Dumb AI: " << playerOn << endl;
   cout << "Total Games Won vs. Dumb AI: " << playerWon << endl;
   cout << "Win Rate % vs. Dumb AI: " << totWinDAI << endl << endl;
   
   cout << "Total Games Played vs. Smart AI: " << playerGame << endl;
   cout << "Total Games Won vs. Smart AI: " << playWin << endl;
   cout << "Win Rate % vs. Smart AI: " << perctWon << endl;
   
}

/**
 * This allows the stats to be placed into the file 
 * @param playerOne: the amount of games won by the user
 * @param numGame: the total number of game played against another player
 * @param totWin: the percent rate which player won against another player
 * @param playerOn: the number games played against Dumb AI
 * @param playerWon: the number of games won against Dumb AI
 * @param totWinDAI: the percent rate of wins against Dumb AI
 * @param playerGame: the number of games played against Smart AI
 * @param playWin: the amount of times the player won against Smart AI
 * @param perctWon: the win percentage rate against Smart AI
 * @param fileName the name of file provided
 */
void outputToFile(int &playerOne, int &numGame, double &totWin, int &playerOn, int &playerWon, double &totWinDAI, int &playerGame, int &playWin, double &perctWon, string fileName)
{
    ofstream fout;
    fout.open(fileName);
    outputToStream(playerOne, numGame, totWin, playerOn, playerWon, totWinDAI, playerGame, playWin, perctWon, fout);
    fout.close();
    
}

/**
 * This allows the game that was saved file to be viewed and outputted
 * @param a: the array
 * @param rows: the number of rows
 * @param out
 */
void outputToS(int a[][COLUMN], int rows, ostream& out)
{
    cout << "TIC-TAC-TOE" << endl;
    
    output(a, rows);
    
}


/**
 * This allows the game saved to be outputted to the file
 * @param a: the array
 * @param rows: the number of rows
 * @param fileName: the file name
 */
void outputToF(int a[][COLUMN], int rows, string fileName)
{
    ofstream fout;
    fout.open(fileName);
    outputToS(a, rows, fout);
    fout.close();
}

/**
 * This allows the user chose a file or enter a file name
 * to save their game into
 * @param a: the array
 * @param rows: the number of rows
 */
void saveFile(int a[][COLUMN], int rows)
{
    string fileName;
    
    cout << "Please enter the file name you want to save this game in: " << endl;
    cin >> fileName;
    
    outputToF(a, rows, fileName);
}


//HANG MAN FUNCTIONS BELOW : 

/**
 * This functions shows the Hangman Stats from the file
 * @param pOWins: the number of times player one won
 * @param pTWins: the number of times player two won
 * @param out
 */
void hangManStats(int &pOWins, int &pTWins, ostream& out)
{
    cout << "Number of games won by Player One: " << pOWins << endl;
    cout << "Number of games won by Player Two: " << pTWins << endl;
}

/**
 * This functions allows the number of times each player won
 * to be stored in a file
 * @param pOWins: the number of times player one won
 * @param pTWins: the number of times player two won
 * @param fileName: the name of the file
 */
void fileHangMan(int &pOWins, int &pTWins, string fileName)
{
    ofstream fout;
    fout.open(fileName);
    hangManStats(pOWins, pTWins, fout);
    fout.close();
}

/**
 * This functions explains the rules of the game. It also allows
 * player one to put in a word for player two to guess and contains
 * the function that starts the game. Once that function is finished,
 * it calculates the winner based on the number of tries
 * and stores it into a file
 * @param pOWins: the number of times player one won
 * @param pTWins: the number of times player two won
 */
void hangMan(int &pOWins, int &pTWins)
{
    string playAgain;
    
    do
    {    
        int numTry = 0;

        cout << "Hello! Welcome to Hangman!" << endl;
        cout << "Two players are needed for this game!" << endl;
        cout << "Rules: " << endl;
        cout << "Player One types in ONE word, and Player Two tries to guess it" << endl;
        cout << "If you get a letter or word guess wrong, we will build a man" << endl;
        cout << "That has one head, one body, two arms, and two legs" << endl;
        cout << "If your run out of parts you'll lose! " << endl;

        string playerWord;
        cout << endl << "Player One, Please enter a word" << endl;
        cin >> playerWord;
        
        
        cout << endl << endl << endl << endl;
        
        int wordSize = 0;

        for(int i = 0; i < playerWord.size(); i++)
        {
            wordSize++;
        }

        int size = wordSize;
        string a[size];

        for(int i = 0; i < playerWord.size(); i++)
        {
           a[i] = playerWord[i];
        }

        numTry = answer(a, size, numTry);

        
        if (numTry == 6)
        {
            cout << "You lose, Player One Wins" << endl;
            pOWins++;
            cout << "Number of games won by Player One: " << pOWins << endl;
            cout << "Number of games won by Player Two: " << pTWins << endl;
        }
        else if (numTry < 6)
        {
            cout << "PlayerOne loses, You won!" << endl;
            pTWins++;
            cout << "Number of games won by Player One: " << pOWins << endl;
            cout << "Number of games won by Player Two: " <<  pTWins << endl;
        }
        
        cout << endl << "Would you like to play again? " << endl;
        cin >> playAgain;
      
    }while (tolower(playAgain[0]) == 'y'); 
    
}

/**
 * This functions has multiple purposes, it allows player one to give a hint,
 * creates the vectors to store right and wrong guesses, fills up the arrays,
 * displays all the arrays and vectors, calculates the number tries and the letters guessed,
 * and allows player two to guess until they win or lose.
 * @param a: the array
 * @param size: the size of the array
 * @param numTry: the number of tries player two uses
 * @return returns the number of tries
 */
int answer(string a[], int size, int numTry)
{
    cout << "Please give player two a hint: " << endl;
    string hint;
    cin >> hint;
    
    int row = 3;
    string p[row][COLUMN];
    
    fillDIMArray(p, row);
    
    vector<string> wrong;
    vector<string> right;
    
    string d[size];

    fillArray(d, size);
    
    do
    {
        cout << "Player 2, Please guess a letter" << endl;
        string guess;
        cin >> guess;
        
        int tries = 0;
        
        for(int i = 0; i < size ; i++)
        {
            if(guess == a[i])
            {
                d[i] = a[i];
                right.push_back(guess);
                tries++;
                
                if(right.size() == size)
                {
                    return numTry;
                }
            }
            else if(guess != a[i] && i == (size - 1) && tries == 0)
            {
                wrong.push_back(guess);
                numTry++;
                
                if(numTry == 6)
                {
                    return numTry;
                }
            }
        }
        
        cout << "Hint: " << hint << endl;
        
        cout << "HangMan Display: " << endl;
        outputPicture(p, row, numTry);
        
        cout << "Display: ";
        outputFlatArray(d, size);
        
        cout << "Right Guesses: ";
        outputV(right);

        cout << "Wrong Guesses: ";
        outputV(wrong);

            
    }while(numTry < 7);
    
}

/**
 * This fills up a multi-dim array with x's
 * @param a: the array
 * @param row: the number of rows
 */
void fillDIMArray(string a[][COLUMN], int row)
{
     for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
           a[i][j] = "x"; 
        }
    }
    
}

/**
 * This allows the output of elements inside the vector
 * @param v: the vector
 */
void outputV(const vector<string>& v) 
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }    
    cout << endl;   
}

/**
 * This allows the output of a Multi-Dim array
 * @param a: the array
 * @param row: the number of rows
 */
void outputDIMArray(string a[][COLUMN], int row)
{
     for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
           cout << a[i][j]; 
        }
        cout << endl;
    }
}

/**
 * This allows the output of a static array
 * @param a: the array
 * @param size: the size of the array
 */
void outputFlatArray(string a[], int size)
{
     for(int i = 0; i < size; i++)
    {
         cout << a[i] << " ";
    }
     cout << endl;
}

/**
 * This function fills in an array with X's
 * @param a: the array
 * @param size: the size of the array
 */
void fillArray(string a[], int size)
{
     for(int i = 0; i < size; i++)
    {
         a[i] = " X ";
    }
}

/**
 * This function allows the hangman picture to appear every time
 * the user gets a guess wrong
 * @param p: The dynamic array
 * @param row: the number rows
 * @param numTry: the um of tries the user got wrong
 */
void outputPicture(string p[][COLUMN], int row, int numTry)
{
    
    if (numTry == 6)
    {
        p[2][2] = "/";
        outputDIMArray(p,row);
    }
    else if (numTry == 5)
    {
        p[2][0] = "/";
        outputDIMArray(p,row);
    }
    else if (numTry == 4)
    {
        p[1][2] = "-";
        outputDIMArray(p,row);
    }
    else if (numTry == 3)
    {
        p[1][0] = "-";
        outputDIMArray(p,row);
    }
    else if (numTry == 2)
    {
        p[1][1] = "|";
        outputDIMArray(p,row);
    }
    else if (numTry == 1)
    {
        p[0][1] = "O";
        outputDIMArray(p,row);
    }
    else
    {
       outputDIMArray(p,row); 
    }
   
}

/**
 * This function allows two players to guess for hangman
 * instead of one. It explains the rule 
 * as a random word, along with, a hint it chosen by a randomizer.
 * The players can play as long as they want as it keeps tracks of the score
 * @param pOWins: the number of times player one won
 * @param pTWins: the amount of time player two won
 */
void randomHangMan(int &pOWins, int &pTWins)
{
    string hAgain;
    
    do
    {
        int tries;
        int player;
        
        cout << "Hello, in this version of hangman, Two players try to guess the word" << endl;
        cout << "I random will be generated and each player will take turns entering a letter " << endl;
        cout << "Whoever gets the last correct letter wins" << endl;
        cout << "GAME IS BEGINING . . . " << endl;
        
        string word;
        string hint;
        
        randomWord(word, hint);
   
        int size = word.size();
        string a[size];

        for(int i = 0; i < word.size(); i++)
        {
           a[i] = word[i];
        }
        
        tries = hangGame(a, size, tries, hint, player);

        if (tries < 6 && player % 2)
        {
            cout << "You lose, Player Two Wins" << endl;
            pTWins++;
            cout << "Number of games won by Player One: " << pOWins << endl;
            cout << "Number of games won by Player Two: " << pTWins << endl;
        }
        else if (tries < 6)
        {
            cout << "You lose, Player One Wins" << endl;
            pOWins++;
            cout << "Number of games won by Player One: " << pOWins << endl;
            cout << "Number of games won by Player Two: " << pTWins << endl;
        }
        else if (tries == 6)
        {
            cout << "Both players lose!" << endl;
            cout << "Number of games won by Player One: " << pOWins << endl;
            cout << "Number of games won by Player Two: " <<  pTWins << endl;
        }
        
       
        cout << "Would you like to play again?" << endl;
        cin >> hAgain;
         
    }while(tolower(hAgain[0]) == 'y');
   
    
}


/**
 * This function allows the gamw to be displayed while allowing each
 * player to take a turn. It also helps determine which player wins or looses
 * @param a:the array
 * @param size: the size of the array
 * @param tries: the number of times they got the guess wrong
 * @param hint: the hint for the word
 * @param player: the player who wins
 * @return the number of tries
 */
int hangGame(string a[], int size, int tries, string &hint, int &player)
{
    
    int row = 3;
    string p[row][COLUMN];
    
    fillDIMArray(p, row);
    
    vector<string> wrong;
    vector<string> right;
    
    string d[size];

    fillArray(d, size);
    
    player = 1;
    
    do
    {
        string guess;
        
        if(player % 2)
        {
            cout << "Player 2, Please guess a letter" << endl;
            cin >> guess;
        }
        else
        {
          cout << "Player 1, Please guess a letter" << endl;
          cin >> guess;  
        }

        int tri = 0;

        for(int i = 0; i < size ; i++)
        {
            if(guess == a[i])
            {
                d[i] = a[i];
                right.push_back(guess);
                tri++;

                if(right.size() == size)
                {
                    return tries;
                }
            }
            else if(guess != a[i] && i == (size - 1) && tri == 0)
            {
                wrong.push_back(guess);
                tries++;

                if(tries == 6)
                {
                    return tries;
                }
            }
        }

        player++;
        
        cout << "Hint: " << hint << endl;

        cout << "HangMan Display: " << endl;
        outputPicture(p, row, tries);

        cout << "Display: ";
        outputFlatArray(d, size);

        cout << "Right Guesses: ";
        outputV(right);

        cout << "Wrong Guesses: ";
        outputV(wrong);
     
    }while(tries < 7);
    
}

/**
 * This allows a random word to be picked along
 * with a hint for the players to guess
 * @param word: the word the player needs to guess
 * @param hint: a hint for the word
 */
void randomWord(string &word, string &hint)
{
    int randW = rand() % (10 - 1) +1;
    
    if(randW == 1)
    {
        word = "hawks";
        hint = "Animal" ;                
    }
    
    else if(randW == 2)
    {
        word = "water";
        hint = "Liquid";       
    }
    else if(randW == 3)
    {
        word = "chocolate";
        hint = "Dessert";        
    }
    else if(randW == 4)
    {
        word = "ramen";
        hint = "Food";
    }
    else if(randW == 5)
    {
       word = "spiderman";
       hint = "SuperHero" ;       
    }
    else if(randW == 6)
    {
       word = "blanket";
       hint = "Soft";
    }
    else if(randW == 7)
    {
        word = "airplane";
        hint = "Transportation"; 
    }
    else if(randW == 8)
    {
       word = "mitochondria"; 
       hint = "Science";        
    }
    else if(randW == 9)
    {
      word = "melon";  
      hint = "Fruit";        
    }
    else if(randW == 10)
    {
       word = "computer";
       hint = "Technology";
    }
}




    