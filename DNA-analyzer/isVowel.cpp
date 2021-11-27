//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
// Project 1 - Question 2 

// Program tells you if a character is a vowel or not 
#include <iostream>
using namespace std; 

/* This function tells you if a character is a vowel or not 
 * Parameters : One character 
 * Returns a boolean value, 1 = True, the character is a vowel or 0 = False, the character is not a vowel 
*/ 

bool isVowel(char letter)
{ 
    bool vowel; 
    if(letter == 'u' || letter == 'U' || letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter =='i' || letter == 'I' || letter == 'o' || letter == 'O')
    // conditional that sets the boolean value to true if the inputed character is a vowel 
    {
        vowel = true;
    } 
    return vowel; 
}

int main(){
    char letter; 
    cin >> letter; // Asks user for parameter 
    isVowel(letter); // calls function 
    return 0; 
}