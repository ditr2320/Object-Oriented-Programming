//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
// Project 1 - question 1 

// Prints a string in reverse 
#include <iostream>
#include <string> 
using namespace std; 

/* This function accepts a string as input and prints the reverse of the string 
 * Parameters : one string 
 * Outputs the string backwards 
 * No return 
*/ 

 void reverse(string string1){  
    for (int i = string1.length()-1; i >= 0; i-- ) // Prints letters starting at last positiion and goes down in position until 0 is reached 
    {
        cout << string1[i]; 
    }
    cout << endl; 
    }

int main(){
    string string1;
    getline(cin,string1); // function that allows for multi-word strings 
    reverse(string1); // calls function from earlier 
    return 0; 
}