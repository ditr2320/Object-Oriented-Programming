//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Homework 7 - Question 3 

#include <iostream>
#include <cmath>
#include "Date.h"
using namespace std;

int main() 
{
int month = 3; 
int day = 24; 

Date D1 = Date(); 
Date D2 = Date(month, day); 

cout << "Date: " << D1.getDate() << endl; 
cout << "Date: " << D2.getDate() << endl; 
D1.addDay(5, D1.getMonthType(D1.getMonth())); 
D2.addDay(14, D2.getMonthType(D1.getMonth())); 
cout << "Date: " << D1.getDate() << endl; 
cout << "Date: " << D2.getDate() << endl; 
return 0; 
}