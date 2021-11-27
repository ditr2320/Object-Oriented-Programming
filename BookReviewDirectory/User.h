#ifndef USER_H
#define USER_H

#include <string>
#include<iostream>
using namespace std; 

// Class called User 

class User
{
    private: 
    string username; 
    int numRatings; // Number of books in the database
    int size; // capacity of the ratings array - constant  
    int ratings[50]; // number of elements should be size

    public: 
    User(); // default constructor
    User(string user, int ratingArr[], int numRates); // Parameterized constructor 
    string getUsername(); 
    void setUsername(string user); 
    int getRatingAt(int index); 
    bool setRatingAt(int index, int value); 
    int getNumRatings(); 
    void setNumRatings(int num); 
    int getSize(); 

}; 

#endif