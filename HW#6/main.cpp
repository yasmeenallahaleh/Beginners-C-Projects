/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on October 9, 2023, 7:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes

int max(int num1, int num2);
double max(double num1, double num2);
void problemOne();
void swapIntegers(int &numOne, int &numTwo);
void problemTwo();
void swapStrings(string &stringOne, string &stringTwo);
void problemThree();
void swapChars(char &charOne, char &charTwo);
void problemFour();
void calculations(double feet, double inches, double &meters, double &centiM);
void output(double feet, double inches, double meters, double centiM);
void input(double &feet, double &inches);
void problemFive();
void insertCents(int &amount_left);
void compute_coins(int coin_value, int& num, int& amount_left);
void problemSix();
void problemSeven();

/*
 * 
 */
int main(int argc, char** argv) 
{
    string menuAgain;
    
    do
    {
    
        cout << "1.) Problem 1" << endl;
        cout << "2.) Problem 2" << endl;
        cout << "3.) Problem 3" << endl;
        cout << "4.) Problem 4" << endl;
        cout << "5.) Problem 5" << endl;
        cout << "6.) Problem 6" << endl;
        cout << "7.) Problem 7" << endl;

        int option;
        cin >> option;

        switch (option)
        {
            case 1:
            {
                problemOne();
                break;  
            }
            case 2:
            {
                problemTwo();
                break;
            }
            case 3:
            {
                problemThree();;
                break;
            }
            case 4:
            {
                problemFour();
                break;
            }
            case 5:
            {
                problemFive();
                break;
            }
            case 6:
            {
                problemSix();
                break;
            }
            case 7:
            {
                problemSeven();
                break;
            }
        }
    }while(tolower(menuAgain[0]) == 'y');  
    
    return 0;
}

//PROBLEM ONE FUNCTIONS
/**
 * 
 * @param num1: the user inserts one number (an integer)
 * @param num2: the user inserts second number (an integer)
 */
int max(int num1, int num2)
{
  if (num1 > num2)
   {
      return num1;
   }
   else 
   {
      return num2;
   }
}

/**
 * 
 * @param num1: the user inserts one number (a double)
 * @param num2 the user inserts second number (a double)
 */
double max(double num1, double num2)
{
   if (num1 > num2)
   {
      return num1;
   }
   else 
   {
      return num2;
   }
   
}
/**
 * The function allows the user enter two numbers no matter 
 * if an integer or double and says which one is the biggest
 */
void problemOne()
{
    cout << "Please enter two numbers: " << endl;
    
    cout << "First Number: ";
    double num1;
    cin >> num1;
    
    cout << "Second Number: ";
    double num2;
    cin >> num2;
    
    
    cout << "The biggest number is: " << max(num1, num2);
    
}
  
//PROBLEM TWO FUNCTIONS
/**
 * This functions allows the swapping of two inputted integers
 * @param numOne: the user enters the first integer
 * @param numTwo: the user enters the second integer
 */
void swapIntegers(int &numOne, int &numTwo)
{ 
   int temp = numOne;
   numOne = numTwo;
   numTwo = temp;
}

/**
 * This functions contains the swapIntegers function and asks
 * the user to enter two integers and swaps them. 
 */
void problemTwo()
{
    cout << "Please enter two integers: "<< endl;
    cout << "Integer One: ";
    int num1;
    cin >> num1;
    
    cout << "Integer Two: ";
    int num2;
    cin >> num2;
    
    cout << "Int One: " << num1 << "  Int Two: " << num2 << endl;
    
    swapIntegers(num1, num2);
    
    cout << "Int One: " << num1 << "  Int Two: " << num2 << endl; 
}

//PROBLEM THREE FUNCTIONS
/**
 * This functions swaps two string variables
 * @param stringOne: the first string the user inputs
 * @param stringTwo: the second string the user inputs
 */
void swapStrings(string &stringOne, string &stringTwo)
{
   string temp = stringOne;
   stringOne = stringTwo;
   stringTwo = temp;
}

/**
 * This function asks the user to enter two strings 
 * and outputs them swapped
 */
void problemThree()
{
    cout << "Please enter two strings: "<< endl;
    cout << "String One: ";
    string stringOne;
    cin >> stringOne;
    
    cout << "String Two: ";
    string stringTwo;
    cin >> stringTwo;
    
    cout << "String One: " << stringOne << "  String Two: " << stringTwo << endl;
    
    swapStrings(stringOne, stringTwo);
    
    cout << "String One: " << stringOne << "  String Two: " << stringTwo << endl; 
}

//PROBLEM FOUR FUNCTIONS
/**
 * 
 * @param charOne: This is the first character of the string inputted by the user
 * @param charTwo: This is the second character of the string inputted by the user
 */
void swapChars(char &charOne, char &charTwo)
{ 
   char temp = charOne;
   charOne = charTwo;
   charTwo = temp;
}

/**
 * This function asks the user for the first string and includes the
 * swapChars function.
 * It swaps the first two letters then asks the user for two more 
 * strings and outputs the two string with the first letters of
 * each of them swapped.
 * 
 */
void problemFour()
{
    cout << "Hello, please enter a string: " << endl;
    string stringOne; 
    cin >> stringOne;
    
    cout << "A: " << stringOne << endl;
    
    char oneChar = stringOne[0];
    char twoChar = stringOne[1];
    
    swapChars(oneChar, twoChar);
    
    cout << "B: " << oneChar << twoChar;
    
    for(int i = 2; i < stringOne.length(); i++)
    {
        cout << stringOne[i];
    }
    
    cout << endl << "Now, enter two  strings!" << endl;
    
    cout << "First String: " << endl;
    string stringTwo;
    cin >> stringTwo;
   
    
    cout << "Second String: " << endl;
    string stringThree;
    cin >> stringThree;
    
    cout << "A: " << stringTwo << " " << stringThree << endl;
   
    char thirChar = stringTwo[0];
    char fourChar = stringThree[0];
    
    swapChars(thirChar, fourChar);
    
    cout << "B: " << thirChar; 
    
    for(int i = 1; i < stringTwo.length(); i++)
    {
        cout << stringTwo[i];
    }
    
    cout << " " << fourChar;
    
    for(int i = 1; i < stringThree.length(); i++)
    {
        cout << stringThree[i];
    }

}


//PROBLEM FIVE FUNCTIONS
/**
 * 
 * @param feet: the number of feet the user inputted
 * @param inches: the number of inches the user inputted
 */
void input(double &feet, double &inches)
{
    cout << "Enter the amount of feet: " << endl;
    cin >> feet;
    
    cout << "Enter the amount of inches: " << endl;
    cin >> inches;
}

/**
 * 
 * @param feet: the number of feet the user inputted 
 * @param inches: the number of inches the user inputted
 * @param meters: the number of feet & inches converted to meters
 * @param centiM: the remaining decimal of the meters variable converted to centimeters
 */
void calculations(double feet, double inches, double &meters, double &centiM)
{
  double metToFoot = 0.3048;
  double centToMet = 100;
  double incToFoot = 12;
  
  double totalInch = feet * incToFoot;
  double inchToFeet = (totalInch + inches) / incToFoot;
  
  meters = inchToFeet * metToFoot;
  centiM = (meters - int(meters)) * centToMet;
  meters = int(meters);
  
    
}

/**
 * 
 * @param feet: the number of feet the user inputted 
 * @param inches: the number of inches the user inputted
 * @param meters: the number of feet & inches converted to meters
 * @param centiM: the remaining decimal of the meters variable converted to centimeters
 */
void output(double feet, double inches, double meters, double centiM)
{
    cout << "Your " << feet << " feet & " << inches << " inches convert to: " 
           << meters << " Meters and " << centiM << " centimeters!" << endl;
}

/**
 * This function allows the output of converted feet and inches to
 * meters and centimeters and allows the user to repeat this calculation.
 */
void problemFive()
{
    string calcAgain;
    
    do 
    {
       double feet;
       double inches;
       double meters;
       double centiM;  

       input (feet, inches);
       calculations (feet, inches, meters, centiM);
       output (feet, inches, meters, centiM);

       cout << "Would you like to repeat this calculation? " << endl;
       cin >> calcAgain;
       
    }while(tolower(calcAgain[0]) == 'y');
    
}

//PROBLEM 6 FUNCTIONS
/**
 * 
 * @param amount_left: the amount of cents left over from what the user inserted 
 */
void insertCents(int &amount_left)
{
    int quarter = 25;
    int dime = 10;
    int penny = 1;
    int num;
    
    cout << "Please insert the amount of cents: " << endl;
    cin >> amount_left;
    
    if ( 0 < amount_left < 100 )
    {
        cout << amount_left << " cents can be given as: " << endl;
        
        compute_coins(quarter, num, amount_left);
        cout << num << " quarter(s)  ";
        
        compute_coins(dime, num, amount_left);
        cout << num << " dime(s)  ";
        
        compute_coins(penny, num, amount_left);
        cout << num << " penny(pennies)  " << endl;
        
        cout << "Thank You, Have a nice day!!" << endl;
    }
    else
    {
        cout << "Not a valid input" << endl;
    }
}

/**
 * 
 * @param coin_value: the value of the coin calculated
 * @param num: the amount of coins need for the value
 * @param amount_left: the amount left from the inserted amount
 */
void compute_coins(int coin_value, int& num, int& amount_left)
{
    num = amount_left / coin_value;
    amount_left = (amount_left) - (coin_value * num);
    
}

/**
 * This function stores the insertCents function
 * to allow the user to use it when choosing option 
 * number six in the menu 
 */
void problemSix()
{
    int amount_left;
    insertCents(amount_left);
}

//PROBLEM SEVEN FUNCTION
/**
 * This function stores the insertCents function
 * to allow the user to use it when choosing option 
 * number six in the menu and allows the user calculates the cents 
 * as many times as desired
 */
void problemSeven()
{
    string doAgain;
    
    do 
    {
      problemSix();  
      
      cout << "Would you like to repeat this calculation? " << endl;
      cin >> doAgain;
       
    }while(tolower(doAgain[0]) == 'y');
    
}

    


