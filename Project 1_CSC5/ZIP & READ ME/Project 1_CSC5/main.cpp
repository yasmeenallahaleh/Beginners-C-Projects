/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on September 30, 2023, 4:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */


//Prototype For Function:
void slotsChance(int &randNum);

//Global Variable
//Chips user starts out with
int chips = 100;

//Main 
int main(int argc, char** argv) 
{
  
    srand(time(0));
    string contAgain;
    
    do
    {
        // This outputs different options the user can choose
        cout << "You have " << chips << " chips!" << endl;
        cout << "Select a game you would like to play:" << endl;
        cout << "1.) Slots" << endl; //GAME 1
        cout << "2.) Black Jack" << endl;//GAME 2
        cout << "3.) 5 Card Poker" << endl; // EXTRA CREDIT GAME
        
        cout << "NOTE: If you end a game with 0 chips, the program will" << endl 
                << "finish since you have no more chips to bet!" << endl;

        int option;
        cin >> option;

        //Menu Operation
        switch(option)
        {
            case 1:
            {  //Slots game
               string slotsAgain; 

               do
               {
                  cout << "You are playing Slots!" << endl;
                  cout << "'5' is considered a Wild" << endl;
                  cout << "'6' considered a Cherry" << endl;
                  cout << "Try to get three in a row for the center row!" << endl;

                  int bet;
                  cout << "How much would you like to bet? " << endl;
                  cin >> bet;
                 
                  string name;
                  cout << "Please enter your name: ";
                  cin >> name;
                
                  //Generates random numbers for each slot
                  int randNum = rand() % 19 + 1;
                  int randNum1 = rand() % 19 + 1;
                  int randNum2 = rand() % 19 + 1;
                  int randNum3 = rand() % 19 + 1;
                  int randNum4 = rand() % 19 + 1;
                  int randNum5 = rand() % 19 + 1;
                  int randNum6 = rand() % 19 + 1;
                  int randNum7 = rand() % 19 + 1;
                  int randNum8 = rand() % 19 + 1;

                  int width = 4;
                
                  //Creates the chances for the numbers including CHerry & Wild
                  slotsChance(randNum);
                  slotsChance(randNum1);
                  slotsChance(randNum2);
                  slotsChance(randNum3);
                  slotsChance(randNum4);
                  slotsChance(randNum5);
                  slotsChance(randNum6);
                  slotsChance(randNum7);
                  slotsChance(randNum8);

                  cout << name << "'s slot game!" << endl;
                  cout << left;

                  //Sets up the Board
                  cout << "--------------" << endl;

                  cout << setw(width) << randNum
                       << setw(width) << randNum1 
                       << randNum2 << endl;

                  cout << setw(width) << randNum3
                       << setw(width) << randNum4 
                       << randNum5 << endl;

                  cout << setw(width) << randNum6
                       << setw(width) << randNum7 
                       << randNum8 << endl;

                  cout << "--------------" << endl;

                  //If statement determines how player wins or looses
                  //These conditions are for the cherries
                  if (randNum3 == 6 && randNum4 == 6 && randNum5 == 6)
                  {
                      cout << "YOU GOT THREE CHERRIES!" << endl;
                      cout << "You win!!" << endl;
                      chips = chips + (bet * 5);
                      cout << "You won " << bet * 5 << " chips " << endl; 
                  }
                  else if (randNum3 == 6 && randNum4 == 6 )
                  {
                      cout << "YOU GOT TWO CHERRIES!" << endl;
                      cout << "You win!!" << endl;
                      chips = chips + (bet * 4);
                      cout << "You won " << bet * 4 << " chips " << endl; 
                  }
                  else if (randNum3 == 6 && randNum5 == 6 )
                  {
                      cout << "YOU GOT TWO CHERRIES!" << endl;
                      cout << "You win!!" << endl;
                      chips = chips + (bet * 4);
                      cout << "You won " << bet * 4 << " chips " << endl; 
                  }
                  else if (randNum4 == 6 && randNum5 == 6 )
                  {
                      cout << "YOU GOT TWO CHERRIES!" << endl;
                      cout << "You win!!" << endl;
                      chips = chips + (bet * 4);
                      cout << "You won " << bet * 4 << " chips " << endl; 
                  }
                  else if(randNum3 == 6 || randNum4 == 6 || randNum5 == 6 )
                  {
                      cout << "YOU GOT A CHERRY!" << endl;
                      cout << "You win!!" << endl;
                      chips = chips + (bet * 3);
                      cout << "You won " << bet * 3 << " chips " << endl;
                  }
                  //These are for the wilds
                  else if (randNum3 == 5 && randNum4 == 5 && randNum5 == 5)
                  {
                      cout << "WOW! You got THREE Wilds !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 4);
                      cout << "You won " << bet * 4 << " chips " << endl;
                  }
                  else if (randNum4 == 5 && randNum3 == 5)
                  {
                      cout << "You got Two Wilds !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 3);
                      cout << "You won " << bet * 3 << " chips " << endl;
                  }
                  else if (randNum4 == 5 && randNum5 == 5)
                  {
                      cout << "You got Two Wilds !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 3);
                      cout << "You won " << bet * 3 << " chips " << endl;
                  }
                  else if (randNum3 == 5 && randNum5 == 5)
                  {
                      cout << "You got Two Wilds !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 3);
                      cout << "You won " << bet * 3 << " chips " << endl;
                  }
                  else if( randNum3 == randNum5 && randNum4 == 5)
                  {
                      cout << " You got One Wild !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 2);
                      cout << "You won " << bet * 2 << " chips " << endl;
                  }
                  else if(randNum3 == randNum4 && randNum5 == 5)
                  {
                      cout << " You got One Wild !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 2);
                      cout << "You won " << bet * 2 << " chips " << endl;
                  }
                  else if (randNum4 == randNum5 && randNum3 == 5)
                  {
                      cout << "You got One Wild !!" << endl;
                      cout << "You win" << endl;
                      chips = chips + (bet * 2);
                      cout << "You won " << bet * 2 << " chips " << endl;
                  }
                  //A regular win
                  else if( randNum3 == randNum4  && randNum4 == randNum5 )
                  {
                      cout << "You win!!!" << endl;
                      chips = chips + bet;
                      cout << "You won " << bet << " chips! " << endl;
                  }
                  else //Else if user has non of the conditions above
                  {
                      cout << "You lost lol"<< endl;
                      chips = chips - bet;
                      cout << "You lost " << bet << " chips " << endl;
                  }

                  cout << "You now have " << chips << " chips!" << endl;
                  cout << "Would you like to play slots again?" << endl;
                  cin >> slotsAgain;

              } while (tolower(slotsAgain[0]) == 'y' && chips > 0);

              break;
            }
            case 2:
            {
               //Black Jack game
                string bjAgain;
                
                do
                {
                    //Introduction
                    cout << "Welcome To BlackJack! You are now playing!" << endl;
                    cout << "You have " << chips << " chips. " << endl;
                    cout << "How much will you bet ?" << endl;
                    int bet;
                    cin >> bet;

                    //Randomizes the cards for the players
                    int playerCard = rand() % 11 +1;
                    int dealerCard = rand() % 11 +1;
                    int player = 0;
                    int dealer =0;

                    //Draws the first two cards for dealer
                     for(int i = 0 ; i < 2; i++)
                    {
                        dealerCard = rand() % 11 +1; 
                        dealer = dealer + dealerCard;
                        cout << "The dealer's card is: " << dealerCard << endl;

                        if ( dealerCard == 1 )
                        {
                            cout << "Dealer received a hard Ace" << endl;
                        }
                        else if (dealerCard == 11)
                        {
                            cout << "Dealer received a soft Ace" << endl;
                        }
                        else
                        {
                           cout << " Continuing..." << endl;
                        }
                    }
                    //Draw Players First Two cards
                    for(int i = 0 ; i < 2; i++)
                    {
                        playerCard = rand() % 11 +1;
                        player = player + playerCard;
                        cout << "Your card is: " << playerCard << endl;

                        //If player receives Ace
                        if ( playerCard == 1 )
                        {
                            cout << " You received a hard Ace" << endl;
                        }
                        else if (playerCard == 11)
                        {
                            cout << "You received a soft Ace" << endl;
                        }
                        else
                        {
                           cout << " Continuing..." << endl;
                        }

                    }
                     //Display the total of both cards
                    cout << "Your combination for your cards is: " << player << endl; 

                    // Used to see if user would pull another card
                    string hit;
                    cout << "Would the player want to hit another card? " << endl;
                    cin >> hit;

                    //While loop so user can hit as many times as wanted    
                    while(tolower(hit[0]) == 'y')
                    {
                       playerCard = rand() % 11 +1;
                       player = player + playerCard;
                       cout << player << endl;

                       //If player receives ace
                       if ( playerCard == 1 )
                       {
                           cout << "You received a hard Ace" << endl;
                       }
                       else if (playerCard == 11)
                       {
                           cout << "You received a soft Ace" << endl;
                       }
                       else
                       {
                          cout << "Continuing..." << endl;
                       }

                       cout << "Would the player want to hit another card" << endl;
                       cin >> hit;
                    }
                     // When user decides to not hit anymore
                    cout << "You've decided to stay!" << endl;

                    //Allows the dealer to pull after players stays

                    cout << "Dealer is now pulling ..." << endl;

                    //If the dealer has less than one, he has to pull
                    while (dealer < 21)
                    {
                        dealerCard = rand() % 11 +1;
                        dealer = dealer + dealerCard; 

                        if(dealerCard == 11 && dealer == 17)
                        {
                           cout << "The dealer hit on a hard 17" << endl;
                        }
                        else if (dealerCard == 1 && dealer == 17)
                        { //If dealer receives soft ace, he has to pull again 
                           cout << "Dealer must hit again" << endl;
                           dealerCard = rand() % 11 +1;
                           dealer = dealer + dealerCard;
                        }
                        else if (dealer < 17)
                        {
                           dealerCard = rand() % 11 +1; 
                           dealer = dealer + dealerCard;
                        }
                    }
                    cout << "Dealer final total is: " << dealer << endl;

                   // Decides who wins and looses
                    if (dealer > player && dealer <= 21) 
                    //If dealer as the higher number and is less than or equal to 21    
                    {
                        cout << "Dealers wins. YOU LOOSE !!" << endl;
                        chips = chips - bet;
                    }
                    //If dealer has higher than the player and is over 21
                    else if (dealer > player && dealer > 21)
                    {
                        cout << "Dealers looses! YOU WIN!!!" << endl;
                        chips = chips + bet;
                    }
                    else //Anything else the user wins
                    {
                        cout << "Dealer lost! YOU WIN!!!" << endl;
                        chips = chips + bet;
                    }
                    
                    cout << "You now have " << chips << " chips!" << endl;
                    cout << "Would you like to play BlackJack again?" << endl;
                    cin >> bjAgain;
                    
                }while (tolower(bjAgain[0]) == 'y' && chips > 0);
                
                break;
            }
            case 3:
            {
                // 5 Card Poker Game
                string pokerAgain;
                
                do
                {
                    cout << "Welcome To 5 Card Poker! You are now playing!" << endl;
                    cout << "You have " << chips << " chips. " << endl;
                    cout << "How much will you bet ?" << endl;
                    int bet;
                    cin >> bet;

                    //Explaining the bets
                    cout << "Now pulling your cards . . ." << endl;
                    cout << "IMPORTANT: Your bet will increase based on the winning hand" << endl;
                    cout << " Four of Kind: Bet will Increase 5 times!" << endl;
                    cout << " Full: Bet will Increase 4 times!" << endl;
                    cout << " Three of Kind: Bet will Increase 3 times!" << endl;
                    cout << " Two Pair : Bet will Increase 2 times!" << endl;
                    cout << " Pair: Bet will stay the same!" << endl;

                    //Randomizes the cards
                    int card1 = rand() % 11 +1;
                    int card2 = rand() % 11 +1;
                    int card3 = rand() % 11 +1;
                    int card4 = rand() % 11 +1;
                    int card5 = rand() % 11 +1;

                    //Outputs which cards you have
                    cout << " Your cards are:" << endl
                            << "Card One: " << card1 << endl << "Card Two: " << card2 
                            << endl << "Card Three: " << card3 << endl << "Card Four: " << card4 
                            << endl << "Card Five: " << card5 << endl; 

                    //Asking if user would like to switch any cards
                    cout << "Would you like to switch any cards?" << endl;
                    cout << "NOTE: You can switch only each card once" << endl;
                    string sCards;
                    cin >> sCards;

                    // If the user decides to switch any cards
                    while (tolower(sCards[0]) == 'y')
                    {
                        cout << "Which card would you like to switch out?" << endl;
                        int numCard;
                        cin >> numCard;

                        if(numCard == 1)
                        {
                           card1 = rand() % 11 +1;
                           cout << " Card One is now: " << card1 << endl;
                        }
                        else if(numCard == 2)
                        {
                           card2 = rand() % 11 +1;
                           cout << " Card Two is now: " << card2 << endl;
                        }
                        else if(numCard == 3)
                        {
                           card3 = rand() % 11 +1;
                           cout << " Card Three is now: " << card3 << endl;
                        }
                        else if(numCard == 4)
                        {
                           card4 = rand() % 11 +1;
                           cout << " Card Four is now: " << card4 << endl;
                        }
                        else if(numCard == 5)
                        {
                           card5 = rand() % 11 +1;
                           cout << " Card Five is now: " << card5 << endl;
                        }

                        cout << "Would you like to switch another card?" << endl;
                        cin >> sCards;

                    }

                    //This VERY LONG if-statement decides what the user wins depending
                    //on what cards they pull & switched

                    //FULL HOUSE Conditions
                    if((card1 == card2 && card2 == card3) && card4 == card5)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card1 == card2 && card2 == card4) && card3 == card5)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if((card1 == card2 && card2 == card5) && card3 == card4)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card1 == card3 && card3 == card4) && card2 == card5)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card1 == card3 && card3 == card5) && card4 == card2)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card1 == card4 && card4 == card5) && card2 == card3)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card2 == card3 && card3 == card4) && card1 == card5)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card2 == card3 && card3 == card5) && card1 == card4)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card2 == card3 && card3 == card4) && card1 == card5)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card2 == card5 && card5 == card4) && card1 == card5)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    else if ((card3 == card4 && card4 == card5) && card1 == card2)
                    {
                        cout << "You got a Full House!" << endl;
                        chips = chips + (bet * 4);
                    }
                    //FOUR OF KIND Conditions
                    else if (card1 == card2 == card3 == card4)
                    {
                        cout << "You got four of kind" << endl;
                        chips = chips + (bet * 5);
                    }
                    else if (card2 == card3 == card4 == card5)
                    {
                        cout << "You got four of kind" << endl;
                        chips = chips + (bet * 5);
                    }
                    else if (card1 == card3 == card4 == card5)
                    {
                        cout << "You got four of kind" << endl;
                        chips = chips + (bet * 5);
                    }
                    else if (card1 == card2 == card4 == card5)
                    {
                        cout << "You got four of kind" << endl; 
                        chips = chips + (bet * 5);
                    }
                    else if (card1 == card2 == card3 == card5)
                    {
                        cout << "You got four of kind" << endl;
                        chips = chips + (bet * 5);
                    }
                    //THREE OF KIND Conditions
                    else if(card1 == card2 && card2 == card3)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card1 == card2 && card2 == card4)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if(card1 == card2 && card2 == card5)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card1 == card3 && card3 == card4)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card1 == card3 && card3 == card5)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card1 == card4 && card4 == card5)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card2 == card3 && card3 == card4)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card2 == card3 && card3 == card5)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card2 == card5 && card5 == card4)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card2 == card3 && card3 == card4)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);
                    }
                    else if (card3 == card4 && card4 == card5)
                    {
                        cout << "You got a three of kind" << endl;
                        chips = chips + (bet * 3);;
                    }
                    //TWO PAIRS Condition
                    else if(card1 == card2 && card3 == card4)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if(card1 == card2 && card3 == card5)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if(card1 == card2 && card4 == card5)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if (card2 == card3 && card1 == card4)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if (card2 == card3 && card1 == card5)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if (card2 == card3 && card4 == card5)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if (card3 == card4 && card1 == card2)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if (card3 == card4 && card1 == card5)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if (card3 == card4 && card2 == card5)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if(card4 == card5 && card1 == card2)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if(card4 == card5 && card1 == card3)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    else if(card4 == card5 && card3 == card2)
                    {
                        cout << "You got two pairs!" << endl;
                        chips = chips + (bet * 2);
                    }
                    // PAIR Conditions
                    else if(card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5)
                    {
                        cout << "You got a pair!" << endl;
                        chips = chips + bet;
                    }
                    else if(card2 == card3 || card2 == card4 || card2 == card5)
                    {
                        cout << "You got a pair!" << endl;
                        chips = chips + bet;
                    }
                    else if(card3 == card4 || card3 == card5)
                    {
                        cout << "You got a pair!" << endl;
                        chips = chips + bet;
                    }
                    else if (card4 == card5)
                    {
                        cout << "You got a pair!" << endl;
                        chips = chips + bet;
                    }
                    else //If no conditions were met, player loose, sadly
                    {
                        cout << "Lol loser !!" << endl;
                        chips = chips - bet;
                    }
                    
                    cout << "You now have " << chips << " chips!" << endl;
                    cout << "Would you like to play 5 Card Poker again?" << endl;
                    cin >> pokerAgain;

                } while (tolower(pokerAgain[0]) == 'y' && chips > 0);
                
                break;
            }
        }

        cout << "Would you like to go back to the game options?" << endl;
        cin >> contAgain;

    }while (tolower(contAgain[0]) == 'y' && chips > 0);
    
    //When user decides to stop playing
    cout << " You finished playing with: " << chips << " chips!" << endl;
    
    return 0;
    
}

//FUNCTION:

/**
 * This function helps creates chances for each slot
 * @param randNum: the random number generated by each slot
 */
void slotsChance(int &randNum)
{
    if(randNum == 1 || randNum == 2 || randNum == 3 ||randNum == 4)
    {
        randNum = 1;
    }
    else if(randNum == 5 || randNum == 6 || randNum == 7 ||randNum == 8)
    {
        randNum = 2;
    }
    else if(randNum == 9 || randNum == 10 || randNum == 11 ||randNum == 12)
    {
        randNum = 3;
    }
    else if(randNum == 13 || randNum == 14 || randNum == 15 ||randNum == 16)
    {
        randNum = 4;
    }
    else if(randNum == 17 || randNum == 18 )
    {
        randNum = 5;
    }
    else 
    {
        randNum = 6;
    }
}
