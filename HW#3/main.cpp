/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on September 16, 2023, 7:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//HomeWork 3
    
    string menuAgain;
    
    do   
    {    
        cout << "Please select one of the options: " << endl;
        cout << "1) Problem 1" << endl;
        cout << "2) Problem 2" << endl;
        cout << "3) Problem 3" << endl;
        cout << "4) Problem 4" << endl;
        cout << "5) Problem 5" << endl;
        cout << "6) Problem 6" << endl;
        cout << "7) Problem 7" << endl;

        int userInput;
        cin>> userInput;

        switch (userInput)
        {
            case 1:
            {
                //PROBELM 1
                cout << "Please enter ten numbers: " << endl;
                int allNum = 0; 
                int negative = 0;
                int positive = 0;


                for (int i = 1; i <= 10; i++)
                {
                   cout << "Number " << i << ":";
                   int num;
                   cin >> num;
                   cout << num << endl;
                   allNum = num + allNum;

                   if (num < 0)
                   { 
                    negative = num + negative;
                   }
                   else if (num > 0)
                   {
                    positive = num + positive;
                   }

                   if (i == 10) 
                   {
                      cout << "Your sum for positive numbers is: " << positive << endl;
                      cout << "Your sum for negative numbers is: " << negative << endl;
                      cout << "Your sum for all your numbers is: " << allNum << endl << endl;
                   }

                }
                    break;
            }
            case 2:
            {
                //Problem 2:

                    cout << "Please enter ten numbers: " << endl;
                double allNum = 0; 
                double negative = 0;
                double positive = 0;
                int counter = 0;
                int count = 0;

                for (int i = 1; i <= 10; i++)
                {
                   cout << "Number " << i << ":";
                   double num;
                   cin >> num;
                   cout << num << endl;
                   allNum = num + allNum;

                   if (num < 0)
                   {    
                    negative = num + negative;
                    counter ++;
                   }
                   else if (num > 0)
                   {
                    positive = num + positive;
                    count ++;
                   }

                   if (i == 10) 
                   {
                      cout << "The numbers you used are: " << endl;
                      cout << "Your sum for positive numbers is: " << positive << endl;
                      cout << "Your average for positive numbers is: " << positive/count << endl;
                      cout << "Your sum for negative numbers is: " << negative << endl;
                      cout << "Your average for negative numbers is: " << negative/counter << endl;
                      cout << "Your sum for all your numbers is: " << allNum << endl;
                      cout << "Your average for all your numbers is: " << allNum/10 << endl;
                   }

                }

               break; 
            }
            case 3:
            {
                // Problem 3:

                    cout << "Generating ten random numbers " << endl;
                double allNum = 0; 
                double negative = 0;
                double positive = 0;


                for (int i = 1; i <= 10; i++)
                {
                   int min = -100;
                   int max = 100;
                   int randNum = rand()%(max - min +1) + min;

                   cout << "Number " << i << ":" <<  randNum << endl;
                   allNum = randNum + allNum;

                   if (randNum < 0)
                   { 
                    negative = randNum + negative;
                   }
                   else if (randNum > 0)
                   {
                    positive = randNum + positive;
                   }

                   if (i == 10) 
                   {
                      cout << "Your sum for positive numbers is: " << positive << endl;
                      cout << "Your sum for negative numbers is: " << negative << endl;
                      cout << "Your sum for all your numbers is: " << allNum/10 << endl << endl;
                   }

                }

               break; 
            }
            case 4:
            {
                // Problem 4:

                string continueAgain;

                do 
                {
                       int bar = 230;

                        cout << "Please enter your weight in pounds: ";
                        int weight;
                        cin >> weight;

                        cout << "Please enter your height in inches: ";
                        int height;
                        cin >> height;

                        cout << "Please enter your age in years: ";
                        int age;
                        cin >> age;

                        cout << "Please enter gender Man(M) or Woman(W): ";
                        string gender;
                        cin >> gender;

                        if(tolower(gender[0]) == 'w' )
                        { 
                            int bmrW = (66 + (6.3 * weight) + (12.9 * height)
                            -(6.8 * age))/ bar;
                            cout << endl << "You can eat " << bmrW << " chocolate bars!" << endl;
                        }
                        else if (tolower(gender[0]) == 'm')  
                        {
                            int bmrM = (655 + (4.3 * weight) + (4.7 * height)
                                -(4.7 * age))/ bar;
                            cout << endl << "You can eat " << bmrM << " chocolate bars!" << endl;
                        }

                      cout << "Would you like to go again? ";
                      cin >> continueAgain;


                } while (tolower(continueAgain[0]) == 'y'); 

                break;
            }
            case 5:
            {
                 //Problem 5: 

                cout << "How many exercises do you want to input? ";
                double numExc;
                cin >> numExc;

                double i = 0;
                double finalScore = 0;
                double finalTotal = 0;


                while ( i < numExc)
                 {
                    i++;
                    cout << "Score received for exercise " << i << ": ";
                    double score;
                    cin >> score;
                    finalScore = score + finalScore;

                    cout << "Total points possible for exercise " << i << ": ";
                    double total;
                    cin >> total;
                    finalTotal= total + finalTotal;

                    double percentage = (finalScore/finalTotal)*100;

                    if ( i == numExc)
                        {
                            cout << endl << "Your total is " << finalScore << " out of " 
                                << finalTotal << ", or " << setprecision(4) << percentage << "%." << endl;
                        }
                }

                break;
            }
            case 6:
            {
                //Problem 6

                  cout << endl << "Hello Player One! Choose Rock, Paper, or Scissors!" << endl;
                string userOneInput;
                cin >> userOneInput;

                cout << "Hello player Two! Choose Rock, Paper, or Scissors!" << endl;
                string userTwoInput;
                cin >> userTwoInput;


                   if (tolower(userOneInput[0]) == 'r' && tolower(userTwoInput[0]) == 's')   
                    {
                        cout << "Rock Breaks Scissors";
                    }
                else if (tolower(userOneInput[0]) == 's' && tolower(userTwoInput[0]) == 'r')      
                    {
                        cout << "Rock Breaks Scissors";
                    }
                else if (tolower(userOneInput[0]) == 'p' && tolower(userTwoInput[0]) == 'r')      
                    {
                        cout << "Paper Covers Rock";
                    } 
                else if (tolower(userOneInput[0]) == 'r' && tolower(userTwoInput[0]) == 'p')      
                    {
                        cout << "Paper Covers Rock";
                    } 
                else if (tolower(userOneInput[0]) == 's' && tolower(userTwoInput[0]) == 'p')      
                    {
                        cout << "Scissors Cut Paper";
                    } 
                else if (tolower(userOneInput[0]) == 'p' && tolower(userTwoInput[0]) == 's')      
                    {
                        cout << "Scissors Cut Paper";
                    } 
                else if (tolower(userOneInput[0]) == 's' && tolower(userTwoInput[0]) == 's')      
                    {
                       cout << "Nobody Wins";
                    }
                else if (tolower(userOneInput[0]) == 'p' && tolower(userTwoInput[0]) == 'p')      
                    {
                        cout << "Nobody Wins";
                    } 
                else if (tolower(userOneInput[0]) == 'r' && tolower(userTwoInput[0]) == 'r')      
                    {
                        cout << "Nobody Wins";
                    }  
                break;
            }
            case 7:
            {
                //Problem 7
                string playAgain;

                do 
                    {
                        cout << endl << "Hello Player One! Choose Rock, Paper, or Scissors!" << endl;
                        string userOneInput;
                        cin >> userOneInput;

                        cout << "Hello player Two! Choose Rock, Paper, or Scissors!" << endl;
                        string userTwoInput;
                        cin >> userTwoInput;


                           if (tolower(userOneInput[0]) == 'r' && tolower(userTwoInput[0]) == 's')   
                            {
                                cout << "Rock Breaks Scissors";
                            }
                        else if (tolower(userOneInput[0]) == 's' && tolower(userTwoInput[0]) == 'r')      
                            {
                                cout << "Rock Breaks Scissors";
                            }
                        else if (tolower(userOneInput[0]) == 'p' && tolower(userTwoInput[0]) == 'r')      
                            {
                                cout << "Paper Covers Rock";
                            } 
                        else if (tolower(userOneInput[0]) == 'r' && tolower(userTwoInput[0]) == 'p')      
                            {
                                cout << "Paper Covers Rock";
                            } 
                        else if (tolower(userOneInput[0]) == 's' && tolower(userTwoInput[0]) == 'p')      
                            {
                                cout << "Scissors Cut Paper";
                            } 
                        else if (tolower(userOneInput[0]) == 'p' && tolower(userTwoInput[0]) == 's')      
                            {
                                cout << "Scissors Cut Paper";
                            } 
                        else if (tolower(userOneInput[0]) == 's' && tolower(userTwoInput[0]) == 's')      
                            {
                               cout << "Nobody Wins";
                            }
                        else if (tolower(userOneInput[0]) == 'p' && tolower(userTwoInput[0]) == 'p')      
                            {
                                cout << "Nobody Wins";
                            } 
                        else if (tolower(userOneInput[0]) == 'r' && tolower(userTwoInput[0]) == 'r')      
                            {
                                cout << "Nobody Wins";
                            }  

                           cout << endl << "Would you like to play again? " << endl;
                           cin >> playAgain;

                }while (tolower(playAgain[0]) == 'y');

                break;
            }
        }
        
       cout << endl << "Would you like to go back to the menu? : ";
       cin >> menuAgain;   
        
    }while(tolower(menuAgain[0]) == 'y');

    return 0;
}

