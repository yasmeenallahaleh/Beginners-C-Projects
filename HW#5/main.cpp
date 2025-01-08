/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on September 30, 2023, 6:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>


using namespace std;

/*
 * 
 */

//PROTOTYPES For My Functions
void userRockPaper();
void AIRockPaper();
double calcMpg(double milesTrav, double litersCons);
void iceCream();
void input (double &pounds, double &ounces);
void calculations(double pounds, double ounces, double &kilograms, double &grams);
void outputFunc(double pounds, double ounces, double kilograms, double grams);

//Constant Global Variable 
const double GAL = 0.264179;


//Main Function
int main(int argc, char** argv)
{

    srand(time(0));
    string again;
    
    do 
    {    
        //Allows user to choose option
        cout << "Please Choose An Option: " << endl;
        cout << " 1.) Problem 1" << endl;
        cout << " 2.) Problem 2" << endl;
        cout << " 3.) Problem 3" << endl;
        cout << " 4.) Problem 4" << endl;
        cout << " 5.) Problem 5" << endl;
        cout << " 6.) Problem 6" << endl;

        int choose;
        cin >> choose;
        
        //Menu-Operation System
        switch(choose)
        {
            case 1:
            {
                //Question 1
                cout << "Choose an Option: " << endl;
                cout << "1.) Two Players" << endl;
                cout << "2.) AI Players" << endl;
                
                int userOption;
                cin >> userOption;

                if(userOption == 1)
                {
                  userRockPaper();  
                }
                else if(userOption == 2)
                {
                  AIRockPaper();
                }
                else
                {
                  cout << "Invalid Input" << endl;
                }

               break;
            }
            case 2:
            {
              //Question 2:  
              double litersCons;
              double milesTrav;

              cout << "Please enter how many liters did your car consume? ";
              cin >> litersCons;

              cout << "Please enter how many miles did your car travel? ";
              cin >> milesTrav;

              cout << "Your car delivered: " << calcMpg(milesTrav, litersCons)
                      << " miles per gallon! " << endl;

              break;
            }
            case 3:
            {
              //Question 3:
              iceCream();

              break;
            }
            case 4:
            {
              //Question 4 (Tells where the location is)
              cout << "The comments of the functions are down below in the code "
                      "for Problems One and Two" << endl;

              break;
            }
            case 5:
            {
              //Question 5:
              cout << "Please choose an Option:" << endl;
              cout << "1.) Rock, Paper, Scissors" << endl;
              cout << "2.) Car Miles Per Gallon Calculator" << endl;

              int probFivMenu;
              cin >> probFivMenu;

              //Menu for Problem Five
              switch(probFivMenu)
              {
                 case 1:
                 {
                   //Two Player Option
                   cout << "Choose an Option: " << endl;
                   cout << "1.) Two Players" << endl;
                   cout << "2.) AI Players" << endl;
                     
                   int userOption;
                   cin >> userOption;

                   if(userOption == 1)
                   {
                     userRockPaper();  
                   }
                   else if(userOption == 2)
                   {
                     AIRockPaper();
                   }
                   else
                   {
                     cout << "Invalid Input" << endl;
                   } 
                     
                   break;
                  }
                  case 2:
                  {
                    //AI Option
                    double litersCons;
                    double milesTrav;

                    cout << "Please enter how many liters did your car consume? ";
                    cin >> litersCons;

                    cout << "Please enter how many miles did your car travel? ";
                    cin >> milesTrav;

                    cout << "Your car delivered: " << calcMpg(milesTrav, litersCons)
                           << " miles per gallon! " << endl; 
                    break;
                  }

                }

                break;
            }
            case 6:
            {
              //Question 6: 
              string calcWeightAgain;

              do
              {
                double pounds;
                double ounces;
                double kilograms;
                double grams;  
                  
                input (pounds, ounces);
                calculations (pounds, ounces, kilograms, grams);
                outputFunc (pounds, ounces, kilograms, grams);
                
                cout << "Would you like to repeat this calculation? " << endl;
                cin >> calcWeightAgain;

              }while(tolower(calcWeightAgain[0]) == 'y');

              break;
            }
        }
        
        //Ask user if they would like to go to main menu again
        cout << endl << "Would you like to go back to the main menu?" << endl;
        cin >> again;
        
    }while(tolower(again[0]) == 'y')  ;  
       
    
    return 0;
}


//FUNCTIONS Defined

//PROBLEM 1 (TWO PLAYER)

/**
 * This functions allows Two Players to play Rock, Paper, Scissors
 * with each other.
 * The function allows each user inputs an option 
 * and the function decides the winning option and outputs the results.
 */
void userRockPaper()
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

//PROBLEM 1 (AI PLAYERS)

/**
 * This function allows an Two AI players to play
 * Rock, Paper, Scissors with each other.
 * A number is assigned to each option and is randomized for
 * both AI players.
 * Then the function outputs which options the Ai chose and 
 * then winning option. 
 */
void AIRockPaper()
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

//PROBLEM 2:

/**
 * 
 * @param milesTrav: The user inputs the amount of miles traveled.
 * @param litersCons: The user inputs the liters used so it can 
 * covert it to the number of gallons.
 * @return mpg: It returns the number of miles per gallon.
 */
double calcMpg(double milesTrav, double litersCons)
{
    double litersToGal = litersCons * GAL;
    double mpg = litersToGal / milesTrav;
    return mpg;
}    

//PROBLEM 3:

/**
 * This function allows the user to;
 * 1.) input the amount of customers in a group
 * 2.) input the weight in ounces of the ice cream
 * 3.) calculate the portion of ice cream for each person
 * 4.) out the calculation for the customers
 */
void iceCream()
{
    double numCust;
    double weight;
    
    cout << "Hello! Welcome to the Ice Cream Shop!" << endl;
    cout << "Please enter the amount of customers: " << endl;
    cin >> numCust;
    cout << "Please enter the weight (oz) of the ice cream: " << endl;
    cin >> weight;
    
    int portion = weight/numCust;
    
    cout << "Each customer will receive " << portion << " ounces of ice cream!" << endl;
}

//Problem 6 

//Inputs the pounds & ounces
/**
 * 
 * @param pounds: the number of pounds is inserted by the user
 * @param ounces: the number of ounces inserted by the user
 */
void input (double &pounds, double &ounces)
{
    cout << "Enter the number of pounds: ";
    cin >> pounds;
    
    cout << "Enter the number of ounces: ";
    cin >> ounces;

}

/**
 * 
 * @param pounds: the pounds inserted by the user
 * @param ounces: the ounces inserted by the user
 * @param kilograms: the kilograms converted from weight
 * @param grams: the grams converted from the weight
 */
void calculations(double pounds, double ounces, double &kilograms, double &grams)
{
    
   double poundsPerKG = 2.2046;
   double ouncesPPound = 16;
   double gramPerKG = 1000;
           
   double totalPounds = pounds + ounces;
   double ozToLbs = totalPounds / ouncesPPound;
   
   kilograms = ozToLbs / poundsPerKG;
   grams = (kilograms - int(kilograms)) * 1000;
   kilograms = int(kilograms);
   
  
}

/**
 * 
 * @param pounds: the pounds inserted by the user
 * @param ounces: the ounces inserted by the user
 * @param kilograms: the kilograms converted from weight
 * @param grams: the grams converted from the weight
 */
void outputFunc(double pounds, double ounces, double kilograms, double grams)
{
    cout << "Your " << pounds << " pounds & " << ounces << " ounces convert to: " 
            << kilograms << " Kilograms and " << grams << " grams!" << endl;
    
}

