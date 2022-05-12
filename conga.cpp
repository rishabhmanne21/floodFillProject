#include "conga.h"
#include <math.h>
using namespace std;


    Conga::Conga()
    {

        newList;                // newList is passed in through the default Conga constructor 

    }

    void Conga::engine(Zombie z)
    {
        newList.AddToFront(z);          // the engine function adds a Zombie to the front of the list
    } 
    
    void Conga::caboose(Zombie z)
    {                                   
        newList.AddToEnd(z);            // caboose function adds a Zombie to the end of the list
    }

    void Conga::jumpInTheLine(Zombie z, int index)
    {
        newList.AddAtIndex(z, index);           // this function adds a Zombie at a random index in the conga line
    }

    void Conga::everyoneOut(Zombie z)
    {
        newList.RemoveAllOf(z);                 // every Zombie of a particular color is removed from the line here
    }

    void Conga::youreDone(Zombie z)
    {
        newList.RemoveTheFirst(z);              // the first Zombie of a particular color is removed from the list
    }

    void Conga::brains(Zombie z)            
    {
        newList.AddToFront(z);                          // this adds a Zombie to the beginning, middle, and end of list(same color)
        newList.AddToEnd(z);
        newList.AddAtIndex(z, floor((newList.Length())/2));
    }

    void Conga::rainbowBrains(Zombie z, char array[])
    {
        newList.AddToFront(z);                          // this adds Zombie to the beginning of the list

        char currColor = z.getColor();              // holder of the inputted color

        for(int i = 0; i < 6; i++)
        {
            if(array[i] == currColor)
            {
                continue;                           // if the color is already added, we skip it
            }

            else
            {
                Zombie zombie;                  // else we create a Zombie with a color and add to the end till we accomplish all colors here
                zombie.setColor(array[i]);
                newList.AddToEnd(zombie);
            }
        }

    

    }

    void Conga::makingNewFriends(Zombie z)
    {
        if(newList.ElementExists(z) == false)                   // if the desired Zombie doesn't exist, it's added to the end of the list
        {
            newList.AddToEnd(z);
        }
                             
        else     
        {
            int randVal = 1 + (rand() % 3);             // creating a random 50% chance of adding before or after this Zombie

            if(randVal == 1)      
            {
                newList.AddBefore(newList.Find(z),z);       // if value is 1, we add before current Zombie
            }
            else
            {
                newList.AddAfter(newList.Find(z),z);        // otherwise we add after the current Zombie
            }
        }   
    }

    void Conga::unstableZombie(Zombie z)
    {
        
        newList.RemoveTheFirst(z);
        int randVal = 1 + (rand() % 3);             // creating a random 50% chance of adding before or after this Zombie


        if(randVal == 1)                            // we navigate the list and find where the certain nodes area
        {
            newList.AddBefore(newList.Find(z),z);       // if value is 1, we add before current Zombie
        }
        else                                            // if a node is present, then we duplicate it
        {
            newList.AddAfter(newList.Find(z),z);        // otherwise we add after the current Zombie
        }
    }


