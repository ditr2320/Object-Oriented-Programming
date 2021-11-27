//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Homework 7 - Question 3 

#include "Book.h"
#include <iostream>
#include <cmath>
using namespace std; 

Book :: Book() // default constructor 
{
    title = ""; 
    genre = ""; 
    author = ""; 
}

Book :: Book(string bookTitle, string bookAuthor, string bookGenre) //parameterized constructor 
{
    title = bookTitle; 
    author = bookAuthor; 
    genre = bookGenre; 
}

string Book :: getTitle() 
{
    return title; 
}

void Book :: setTitle(string bookTitle)
{
    title = bookTitle; 
}

string Book :: getAuthor()
{
    return author; 
}

void Book :: setAuthor(string bookAuthor)
{
    author = bookAuthor; 
}

string Book :: getGenre()
{
    return genre; 
}

void Book :: setGenre(string bookGenre)
{
    genre = bookGenre; 
}