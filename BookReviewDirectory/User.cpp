//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 6 

#include "User.h"
#include <iostream>
#include <cmath>
using namespace std; 

User :: User() // default constructor  
{
    username = ""; 
    numRatings = 0; 
    size = 50; 
    for(int i =0; i<size; i++)
    {
        ratings[i]= 0; 
    }
}

User :: User(string user, int ratingArr[], int numRates) //parameterized constructor 
{
    size = 50; 
    username = user; 
    if(numRates < size && numRates >= 0 )
    {
    numRatings = numRates; 
    }
    for(int i =0; i<numRates; i++)
    {
        ratings[i] = ratingArr[i]; 
    }
}

string User :: getUsername()
{
    return username; 
}

void User :: setUsername(string user)
{
    username = user; 
}

int User :: getRatingAt(int index)
{
    if(index >= size || index < 0)
    {
        return -1; 
    }
    return ratings[index]; 
}

bool User :: setRatingAt(int index, int value)
{
    if(index < size && index >= 0)
    {
        if(value <= 5 && value >= 0)
        {
        ratings[index] = value; 
        return true; 
        }
    }
    return false; 
}

int User :: getNumRatings()
{
    return numRatings; 
}

void User :: setNumRatings(int num)
{
    numRatings = num; 
}

int User :: getSize()
{
    return size; 
}