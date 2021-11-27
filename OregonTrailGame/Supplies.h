#ifndef SUPPLIES_H
#define SUPPLIES_H

#include <string>
#include<iostream>
#include "Player.h"
using namespace std; 

class Supplies
{
    private:  
    int numOxen; 
    int lbsFood; 
    int numBullets; 
    int numWagonParts; 
    int numKits; 
    double priceMultiplier; 

    int rabbit; // 0 is no, 1 is yes
    int fox; 
    int deer; 
    int bear; 
    int moose; 
    int puzzle; // 0 is unsuccessful, 1 is successful 
    int numPlayers; 
    int foodLeftBehind; // 0 is no, 1 is yes

    public: 
    Supplies(); // default constructor
    int getNumOxen(); 
    int getLbsFood(); 
    int getNumBullets(); 
    int getNumWagonParts(); 
    int getNumKits(); 
    double getPriceMultiplier(string fortname); 
    int getNumPlayers(); 
    int getPuzzleOutcome(); 

    void addNumOxen(int oxen); 
    void addLbsFood(int lbs); 
    void addNumBullets(int bullets); 
    void addNumWagonParts(int wagon);
    void addNumKits(int kits);  

    void subNumBullets(int bullets); 
    void subLbsFood(int lbs); 
    void subNumKits(int kits); 
    void subNumOxen(int oxen); 
    void subNumWagonParts(int wagon); 

    int getRabbit(); 
    int getFox(); 
    int getDeer(); 
    int getBear(); 
    int getMoose(); 
    int getPuzzle(int num, int choice); // 0 is no, 1 is yes
    void successfulHunt(char animal); //adds lbs of food and subtracts bullets
    //returns whether or not food was left behind, 0 is no, 1 is yes 
    int eatAfterHunt(int choice); // 0 is eat poor, 1 is moderately, 2 is well 
    void subtractPlayer(); // removes a player if they die 
}; 

#endif