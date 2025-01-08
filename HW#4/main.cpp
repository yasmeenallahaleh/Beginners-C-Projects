/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on September 24, 2023, 2:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
 srand(time(0));
 string menuAgain;
    
    do   
    {    
        cout << "Please select one of the options: " << endl;
        cout << "1) Rock, Paper Scissors Game! " << endl; //Question #3
        cout << "2) Miles Per Gallon Car Calculator! " << endl; //Question #4
        cout << "3) Telephone Insert! " << endl; //Question #5
        cout << "4) Miles Per Gallon With File" << endl; //Question #7
        cout << "5) Two Cars Efficiency Decider! (With File)" << endl; //Question #9

        int userInput;
        cin>> userInput;

        switch (userInput)
        {
            case 1:
            {
              cout << "Hello, would you want to play Rock Paper "
                      "Scissors or allow AI to play for you?" << endl;
              cout << "Options: " << endl;
              cout << "1) Two Players" << endl;
              cout << "2) AI Players" << endl;
             
              int userOption;
              cin>> userOption;
              
              if (userOption == 1)
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
                else
                {
                  cout << "Invalid Input";
                }
              }
              else if (userOption == 2)
              {
                cout << "Hello AI Players, These are your choices " << endl
                          << "1) Rock" << endl 
                          << "2) Scissors" << endl
                          << "3) Paper " << endl << endl;

                int low = 1;
                int high = 3;

                cout<< "Hello Player One! Choose Rock, Paper, or Scissors!" << endl;
                int userOneInput = rand()%(high - low + 1) + low;
                cout << userOneInput << endl;

                cout << "Hello player Two! Choose Rock, Paper, or Scissors!" << endl;
                int userTwoInput = rand()%(high - low + 1) + low;
                cout << userTwoInput << endl;


                if (userOneInput == 1 && userTwoInput == 2)   
                {
                  cout << "Rock Breaks Scissors";
                }
                else if (userOneInput == 2 && userTwoInput == 1)      
                {
                  cout << "Rock Breaks Scissors";
                }
                else if (userOneInput == 1 && userTwoInput == 3)      
                {
                  cout << "Paper Covers Rock";
                } 
                else if (userOneInput == 3 && userTwoInput == 1)      
                {
                  cout << "Paper Covers Rock";
                } 
                else if (userOneInput == 2 && userTwoInput == 3)      
                {
                  cout << "Scissors Cut Paper";
                } 
                else if (userOneInput == 3 && userTwoInput == 2)      
                {
                  cout << "Scissors Cut Paper";
                } 
                else if (userOneInput == 1 && userTwoInput == 1)      
                {
                 cout << "Nobody Wins";
                }
                else if (userOneInput == 2 && userTwoInput == 2)      
                {
                  cout << "Nobody Wins";
                } 
                else if (userOneInput == 3 && userTwoInput == 3)      
                {
                  cout << "Nobody Wins";
                } 
                else
                {
                  cout << "Invalid Input";
                }   
              }
              else
              {
                  cout << "Invalid Option";
              }
                break;

            }
            case 2:
            { 
              string calcAgain; 
              
              do
              {  
                double gallons = 0.264179;
                double litersCons;
                double milesTrav;
              
                cout << "Please enter how many liters did your car consume? ";
                cin >> litersCons;
              
                cout << "Please enter how many miles did your car travel? ";
                cin >> milesTrav;
              
                double litersToGal = litersCons * gallons;
                double mpg = litersToGal / milesTrav;
              
                cout << "Your car delivered: " << mpg << " miles per gallon! " << endl;
                cout << "Would you like to repeat this calculation? " << endl;
                cin >> calcAgain;
              
              }while (tolower(calcAgain[0]) == 'y');  
              
              break; 
            }
            case 3:
            {
               cout << "Enter a telephone number with one dash in between the numbers: ";
               string phoneNum;
               cin >> phoneNum;
             
               for(int i = 0; i < phoneNum.size(); i++)
               {
                   char c = phoneNum[i];
                   if(c != '-')
                   {
                     cout << phoneNum[i];  
                   }
                   else;
               }
               break; 
            }
            case 4:
            {
               ifstream fin;
               fin.open("data.txt");
               
               double liters;
               double miles;
               
               fin >> liters;
               fin >> miles;
               
               fin.close();
               
              string calcAgain; 
              
              do
              { 
                double gallons = 0.264179;
                double litersToGal = liters * gallons;
                double mpg = litersToGal / miles;
              
                cout << "Your car delivered: " << mpg << " miles per gallon! " << endl;
                cout << "Would you like to repeat this calculation? " << endl;
                cin >> calcAgain;
              
              }while (tolower(calcAgain[0]) == 'y');  
                
              break;
            }
            case 5:
            {
               fstream fin;
               fin.open("data.txt");
               
               double liters;
               double miles;
               double litersTwo;
               double milesTwo;
               
               fin >> liters;
               fin >> miles;
               fin >> litersTwo;
               fin >> milesTwo;
               
               fin.close();
              
              double gallons = 0.264179;
              double litersToGal = liters * gallons;
              double mpg = litersToGal / miles;
              double galTwo = litersTwo * gallons;
              double mpgTwo = galTwo / milesTwo;
              
              cout << "Your car delivered: " << mpg << " miles per gallon! " << endl;
              cout << "Your second car delivered: " << mpgTwo << " miles per gallon! " << endl;
              
              if(mpg > mpgTwo)
              {
                  cout << "Your first car is more efficient!" << endl;
              }
              else if (mpg == mpgTwo)
              {
                  cout << "Both cars are equally efficient!" << endl;
              }        
              else
              {
                  cout << "Your second car is more efficient!" << endl;
              }
              
              break;
            }
<<<<<<< HEAD
            default cout << "Invalid Input" << endl; 
=======
           default:
                   cout << "Invalid Input" << endl;
>>>>>>> 6eb89b48586a38d0ebaa9465fbcd24d140d0ee36
    }
        
       cout << endl << "Would you like to go back to the menu? : ";
       cin >> menuAgain;   
        
    }while(tolower(menuAgain[0]) == 'y');
         
            
    return 0;
}

