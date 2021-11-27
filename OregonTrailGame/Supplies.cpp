//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 3 

#include "Supplies.h"
#include <iostream>
#include <cmath>
#include <string> 
#include <fstream>
using namespace std; 

Supplies :: Supplies()
{
    numOxen = 0; 
    lbsFood = 0; 
    numBullets = 0; 
    numWagonParts = 0; 
    numKits = 0; 
    priceMultiplier = 0; 

    rabbit = 0; 
    fox = 0; 
    deer = 0; 
    bear = 0; 
    moose = 0; 

    numPlayers = 5; 
    foodLeftBehind = 0; 
}

int Supplies :: getNumOxen()
{
    return numOxen; 
}

int Supplies :: getLbsFood()
{
    return lbsFood; 
}

int Supplies :: getNumBullets()
{
    return numBullets; 
}

int Supplies :: getNumWagonParts()
{
    return numWagonParts; 
}

int Supplies :: getNumKits()
{
    return numKits; 
}

int Supplies :: getNumPlayers()
{
    return numPlayers; 
}

int Supplies :: getPuzzleOutcome()
{
    return puzzle; 
}

double Supplies :: getPriceMultiplier(string fortname)
{
    int milestoneNum; 
    if(fortname == "Fort Kearney")
    {
        milestoneNum = 3; 
    }
    if(fortname == "Fort Laramie")
    {
        milestoneNum = 5; 
    }
    if(fortname == "Fort Bridger")
    {
        milestoneNum = 8; 
    }
    if(fortname == "Fort Hall")
    {
        milestoneNum = 11; 
    }
    if(fortname == "Fort Boise")
    {
        milestoneNum = 13; 
    }
    if(fortname == "Fort Walla Walla")
    {
        milestoneNum = 15; 
    }
    switch(milestoneNum)
    {
        case 3: priceMultiplier = 0.25; 
                break; 
        case 5: priceMultiplier = 0.50; 
                break; 
        case 8: priceMultiplier = 0.75; 
                break; 
        case 11: priceMultiplier = 1.00; 
                break; 
        case 13: priceMultiplier = 1.25; 
                break; 
        case 15: priceMultiplier = 1.50; 
                break; 
        default: priceMultiplier = 0; 
    }
    return priceMultiplier; 
}

void Supplies :: addNumOxen(int oxen)
{
    numOxen = numOxen + oxen;  
}
void Supplies :: addLbsFood(int lbs)
{
    lbsFood = lbsFood + lbs; 
}
void Supplies :: addNumBullets(int bullets)
{
    numBullets = numBullets + bullets; 
}

void Supplies :: addNumWagonParts(int wagon)
{
    numWagonParts = numWagonParts + wagon; 
}

void Supplies :: addNumKits(int kits)
{
    numKits = numKits + kits; 
}

void Supplies :: subNumBullets(int bullets)
{
    if(numBullets > bullets)
    {
        numBullets = numBullets - bullets; 
    }
    else
    {
        numBullets = 0; 
    }
    
}

void Supplies :: subLbsFood(int lbs)
{
    lbsFood = lbsFood - lbs; 
}

void Supplies :: subNumKits(int kits)
{
    numKits = numKits - kits; 
}

void Supplies :: subNumOxen(int oxen)
{
    numOxen = numOxen - oxen; 
}

void Supplies :: subNumWagonParts(int wagon)
{
    numWagonParts = numWagonParts - wagon; 
}

int Supplies :: getRabbit()
{
    int prob = 50; 
    srand(time(0)); // setting seed
    int num = (rand() % 100) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        rabbit = 1; 
    }
    else
    {
        rabbit = 0; 
    }
    return rabbit; 
}

int Supplies :: getFox()
{
    int prob = 25; 
    srand(time(0)); // setting seed
    int num = (rand() % 100) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        fox = 1; 
    }
    else
    {
        fox = 0; 
    }
    return fox; 
}

int Supplies :: getDeer()
{
    int prob = 15; 
    srand(time(0)); // setting seed
    int num = (rand() % 100) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        deer = 1; 
    }
    else
    {
        deer = 0; 
    }
    return deer; 
}

int Supplies :: getBear()
{
    int prob = 7; 
    srand(time(0)); // setting seed
    int num = (rand() % 100) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        bear = 1; 
    }
    else
    {
        bear = 0; 
    }
    return bear; 
}

int Supplies :: getMoose()
{
    int prob = 5; 
    srand(time(0)); // setting seed
    int num = (rand() % 100) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        moose = 1; 
    }
    else
    {
        moose = 0; 
    }
    return moose; 
}

int Supplies :: getPuzzle(int num, int choice)
{
    if(choice == num)
    {
        puzzle = 1; 
    }
    else
    {
        puzzle = 0; 
    }
    return puzzle; 
}

void Supplies :: successfulHunt(char animal)
{
    switch(animal)
    {
        case 'r':addLbsFood(5); 
                subNumBullets(10); 
                break; 
        case 'f':addLbsFood(10); 
                subNumBullets(8); 
                break; 
        case 'd':addLbsFood(60);
                subNumBullets(5); 
                break; 
        case 'b':addLbsFood(200); 
                subNumBullets(10);
                break; 
        case 'm':addLbsFood(500);
                subNumBullets(10);     
                break;        
    }; 
} 

void Supplies :: subtractPlayer()
{
    numPlayers--; 
}

int Supplies :: eatAfterHunt(int choice)
{
    switch(choice)
    {
        case 0: subLbsFood(2*numPlayers); 
        case 1: subLbsFood(3*numPlayers); 
        case 2: subLbsFood(4*numPlayers); 
    }; 
    if(lbsFood > 1000)
    {
        lbsFood = 1000; 
        foodLeftBehind = 1; 
    }
    else
    {
        foodLeftBehind = 0; 
    }
    return foodLeftBehind; 
}