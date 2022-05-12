/* 
Name: Rishabh Manne  
Date: 4/28/22
Description: Implementing a templated doubly linkedList that holds zombie objects and performs operations on them
Usage: ./exe
*/

#include <string.h> 
#include <stdio.h>
#include <iostream>
#include <fstream>                  // importing the necessary libraries here
#include <stdlib.h>                 // these will be used to use certain functions of C++
#include <iomanip>
#include <queue>
#include "manne_list.h"                // importing the .h files to use their functions/variables
#include "zombie.h"                    // Conga functions will be used this way
#include "conga.h"
using namespace std;

void randomRoundMaker(Conga, Zombie, char []);          // forward declaring the helper method

int main(int argc, char** argv)
{

    char colors[6] = {'R', 'Y', 'G', 'B', 'M', 'C'};       // array to hold the zombie colors in chars

    Conga conga;                                        // creating new conga/zombie objects to initialize line
    Zombie zombie;
    
    

    int randColorIndex = 0;                     // a randomizer var to select a random color for zombie each time
    randColorIndex = rand() % 6;

    zombie.setColor(colors[randColorIndex]);            // setting the color to the zombie


    conga.rainbowBrains(zombie, colors);            // calling rainbowBrains function to prepare list

    int randBrain = 2 + (rand() % 6);               // randomizing the number of times we call brains

    int accum = 0;

    

    while(accum < randBrain)
    {
        Zombie brainZombie;
        randColorIndex = rand() % 6;                        // randomly create zombies/colors and populate the list with brains until random variable is exceeded
        brainZombie.setColor(colors[randColorIndex]);


        conga.brains(brainZombie);
        accum++;
    }

    int rounds;
    int rCount = 0;                                         // holder variables for number of rounds

    cout << "How many rounds would you like to run? ";
    cin >> rounds;
    cout << endl << endl;                                   // asking user how many rounds they would like to run

    char* a = new char[1];                              // holding user input(easy for strcmp later)
      

    while(rounds > 0)                               // as long as user desires for a valid amount of rounds, this loop runs
    {

        while(rCount != rounds)                     // until we reach the number of desired rounds we loop
        {

         if(conga.newList.Length() == 0)
         {
             cout << "Party is over! ";                      // if list, empties the party is over and we break the loop
             break;                       
         }

         cout << "Round: " << rCount << endl;
         cout << "The Zombie Party keeps on groaning!" << endl;     // zombies will keep groaning and current list information is printed
         cout << "Size: " << conga.newList.Length() << " :: ";
         conga.newList.PrintList();
         cout << endl;
         
         Zombie newZomb;


         randColorIndex = rand() % 6;                   // creating a random zombie with a random color to be added to the conga line in some particular way
         newZomb.setColor(colors[randColorIndex]);

         randomRoundMaker(conga, newZomb, colors);                      // calling helper method to do a random action on the conga line with the zombie

         cout << "The conga line is now:" << endl;
         cout << "Size: " << conga.newList.Length() << " :: ";          // updating the new line's information and printing the new conga line as a whole
         conga.newList.PrintList();
         cout << endl;
         cout << "*******************" << endl << endl << endl;         // to separate the rounds neatly

         rCount++;                  // increment rCount

        }

        cout << "Would you like to continue the party? (y/n) ";
        cin >> a;                                                   // if they would like to continue, we ask them the number of rounds below
        cout << endl << endl;                                       // using endl to make formatting easier in the terminal window


        if(strcmp(a,"y") == 0)
        {
            cout << "Enter the number of new rounds ";
            cin >> rounds;                                      // obtaining new number of rounds
            rCount = 0;

        }

        else
        {
            break;                                                  // otherwise loop is exited and program stops
        }
        
    }     
             



    return 0;                               // returning an int because of main method type
}


void randomRoundMaker(Conga cLine, Zombie zom, char values[])     // helper method to randomize conga actions
{


    int randNum;

    randNum = 1 + (rand() % 10);                    // randomizing a value to see which conga action to perform on line

    if(randNum == 1)                        // 1 represents the engine function, which adds to front
    {
        cLine.engine(zom);
        cout << zom.getColor() << " zombie jumps in the front of the line! (ENGINE)" << endl;   
    }

    else if(randNum == 2)                   // 2 represents the caboose function, which adds to end
    {
        cLine.caboose(zom);
        cout << zom.getColor() << " zombie pulls up the rear! (CABOOSE)" << endl;
    }

    else if(randNum == 3)                   // 3 represents jump in the line, which moves a zombie in list
    {
        int xVar;
        xVar = 0 + (rand() % cLine.newList.Length());
        cLine.jumpInTheLine(zom, xVar);
        cout << zom.getColor() << " zombie has shifted randomly in the line! (JUMPINLINE)" << endl;
    }

    else if(randNum == 4)                   // 4 represents everyoneOut, where a type of zombie are all removed
    {
        cLine.everyoneOut(zom);
        cout << zom.getColor() << " zombies have all been eradicated from line! (EVERYONEOUT)" << endl;
    }   

    else if(randNum == 5)                   // 5 represents youreDone, where one of the zombies has to leave his type
    {
        cLine.youreDone(zom);
        cout << zom.getColor() << " zombie has got to say bye to his fellow buddies! (YOUREDONE)" << endl;
    }

    else if(randNum == 6)                   // 6 represents the brains where we add two zombies of same type to line
    {
        cLine.brains(zom);
        cout << zom.getColor() << " zombie has got two more of his buddies in the line now! (BRAINS)" << endl;
    }

    else if(randNum == 7)                   // 7 represents rainbowBrains where we add all colors of zombies
    {
        cLine.rainbowBrains(zom, values);
        cout << zom.getColor() << " zombie brought a whole party itself! (RAINBOW BRAINS!)" << endl;
    }

    else if(randNum == 8)                   // 8 is makingnewFriends, where a zombie will have one of his type added
    {
        cLine.makingNewFriends(zom);
        cout << zom.getColor() << " zombie has got a new friend on the way! (MAKINGNEWFRIENDS)" << endl;
    }
    else                                // last function is unstableZombie, where a zombie shakes up the line as he enters it
    {
        cLine.unstableZombie(zom);
        cout << zom.getColor() << " zombie has caused some damage on his way up the line! (UNSTABLEZOMBIE)" << endl;
    }

   




}