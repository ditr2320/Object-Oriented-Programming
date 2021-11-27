//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
// Project 1 - Question 5

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
    double seq1Length = seq1.length(); 
    double seq2Length = seq2.length(); 
    if (seq1Length == seq2Length) // String 1 must have a length greater than 0 and the lengths must be equal
    {
        for(int i=0; i<= seq1Length - 1; i++) // Checks if strings are equal one position at a time
        {
            if (seq1[i] != seq2[i]) // if characters at position i are equal 
            {
                hamming_distance++; // increases hamming distance by 1 if characters are different 
            }
        }
        similarity_score = (seq1Length - hamming_distance) / seq1Length; // equation for sim score 
    }
    else // user validation - if two sequences are not of equal length or have a length of 0
    {
        similarity_score = 0; 
    }
    return similarity_score; 
}

/* This function finds the best similarity score between a sequence and a genome sub-sequence 
 * Parameters : One genome string and one sequence string 
 * Returns the best similarity score present 
*/ 

double findBestSimScore(string genome,string sequence)
{   
    int genomeLength = genome.length(); 
    int sequenceLength = sequence.length(); 
    double max = 0.0; 
    for (int i=0; (i < genomeLength - (sequenceLength-1)); i++) // runs for calculated number of genome sub-sequences that are present 
    {
        string genomesub = genome.substr(i,sequenceLength); // creates a sub-sequence at each possible starting position (genomesub)
        calcSimScore(genomesub,sequence); // calls function that will calculate the simscore between the sub-sequence and sequence 
        if((calcSimScore(genomesub,sequence) > max )) 
        {
            max = calcSimScore(genomesub,sequence); // Updates max (if necessary) as it loops through all the sub-sequences 
        }
    }
    return max; 
}

int main()
{
    string genome; 
    string sequence; 
    cout << "Enter genome:" << endl; 
    cin >> genome; 
    cout << "Enter sequence:" << endl; 
    cin >> sequence; 
    findBestSimScore( genome, sequence); // Calls function 
    cout << findBestSimScore( genome, sequence) << endl; // prints the best similarity score 
    return 0; 
}