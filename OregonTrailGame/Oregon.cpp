//CSCI 1300 Fall 2020
//Author: Didi Trifonova
//Recitation: 351 - Sourav Chakraborty
//Homework 7 - Question 3 

#include <iostream>
#include <cmath>
#include "Game.h"
#include "Supplies.h"
#include "Player.h"
#include "Date.h"
using namespace std;

int main()
{
    Player P1 = Player(); 
    Game G1 = Game(); 
    Supplies S1 = Supplies(); 
    Date D1 = Date();
    G1.readMilestones(); 
    string name1; 
    string name2; 
    string name3; 
    string name4; 
    string name5; 
    char yn, yn1, yn2;
    int c, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10; 
    int c11, c12, c13, c14, c15, c16, c17, c18, c19, c20;  
    int c21, c22, c23, c24, c25, c26, c27, c28, c29; 
    int c30, c31; 

    cout << endl; 
    cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847." << endl; 
    cout << "YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl; 
    cout << endl; 
    while(yn != 'y')
    {
        cout << "What is the first name of the wagon leader?" << endl; 
        cin >> name1; 
        cout << "Is this correct? (y)es/(n)o" << endl; 
        cin >> yn; 
    }
    while(yn1!= 'y')
    {
        cout << "What are the first names of the four other members in your party?" << endl; 
        cin >> name2; 
        cin >> name3; 
        cin >> name4; 
        cin >> name5; 
        cout << "Is this correct? (y)es, (n)o" << endl; 
        cin >> yn1; 
    }
    G1.setPlayerNames(name1,name2,name3,name4,name5); 
    cout << "It is 1848. Your jumping off place for Oregon is Independence, Missouri. You must decide which month to leave Independence." << endl; 
    cout << "Would you like to start on 03/28/1847? Otherwise you may choose a date between 03/01/1847 and 05/01/1847.(y)es/(n)o" << endl; 
    cin >> yn2; 
    if(yn2 == 'n')
    {
        cout << "What month would you like to depart?" << endl << "1.March" << endl << "2.April" << endl << "3.May" << endl; 
        cin >> c; 
        if(c == 1)
        {
            D1.setMonth(3); 
            cout << "What day would you like to depart? (March has 31 days)" << endl; 
            cin >> c1; 
            D1.setDay(c1); 
        }
        if(c== 2)
        {
            D1.setMonth(4);
            cout << "What day would you like to depart? (April has 30 days)" << endl; 
            cin >> c2; 
            D1.setDay(c2); 
        }
        if(c == 3)
        {
            D1.setMonth(5);
            D1.setDay(1); 
        }
    }
    cout << endl; 
    G1.readStoreinfo(); 
    G1.printStoreinfo();   
    while(c3 != 5)
    {
        cout << endl << "What would you like to purchase?" << endl << "1.Oxen" << endl << "2.Food" << endl << "3.Bullets" << endl << "4.Miscellaneous supplies" << endl << "5.Exit the store" << endl; 
        cin >> c3; 
        if(c3 == 1)
        {
            while( c4 < 3 || c4 > 5)
            {
                cout << "You must spend between $100 and $200 dollars on oxen. There are two oxen in a yoke. Price of one yoke: $40" << endl << "How much yoke would you like to buy?" << endl; 
                cin >> c4; 
                if(c4 >= 3 && c4 <= 5)
                {
                    S1.addNumOxen(c4*2); 
                    G1.subMoney(c4*40); 
                }
                if(c4 < 3)
                {
                    cout << "You must purchase at least 3 yoke" << endl ;
                }
                if(c4 > 5)
                {
                    cout << "You may purchase a maximum of 5 yoke" << endl; 
                }
            }
            cout << "You have $" << G1.getMoney() << " left." << endl; 
        }
        if(c3 == 2)
        {
            cout << "We recommend you to purchase 200 lbs of food per person, at 50 cents per pound." << endl << "How many pounds of food would you like to purchase?" << endl; 
            cin >> c5; 
            if(c5 >= 0 && c5 <= 1000) //validation to make sure they dont buy more food than money available
            {
                S1.addLbsFood(c5); 
                G1.subMoney(c5*(0.50)); 
            }
            else
            {
                cout << "invalid option" << endl; 
            }
            cout << "You have $" << G1.getMoney() << " left." << endl; 
        }
        if(c3 == 3)
        {
            cout << "A box of 20 bullets costs $2. You will need the bullets for hunting along the way." << endl << "How many boxes of bullets would you like to purchase?" << endl; 
            cin >> c6; 
            if(c6 >= 0 && c6 <= G1.getMoney()/2)
            {
                S1.addNumBullets(c6*20); 
                G1.subMoney(c6 * 2); 
            }
            else
            {
                cout << "invalid option" << endl; 
            }
            cout << "You have $" << G1.getMoney() << " left." << endl; 
        }
        if(c3 == 4)
        {
            cout << "A wagon part (wheels, axles, tongues) costs $20. If the wagon breaks along the way, any wagon parts will be used to fix it." << endl << "How many would you like to purchase?" << endl; 
            cin >> c7; 
            if(c7 >= 0 && c7 <= G1.getMoney()/20)
            {
                S1.addNumWagonParts(c7); 
                G1.subMoney(c7*20); 
            }
            else
            {
                cout << "invalid option" << endl; 
            }
            cout << "Each medical kit costs $25." << endl << "How many kits would you like to buy?" << endl; 
            cin >>  c8; 
            if(c8 >= 0 && c8 <= G1.getMoney()/25)
            {
                S1.addNumKits(c8); 
                G1.subMoney(c8*25); 
            }
            else
            {
                cout << "invalid option" << endl;
            }
            
            cout << "You have $" << G1.getMoney() << " left." << endl; 
        }
    }
    G1.statusUpdate(S1, D1, P1); 
    if(G1.getEndgame(P1, D1, S1) == 1)
    {
        return 0; 
    }

    while(c9 != 4)
    { 
        cout << "Do you want to (1) rest, (2) continue on trail, (3) hunt, or (4) quit? " << endl; 
        cin >> c9; 
        if(c9 == 1) // choosing to rest
        {
            srand(time(0)); // setting seed
            int addedDays = (rand() % 3) +1; // randomly generates from 1 to 3 
            D1.addDay(addedDays, D1.getMonthType(D1.getMonth()));
            S1.subLbsFood(addedDays * 3 * S1.getNumPlayers()); // Subtracts food 
        }
        if(c9 == 2) // choosing to continue
        {
            D1.addDay(14, D1.getMonthType(D1.getMonth())); 
            int addedDays = 14; 
            S1.subLbsFood(addedDays * 3 * S1.getNumPlayers());  // Subtracts food 
            srand(time(0)); // setting seed
            int numMilesAdded = (rand()% (140 - 70 + 1))+ 70; // Generates numbers between 70 and 140
            if(numMilesAdded < G1.getMilesLeft(G1.getMiles()))
            {
                G1.addMiles(numMilesAdded); // adding number of miles wanted 
            }
            else
            {
                cout << "You were prepared to travel " << numMilesAdded << " miles but you have arrived at " << G1.getNearestMilestone(G1.getMiles()) << endl; 
                cout << "What do you want to do? Rest(1) or Continue (2)?" << endl; 
                cin >> c13; 
                if(c13 == 1)
                { 
                    string mName = G1.getNearestMilestone(G1.getMiles());
                    G1.addMiles(G1.getMilesLeft(G1.getMiles()));
                    if(mName == "Fort Kearney" || mName == "Fort Laramie" || mName == "Fort Bridger" || mName == "Fort Hall" || mName == "Fort Boise" || mName == "Fort Walla Walla")
                    {
                        cout << "You have reached a fort!" << endl; 
                        while(c14 != 3)
                        {
                            cout << "Would you like to (1)rest (2)shop or (3)continue ?" << endl;  
                            cin >> c14; 
                            if(c14 == 1)
                            {
                                srand(time(0)); // setting seed
                                int addedDays = (rand() % 3) +1; // randomly generates from 1 to 3 
                                D1.addDay(addedDays, D1.getMonthType(D1.getMonth()));
                                S1.subLbsFood(addedDays * 3 * S1.getNumPlayers()); // Subtracts food 
                            }
                            if(c14 == 2)
                            {
                                double p = S1.getPriceMultiplier(mName); 
                                while(c15 != 5)
                                {
                                    cout << endl << "What would you like to purchase?" << endl << "1.Oxen" << endl << "2.Food" << endl << "3.Bullets" << endl << "4.Miscellaneous supplies" << endl << "5.Exit the store" << endl; 
                                    cin >> c15;
                                    if(c15 == 1)
                                    {
                                        cout << "There are two oxen in a yoke." << endl << "The price of a yoke is " << (40 + 40*p) << endl; 
                                        cout << "How much yoke would you like to buy?" << endl; 
                                        cin >> c16; 
                                        if(c16 >= 0 && c16 <= G1.getMoney()/(40 + 40*p)) 
                                        {
                                            S1.addNumOxen(c16*2); 
                                            G1.subMoney(c16*(40 + 40*p)); 
                                        }
                                        else
                                        {
                                            cout << "Invalid option" << endl; 
                                        }
                                        cout << "You have $" << G1.getMoney() << " left." << endl;
                                    } 
                                    if(c15 == 2)
                                    {
                                        cout << "How many pounds of food would you like to purchase?" << endl; 
                                        cin >> c17; 
                                        if(c17>= 0 && c17 <= G1.getMoney()*2) 
                                        {
                                            S1.addLbsFood(c17); 
                                            G1.subMoney(c17*(0.50)); 
                                        }
                                        else
                                        {
                                            cout << "invalid option" << endl; 
                                        }
                                        cout << "You have $" << G1.getMoney() << " left." << endl; 
                                    }
                                    if(c15 == 3)
                                    {
                                        cout << "A box contains 20 bullets and costs " << (2 + 2*p) << endl << "How many boxes of bullets would you like to purchase?" << endl; 
                                        cin >> c18; 
                                        if(c18 >= 0 && c18 <= G1.getMoney()/(2 + 2*p)) 
                                        {
                                            S1.addNumBullets(c18*20); 
                                            G1.subMoney(c18 * (2 + 2*p)); 
                                        }
                                        else
                                        {
                                            cout << "invalid option" << endl; 
                                        }
                                        cout << "You have $" << G1.getMoney() << " left." << endl; 
                                    }
                                    if(c15 == 4)
                                    {
                                        cout << "Wagon parts cost " << 20 + (20*p) << endl << "How many wagon parts (wheels, axles, tongues) would you like to purchase?" << endl; 
                                        cin >> c19; 
                                        if(c19 >= 0 && c19 <= G1.getMoney()/(20 + 20*p)) 
                                        {
                                            S1.addNumWagonParts(c19); 
                                            G1.subMoney(c19* (20 + 20*p)); 
                                        }
                                        else
                                        {
                                            cout << "invalid option" << endl; 
                                        }
                                        cout << "How many medical kits would you like to buy? Each kit costs " << 25 + 25*p << endl; 
                                        cin >> c20; 
                                        if(c20 >= 0 && c20 <= G1.getMoney()/(25 + 25*p)) 
                                        {
                                            S1.addNumKits(c20); 
                                            G1.subMoney(c20*(25 + 25*p)); 
                                        }
                                        else
                                        {
                                            cout << "invalid option" << endl; 
                                        }
                                        cout << "You have $" << G1.getMoney() << " left." << endl; 
                                    }
                                }
                                c15 = 0; 
                            }
                        }
                        c14 = 0;
                    } 
                }
                if(c13 == 2)
                {
                    G1.addMiles(numMilesAdded); // choosing to continue instead of staying at fort
                }
            }
        }
        if(c9 == 3)
        {
            int temp2 = S1.getRabbit(); 
            if(temp2 == 0)
            {
                cout << "You did not encounter any rabbits." << endl; 
            }
            if(temp2 == 1)
            {
                cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT!" << endl << "DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl; 
                cin >> c10; 
                if(c10 == 1)
                {
                    if(S1.getNumBullets() < 10)
                    {
                        cout << "The hunt is unsuccesful because you need at least 10 bullets" << endl; 
                    }
                    else
                    {
                        int count = 0; 
                        int puzzleOutcome = 0; 
                        cout << "You must solve a puzzle in order to have a successful hunt." << endl <<  "You have three chances to correctly guess a number between 1 and 5" << endl; 
                        srand(time(0));
                        int puzzleNum = (rand() % 5) +1; // randomly generates from 1 to 5
                        while(puzzleOutcome != 1 && count < 3)
                        {
                            cout << "Please enter a number between 1 and 5" << endl; 
                            cin >> c11; 
                            puzzleOutcome = S1.getPuzzle(puzzleNum, c11); 
                            if(puzzleOutcome == 0)
                            {
                                cout << "You did not guess correctly" << endl; 
                            }
                            if(puzzleOutcome == 1)
                            {
                                cout << "Congratulations, you guessed correctly and had a successful hunt!" << endl; 
                                S1.successfulHunt('r'); // adds food and subtracts bullets 
                                cout << "How well would you like to eat?" << endl << "1. Poorly: 2 lbs of food, per person" << endl << "2. Moderately: 3 lbs of food, per person" << endl << "3. Well: 5 lbs of food, per person" << endl; 
                                cin >> c12; 
                                int temp3 = S1.eatAfterHunt(c12); // subtracts food 
                                if(temp3 == 1)
                                {
                                    cout << "The wagon cannot hold more than 1000 lbs of food and you had to leave some food behind." << endl; 
                                }
                                if(temp3 == 0)
                                {
                                    cout << "You have " << S1.getLbsFood() << " pounds of food left." << endl; 
                                }
                            }
                            count++; 
                        }
                    }
                }
            }
            int temp3 = S1.getFox(); 
            if(temp3 == 0)
            {
                cout << "You did not encounter any foxes." << endl; 
            }
            if(temp3 == 1)
            {
                cout << "YOU GOT LUCKY! YOU ENCOUNTERED A FOX!" << endl << "DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl; 
                cin >> c21; 
                if(c21 == 1)
                {
                    if(S1.getNumBullets() < 10)
                    {
                        cout << "The hunt is unsuccesful because you need at least 10 bullets" << endl; 
                    }
                    else
                    {
                        int count = 0; 
                        int puzzleOutcome = 0; 
                        cout << "You must solve a puzzle in order to have a successful hunt." << endl <<  "You have three chances to correctly guess a number between 1 and 5" << endl; 
                        srand(time(0));
                        int puzzleNum1 = (rand() % 5) +1; // randomly generates from 1 to 5                       
                        while(puzzleOutcome != 1 && count < 3)
                        {
                            cout << "Please enter a number between 1 and 10" << endl; 
                            cin >> c22; 
                            puzzleOutcome = S1.getPuzzle(puzzleNum1, c22); 
                            if(puzzleOutcome == 0)
                            {
                                cout << "You did not guess correctly" << endl; 
                            }
                            if(puzzleOutcome == 1)
                            {
                                cout << "Congratulations, you guess correctly and had a successful hunt!" << endl; 
                                S1.successfulHunt('d'); // adds food and subtracts bullets 
                                cout << "How well would you like to eat?" << endl << "1. Poorly: 2 lbs of food, per person" << endl << "2. Moderately: 3 lbs of food, per person" << endl << "3. Well: 5 lbs of food, per person" << endl; 
                                cin >> c23; 
                                int temp3 = S1.eatAfterHunt(c23); // subtracts food 
                                if(temp3 == 1)
                                {
                                    cout << "The wagon cannot hold more than 1000 lbs of food and you had to leave some food behind." << endl; 
                                }
                                if(temp3 == 0)
                                {
                                    cout << "You have " << S1.getLbsFood() << " pounds of food left." << endl; 
                                }
                            }
                            count++; 
                        }
                    }
                }
            }
            int temp4 = S1.getDeer(); 
            if(temp4 == 0)
            {
                cout << "You did not encounter any deer." << endl; 
            }
            if(temp4 == 1)
            {
                cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER!" << endl << "DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl; 
                cin >> c24; 
                if(c24 == 1)
                {
                    if(S1.getNumBullets() < 10)
                    {
                        cout << "The hunt is unsuccesful because you need at least 10 bullets" << endl; 
                    }
                    else
                    {
                        int count = 0; 
                        int puzzleOutcome = 0; 
                        cout << "You must solve a puzzle in order to have a successful hunt." << endl <<  "You have three chances to correctly guess a number between 5" << endl; 
                        srand(time(0));
                        int puzzleNum2 = (rand() % 10) +1; // randomly generates from 1 to 5                       
                        while(puzzleOutcome != 1 && count < 3)
                        {
                            cout << "Please enter a number between 1 and 5" << endl; 
                            cin >> c25; 
                            puzzleOutcome = S1.getPuzzle(puzzleNum2, c25); 
                            if(puzzleOutcome == 0)
                            {
                                cout << "You did not guess correctly" << endl; 
                            }
                            if(puzzleOutcome == 1)
                            {
                                cout << "Congratulations, you guess correctly and had a successful hunt!" << endl; 
                                S1.successfulHunt('d'); // adds food and subtracts bullets 
                                cout << "How well would you like to eat?" << endl << "1. Poorly: 2 lbs of food, per person" << endl << "2. Moderately: 3 lbs of food, per person" << endl << "3. Well: 5 lbs of food, per person" << endl; 
                                cin >> c26; 
                                int temp3 = S1.eatAfterHunt(c26); // subtracts food 
                                if(temp3 == 1)
                                {
                                    cout << "The wagon cannot hold more than 1000 lbs of food and you had to leave some food behind." << endl; 
                                }
                                if(temp3 == 0)
                                {
                                    cout << "You have " << S1.getLbsFood() << " pounds of food left." << endl; 
                                }
                            }
                            count++; 
                        }
                    }
                }
            }
            int temp5 = S1.getBear(); 
            if(temp5 == 0)
            {
                cout << "You did not encounter any bears." << endl; 
            }
            if(temp5 == 1)
            {
                cout << "YOU GOT LUCKY! YOU ENCOUNTERED A BEAR!" << endl << "DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl; 
                cin >> c27; 
                if(c27 == 1)
                {
                    if(S1.getNumBullets() < 10)
                    {
                        cout << "The hunt is unsuccesful because you need at least 10 bullets" << endl; 
                    }
                    else
                    {
                        int count = 0; 
                        int puzzleOutcome = 0; 
                        cout << "You must solve a puzzle in order to have a successful hunt." << endl <<  "You have three chances to correctly guess a number between 1 and 5" << endl; 
                        srand(time(0));
                        int puzzleNum3 = (rand() % 5) +1; // randomly generates from 1 to 5                     
                        while(puzzleOutcome != 1 && count < 3)
                        {
                            cout << "Please enter a number between 1 and 10" << endl; 
                            cin >> c28; 
                            puzzleOutcome = S1.getPuzzle(puzzleNum3,c28); 
                            if(puzzleOutcome == 0)
                            {
                                cout << "You did not guess correctly" << endl; 
                            }
                            if(puzzleOutcome == 1)
                            {
                                cout << "Congratulations, you guess correctly and had a successful hunt!" << endl; 
                                S1.successfulHunt('b'); // adds food and subtracts bullets 
                                cout << "How well would you like to eat?" << endl << "1. Poorly: 2 lbs of food, per person" << endl << "2. Moderately: 3 lbs of food, per person" << endl << "3. Well: 5 lbs of food, per person" << endl; 
                                cin >> c29; 
                                int temp3 = S1.eatAfterHunt(c29); // subtracts food 
                                if(temp3 == 1)
                                {
                                    cout << "The wagon cannot hold more than 1000 lbs of food and you had to leave some food behind." << endl; 
                                }
                                if(temp3 == 0)
                                {
                                    cout << "You have " << S1.getLbsFood() << " pounds of food left." << endl; 
                                }
                            }
                            count++; 
                        }
                    }
                }
            }
            int temp6 = S1.getMoose(); 
            if(temp6 == 0)
            {
                cout << "You did not encounter any moose." << endl; 
            }
            if(temp6 == 1)
            {
                cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE!" << endl << "DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl; 
                cin >> c27; 
                if(c27 == 1)
                {
                    if(S1.getNumBullets() < 10)
                    {
                        cout << "The hunt is unsuccesful because you need at least 10 bullets" << endl; 
                    }
                    else
                    {
                        int count = 0; 
                        int puzzleOutcome = 0; 
                        cout << "You must solve a puzzle in order to have a successful hunt." << endl <<  "You have three chances to correctly guess a number between 1 and 5" << endl; 
                        srand(time(0));
                        int puzzleNum4 = (rand() % 5) +1; // randomly generates from 1 to 5                    
                        while(puzzleOutcome != 1 && count < 3)
                        {
                            cout << "Please enter a number between 1 and 5" << endl; 
                            cin >> c28; 
                            puzzleOutcome = S1.getPuzzle(puzzleNum4, c28); 
                            if(puzzleOutcome == 0)
                            {
                                cout << "You did not guess correctly" << endl; 
                            }
                            if(puzzleOutcome == 1)
                            {
                                cout << "Congratulations, you guess correctly and had a successful hunt!" << endl; 
                                S1.successfulHunt('m'); // adds food and subtracts bullets 
                                cout << "How well would you like to eat?" << endl << "1. Poorly: 2 lbs of food, per person" << endl << "2. Moderately: 3 lbs of food, per person" << endl << "3. Well: 5 lbs of food, per person" << endl; 
                                cin >> c29; 
                                int temp3 = S1.eatAfterHunt(c29); // subtracts food 
                                if(temp3 == 1)
                                {
                                    cout << "The wagon cannot hold more than 1000 lbs of food and you had to leave some food behind." << endl; 
                                }
                                if(temp3 == 0)
                                {
                                    cout << "You have " << S1.getLbsFood() << " pounds of food left." << endl; 
                                }
                            }
                            count++; 
                        }
                    }
                }
            }
            D1.addDay(1, D1.getMonthType(D1.getMonth())); 
        }
        int misfortuneType = G1.getMisfortune(S1);
        if(misfortuneType == 1)
        {
            if(S1.getNumKits() > 0)
            {
                G1.misfortunePlayerDisease(); 
                S1.subNumKits(1); 
                G1.useMedKit(S1); 
            }
            else if(S1.getNumKits() == 0 )
            {
                G1.misfortunePlayerDisease(); 
                cout << "You do not have a medical kit, would you like to (1) rest or (2) press on ?" << endl; 
                cin >> c30; 
                G1.noMedKit(S1,D1,c30); 
            }
        }
        if(misfortuneType == 2)
        {
            S1.subNumOxen(1);
            G1.misfortuneOxen(S1); 
        }
        if(misfortuneType == 3)
        {
            if(S1.getNumWagonParts() > 0)
            {
                S1.subNumWagonParts(1);
            }
            else if(S1.getNumWagonParts() <= 0)
            {
                G1.setWagonStatus(1); 
            } 
            G1.misfortuneWagon(S1);
        }
        // Raiders
        int raiders = G1.getRaiderAttack();
        if(raiders == 1)
        {
            cout << "Would you like to (1)Run, (2)Attack, or (3)Surrender ? " << endl; 
            cin >> c31; 
            if(c31 == 2)
            {
                cout << "You must pass this puzzle to win" << endl; 
                int puzzleOutcome = 0; 
                int count = 0; 
                srand(time(0));
                int puzzleNum5 = (rand() % 5) +1; // randomly generates from 1 to 5                
                while(puzzleOutcome != 1 && count < 3) 
                {
                    cout << "Please enter a number between 1 and 5" << endl; 
                    cin >> c11; 
                    puzzleOutcome = S1.getPuzzle(puzzleNum5, c11); 
                    if(puzzleOutcome == 0)
                    {
                        cout << "You did not guess correctly" << endl; 
                    }
                    if(puzzleOutcome == 1)
                    {
                        cout << "You guessed correctly!" << endl; 
                    }
                    count++; 
                }
                G1.raiderChoices2(S1, 2, puzzleOutcome); 
                if(puzzleOutcome == 0)
                {
                    int quarter = G1.getMoney()/4.0; 
                    G1.subMoney(quarter); 
                    S1.subNumBullets(50); 
                }
                if(puzzleOutcome == 1)
                {
                    S1.addLbsFood(50); 
                    S1.addNumBullets(50); 
                }
            }
            else
            {
                G1.raiderChoices(S1, c31); 
                if(c31 == 1)
                {
                    S1.subNumOxen(1); 
                    S1.subLbsFood(10); 
                    if(S1.getNumWagonParts() > 0)
                    {
                    S1.subNumWagonParts(1); 
                    }
                }
                if(c31 == 3)
                {
                    int quarter = G1.getMoney()/4.0; 
                    G1.subMoney(quarter);
                }
            }
        }
        // Status update
        G1.statusUpdate(S1, D1, P1); 
        // checking if they can continue game
        if(G1.getEndgame(P1, D1, S1) == 1)
        {
            G1.writeFile(S1,D1,P1); 
            return 0; 
        }
        // checking if they have made it to oregon city 
        if(G1.getMiles() >= 2040)
        {
            cout << "You made it to Oregon City!" << endl; 
            return 0; 
        }
    }
    return 0; 
}