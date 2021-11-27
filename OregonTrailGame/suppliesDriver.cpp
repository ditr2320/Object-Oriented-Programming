//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Homework 7 - Question 3 

#include <iostream>
#include <cmath>
#include "Supplies.h"
using namespace std;

int main()
{
    Supplies S1 = Supplies(); 
    cout << "Milestone 8: " << S1.getPriceMultiplier(8) << endl; 
    cout << "Milestone 4: " << S1.getPriceMultiplier(4) << endl;
    cout << S1.getRabbit() << endl; 
    return 0;
}