/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on August 28, 2023, 6:32 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//Program that stores Sum of Two Numbers
    int total = 50 + 100;
    cout << "50 + 100 = " << total << endl << endl;
    
// Program that computes sales tax
    double state = 95.0 * 0.04;
    double county = 95.0 * 0.02;
    double totalAmount = 95.0 + state + county;
    cout << "You total including state and county tax is : $" << totalAmount << endl << endl;
    
//Program that computes the tax and tip on restaurant bill
    double food = 88.67;
    double taxes = food * 0.0675;
    double totalWithTax = taxes + 88.67;
    double tip = totalWithTax * 0.20;
    double totalPrice = totalWithTax + tip;
    cout << "Hello Customer, " << endl << " Your break down for your total meal cost is: " 
         << endl << "Meal cost: $" << food << endl << "Tax: $" << taxes << endl << "Tip:$" << tip 
         << endl << "Total Cost: $" << totalPrice << endl << "Thank You, have a nice day!" << endl << endl;
    
   // Program that calculates the number of miles per gallon the car gets
    double milesPerGal = 375 / 15;
    cout << "This car uses: " << milesPerGal << " Miles Per Gallon" << endl << endl;
    
   // Program that displays personal information
    string name = "Yasmeen Allahaleh";
    int phoneNum = 1237889090;
    string major = "Computer Science";
    cout << "You wanna learn more about me? Look below for some information!!!" << endl << endl << "Name: "
           << name << endl << "My Number: " << phoneNum << endl << "My Major: " << major << endl; 
    return 0;
}

