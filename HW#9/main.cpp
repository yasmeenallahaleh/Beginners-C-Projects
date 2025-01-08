/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahale
 *
 * Created on November 4, 2023, 12:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Prototypes:
void problemOne();
void addPerson(vector<int>& planeID, vector<string>& name);
void problemTwo();
void inputFromFile( vector<string>& firstName, vector<string>& lastName, string fileName);
void outputToStream(const vector<string>& firstName, const vector<string>& lastName, ostream& out);
void problemThree();
void inputFile(vector<string>& firstName, vector<string>& lastName, string fileName);
void problemFour();
void storeRanNum(int a[], int size);
void outputArray (int a[], int size);
void bubbleSort(int a[], int size);
void problemFive();
void selectSort(int a[], int size);
void problemSix();
void orderValues(vector<int>& probSeven, int num);
void problemSeven();
void outputVector(const vector<int>& probSeven);
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
        cout << "7) Problem 7" << endl;

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
            case 7:
            {
                problemSeven();
                break;
            }
            default :
                cout << "Not a valid option" << endl;
        }
        
        cout << "Would you like to go to another menu option?" << endl;
        cin >> menuAgain;
        
    }while(tolower(menuAgain[0]) == 'y');
    
    

    return 0;
}


/**
 * This functions contains other functions that allows a person to create 
 * a plane ticket with their name and a random generated plane ID ticket.
 */
void problemOne()
{
    vector<string> name;
    vector<int> planeID;
    
    addPerson(planeID, name);
    
     for(int i = 0; i < name.size(); i++)
    {
        cout << name[i] << " " << planeID[i] << endl;
    }
}

/**
 * This function adds another person with an plane ID ticket
 * to parallel vectors
 * @param planeID: the vector that stores the ID ticket number
 * @param name: the vector that stores the name of passenger
 */
void addPerson(vector<int>& planeID, vector<string>& name)
{
    string againAdd;
    
    do
    {
        cout << "Hello New Customer! " << endl;
        cout << "Please enter a name for your flight!" << endl;
        cout << "Name: ";

        string customer;
        cin >> customer;

        name.push_back(customer);

        planeID.push_back(rand() % 40 + 1); 


        for(int i = 0; i < name.size(); i++)
        {
           cout << name[i] << " " << planeID[i] << endl; 
        } 
        
        cout << "Would you like to add another customer?" << endl;
        cin >> againAdd;
        
    }while(tolower(againAdd[0]) == 'y');
    
}

/**
 * This function contains other functions that allow
 * the input from a file to be seperated into two different
 * vectors.
 */
void problemTwo()
{
    
    vector<string> firstName;
    vector<string> lastName;
    
    const string NAMEFILE = "names.txt";
    inputFromFile(firstName, lastName, NAMEFILE);
    
    outputToStream(firstName, lastName, cout);
}

/**
 * This functions finds the space between the first and last name 
 * so it could be stored in to different vectors.
 * @param firstName: the vector created to store first names
 * @param lastName: the vector created to store last names
 * @param fileName: the file where we get the input
 */
void inputFromFile(vector<string>& firstName, vector<string>& lastName, string fileName)
{
    ifstream fin;
    fin.open(fileName);
    
    string rowNumber;
    
    while (getline(fin, rowNumber))
    {
        int location = rowNumber.find(' ');
        string fName = rowNumber.substr(0, location);
        string lName = rowNumber.substr(location + 1);
        
        firstName.push_back(fName);
        lastName.push_back(lName);
    }
    
    
}

/**
 * This function allows the element inside a multiple vectors
 * to be outputed
 * @param firstName: the vector that stores first names
 * @param lastName: the vector that stores last names
 * @param out: allows to be outputted
 */
void outputToStream(const vector<string>& firstName, 
        const vector<string>& lastName, ostream& out)
{
    for(int i = 0; i < firstName.size(); i++)
    {
        out << firstName[i] << " " << lastName[i] << endl;
    }
}

/**
 * This function contains other functions that allow user input 
 * from a file to be stored inside a vector
 */
void problemThree()
{
    vector<string> firstName;
    vector<string> lastName;
    
    const string NAMEFILE = "broken.txt";
    inputFile(firstName, lastName, NAMEFILE);
    
    outputToStream(firstName, lastName, cout);
    
}

/**
 * This function allows to grab input of 
 * the first and last name from a file
 * @param firstName: the vector with first name given by user
 * @param lastName: the vector with last name given by user
 * @param fileName: the name of the file where input is stored
 */
void inputFile(vector<string>& firstName, vector<string>& lastName, string fileName)
{
    ifstream fin;
    fin.open(fileName);
    
    string rowNumber;
    
    while (getline(fin, rowNumber))
    {
        int location = rowNumber.find(' ');
        string fName = rowNumber.substr(0, location);
        string lName;
        if(location == -1)
        {
            lName = " ";
        }
        else
        {
            lName = rowNumber.substr(location + 1);
        }
        
        
        lastName.push_back(lName);
        firstName.push_back(fName);
    }
    
    
}

/**
 * This function contains other functions that allows
 * an array to filled with random values and do a selected sort
 */
void problemFour()
{
    int size = 8;
    int a[size];
    
    cout << "Array Unsorted: " << endl;
    storeRanNum(a, size);
    
    outputArray(a, size);
    
    cout << "Array After Bubble Sort: " << endl;
    bubbleSort(a, size);
    
    outputArray(a, size);
}

/**
 * This function gives an array random values
 * @param a: the array created
 * @param size: the size of the array
 */
void storeRanNum(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        a[i] = rand() % 20 +1;
    }
       
}

/**
 * This function outputs the elements in the array
 * @param a: the array created
 * @param size: the size of the array
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
 * This function sorts numbers in an array by using 
 * the bubble sort method
 * @param a: the array created
 * @param size: the size of the array
 */
void bubbleSort(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int h = 0; h < size - 1; h++)
        {
            if(a[h] > a[h + 1])
            {
              swap(a[h], a[h + 1]);  
            }
        }
    }
}

/**
 * This function contains other functions that allows
 * an array to filled with random values and do a selected sort
 */
void problemFive()
{
    int size = 8;
    int a[size];
    
    cout << "Array Unsorted: " << endl;
    storeRanNum(a, size);
    
    outputArray(a, size);
    
    cout << "Array After Selection Sort: " << endl;
    selectSort(a, size);
    
    outputArray(a, size); 
}
/**
 * This function does a selected sort on an array
 * @param a: the array created
 * @param size: the size of the array
 */
void selectSort(int a[], int size)
{
     for(int i = 0; i < size - 1 ; i++)
    {
        int min = i; 
        
        for(int h = i; h < size; h++)
        {
            if(a[h] < a[min])
            {
              min = h;  
            }
        }
        
        swap(a[i], a[min]);
    }
     
}

/**
 * This functions allows a multi deminsion array
 * to be created with desired number rows and columns 
 * pulled from a file.
 */
void problemSix()
{
    const string FILENAME = "scores.txt";
    
    fstream fin;
    fin.open(FILENAME);
    
    int row;
    int column;
    int numScore;
    
    fin >> row;
    fin >> column;
    fin >> numScore;
    
    fin.close();
    
    int a[row][column];
    
    for(int i = 0;  i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            a[i][j] = numScore - (i * row + j);      
        }              
    }          
          
    
    for(int i = 0;  i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    fin.close();
}

/**
 * This functions contains other functions 
 * that allows a user enter a number into vector 
 * and put its value in order
 */
void problemSeven()
{
    string again;
    vector<int> probSeven;

  do
  {
    cout << "Please enter a number to add to vector: " << endl;
    int num;
    cin >> num;

    probSeven.push_back(num);
    orderValues(probSeven, num);
    
    cout << "Would you like to add another number?" << endl;
    cin >> again;
    
  }while(tolower(again[0]) == 'y');

  outputVector(probSeven);
  
}

/**
 * This functions allows each number to be sorted as it's added to the vector
 * @param probSeven: the vector created
 * @param num: the number added by user
 */
void orderValues(vector<int>& probSeven, int num)
{
    for(int i = 0; i < probSeven.size() - 1; i++)
    {
        if(num < probSeven[i])
        {
            swap(probSeven[i + 1], probSeven[i]); 
        }       
    }
}

/**
 * This functions allows each element in the vector to be outputted
 * @param probSeven: the vector created
 */
void outputVector(const vector<int>& probSeven)
{
    for(int i = 0; i < probSeven.size(); i++)
    {
        cout << probSeven[i] << " ";
    }
    cout << endl;
}