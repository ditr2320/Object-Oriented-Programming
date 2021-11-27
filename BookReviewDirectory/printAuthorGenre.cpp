//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - Question 4 

#include "Book.h"
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
    if (num > size) 
    {
        num = -1; 
    }
    if (myStr.length() <= 1 )
    {
        num = 0; 
    }
    return num; 
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

//Takes in an array of objects and the number of books in the array
//Prints the title and author of each book 

void printAllBooks(Book books[],int numBooks)
{
    if(numBooks <= 0)
    {
        cout << "No titles found for this genre-author pair." << endl; 
    }
    else
    {
        cout << "Here is a list of books that match this genre-author pair:" << endl; 
        for(int i =0; i<numBooks; i++)
        {
            cout << books[i].getTitle() << " by "; 
            cout << books[i].getAuthor() << endl;
        }
    }
}

// Function that takes in genre as a string, the author's first letter, an array of Book objects, and the number of books stored
// This function will print a list of books that match the given genre and letter 

int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored)
{
    Book newBooks[50]; 
    int j = 0; 
    for(int i = 0; i< numBooksStored; i++)
    {
        string author = books[i].getAuthor(); 
        char letter = author[0]; 
        if(books[i].getGenre() == genre && letter == authorFirstLetter) // conditional to check letter and genre 
        {
            newBooks[j] = books[i]; // Assigns all matches to an array
            j++; 
        }
    }
    printAllBooks(newBooks,j); // prints new array 
    return j; 
}

int main()
{
Book books[50];
string fileName = "books.txt"; 
readBooks(fileName, books, 0, 50);
printAuthorGenre("fantasy", 'R', books, 50);
}