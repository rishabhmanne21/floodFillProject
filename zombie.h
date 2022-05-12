
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
using namespace std;

class Zombie
{

        public:
                                            
        Zombie();                               // constructor for the Zombie is present here 


        char getColor();                        // declaring getters and setters for the color of the zombie
        void setColor(char col);

        bool operator== (Zombie &z)
        {
            return (this->color == z.color);        // overloading the == operator, to compare color of zombies instead
            
        }     

        friend ostream& operator<<(ostream &out,Zombie &z)
        {
           return out << " [" << z.color << "]";                // overloading the cout << operator to print the color of the zombies instead 
                                                                // with appropriate formatting
        }

        private:

        char color;                 // private color attribute of the zombie

           
            
        
        
        
};


#endif