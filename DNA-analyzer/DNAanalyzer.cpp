//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
// Project 1 - Question 7

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

/* This function will find the best match or matches of the sequence in the three genomes 
 * Parameters : Three genome strings of equal length and 1 sequence, none should have a length of 0 
 * Does not return anything
*/ 

void findMatchedGenome(string genome1, string genome2, string genome3, string sequence)
{
    if(genome1.length() == 0 || genome2.length() == 0 || genome3.length() == 0 || sequence.length() ==0 )
    {
        cout << "Genomes or sequence is empty." << endl; 
    }
    else if(genome1.length() != genome2.length() || genome1.length() != genome2.length() || genome2.length() != genome3.length())
    {
        cout << "Lengths of genomes are different." << endl; 
    }
    else 
    {
        double case1 = findBestSimScore(genome1, sequence); // Best similarity score between first genome and sequence 
        double case2 = findBestSimScore(genome2, sequence); // Best similarity score between second genome and sequence 
        double case3 = findBestSimScore(genome3, sequence); // Best similarity score between third genome and sequence 
        // Conditionals that print statements based on which genome contains the best match with the sequence 
        if (case1 >= case2 && case1 >= case3)
        {
            cout << "Genome 1 is the best match." << endl; 
        }
        if (case2 >= case1 && case2 >= case3)
        {
            cout << "Genome 2 is the best match." << endl; 
        }
        if (case3 >= case2 && case3 >= case1)
        {
            cout << "Genome 3 is the best match." << endl; 
        }
    }
}

int main()
{
    int menuChoice; 
    string sequence1, sequence2, sequence, genome, genome1, genome2, genome3;  
    do {
    // Prints menu 
    cout << "Select a numerical option:" << endl << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl << "2. Find the best similarity score" << endl; 
    cout << "3. Analyze the genome sequences" << endl << "4. Quit" << endl; 
    cin >> menuChoice; 
    switch(menuChoice) // switch statement for each menu choice 
    {
        case 1: // Finding similarity score between two sequences 
                cout << "Enter sequence 1:" << endl; 
                cin >> sequence1; 
                cout << "Enter sequence 2:" << endl; 
                cin >> sequence2; 
                cout << "Similarity score: " << calcSimScore(sequence1,sequence2) << endl; 
                break; 
        case 2: // Finding the best similarity score 
                cout << "Enter a genome:" << endl; 
                cin >> genome; 
                cout << "Enter a sequence:" << endl; 
                cin >> sequence;
                cout << "Best similarity score: " << findBestSimScore(genome,sequence) << endl; 
                break; 
        case 3: // Finding the best match between a sequence and three genomes 
                cout << "Enter genome 1:" << endl;
                cin >> genome1; 
                cout << "Enter genome 2:" << endl;
                cin >> genome2; 
                cout << "Enter genome 3:" << endl;
                cin >> genome3; 
                cout << "Enter sequence:" << endl; 
                cin >> sequence; 
                findMatchedGenome(genome1,genome2,genome3,sequence); 
                break; 
        case 4: // Quit option 
                cout << "Good bye!" << endl; 
                break; 
        default: // When a menu option is not chosen 
                cout << "Invalid option." << endl; 
                break; 
    }
    } while (menuChoice != 4); 
}