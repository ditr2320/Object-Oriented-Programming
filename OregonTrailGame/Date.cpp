//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 3 

#include "Date.h"
#include <iostream>
#include <cmath>
#include <string> 
using namespace std; 

Date :: Date() // default constructor 
{
    month = 3; 
    day = 28; 
    year = 1874; 
    date = "3-28-1874"; 
    monthType = 2; 
    turnType = 1; 
    endDate = "11-30-1874"; 
}

Date :: Date(int userMonth, int userDay) //parameterized constructor 
{
    month = userMonth; 
    day = userDay; 
    year = 1874; 
    monthType = getMonthType(userMonth); 
    date = to_string(month) + "-" + to_string(day) + "-" + to_string(year);  
    turnType = 1; 
    endDate = "11-30-1874";
}

int Date :: getMonth() 
{
    return month; 
}

void Date :: setMonth(int userMonth)
{
    month = userMonth; 
}

int Date :: getDay()
{
    return day; 
}

void Date :: setDay(int userDay)
{
    day = userDay; 
}

int Date :: getYear()
{
    return year; 
}

int Date :: getMonthType(int userMonth)
{
    // months with 28 days 
    if(userMonth == 2)
    {
        monthType = 0; 
    }
    // months with 30 days 
    else if(userMonth == 4 || userMonth == 6 || userMonth == 9 || userMonth == 11)
    {
        monthType = 1; 
    }
    // months with 31 days 
    else 
    {
        monthType = 2; 
    }
    return monthType; 
}
string Date :: getDate()
{
    date = to_string(month) + "-" + to_string(day) + "-" + to_string(year); 
    return date; 
}

void Date :: addDay(int numDays, int userMonthType)
{
    if(monthType == 1) //30 day months
    {
        if(day + numDays <= 30)
        {
            day = day + numDays; 
        }
        else
        {
            month++; 
            int temp = 30 - day; 
            int temp1 = numDays - temp; 
            day = temp1; 
        }
    }
    if(monthType == 2) //31 day months
    {
        if(day + numDays <= 31)
        {
            day = day + numDays; 
        }
        else
        {
            month++; 
            int temp = 31 - day; 
            int temp1 = numDays - temp; 
            day = temp1; 
        }
    }
}

string Date :: getEndDate()
{
    return endDate; 
}