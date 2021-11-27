#ifndef BOOK_H
#define BOOK_H

#include <string>
#include<iostream>
using namespace std; 
// Class called Book that tracks title, author, and genre

class Book
{
    private: 
    string title; 
    string author; 
    string genre; 

    public: 
    Book(); // default constructor
    Book(string title, string author, string generate); // Parameterized constructor 
    string getTitle(); 
    void setTitle(string title); 
    string getAuthor(); 
    void setAuthor(string author); 
    string getGenre(); 
    void setGenre(string genre); 

}; 

#endif