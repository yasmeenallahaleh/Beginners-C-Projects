/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on November 15, 2023, 10:50 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//Prototypes:
void problemOne();
void problemTwo();
void problemThree();
void createDArray();
void storeRandom(int b[], int size);
void output(int b[], int size);
void problemFour();
void problemFive();
void problemSix();
void fillVector(vector<int> &v);
int binaryS(const vector<int> &v, int val);


/*
 * 
 */
int main(int argc, char** argv) 
{
    srand(time(0));
    
    string menuAgain;
    
    do
    {
        cout << "Please choose an option: " << endl;
        cout << "1) Problem 1" << endl;
        cout << "2) Problem 2" << endl;
        cout << "3) Problem 3" << endl;
        cout << "4) Problem 4" << endl;
        cout << "5) Problem 5" << endl;
        cout << "6) Problem 6" << endl;

        int choice;
        cin >> choice;


        switch(choice)
        {
            case 1:
            {
                problemOne();
                break;
            }  
            case  2:
            {
                problemTwo();
                break;
            }
            case 3:
            {
                problemThree();
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
            default :
                cout << "Not a valid option" << endl;
        }
        
        cout << endl << "Would you like to go to another menu option?" << endl;
        cin >> menuAgain;
        
    }while(tolower(menuAgain[0]) == 'y');
    
    return 0;
}

/**
 * This function allows values to change due
 * to the help of pointers and allocating memory.
 */
void problemOne()
{
    int value = 42;
    int value1 = value;
    
    int *address;
    int *address1;
    
    address = &value;
    address1 = &value1;

    
    cout << "v: " << value << endl;
    cout << "v1: " << value1 << endl << endl;
    
    value = 12;
    
    cout << "v: " << value << endl;
    cout << "v1: " << value1 << endl << endl;
    
    *address = 25;
    
    cout << "v: " << value << endl;
    cout << "v1: " << value1 << endl << endl;
    
    *address1 = 60;
    
    int *v;
    v = new int;
    *v = 42;
    
    cout << "v: " << *address1 << endl;
    cout << "v1: " << *v << endl;
    
}

/**
 * This function allows the user to choose the size of the dynamic array
 * and fills it in with random numbers. Once filled, it's outputted
 * in the console.
 */
void problemTwo()
{
    int size;
    cout << "Please enter the size you want your array" << endl;
    cin >> size;
    
    int* da = new int[size];
    
    for (int i = 0; i < size; i++)
    {
       da[i] = rand() % 11; 
    }
    
    for (int i = 0; i < size; i++)
    {
       cout << da[i] << " "; 
    }
    cout << endl;
    
    
}

/**
 * This function contains a function with two other functions included
 * to do the same task as problem two. User inputs the size, 
 * random values are inputted, and then it's outputted.
 */
void problemThree()
{
    createDArray();
}

/**
 * This function creates a dynamic array. 
 * Two other functions are also store within this function as 
 * its filled with random values and outputted.
 */
void createDArray()
{
    int size;
    cout << "Please enter the size you want your array" << endl;
    cin >> size;
    
    int* da = new int[size];  
    
    storeRandom(da, size);
    output(da, size);
    
}

/**
 * This functions allows random values to be stored within an array
 * @param b: the array
 * @param size: the size in the array
 */
void storeRandom(int b[], int size)
{
    
   for (int i = 0; i < size; i++)
    {
       b[i] = rand() % 11; 
    }
   cout << endl;
}

/**
 * This function allows the contents of the array to be displayed
 * @param b: the array
 * @param size: the size of the array
 */
void output(int b[], int size)
{
   for (int i = 0; i < size; i++)
    {
       cout << b[i] << " "; 
    }
    cout << endl; 
}

/**
 * This function allows the display of an array
 * and the display the a pointer that points
 * to that specific array
 */
void problemFour()
{
   int size = 5;
   int a[size];
   int *v;
   
   storeRandom(a, size);
   cout << "Contents of Array Are: ";
   output(a, size);
   
   v = a;
   
   cout << "Contents of Pointer Are: ";
   output(v, size);
  
}

/**
 * This functions allows the user to add to a array
 * even if it surpasses the original size
 */
void problemFive()
{
   int size = 5;
   int* da = new int[size];
   
   string answer;
   
   do
   {
       cout << "Please enter a number to add to array" << endl;
       int num;
       cin >> num; 
       
       da[size] = num; 
       size ++;
       
       cout << "Do you want to add another number" << endl;
       cin >> answer; 
       
   }while(tolower(answer[0]) == 'y'); 
   
   output(da, size);
   
   // We can fix this problem of adding over the size by 
   //using an if statement to check the size is < or equal to
   //the size of the current array and error check it.
   
  
}

/**
 * This function allows a binary search to happen with a vector
 * that has a size of 100000.
 */
void problemSix()
{
    int size = 100000;
    
    vector<int> v(size);
    fillVector(v);
    
    cout << "Please enter a number you want to find" << endl;
    int num;
    cin >> num;

    int location = binaryS(v, num);
    
    if (location == -1)
    {
        cout << "Sorry, number not found in this vector!" << endl;
        
    }
    else
    {
        cout << "Number was found at location: " << location << endl;
    }
    
    
}

/**
 * This function allows the vector to be filled with
 * random values
 * @param v: the vector
 */
void fillVector(vector<int> &v)
{
    for(int i = 0; i < v.size() - 1; i++)
    {
        v[i] = i + 1;
    }
}

/**
 * This function allows a binary search on a given number by
 * the user.
 * @param v: the user
 * @param val: the value inputted by user
 * @return middle: The middle number correctly guessed by the search
 */
int binaryS(const vector<int> &v, int val)
{
    int low = 0;
    int high = v.size()-1;
    int middle = (low + high) /2;
    int guess = v[middle];
    
    while(guess != val)
    {
        if(guess < val)
        {
            middle = (middle + v.size()) / 2;
            guess = v[middle];
        }
        else if(guess > val)
        {
            high = middle - 1;
            middle =(low + high) / 2;
            guess = v[middle];
            
        }
        else
        {
            //Found it
        }
    }
                
    return middle;
}