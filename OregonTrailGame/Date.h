//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 3 

#ifndef DATE_H
#define DATE_H

#include <string>
#include<iostream>
using namespace std; 
// Class called Date that handles day month and year 

class Date
{
    private: 
    int day; 
    int month; 
    int year;  
    string date; 
    int monthType; // keeps track of how many days in a month, 1 is 30 days, 2 is 31 days
    int turnType; // 0 is rest, 1 is continue, 2 is hunt
    string endDate; 

    public: 
    Date(); // default constructor
    Date(int day, int month); // Parameterized constructor 
    // Getters and setters
    int getMonth(); 
    void setMonth(int month); 
    int getDay(); 
    void setDay(int day); 
    int getYear(); 
    int getMonthType(int month); 
    string getDate();
    /*
    Takes in number of days that should be added to date and increases month and day accordingly 
    */
    string getEndDate(); 
    void addDay(int numDays, int userMonthType); 
}; 

#endif