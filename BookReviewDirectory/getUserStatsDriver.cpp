//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 10 

#include "User.h"
#include <iomanip>
#include <cctype>
#include <fstream>
#include <algorithm>
using namespace std; 

int getUserStats(string username, User users[], int numUsers, int numBooks)
{
    double sum = 0; 
    double average = 0; 
    int ratings = 0; 
    for(int i =0; i<numUsers; i++)
    {
        if(username == users[i].getUsername()) 
        {
            for(int j =0; j<numBooks; j++)
            {
                if(users[i].getRatingAt(j) != 0)
                {
                sum = sum + users[i].getRatingAt(j); 
                ratings++; //keeping track of the number of non-zero ratings 
                }
            }
            if(sum > 0) // Making sure user has rated at least one book
            {
            average = sum/ratings; 
            cout << username << " rated " << ratings << " books" << endl; 
            cout << username << "'s average rating was " << fixed << setprecision(2) << average << endl; 
            return 1; 
            }
            cout << username << " has not rated any books." << endl; 
            return 0; 
        }
    }
    cout << username << " does not exist." << endl; 
    return -3; 
}

int main()
{
//Creating 3 users 
User users[3];
//Setting username and ratings
users[0].setUsername("User1"); 
users[0].setNumRatings(3); 
users[0].setRatingAt(0,1); 
users[0].setRatingAt(1,4); 
users[0].setRatingAt(2,2);
//Setting username and ratings 
users[1].setUsername("User2"); 
users[1].setNumRatings(3); 
users[1].setRatingAt(0,0); 
users[1].setRatingAt(1,5); 
users[1].setRatingAt(2,3);
//Setting username and ratings 
users[2].setUsername("User3"); 
users[2].setNumRatings(3); 
users[2].setRatingAt(0,0); 
users[2].setRatingAt(1,0); 
users[2].setRatingAt(2,0);


getUserStats("User1", users, 3, 3);
getUserStats("User2", users, 3, 3);
cout << getUserStats("User3", users, 3, 3) << endl; 
cout << getUserStats("User4", users, 3, 3) << endl; 
}