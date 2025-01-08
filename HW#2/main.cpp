/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yasmeen Allahaleh
 *
 * Created on September 10, 2023, 1:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Question 3: 
    
    cout << "Enter your scores one by one John" << endl;
    
    cout << "Quiz 1: ";
    double scoreOneJohn;
    cin >> scoreOneJohn;
    
    cout << "Quiz 2: ";
    double scoreTwoJohn;
    cin >> scoreTwoJohn;
    
    cout << "Quiz 3: ";
    double scoreThreeJohn;
    cin >> scoreThreeJohn;
    
    cout << "Quiz 4: ";
    double scoreFourJohn;
    cin >> scoreFourJohn;
    
    cout << "Enter your scores one by one Mary" << endl;
    
    cout << "Quiz 1: ";
    double scoreOneMary;
    cin >> scoreOneMary;
    
    cout << "Quiz 2: ";
    double scoreTwoMary;
    cin >> scoreTwoMary;
    
    cout << "Quiz 3: ";
    double scoreThreeMary;
    cin >> scoreThreeMary;
    
    cout << "Quiz 4: ";
    double scoreFourMary;
    cin >> scoreFourMary;
    
    cout << "Enter your scores one by one Matthew" << endl;
    
    cout << "Quiz 1: ";
    double scoreOneMatt;
    cin >> scoreOneMatt;
 
    cout << "Quiz 2: ";
    double scoreTwoMatt;
    cin >> scoreTwoMatt;
    
    cout << "Quiz 3: ";
    double scoreThreeMatt;
    cin >> scoreThreeMatt;
    
    cout << "Quiz 4: ";
    double scoreFourMatt;
    cin >> scoreFourMatt;
    
    double avgScoreOne = (scoreOneJohn + scoreOneMary + scoreOneMatt)/3;
    double avgScoreTwo = (scoreTwoJohn + scoreTwoMary + scoreTwoMatt)/3;
    double avgScoreThree = (scoreThreeJohn + scoreThreeMary + scoreThreeMatt)/3;
    double avgScoreFour =(scoreFourJohn + scoreFourMary + scoreFourMatt)/3;
    
    
    
    cout << " Name"
            << setw(11) << " Quiz 1" <<
            setw (11) << " Quiz 2" <<
            setw(11) << " Quiz 3" << setw(11) << " Quiz 4" << endl;
            
     cout << "-----"
            << setw(11) << "-------" <<
            setw (11) << "-------" <<
            setw(11) << "-------" << setw(11) << "-------" << endl;
    
    cout << right;
    cout << "John" << setw(10) << scoreOneJohn 
            << setw(10) << scoreTwoJohn << setw(11) 
            << scoreThreeJohn << setw(11)<< scoreFourJohn << endl;
    
    cout << "Mary" << setw(10) << scoreOneMary 
            << setw(10) << scoreTwoMary << setw(11) 
            << scoreThreeMary << setw(11)<< scoreFourMary << endl;
   
    cout << "Matt" << setw(10) << scoreOneMatt 
            << setw(10) << scoreTwoMatt << setw(11) 
            << scoreThreeMatt << setw(11)<< scoreFourMatt << endl << endl;
    
    
    cout << "Average"; 
    
    cout << setw(7) << fixed << setprecision(2) << avgScoreOne << setw(11) 
            << avgScoreTwo << setw(11) << avgScoreThree << setw(11)
            << avgScoreFour << endl << endl;
    
    //Question 4:
    
    cout << "Welcome to a MadLibs game." << endl 
            << "Please enter 10 character words for each category" << endl <<endl;
    cout << "A name: ";
    string name;
    cin >> name;
    
    cout << "Another name: ";
    string nameTwo;
    cin >> nameTwo;
            
    cout << "A Food: ";
    string food;
    cin >> food;
    
    cout <<  "A Number between 100 and 200: ";
    double number;
    cin >> number;
    
    cout << "An Adjective: ";
    string adj;
    cin >> adj;
    
    cout << "A color: ";
    string color;
    cin >> color;
            
    cout << "An animal: ";       
    string animal;
    cin >> animal;
          
    cout << endl << "Dear " << name << ", " << endl << endl << " I am sorry that I am unable to turn in my homework at this time. "
            << endl <<"First, I ate rotten " << food << "," << " which made me turn " << color << " and extremely ill. I came down with "
            "a fever of " << number << "." << endl << "Next, my " << adj << " pet " << animal << " must have smelled the remains of the "
            << food << " on my " << "homework because he ate it. I am currently rewriting my homework and hope you will accept"
            << "it late." << endl << endl << " Sincerely," << endl << nameTwo;
    
    return 0;
}

