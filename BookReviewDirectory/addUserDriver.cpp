//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 9 

#include "User.h"  
#include <iomanip>
#include <cctype>
#include <fstream>
#include <algorithm>
using namespace std; 

int addUser(string userName, User users[], int numRatings, int numUsersStored, int usersArrSize)
{
    if(numUsersStored >= usersArrSize)
    {
        return -2; 
    }
    for( int i =0; i< usersArrSize; i++)
    {
        if(userName == users[i].getUsername())
        {
            return -1; 
        }
    }
    if(userName.length() == 0 )
    {
        return -1; 
    }
    else
    {
        users[numUsersStored].setUsername(userName); 
        for(int i =0; i<numRatings; i++)
        {
            users[numUsersStored].setRatingAt(i,1);
        }
        numUsersStored++; 
    }
    return numUsersStored; 
}

int main()
{

    User users[2];
    int usersArrSize = 2;
    int numRatings  = 5;
    users[0].setUsername("Ninja");
    // Add 5 ratings given by the user "Ninja"
    for(int i=0; i<numRatings; i++) 
    {
        users[0].setRatingAt(i, i);
        cout << users[0].getRatingAt(i) << endl; 
    }  
    int numUsersStored = 1;
    cout<<addUser("ninja", users, numRatings, numUsersStored, usersArrSize)<<endl;
}
