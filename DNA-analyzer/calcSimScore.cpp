//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
// Project 1 - Question 4

#include <iostream>
using namespace std; 

/* This function calculates the similarity score between two strings 
 * Parameters : Two strings of equal length and a length greater than 0 
 * Returns a double value on the scale of [0.0,1.0] with 1.0 meaning that the strings are identical 
*/ 

double calcSimScore(string seq1, string seq2)
{
    double similarity_score; 
    double hamming_distance = 0; 
    double string_length = seq1.length(); 
    if (string_length > 0 && string_length == seq2.length()) // String 1 must have a length greater than 0 and the lengths must be equal
    {
        for(int i=0; i<= string_length - 1; i++) // Checks if strings are equal one position at a time
        {
            if (seq1[i] != seq2[i]) // if characters at position i are equal 
            {
                hamming_distance++; // increases hamming distance by 1 if characters are different 
            }
        }
        similarity_score = (string_length - hamming_distance) / string_length; // equation for sim score 
    }
    else // user validation - if two sequences are not of equal length or have a length of 0 
    {
        similarity_score = 0; 
    }
    return similarity_score; 
}

int main()
{
    string seq1; 
    string seq2; 
    cin >> seq1; 
    cin >> seq2; 
    calcSimScore(seq1, seq2); // calls function 
    cout << calcSimScore(seq1,seq2) << endl; // prints 

}
