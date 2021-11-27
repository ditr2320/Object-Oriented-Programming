#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include<iostream>
using namespace std; 
// Class that handles players of the game 

class Player
{
    private: 
    string name; 
    int memberType; // 0 is leader, 1 is member
    int mortalityStatus; // 0 is alive, 1 is dead 
    int healthStatus; // 0 is healthy, 1 is sick

    public: 
    Player(); // default constructor
    Player(string name, int memberType); // Parameterized constructor 
    void setName(string name); 
    string getName(); 
    void setMortalityStatus(int mortality); 
    int getMortalityStatus(); 
    void setHealthStatus(int health); 
    int getHealthStatus(); 
    void setMemberType(int member); 
    int getMemberType(); 
}; 

#endif