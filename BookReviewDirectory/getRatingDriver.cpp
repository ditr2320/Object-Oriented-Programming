//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 8

#include "User.h"
#include "Book.h"
#include <iomanip>
#include <cctype>
#include <fstream>
#include <algorithm>
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

// Function that takes in a filename, an array of objects, how many books are stored in the array, and the capacity of the array
// Returns the total number of books in the system as an integer 
int readBooks(string fileName, Book books[], int numBooksStored, int bookArrSize)
{
    ifstream file; 
    string line = ""; 
    string arr[50];
    int counter = 0; 

    file.open(fileName); 
    if(file.fail())
    {
        return -1; 
    }

    if (numBooksStored == bookArrSize)
    {
        return -2;
    }

    while(getline(file,line))
    {
        if(numBooksStored < bookArrSize)
        {
            if(line.length() > 0)
            {
                split(line, ',', arr, 50);
                books[numBooksStored].setAuthor(arr[0]); 
                books[numBooksStored].setTitle(arr[1]); 
                books[numBooksStored].setGenre(arr[2]); 
                numBooksStored ++; 
            }
        }
    }

    file.close();
    return numBooksStored;
}

// This function takes in a username, title, two arrays of objects, and the size of the arrays
// The function will return the rating that corresponds to the username and title 
int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks)
{
    int userCounter = 0; 
    int bookCounter = 0; 
    bool usernameCheck = false; 
    bool titleCheck = false; 
    string username1; 
    string title1; 
    // Converting username and title to lowercase 
    transform(title.begin(), title.end(), title.begin(), ::tolower); 
    transform(username.begin(), username.end(), username.begin(), ::tolower); 

    // Converting array contents to lowercase and comparing strings 
    for(int i =0; i< numBooks; i++)
    {
        title1 = books[i].getTitle(); 
        transform(title1.begin(), title1.end(), title1.begin(), ::tolower); 
        if(title1 == title)
        {
            titleCheck = true; 
            bookCounter = i; 
        }
    }
    for(int i =0; i< numUsers; i++)
    {
        username1 = users[i].getUsername(); 
        transform(username1.begin(), username1.end(), username1.begin(), ::tolower); 
        if(username1 == username)
        {
            usernameCheck = true; 
            userCounter = i; 
        } 
    }
    if(usernameCheck == true && titleCheck == true)
    {
        return users[userCounter].getRatingAt(bookCounter); 
    }
    else
    {
        return -3; 
    }
    
}

int main()
{
    string username = "Cynthia"; 
    string title = "The Hitchhiker's Guide To The Galaxy"; 
    User users[2]; 
    Book books[2]; 
    int numUsers = 2; 
    int numBooks = 2; 
    string fileName = "books.txt"; 
    string fileName1 = "ratings.txt"; 
    int numUsersStored = 0; 
    int numBooksStored = 0; 
    int maxCol = 50; 
    cout << "number of books stored: " << readBooks(fileName, books, numBooksStored, numBooks) << endl; 
    cout << "number of users stored: " << readRatings(fileName1, users, numUsersStored, numUsers, maxCol) << endl; 
    cout << "rating is: " << getRating(username,title, users, books, numUsers, numBooks) << endl; 
}
