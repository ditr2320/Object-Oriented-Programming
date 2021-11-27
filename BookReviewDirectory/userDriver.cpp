//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 6 

#include "User.h"
#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
    string user = "ditr"; 
    int ratingArr[] = {4,2,5,1}; 
    int numRates = 4; 

    User U1 = User(user, ratingArr,numRates); 

    cout << "Username is: " << U1.getUsername() << endl; 
    string user1 = "ditr2320"; 
    U1.setUsername(user1); 
    cout << "Username is: " << U1.getUsername() << endl; 
}