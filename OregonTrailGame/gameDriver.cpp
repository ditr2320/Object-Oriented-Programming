//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Homework 7 - Question 3 

#include <iostream>
#include <cmath>
#include "Game.h"
#include "Supplies.h"
#include "Player.h"
using namespace std;

int main() 
{
Game G1 = Game(); 
Supplies S1 = Supplies(); 
Date D1 = Date(); 
Player P1 = Player(); 
S1.addNumOxen(2); 
G1.subMoney(15); 
cout << G1.getMoney() << endl; 
G1.setMiles(324); 
G1.readMilestones(); 
G1.printMilestone(4); 
G1.printMilestoneMiles(4); 
G1.printMilestoneMileage(4); 
G1.readStoreinfo(); 
G1.printStoreinfo(); 
G1.setPlayerNames("Didi", "Emma", "Tatum", "Lara", "Anja"); 
G1.setMemberTypes(); 
cout << "store status: " << G1.getStoreStatus(3) << endl; 
cout << "Miles left until next milestone: " << G1.getMilesLeft(G1.getMiles()) << endl; 
cout << G1.getNearestMilestone(G1.getMiles()) << endl; 
cout << "misfortune: " << G1.getMisfortune(S1) << endl; 
if(G1.getMisfortune(S1) == 1)
{
    if(S1.getNumKits() > 0)
    {
        G1.misfortunePlayerDisease(); 
        G1.useMedKit(S1); 
    }
    if(S1.getNumKits() == 0 )
    {
        G1.misfortunePlayerDisease(); 
        G1.noMedKit(S1,D1,1); // 1 means "press on!"
    }
}
if(G1.getMisfortune(S1) == 2)
{
    G1.misfortuneOxen(S1); 
}
G1.getRaiderAttack(); 
G1.statusUpdate(S1,D1,P1); 
G1.writeFile(S1,D1,P1); 
return 0; 
}