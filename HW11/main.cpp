/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on November 27, 2023, 3:36 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

//Prototype:
void problemOne();
void output(string a[], int &size);
void deleteString(string a[], int &size, int loc);
void problemTwo();
void addName(string a[], int &size, string name);
void problemThree();
void storeChar(char** a, int rows, int col);
void outChar(char** a, int rows, int col);

struct Animal
{
    string name;
    string color;
    string habitat; 
    
};

void problemFour();
void outputAnimal(const Animal &a);
Animal generateAnimal();

void problemFive();
void outVal(int** a, int &rows, int col);
void storeVal(int** a, int &rows, int col);
/*
 * 
 */
int main(int argc, char** argv) 
{
    string menuAgain;
    
    do
    {
        cout << "Please choose an option: " << endl;
        cout << "1.) Problem One" << endl;
        cout << "2.) Problem Two" << endl;
        cout << "3.) Problem Three" << endl;
        cout << "4.) Problem Four" << endl;
        cout << "5.) Problem Five" << endl;
    
        int option;
        cin >> option;
        
        switch(option)
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
            default :
                cout << "Not a valid option" << endl;  
        }     
        
        cout << "Would you like to go to the menu? " << endl;
        cin >> menuAgain;        
        
    }while(tolower(menuAgain[0]) == 'y');
    
    return 0;
}


/**
 * This function contains other functions that allows 
 * one to delete a name at a certain location 
 * in a dynamic array
 */
void problemOne()
{
    int size = 5;
    
    string* da = new string[size];
    
    da[0] = "Hi";
    da[1] = "Wi";
    da[2] = "Ti";
    da[3] = "Yi";
    da[4] = "Qi";
    
    cout << "Before deleting: " << endl;
    output(da, size);
    
    int loc;
    cout << "Please enter a location you would like to delete: " << endl;
    cin >> loc;
    
    deleteString(da, size, loc);
    
    cout << "After deleting: " << endl;
    output(da, size);
}

/**
 * This function allows one to delete a string
 * from a certain location inputted
 * by the user
 * @param a: the array
 * @param size: the size of the array
 * @param loc: the location wanted to be deleted
 */
void deleteString(string a[], int &size, int loc)
{
    if(loc < 0 || loc >= size - 1)
    {
        cout << "Invalid Location" << endl;
        return;
    }
    
    for(int i = loc; i < size - 1; i++)
    {
        if(i == loc)
        {
            swap(a[loc], a[size - 1]);
            size --;
        }
    }
    
}

/**
 * This outputs the array
 * @param a: the array
 * @param size: the size of the array
 */
void output(string a[], int &size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

/**
 * This function contains other functions that allow
 * one to add a name to an array
 */
void problemTwo()
{
    int size = 5;
    
    string* da = new string[size];
    
    da[0] = "Hi";
    da[1] = "Wi";
    da[2] = "Ti";
    da[3] = "Yi";
    da[4] = "Qi";
    
    cout << "Before adding: " << endl;
    output(da, size);
    
    string name;
    cout << "Please enter a name to add: " << endl;
    cin >> name;
    
    addName(da, size, name);
    
    cout << "After adding: " << endl;
    output(da, size);
    
}

/**
 * This allows a name to be added
 * to an array
 * @param a: the array
 * @param size: the size of the array
 * @param name: the name wanted to be added
 */
void addName(string a[], int &size, string name)
{
    a[size] = name;
    size++;
}

/**
 * This functions contains other functions
 * that create a pattern of a square made up of stars
 */
void problemThree()
{
   int rows = 4;
   int col = 4;
    
   char** a = new char*[rows];
   
   for(int i = 0; i < rows; i++)
   {
       a[i] = new char[col];
   }
   
   storeChar(a, rows, col);
   outChar(a, rows, col);
   
   for(int i = 0; i < rows; i++)
   {
       delete[] a[i];
   }
    
   delete[] a;
   
   
}

/**
 * This function stores chars that allow
 * the array to look like a square made up of stars
 * @param a: the array
 * @param rows: the number of rows
 * @param col: the number of columns
 */
void storeChar(char** a, int rows, int col)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            a[i][j] = '*';
        }
    }
    
    a[1][1] = ' ';
    a[1][2] = ' ';
    a[2][1] = ' ';
    a[2][2] = ' ';
    
}

/**
 * This allows the array to be outputted 
 * @param a: the array
 * @param rows: the number of rows
 * @param col: the number of columns
 */
void outChar(char** a, int rows, int col)
{
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * This allows one to add and print out an animal
 * based on the question from a struct
 */
void problemFour()
{
    Animal ani = generateAnimal();
  
    cout << "Printing object . . . " << endl;
    outputAnimal(ani);
    
}

/**
 * This functions allows the output of the
 *  answers inputted by the user for a specific animals
 * us
 * @param a
 */
void outputAnimal(const Animal &a)
{
    cout << "Name: " << a.name << endl;
    cout << "Color: " << a.color << endl;
    cout << "Habitat: " << a.habitat << endl;
}

/**
 * This allows the user to input information about an animal
 * with variables from a struct labeled animals
 * @return temp
 */
Animal generateAnimal()
{
    Animal temp;
    
    cout << "Enter the Animal's name: " << endl;
    string name;
    cin >> name;
    
    temp.name = name;
    
    cout << "Enter the Animal's color: " << endl;
    string color;
    cin >> color;
    
    temp.color = color;
    
    cout << "Enter the Animal's Habitat (Land, air, or water): " << endl;
    string hab;
    cin >> hab;
    
    temp.habitat = hab;
    
    return temp;
}

/**
 * This functions allows one to insert the amount
 * o rows and columns wanted . They can add rows 
 * to the array if desired.
 */
void problemFive()
{
    int rows;
    int col;
    
    string againRow;
    int add = 0;
    
    cout << "Please enter a number of columns: " << endl;
    cin >> col;
    
    cout << "Please enter a number of rows: " << endl;
    cin >> rows;
    
    do
    {
        if (add > 0)
        {
            rows++;
        }
        
        int** a = new int*[rows];

        for(int i = 0; i < rows; i++)
        {
            a[i] = new int[col];
        }
        
        storeVal(a, rows, col);
        outVal(a, rows, col);
        
        
        for(int i = 0; i < rows; i++)
        {
             delete[] a[i];
        }
    
        delete[] a;
        
        if(add == 0)
        {
            add++;
        }
        
        cout << "Would you like add another row? " << endl;
        cin >> againRow;
        
    }while (tolower(againRow[0]) == 'y');
     
    
}

/**
 * This functions allows the array to be outputted
 * @param a: the array
 * @param rows: the number of rows
 * @param col: the number of columns
 */
void outVal(int** a, int &rows, int col)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 

/**
 * This function assigns values in order 
 * for the array
 * @param a: the array
 * @param rows: the number of rows
 * @param col: the number of columns
 */
void storeVal(int** a, int &rows, int col)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            a[i][j] = i * col + j + 1;
        }
    }

}