//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Project 3 

#include "Game.h"
#include "Player.h"
#include "Supplies.h"
#include "Date.h"
#include <iostream>
#include <cmath>
#include <string> 
#include <fstream>
using namespace std; 

Game :: Game() // default constructor 
{
    money = 1600; 
    miles = 0; 
    endMiles = 2040; 
    storeStatus = -1; 
    nearestMilestone = ""; 
    storeStatus = 0;
    wagonStatus = 0; 
    misfortune = 0; 
    endgame = 0; 

    diseases[0] = "TYPHOID"; 
    diseases[1] = "CHOLERA"; 
    diseases[2] = "DIARRHEA"; 
    diseases[3] = "MEASLES"; 
    diseases[4] = "DYSENTARY"; 
    diseases[5] = "FEVER"; 
}

double Game :: getMoney()
{
    return money; 
}

void Game :: setMoney(double userMoney)
{
    money = userMoney; 
}

int Game :: getMiles()
{
    return miles; 
}

void Game :: setMiles(int userMiles)
{
    miles = userMiles; 
}

void Game :: setWagonStatus(int wagonS)
{
    wagonStatus = wagonS; 
}

int Game :: getWagonStatus()
{
    return wagonStatus; 
}

void Game :: addMiles(int userMiles)
{
    miles = miles + userMiles; 
}

void Game :: subMoney(double userMoney)
{
    if(money > userMoney)
    {
    money = money - userMoney; 
    }
    if(userMoney > money)
    {
        money = 0; 
    }
}

void Game :: setPlayerNames(string leadername, string member1, string member2, string member3, string member4)
{
    playersArray[0].setName(leadername); 
    playersArray[1].setName(member1); 
    playersArray[2].setName(member2); 
    playersArray[3].setName(member3); 
    playersArray[4].setName(member4); 
}

void Game :: setMemberTypes()
{
    playersArray[0].setMemberType(0); 
    playersArray[1].setMemberType(1); 
    playersArray[2].setMemberType(1); 
    playersArray[3].setMemberType(1); 
    playersArray[4].setMemberType(1); 
}

void Game :: readMilestones()
{
    ifstream file; 
    string line = ""; 
    string FileName = "milestones.txt"; 
    file.open(FileName);
    int counter = 0; 
    int mileCounter = 0; 
    while(getline(file,line))
    {
        milestones[counter] = line; 
        string word = ""; 
        int mileage; 
        if(counter%2 != 0) // odd lines only for mileage 
        {
            for(int i = 0; i < line.length()-1 ; i++)
            {
                if(line[i] != 'm')
                {
                    word = word + line[i]; 
                }
                else
                {  
                    if(word.length() > 0)
                    {
                        mileage = stoi(word); 
                        milestoneMileage[mileCounter] = mileage; 
                        mileCounter++; 
                    }
                }
            }
        }
        counter++; 
    }
    file.close(); 
}

void Game :: printMilestone(int milestoneNum)
{
    int temp = (milestoneNum * 2) - 2; 
    cout << milestones[temp] << endl; 
}

void Game ::printMilestoneMiles(int milestoneNum)
{
    int temp = (milestoneNum *2) - 1; 
    cout << milestones[temp] << endl; 
}

void Game :: printMilestoneMileage(int milestoneNum)
{
    cout << milestoneMileage[milestoneNum-1] << endl; 
}

int Game :: getStoreStatus(int milestoneNum)
{
    int temp = (milestoneNum * 2) - 2; 
    string mystr =  milestones[temp]; 
    if(mystr[0] == 'F')
    {
        storeStatus = 1; 
    }
    else
    {
        storeStatus = 0; 
    }
    return storeStatus; 
}

void Game :: readStoreinfo()
{
    ifstream file; 
    string line = ""; 
    string storeFile = "store_info.txt"; 
    file.open(storeFile);
    int lineCounter = 0; 
    while(getline(file,line))
    {
        storeInfo[lineCounter] = line; 
        lineCounter++; 
    }
    file.close(); 
}

void Game :: printStoreinfo()
{
    for(int i = 0; i < 7; i++)
    {
        cout << storeInfo[i] << endl; 
    }
}

int Game :: getMilesLeft(int milesTravelled)
{
    //loops through mileage array until the mileage is greater than miles travleled
    int i = 0; 
    int j = 0; 
    while( j <= milesTravelled)
    {
        j = milestoneMileage[i]; 
        i++; 
    } 
    int temp = milestoneMileage[i-1]; 
    milesLeft = temp - milesTravelled;
    return milesLeft; 
}

string Game :: getNearestMilestone(int milesTravelled)
{
    int i = 0; 
    int j = 0; 
    while( j <= milesTravelled)
    {
        j = milestoneMileage[i]; 
        i++; 
    }
    int milestoneN = i; 
    int temp = (milestoneN * 2) - 2; 
    nearestMilestone = milestones[temp]; 
    return nearestMilestone; 
}

int Game :: getMisfortune(Supplies S1)
{
    misfortune = 0; 
    int prob = 40; 
    srand(time(0)); // setting seed
    int num = (rand() % 100) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        srand(time(0)); // setting seed
        int type = (rand() % 3) +1; // randomly generates from 1 to 3 
        misfortune = type; 
    }
    else
    {
        misfortune = 0;
    }
    return misfortune; 
}

void Game :: misfortunePlayerDisease() // if misfortune is 1 
{
    int tester = 0; 
    while(tester != 1)
    {
        int num1 = rand()%5; // randomly generates a player array position 
        if(playersArray[num1].getMortalityStatus() != 1)
        {
            srand(time(0)); // setting seed
            playersArray[num1].setHealthStatus(1); // assigning sickness to random player 
            playerPos = num1; 
            tester = 1; 
        }
    }
    srand(time(0)); // setting seed
    int num2 = rand()%6; // generates number from 0 to 5 for sickness
    diseaseType = diseases[num2]; // assigns sickness to string
    if(playerPos == 0)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "YOU ARE SICK WITH " << diseaseType << endl; 
    }
    else
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << playersArray[playerPos].getName() << " IS SICK WITH " << diseaseType << endl;  
    }
}

int Game :: useMedKit(Supplies S1) 
{
    misfortune1Outcome = 0; 
    // 50% chance of dying 
    int prob = 50; 
    srand(time(NULL)); // setting seed
    int num = ((rand()%101)+1); // randomly generates from 1 to 100
    if(num <= prob)
    {
        misfortune1Outcome = 1; 
    }
    else
    {
        misfortune1Outcome = 0;
        if(playerPos == 0)
        {
            cout << "///////////////////////////////////////////////" << endl; 
            cout << "YOU HAVE RECOVERED " << diseaseType << endl; 
        }
        else
        {
            cout << "///////////////////////////////////////////////" << endl; 
            cout << playersArray[playerPos].getName() << " HAS RECOVERED FROM " << diseaseType << endl;
        }
        
    }
    if(misfortune1Outcome == 1)
    {
        playersArray[playerPos].setMortalityStatus(1); 
        if(playerPos == 0)
        {
            cout << "///////////////////////////////////////////////" << endl; 
            cout << "YOU HAVE DIED FROM " << diseaseType << endl; 
        }
        else
        {
            cout << "///////////////////////////////////////////////" << endl; 
            cout << playersArray[playerPos].getName() << " HAS DIED FROM " << diseaseType << endl;
        }
    }
    return misfortune1Outcome; 
}

int Game :: noMedKit(Supplies S1, Date D1,int userChoice)
{

    if(userChoice == 1) // choosing to rest 
    {
        D1.addDay(3, D1.getMonthType(D1.getMonth())); 
        int prob = 30; 
        srand(time(0)); // setting seed
        int num = (rand() % 101) +1; // randomly generates from 1 to 100
        if(num <= prob)
        {
            misfortune1Outcome = 1; 
        }
        else
        {
            misfortune1Outcome = 0;
            if(playerPos == 0)
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << "YOU HAVE RECOVERED FROM " << diseaseType << endl; 
            }
            else
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << playersArray[playerPos].getName() << " HAS RECOVERED FROM " << diseaseType << endl;
            }
        }  
        if(misfortune1Outcome == 1)
        {
            playersArray[playerPos].setMortalityStatus(1); 
            if(playerPos == 0)
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << "YOU HAVE DIED FROM " << diseaseType << endl; 
            }
            else
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << playersArray[playerPos].getName() << " HAS DIED FROM " << diseaseType << endl;
            }
        }
    }
    if(userChoice == 2) // choosing to press on 
    {
        int prob = 70; 
        srand(time(0)); // setting seed
        int num = (rand() % 101) +1; // randomly generates from 1 to 100
        if(num <= prob)
        {
            misfortune1Outcome = 1; 
        }
        else
        {
            misfortune1Outcome = 0;
            if(playerPos == 0)
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << "YOU HAVE RECOVERED FROM " << diseaseType << endl; 
            }
            else
            {
                cout << "///////////////////////////////////////////////" << endl; 
            cout << playersArray[playerPos].getName() << " HAS RECOVERED FROM " << diseaseType << endl;
            }
        }  
        if(misfortune1Outcome == 1)
        {
            playersArray[playerPos].setMortalityStatus(1); 
            if(playerPos == 0)
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << "YOU HAVE DIED FROM " << diseaseType << endl; 
            }
            else
            {
                cout << "///////////////////////////////////////////////" << endl; 
                cout << playersArray[playerPos].getName() << " HAS DIED FROM " << diseaseType << endl;
            }
        }
    }
    return misfortune1Outcome; 
}

int Game :: misfortuneOxen(Supplies S1) // if misfortune is 2 
{
    if(S1.getNumOxen() == 0)
    {
        misfortune2Outcome = 1; 
    }
    else
    { 
        misfortune2Outcome = 0; 
    }
    cout << "///////////////////////////////////////////////" << endl;  
    cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << S1.getNumOxen() << " OXEN LEFT." << endl;
    return misfortune2Outcome; 
}

int Game :: misfortuneWagon(Supplies S1) // if misfortune = 3 
{
    srand(time(0)); // setting seed
    int num = (rand() % 3) +1; // randomly generates from 1 to 3 
    if(num == 1)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "OH NO! ONE OF YOUR WHEELS IS BROKEN!" << endl; 
        if(S1.getNumWagonParts() == 0)
        {
            misfortune3Outcome = 1; 
        }
        else
        { 
            misfortune3Outcome = 0; 
        } 
    }
    if(num == 2)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "OH NO! ONE OF YOUR AXELS IS BROKEN!" << endl; 
        if(S1.getNumWagonParts() == 0)
        {
            misfortune3Outcome = 1; 
        }
        else
        { 
            misfortune3Outcome = 0; 
        } 
    }
    if(num == 3)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "OH NO! ONE OF YOUR TONGUES IS BROKEN!" << endl; 
        if(S1.getNumWagonParts() == 0)
        {
            misfortune3Outcome = 1; 
        }
        else
        {
            misfortune3Outcome = 0; 
        } 
    }
    if(misfortune3Outcome == 1)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "YOU DO NOT HAVE SPARE PARTS TO CONTINUE!" << endl; 
    }
    else
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "YOU HAVE SPARE PARTS TO FIX THE WAGON!" << endl; 
    }

    return misfortune3Outcome; // 0 is good, 1 is bad 
}

int Game :: getRaiderAttack()
{
    int M = miles; 
    double prob = (((pow((M/100 - 4), 2) + 72)/(pow((M/100 - 4), 2) + 12)) - 1)/ 0.10; 
    srand(time(0)); // setting seed
    int num = (rand() % 101) +1; // randomly generates from 1 to 100
    if(num <= prob)
    {
        raiderAttack = 1; 
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "RAIDERS AHEAD, THEY LOOK HOSTILE!" << endl; 
    }
    else
    {
        raiderAttack = 0; 
    }
    return raiderAttack; 
}

void Game :: raiderChoices(Supplies S1, int choice)
{
    if(choice == 1)
    {
        cout << "YOU LOST ONE OXEN, 10 LBS OF FOOD, AND ONE WAGON PART" << endl;
    }
    if(choice == 3)
    {
        cout << "YOU LOST A QUARTER OF YOUR MONEY" << endl; 
    }
}

void Game :: raiderChoices2(Supplies S1, int choice, int puzzleOutcome)
{
    if(puzzleOutcome == 1) //successful puzzle 
    {
        cout << " CONGRATS! YOU GAINED 50 POUNDS OF FOOD AND 50 BULLETS." << endl; 
    }
    if(puzzleOutcome == 0) //unsuccessful puzzle 
    {
        cout << "YOU LOST A QUARTER OF YOUR MONEY AND 50 BULLETS" << endl; 
    }
}


void Game :: statusUpdate(Supplies S1, Date D1, Player P1)
{
    cout << "//////////////////////////////// STATUS UPDATE ////////////////////////////////" << endl; 
    cout << "Date: " << D1.getDate() << endl; 
    if(getMiles() < 2040)
    {
    cout << "Miles travelled: " << getMiles() << " miles" << endl; 
    cout << "Distance until next milestone: " << getMilesLeft(getMiles()) << " miles" << endl;
    }
    else
    {
        cout << "Miles travelled: 2040" << endl; 
        cout << "Distance until next milestone: 0" << endl; 
    } 
    if(S1.getLbsFood() > 0)
    {
    cout << "Food available: " << S1.getLbsFood() << " pounds" << endl; 
    }
    else
    {
        cout << "Food avaliable: 0 pounds" << endl; 
    }
    cout << "Number of bullets: " << S1.getNumBullets() << " bullets" << endl; 
    cout << "Cash available: " << getMoney() << " Dollars" << endl; 
    cout << "Oxen remaining: " << S1.getNumOxen() << " Oxen" << endl; 
    cout << "Spare parts: " << S1.getNumWagonParts() << " Wagon Parts" << endl; 
    cout << "Medical Kits: " << S1.getNumKits() << " kits" << endl; 
} 

void Game :: writeFile(Supplies S1, Date D1, Player P1)
{
    gameStats[0] = "Date: " + D1.getDate(); 
    if(getMiles() < 2040)
    {
        gameStats[1] = "Miles travelled: " + to_string(getMiles()) + " miles"; 
        gameStats[2] = "Distance until next milestone: " + to_string(getMilesLeft(getMiles())) + " miles"; 
    }
    else
    {
        gameStats[1] = "Miles travelled: 2040"; 
        gameStats[2] = "Distance until next milestone: 0"; 
    }
    if(S1.getLbsFood() > 0)
    {
        gameStats[3] = "Food available: " + to_string(S1.getLbsFood()) + " pounds"; 
    }
    else
    {
        gameStats[3] = "Food available: 0 pounds"; 
    }
    gameStats[4] = "Number of bullets: " + to_string(S1.getNumBullets()) + " bullets"; 
    gameStats[5] = "Cash available: " + to_string(getMoney()) + " dollars"; 
    
    ofstream out_file; 
    out_file.open("results.txt"); 
    for(int i = 0; i<6; i++)
    {
        out_file << gameStats[i] << endl; 
    }

}

void Game :: setEndgame(int choice)
{
    endgame = choice; 
}

int Game :: getEndgame(Player P1, Date D1, Supplies S1)
{
    if(D1.getDay() >= 30 && D1.getMonth() >= 11)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "Game Over! You ran out of time." << endl; 
        endgame = 1; 
    } 
    else if(S1.getLbsFood() <= 0) 
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "Game Over! You have no food." << endl; 
        endgame = 1; 
    }
    else if(S1.getNumOxen() <= 0)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "Game Over! You have no oxen left." << endl; 
        endgame = 1; 
    }
    else if(playersArray[0].getMortalityStatus() == 1)
    {
        cout << "///////////////////////////////////////////////" << endl; 
        cout << "Game Over! You died." << endl; 
        endgame = 1; 
    }
    else if(getWagonStatus() == 1)
    {
        cout << "///////////////////////////////////////////////" << endl;
        cout << "Game Over! Your wagon is broken." << endl; 
        endgame = 1;
    }
    return endgame; 
}