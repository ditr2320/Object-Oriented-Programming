#ifndef GAME_H
#define GAME_H

#include <string>
#include<iostream>
#include "Player.h"
#include "Supplies.h"
#include "Date.h"
using namespace std; 

class Game
{
    private:  
    Player playersArray[5]; // array of objects from another class, for randomly selecting players 
    double money; 
    int miles; 
    int endMiles; // miles till oregon city
    int milesLeft; // miles until next milestone
    string nearestMilestone; // returns nearest milestone
    // array that holds lines from milestones.txt file 
    string milestones[30]; //Kansas river crossing is milestone 0, only even numbers, Fort Walla Walla is 28, even numbers are miles
    int milestoneMileage[15]; // only has milestone mileage as integers, 0 is kansas river crossing, 14 is Fort Walla Walla 
    int storeStatus; // 0 if store is not avaliable, 1 if store is avaliable 
    int wagonStatus; // 0 is working 1 is broken; 
    string storeInfo[7]; // stores text from store_info.txt
    int misfortune; // 0 is no, 1 is yes and med kit, 2 is yes and no med kit;
    int misfortune1Outcome; //0 is healthy; 1 is dead
    int misfortune2Outcome; // 0 means that oxen left; 1 means that no oxen left
    int misfortune3Outcome; // 0 means you fixed the wagon, 1 means you did not 
    int playerPos; // position in players array 
    string diseases[6]; 
    string diseaseType; 
    int raiderAttack; // 0 is no 1 is yes 
    string gameStats[6]; 
    int endgame; 
    int numMilesAdded; 

    public: 
    Game(); // default constructo
    double getMoney(); 
    void setMoney(double userMoney); 
    int getMiles(); 
    void setMiles(int userMiles); 
    // Function that takes in number of miles as int and adds to current number
    void addMiles(int userMiles); 
    // Function that deducts money
    void subMoney(double userMoney); 
    // Takes in file of milestones into an array
    void readMilestones(); 
    // Prints milestone 
    void printMilestone(int milestoneNum); 
    // Prints mileage as string
    void printMilestoneMiles(int milestoneNum); 
    // Prints mileage as integer
    void printMilestoneMileage(int milestoneNum); 
    // Returns if a milestone is a store or not 
    int getStoreStatus(int milestoneNum); 
    // Returns status of wagon
    int getWagonStatus(); 
    // Modifty wagon status
    void setWagonStatus(int wagonS); 
    // Takes store info file and stores in array
    void readStoreinfo(); 
    // Prints store info array
    void printStoreinfo(); 
    // Returns miles until next milestone
    int getMilesLeft(int milesTravelled); 
    // Prints nearest milestone
    string getNearestMilestone(int milesTravelled); 
    // sets names in players array 
    void setPlayerNames(string leadername, string member1, string member2, string member3, string member4); 
    // Set member types 
    void setMemberTypes(); 
    // Returns misfortune integer 
    int getMisfortune(Supplies S1); // 0 is no, 1 is disease, 2 is oxen, 3 is wagon
    // Prints which player is sick and from which disease 
    void misfortunePlayerDisease(); // assings sick player and disease - if misfortune is 1 
    //Misfortune 1  - kit avaliable
    int useMedKit(Supplies S1); 
    //Misfortunes 1 - kit unavaliable
    int noMedKit(Supplies S1, Date D1,int userChoice); 
    //Misfortune 2 
    int misfortuneOxen(Supplies S1); //returns outcome of misfortune  
    //Misfortune 3 
    int misfortuneWagon(Supplies S1); //returns outcome of misfortune 
    // Raider attack 
    int getRaiderAttack(); // 0 is good, 1 is bad 
    // raider options; 
    void raiderChoices(Supplies S1, int choice); // 2 raider scenarios 
    // raider options
    void raiderChoices2(Supplies S1, int choice, int puzzleOutcome); // 1 raider scenario
    // prints status update
    void statusUpdate(Supplies S1, Date D1, Player P1); 
    // Writing results of game to txt file
    void writeFile(Supplies S1, Date D1, Player P1); 
    // returns days added
    int getNumDaysAdded(); 
    // for ending the game 
    int getEndgame(Player P1, Date D1, Supplies S1); // 0 is good, 1 is end game
    // for ending the game 
    void setEndgame(int choice); // 0 is good, 1 is end game

}; 

#endif