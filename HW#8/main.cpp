(/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on October 29, 2023, 1:18 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;


//Prototypes:
void problemOne ();
void delNum (vector<int>& probOne, int loc);
void valuesVector(vector<int>& probOne, int size);
void outputVector(const vector<int>& probOne);
void problemTwo();
void valueArray (int a[], int size);
void outputArray (int a[], int size);
void delNumArray(int a[], int loc, int& size);
void problemThree ();
void orderVectDel(vector<int>& probThree, int& num);
void problemFour();
void orderDelErrorChk(vector<int>& probThree, int& num);
void problemFive();
void ordrdArrayDel(int a[], int& size, int& num);
void problemSix();
bool repeatNum(vector<int> &probSix, int num);
void problemSeven();
void addNumVect(vector<int> &probSeven, int &addNum);
void outputVec(vector<int>& probOne);
void valuesVec(vector<int>& probOne, int &size);
void problemEight();
void deleteRepeats(char c[], int &size);



/*
 * 
 */
int main(int argc, char** argv) 
{
    string menuAgain;
    
    do
    {
        //Menu
        cout << "1) Problem One" << endl;
        cout << "2) Problem Two" << endl;
        cout << "3) Problem Three" << endl;
        cout << "4) Problem Four" << endl;
        cout << "5) Problem Five" << endl;
        cout << "6) Problem Six" << endl;
        cout << "7) Problem Seven" << endl;
        cout << "8) Problem Eight" << endl;
        cout << "Please enter an option: ";

        int menu;
        cin >> menu;

        switch(menu)
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
            case 7:
            {
                problemSeven();
                break;
            }
            case 8:
            {
                problemEight();
                break;
            }
            default:
                cout << "Not a valid input!" << endl;
        }
        
        cout << "Would you like another menu option" << endl;
        cin >> menuAgain;
        
    }while(tolower(menuAgain[0]) == 'y');    
            
   
    return 0;
}

//FUNCTIONS: 

/**
 * This function contains the ability to delete a number
 * from a location in the created vector
 */
void problemOne ()
{
   vector<int> probOne;
   
   valuesVector(probOne, 5);
   
   outputVector(probOne);
   
   cout << "What location would you want to delete?" << endl;
   int loc;
   cin >> loc;
   
   delNum(probOne, loc);
   
   outputVector(probOne);
   
}


/**
 * This function creates functions for vector called probOne
 * @param probOne: The vector created for problem one
 * @param size: the size of the vector
 */
void valuesVector(vector<int>& probOne, int size)
{
    for(int i = 0; i < size; i++)
    {
        probOne.push_back(i+1);
    }
}

/**
 * This function outputs each element of the vector
 * @param probOne: the vector created for problem One
 */
void outputVector(const vector<int>& probOne)
{
    for(int i = 0; i < probOne.size(); i++)
    {
        cout << probOne[i] << " ";
    }
    cout << endl;
}

/**
 * This function deletes the number on the location chosen
 * in the vector
 * @param probOne: the vector created for problem one
 * @param loc: the location where the user wants to delete
 */
void delNum(vector<int>& probOne, int loc)
{
    swap(probOne[loc], probOne[probOne.size()-1]);
    probOne.pop_back();
    
}

/**
 * This function was created to store all the functions
 * used to delete a number in a location in the created array
 */
void problemTwo()
{
    int arraySize = 5;
    int a[arraySize];
    
    valueArray(a, arraySize);
    
    outputArray(a, arraySize);
    
    cout << "What location would you want to delete?" << endl;
    int loc;
    cin >> loc;
    
    delNumArray(a, loc, arraySize);
  
    outputArray(a, arraySize);
    
}

/**
 * This function assigns values for each index in the array
 * @param a: the array created to store values
 * @param size: the amount of elements in each array
 */
void valueArray (int a[], int size)
{    
    for(int i = 0; i < size; i++)
    {
       a[i] = (i +1);     
    }
}

/**
 * This function outputs each element in the array
 * @param a: the array created to store values
 * @param size: the amount of elements in each array
 */
void outputArray (int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

/**
 * This function deletes numbers from a certain location
 * in an array
 * @param a: the array created to store values
 * @param loc: the location where the user wants to delete value
 * @param size: the number elements in the array
 */
void delNumArray(int a[], int loc, int& size)
{
    swap(a[loc], a[size -1]);
    size--;
}

/**
 * This function holds all the functions for problem three
 * that allows the user to remove a number they don't want
 */
void problemThree ()
{
   vector<int> probThree;
   
   valuesVector(probThree, 5);
   
   outputVector(probThree);
   
   cout << "What number would you want to delete?" << endl;
   int num;
   cin >> num;
   
   orderVectDel(probThree, num);
   
   outputVector(probThree); 
}

/**
 * This function deletes a number in vector and keeps the values in order
 * @param probThree: the vector created for problem three
 * @param num: the number the user wanted to remove
 */
void orderVectDel(vector<int>& probThree, int& num)
{
    int loc;
    
    for(int i = 0; i < probThree.size()-1; i++)
    {
       if(num == probThree[i])
       {
           loc = i;
       }
    }
    
    for(int i = loc; i < probThree.size() - 1; i++)
    {
          probThree[i] = probThree[i + 1];
    } 
    probThree.pop_back();
}

/**
 * This function contains the functions to solve problem three
 * that allows a number to be removed from a vector while safe checking it
 */
void problemFour()
{
   vector<int> probFour;
   
   valuesVector(probFour, 5);
   
   outputVector(probFour);
   
   cout << "What number would you want to delete?" << endl;
   int num;
   cin >> num;
   
   orderDelErrorChk(probFour, num);
   
   cout << "Here are the numbers in the vector!" << endl;
   outputVector(probFour);
}


/**
 * This functions allows the user to delete a number available in 
 * the vector while safe checking it
 * @param probThree: the vector created to contain values
 * @param num: the number the user wants to delete
 */
void orderDelErrorChk(vector<int>& probThree, int& num)
{
    //Error Checking
    if(num < 0 || num > 5)
    {
        cout << "Number Not found in Vector!" << endl;
        return;
    }
     
    
    int loc;
    
    for(int i = 0; i < probThree.size()-1; i++)
    {
       if(num == probThree[i])
       {
           loc = i;
       }
    }
    
    for(int i = loc; i < probThree.size() - 1; i++)
    {
          probThree[i] = probThree[i + 1];
    } 
    probThree.pop_back();
}

/**
 * This function contains other functions that solve problem five in order 
 * to allow the user to delete a certain number from an array
 */
void problemFive()
{
    int arraySize = 5;
    int b[arraySize];
    
    valueArray(b, arraySize);
    
    outputArray(b, arraySize);
    
    cout << "What number would you want to delete?" << endl;
    int num;
    cin >> num;
    
    ordrdArrayDel(b, arraySize, num);
  
    outputArray(b, arraySize);
}

/**
 * This function deletes a number from an array while keeping
 * the values in order
 * @param b: the array created to store values
 * @param size: the amount of elements in the array
 * @param num: the number the user chose to remove
 */
void ordrdArrayDel(int b[], int& size, int& num)
{
    int loc;
    
    for(int i = 0; i < size - 1; i++)
    {
       if(num == b[i])
       {
           loc = i;
       }
    }
    
    for(int i = loc; i < size - 1; i++)
    {
          b[i] = b[i + 1];
    } 
    size --;
    
}

/**
 * This function contains other functions used to write a function
 * to determine if a number is present inside the vector
 */
void problemSix()
{
   vector<int> probSix;
   
   valuesVector(probSix, 5);
    
   cout << "Hello" << endl;
   cout << "This finds if a number inside a vector!" << endl;
   cout << "Please enter a number: ";
   
   int num;
   cin >> num;
   
   repeatNum(probSix, num);
   
   cout << "Here are the numbers inside the vector!" << endl;
   outputVector(probSix);
   
}

/**
 * This bool function determines if a number is present in a vector
 * @param probSix: the vector created to store values
 * @param num: the number the user chose 
 * @return : returns if the bool is true or false
 */
bool repeatNum(vector<int> &probSix, int num)
{
    bool repeatNum = false;
    
    for(int i = 0; i < probSix.size()-1; i++)
    {
       if(num == probSix[i])
       {
           cout << "The number is already is inside the vector!" << endl;
           repeatNum = true;
           return repeatNum;
       }
      
    }
    
    if(repeatNum == false)
    {
        cout << "This number is not inside the vector yet!" << endl;
    }
    
    return repeatNum;
}

/**
 * This function stores other functions to 
 * solve problem seven in order to add numbers not in present
 * numbers in the vectors. If number are in the vector, 
 * it won't add it to the vector
 *  
 */
void problemSeven()
{
    string againAdd;
    
    vector<int> probSeven;
    
    probSeven.push_back(1);
    probSeven.push_back(2);
    probSeven.push_back(3);
    probSeven.push_back(4);
     
    do
    {
        cout << "Before manipulation:" << endl;
        outputVec(probSeven);

        cout << "Please enter a value to add to vector" << endl;
        int addNum;
        cin >> addNum;

        addNumVect(probSeven, addNum);
       
        
        cout << "Would you like to add another number?" << endl;
        cin >> againAdd;
        
        
    }while(tolower(againAdd[0]) == 'y');
    
}

/**
 * This function outputs the values in the vector
 * @param probSeven: the vector created to store values
 */
void outputVec(vector<int> &probSeven)
{
    for(int i = 0; i < probSeven.size(); i++)
    {
        cout << probSeven[i] << " ";
    }
    cout << endl;
}

/**
 * This function adds a number to the vector if
 * the umber isn't already in the vector.
 * If not it won't add it as "its not valid"
 * @param probSeven: the vector created to store values
 * @param addNum: the number the user wants to add to the vector
 */
void addNumVect(vector<int> &probSeven, int &addNum)
{
    if(repeatNum(probSeven, addNum) == false)
    {
      probSeven.push_back(addNum);  
      outputVec(probSeven);
    }
    else
    {
        cout << "Not valid!" << endl;
    }
    
}

/**
 * This functions contains other function that solve problem eight
 * in deleting repeated chars in a partially filled array
 */
void problemEight()
{
    cout << "This program deletes the repeated character" << endl;
    
    int size = 4;
    char c[size];
    
    c[0]='b';
    c[1]='y';
    c[2]='b';
    c[3]='e';
    
    cout << "Before manipulation:" << endl;
    for( int i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    
    deleteRepeats(c, size);
    
    cout << "After manipulation:" << endl;
    for( int i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

/**
 * This function allows a character to be deleted if 
 * found repeating
 * @param c: the array created to stor characters
 * @param size: the amount of elements in the 
 */
void deleteRepeats(char c[], int &size)
{
    if (c[0] == c[1])
    {
        for(int i = 1; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--;
    }
    else if (c[0] == c[2])
    {
       for(int i = 2; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--; 
    }
    else if( c[0] == c[3])
    {
        for(int i = 3; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--;
    } 
    else if(c[1] == c[3])
    {
        for(int i = 3; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--;
    } 
    else if(c[1] == c[2])
    {
        for(int i = 2; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--;
    }
    else if(c[1] == c[3])
    {
        for(int i = 3; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--;
    } 
    else if(c[2] == c[3])
    {
        for(int i = 3; i < size -1; i++)
        {
           c[i] = c[i + 1]; 
        }
        size--;
    } 
}
