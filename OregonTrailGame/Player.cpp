//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 3 

#include "Player.h"
#include <iostream>
#include <cmath>
#include <string> 
using namespace std; 

Player :: Player() // default constructor 
{
    name = ""; 
    memberType = 0; //leader 
    mortalityStatus = 0; // alive
    healthStatus = 0; // healthy 
}

Player :: Player(string userName, int userMemberType) //parameterized constructor 
{
    name = userName; 
    memberType = userMemberType; 
    mortalityStatus = 0; 
    healthStatus = 0; 
}

void Player :: setName(string userName)
{
    name = userName; 
}

string Player :: getName()
{
    return name; 
}

void Player :: setMortalityStatus(int mortality)
{
    mortalityStatus = mortality; 
}

int Player :: getMortalityStatus()
{
    return mortalityStatus; 
}

void Player :: setHealthStatus(int health)
{
    healthStatus = health; 
}

int Player :: getHealthStatus()
{
    return healthStatus; 
}

void Player :: setMemberType(int member)
{
    memberType = member;
}

int Player :: getMemberType()
{
    return memberType; 
}
