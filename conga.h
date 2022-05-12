#ifndef CONGA_H
#define CONGA_H
#include "zombie.h"
#include "manne_list.h"
using namespace std;

class Conga
{

    public:

    Conga();
    void engine(Zombie z);
    void caboose(Zombie z);
    void jumpInTheLine(Zombie z, int index);                // forward declaring all of the Conga functions
    void everyoneOut(Zombie z);                             // that use the LinkedList methods to change the 
    void youreDone(Zombie z);                               // look of the conga line each time they are randomly called
    void brains(Zombie z);
    void rainbowBrains(Zombie z, char array[]);
    void makingNewFriends(Zombie z);
    void unstableZombie(Zombie z);

    LinkedList<Zombie> newList;         // creating a newList object whenever a Conga object is created in main class

};

#endif