//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
// Project 1 - Question 3 

// Program tells you the number of vowels are in a string 
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
/* This function counts the number of vowels in a string 
 * Parameters : One string 
 * Returns an integer 
*/ 

int numVowels(string myStr) 
{
    int vowelCount= 0; 
    int length = myStr.length(); 
    for(int i=0; i < length; i++ ) // Loops through each letter of string to check if a vowel is present 
    { 
        char letter = myStr[i]; 
        isVowel(letter); // calls function and returns boolean value 
        if (isVowel(letter))
        {
            vowelCount++; // increases count if vowel is present 
        }
    }
    return vowelCount; 
}

int main(){
    string myStr; 
    getline(cin,myStr); //Input
    numVowels(myStr); // Calls function and returns int value for number of vowels 
    cout << numVowels(myStr) << endl; 
}