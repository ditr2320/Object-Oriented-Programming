//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 2 - question 11

#include "User.h"
#include "Book.h"
#include <iomanip>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <string>   
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
        cout << "No books are stored" << endl; 
    }
    else
    {
        cout << "Here is a list of books" << endl; 
        for(int i =0; i<numBooks; i++)
        {
            cout << books[i].getTitle() << " by "; 
            cout << books[i].getAuthor() << endl;
        }
    }
    
}

// Function that takes in genre as a string, an array of Book objects, and the number of books stored
// It will them return how many books the count of books that match that genre as an integer 
int countGenre(string genre, Book books[], int numBooksStored)
{
    int matches = 0; 
    for( int i = 0; i < numBooksStored; i++)
    {
        if(books[i].getGenre() == genre) // conditional to check if genre matches 
        {
            matches++; 
        }
    }
    return matches; 
}

int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored)
{
    Book newBooks[50]; 
    int matches = 0; 
    for(int i = 0; i< numBooksStored; i++)
    {
        string author = books[i].getAuthor(); 
        char letter = author[0]; 
        if(books[i].getGenre() == genre && letter == authorFirstLetter) // conditional to check letter and genre 
        {
            newBooks[matches] = books[i]; // Assigns all matches to an array
            matches++; // counts number of matches 
        }
    }
    if(matches <= 0)
    {
        cout << "No titles found for this genre-author pair." << endl; 
    }
    else
    {
        cout << "Here is a list of books that match this genre-author pair:" << endl; 
        for(int j =0; j<matches; j++)
        {
            cout << newBooks[j].getTitle() << " by "; 
            cout << newBooks[j].getAuthor() << endl;
        }
    }
    return matches; 
}

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
string choice1; 
int choice; 
Book books[50]; 
User users[100];
int numBooks = 0; 
int temp = 0; 
int bookArrSize = 50; 
string fileName = ""; 
string ratingFileName = ""; 
string genreName = ""; 
string bookTitle = ""; 
string authorC; 
char authorCharacter; 
int numMatched; 
string userName; 
int usersArrSize = 100;
int numRatings  = 50;
int maxCol = 50; 
int numUsersStored = 0; 
int ratingValue = 0; 

do{
cout << "Select a numerical option:" << endl; 
cout << "======Main Menu=====" << endl; 
cout << "1. Read books from file" << endl; 
cout << "2. Print all books" << endl; 
cout << "3. Book-count by genre" << endl; 
cout << "4. Filter books by genre, author" << endl; 
cout << "5. Add user" << endl; 
cout << "6. Read ratings" << endl; 
cout << "7. Get rating" << endl; 
cout << "8. Get user statistics" << endl; 
cout << "9. Quit" << endl; 
getline(cin,choice1);
choice = stoi(choice1); 

switch(choice)
{
    case 1: // Reads books from file 
            cout << "Enter a book file name:" << endl; 
            getline(cin,fileName);
            temp = readBooks(fileName, books, numBooks, bookArrSize); 
            if (temp == -1)
            {
                cout << "No books saved to the database." << endl; 
            }
            else if(temp == -2)
            {
                cout << "Database is already full. No books were added." << endl; 
            }
            else if(temp == bookArrSize)
            {
                cout << "Database is full. Some books may have not been added." << endl;
            }
            else
            {
                cout << "Total books in the database: " << readBooks(fileName, books, numBooks, bookArrSize) << endl; 
            }
            if(readBooks(fileName, books, numBooks, bookArrSize) != -2 || readBooks(fileName, books, numBooks, bookArrSize) != -1)
            {
                numBooks = readBooks(fileName, books, numBooks, bookArrSize); 
            }
            break;
    case 2: //Prints all books
            printAllBooks(books,numBooks);
            break; 
    case 3: // Book count by genre
            cout << "Enter the genre: " << endl;
            getline(cin,genreName); 
            cout << "Total " << genreName << " books in the database: " << countGenre(genreName, books, numBooks) << endl; 
            break;  
    case 4: //Filter books by genre, author
            cout << "Enter the genre: " << endl; 
            getline(cin,genreName); 
            cout << "Enter first char of author name: " << endl; 
            getline(cin,authorC);
            authorCharacter = authorC[0]; 
            numMatched = printAuthorGenre(genreName,  authorCharacter, books, numBooks); 
            cout << "Number of titles found for this filter: " << numMatched << endl; 
            break; 
    case 5: // Add user 
            cout << "Enter a user name:" << endl; 
            getline(cin,userName);
            numUsersStored = addUser(userName, users, numRatings, numUsersStored, usersArrSize); 
            if(numUsersStored > 0)
            {
                cout << "Welcome, " << userName << "!" << endl; 
            }
            else
            {
                cout << "User already exists or the username is empty." << endl; 
            }
            break;
    case 6: //Read Ratings
            cout << "Enter the ratings file name: " << endl; 
            getline(cin,ratingFileName);
            numUsersStored = readRatings(ratingFileName,users,numUsersStored,usersArrSize,maxCol); 
            if(numUsersStored == -1)
            {
                cout << "No ratings saved to the database." << endl; 
            }
            else if(numUsersStored == -2)
            {
                cout << "Database is already full. No ratings were added." << endl; 
            }
            else if(numUsersStored == usersArrSize)
            {
                cout << "Database if full. Some ratings may not have been added" << endl; 
            }
            else
            {
                cout << "Total users in the database: " << numUsersStored << endl; 
            }
            break; 
    case 7: // Get rating
            cout << "Enter a user name: " << endl; 
            getline(cin,userName);
            cout << "Enter a book title: " << endl; 
            getline(cin,bookTitle); 
            ratingValue = getRating(userName,bookTitle, users, books, numUsersStored, numBooks); 
            if(ratingValue == -3)
            {
                cout << userName << " or " << bookTitle << " does not exist." << endl; 
            }
            else
            {
                cout << userName << " rated " << bookTitle << " with " << ratingValue << endl; 
            }
            break; 
    case 8: // Get user stats 
            cout << "Enter a user name:" << endl; 
            getline(cin,userName);
            getUserStats(userName, users, numUsersStored,numBooks); 
            break; 
    case 9: // Quit option
            cout << "Good bye!" << endl; 
            break; 
    default: // user validation 
            cout<< "Invalid input." << endl; 
            break;  
}
}while(choice!=9); 
}