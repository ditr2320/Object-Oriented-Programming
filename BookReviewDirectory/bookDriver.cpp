//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Homework 7 - Question 3 

#include <iostream>
#include <cmath>
#include "Book.h"
using namespace std;

int main() {
string title = "A Thousand Splendid Suns"; 
string title2 = "The Kite Runner"; 
string author = "Khaled Hosseini"; 
string genre = "Fiction"; 

Book B1 = Book(title,author,genre); // Creates object B1 

cout << "Title: " << B1.getTitle() << endl; // Prints title of B1 
B1.setTitle(title2); // Assigns new title to title of B1
cout << "Title: " << B1.getTitle() << endl; // Prints title of B1

return 0; 
}
