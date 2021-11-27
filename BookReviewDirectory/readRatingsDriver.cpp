//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 7 

#include "User.h"
#include <iomanip>
#include <cctype>
#include <fstream>
using namespace std; 

/*
Function that takes in four parameters:
Para 1:  String to be split
Para 2: Separator that is a character
Para 3: String array that stores separated strings
Para 4: Size of the array
Returns the number of pieces that string is split into 
*/

int split(string myStr, char separator, string array[], int size)
{
    myStr = myStr + separator; 
    string word = ""; 
    int num = 0; 
    for(int i = 0; i < myStr.length(); i++)
    {
        if(num < size)
        {
        if(myStr[i]!= separator)
        {
            word = word + myStr[i]; // Creates string with letters up until a separator in encountered 
        }
        else 
        {
            if(myStr.length()!= 0)
            {
                array[num] = word; // Stores word in array 
                num++; 
            }
            word = ""; 
        }
        }
    }
    return num; 
}
// Function that takes in a filename, an array of objects, the number of users stored, the objects array size, and the max number of columns
// The function will return how many users are stored after the file is read 
int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize, int maxCol)
{
    ifstream file; 
    string line = ""; 
    file.open(fileName); 
    string fileArray[maxCol+1];
    if (numUsersStored >= usersArrSize)
    {
        return -2; 
    }
    if(file.fail())
    {
        return -1; 
    } 
    while(getline(file,line)) 
    {
        if((line.length()>0) && numUsersStored < usersArrSize)
        {
        int num = split(line, ',', fileArray, maxCol+1); 
        users[numUsersStored].setUsername(fileArray[0]); 
        for (int j = 1; j< num; j++)
        {
            users[numUsersStored].setRatingAt(j-1,stoi(fileArray[j])); 
        }
        numUsersStored++; 
        }
    }
    file.close(); 
    return numUsersStored;
}

int main()
{
    string fileName = "ratings.txt"; 
    User users[10]; 
    int numUsersStored = 0; 
    int usersArrSize = 2; 
    int maxCol = 50; 
    cout << readRatings(fileName,users,numUsersStored,usersArrSize,maxCol) << endl; 
    cout << users[0].getUsername() << endl; 
    cout << users[0].getRatingAt(49) << endl; 
    return 0; 
}