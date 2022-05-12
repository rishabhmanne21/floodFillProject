#ifndef MANNE_LIST_H
#define MANNE_LIST_H
#include <iostream>
using namespace std;


template <typename Type>                // the Nodes of the  Doubly LinkedList will be templated as well
class Node
{
   private:



    friend class Zombie;                   // declaring the friend class to ensure overloaded methods are recognized
                                           // this is important for overloading the << and == operators
   public:

    Node()
    {
        this->next = NULL;
        this->prev = NULL;                  // default node constructor that sets next and prev values to null
    }
    Node(Type data)
    {
        this->next = NULL;
        this->prev = NULL;                  // parameterized constructor sets the data equal to the passed in arg
        this->data = data;
    }
    ~Node()
    {
                                            // destructor that destroys memory of node when called
    }
    Type getData();
    void setData(Type value);
    Node<Type>* next;                       // all public methods and variables of the Node
    Node<Type>* prev;                       // these are accessible to anyone in class
    Type data;



};


template <typename Type>
Type Node<Type>::getData()                      // defining a getter that retrieves the data of the Node
{
   
     return this->data;

    
}

template <typename Type>
void Node<Type>::setData(Type value)            // defining a setter that sets the data of Node to particular value
{
    this->data = value;
}


template <typename T>                           // the doubly linked list is also templated to allow Zombies to populate them
class LinkedList
{

    private:

    Node<T>* head;                              // private attributes of the linkedList which are head, tail, size
    Node<T>* tail;                              // these are particular to a certain LinkedList object
    int size;
    

    public:

    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;                      // default constructor which assigns default values to attributes
        this->size = 0;                         // objects == NULL and ints == 0
    }
   // ~LinkedList();
    void AddToFront(T data);
    void AddToEnd(T data);
    bool AddAtIndex(T data, int index);
    void AddBefore(Node<T>*, T data);
    void AddAfter(Node<T>*, T data);
    T RemoveFromFront();                        // forward declaring all of the methods that will be implemented below of the list
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);
    T RemoveBefore(Node<T>*);
    T RemoveAfter(Node<T>*);
    bool ElementExists(T data);
    Node<T>* Find(T data);
    int IndexOf(T data);
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);
    void PrintList();
    void Empty();
    int Length();


};
       


template <typename T>        
void LinkedList<T>::AddToFront(T data)          // adds Node to front of the list
{
    Node<T>* newNode = new Node(data);       

    if(head == NULL)
    {
        head = newNode;                         // if list is empty, the head and tail are same value(1 value only)
        tail = newNode;
    }

    else
    {
        head->prev = newNode;               // previous value of head is now newNode
        newNode->next = head;               // newNode's next is the head so now is in list
        newNode->prev = NULL;               // previous of NewNode is null since it's the head
        head = newNode;                     // newNode is new head

    }

    size++;                 // increment size of list

}

template <typename T>
void LinkedList<T>::AddToEnd(T data)            // adds Node to end of list
{
    Node<T>* newNode = new Node(data);

    if(head == NULL)
    {
        head = newNode;                     // if list is empty, then head and tail are equal
        tail = newNode;
    }

    else
    {
        tail->next = newNode;
        newNode->prev = tail;               // tail next is newNode, so previous of NewNode is now tail
        newNode->next == NULL;
        tail = newNode;                 // newNode is now new tail so next is NULL
    }

    size++;             // list size increment

}

template <typename T>
bool LinkedList<T>::AddAtIndex(T data, int index)
{
    Node<T>* newNode = new Node(data);

    if((index >= size) || (index < 0))
    {

        return false;                           // if index is out of bounds then false is returned
    }

    if(index == 0)
    {
        this->AddToFront(data);                 // if index is at beginning, AddToFront is called
        return true;
    }

    else if(index == (size - 1))
    {
        this->AddToEnd(data);                   // if index is at end, AddToEnd is called
        return true;                            // true is returned because func is of boolean type
    }

    else
    {

        Node<T>* currValue = head;              // else list traversal commences
        int i = 0;

        while(currValue != NULL)
        {
            if(i == index)
            {
                newNode->next = currValue;        // perform insertion operation by assigning the newNode to currValue's next value
                currValue->prev = newNode;              // now NewNode is next to currValue
                newNode->prev = currValue->prev;
                currValue->prev->next = newNode;
                break;
            }
            currValue = currValue->next;            // we loop till we find the desired index 
            i++;
        }                        
        
        

        size++;                         // increment size and return boolean

        return true;
    }
    

}

template <typename T>
void LinkedList<T>::AddBefore(Node<T>* n, T data)           
{
    Node<T>* newNode = new Node(data);

    Node<T>* currValue = head;

    for(int i = 0; i < this->Length() - 1; i++)
     {
            if(currValue == n)                          // same concept as before but now we see if target node is reached
            {
                newNode->prev = currValue->prev;        // if so, then previous of newNode is assigned to previous of currValue
                currValue->prev = newNode;
                size++;                                 // it takes the place before and size is incremented
            }

            currValue = currValue->next;            // traversal
     }
    

}

template <typename T>
void LinkedList<T>::AddAfter(Node<T>* n, T data)
{
    Node<T>* newNode = new Node(data);

    Node<T>* currValue = head;

    for(int i = 0; i < this->Length() - 1; i++)
     {
            if(currValue == n)
            {
                newNode->next = currValue->next;        // same exact concept as above
                currValue->next = newNode;              // however now it takes the "next" position instead
                size++;                             // size is now incremented
            }

            currValue = currValue->next;            // traversal through the next value of current node
     }
    
    
}

template <typename T>
T LinkedList<T>::RemoveFromFront()
{
    Node<T>* firstVal = head;
    
    if(head == NULL)
    {
        return head->data;              // if head is null, its value is returned
    }

    else
    {
        head = head->next;
        head->prev = NULL;              // otherwise head is reassigned, previous is now null, and that head is returned
        return firstVal->data;
        delete(firstVal);
    }

    size--;                         // size is decremented

}

template <typename T>
T LinkedList<T>::RemoveFromEnd()
{
    Node<T>* LastVal = tail;
    
    if(tail == NULL)
    {
        return tail->data;              // same concept as above, however, if tail is null, its data is returned
    }

    else
    {
        tail = tail->prev;
        tail->next = NULL;                  // otherwise tail is reassigned to previous value and its next is now null
        return LastVal->data;
        delete(LastVal);                // it is returned and size decrements again
    }

    size--;

}

template <typename T>
void LinkedList<T>::RemoveTheFirst(T data)
{
    
     Node<T>* currValue = head;

     Node<T>* temp = new Node<T>();



    int i = 0;
     

        while(i < this->Length() - 1)                   // walking throughout the entire list now
        {
            if(currValue == NULL)
            {
                break;
            }
            if(currValue->getData() == data)            // checking to see if target is reached
            {
                  if(i == 0)
                  {
                      RemoveFromFront();                    // if at beginning, helper function called
                               
                  }  

                  else if(i == this->Length() - 2)
                  {          
                      RemoveFromEnd();                      // if at end, helper function is called(no break because ALL)
                      
                  }

                  else
                  {     
                      temp = currValue;                         // storing current node in temp
                      temp->prev->next = temp->next;            // rearranging list with temp


                      delete(temp);                             // then deleting temp
                      size--;                        
                  }          
            }
            
             i++;                                   // tracker incremented and traversal continues
             currValue = currValue->next;  
        }

}


template <typename T>         
void LinkedList<T>::RemoveAllOf(T data)
{
    
     Node<T>* currValue = head;

     Node<T>* temp = new Node<T>();             // creating a temp node variable to hold the contents of
                                                // currValue when needed 


    int i = 0;
     

        while(i < this->Length() - 1)                   // walking throughout the entire list now
        {
            if(currValue == NULL)                       // if NULL is encountered, then end of list is reached
            {
                break;
            }
            if(currValue->getData() == data)            // checking to see if target is reached
            {
                  if(i == 0)
                  {
                      RemoveFromFront();                    // if at beginning, helper function called
                               
                  }  

                  else if(i == this->Length() - 2)
                  {          
                      RemoveFromEnd();                      // if at end, helper function is called(no break because ALL)
                      
                  }

                  else
                  {     
                      temp = currValue;                 // else the temp is assigned the current node, and rearrangement takes place
                      temp->prev->next = temp->next;


                      delete(temp);
                      size--;                        
                  }          
            }
            
             i++;                                   // tracker incremented and traversal continues
             currValue = currValue->next;  

            
        }


}

template <typename T>
T LinkedList<T>::RemoveBefore(Node<T>* n)
{
    
     Node<T>* currValue = head;

     Node<T>* holder = new Node<T>();

     

        for(int i = 0; i < this->Length() - 1; i++)         // looping through list
        {
            if(currValue == n)
            {
                  if(currValue->prev == head)           // if target is reached, and if at beginning, helper function is called
                  {
                      RemoveFromFront();
                  }  


                  else
                  {
                      holder = currValue;
                      return currValue->prev->data;         // else the removed node's contents are returned
                      delete(currValue->prev);              // that node is deleted and helper variable assists with rearranging the list
                      holder->prev->prev->next = holder;
                      size--;                                   // size is decremented
                  }
            }
            currValue = currValue->next;            // traversing the list
        }


}


template <typename T>
T LinkedList<T>::RemoveAfter(Node<T>* n)
{
    
     Node<T>* currValue = head;

     Node<T>* holder = new Node<T>();

     

        for(int i = 0; i < this->Length() - 1; i++)
        {
            if(currValue == n)
            {                                       // same concept as last method, as we check for target node 

                  if(currValue->next == tail)
                  {
                      RemoveFromEnd();              // if at the end, helper method is called and action is performed
                  }

                  else
                  {
                      holder = currValue;
                      return currValue->next->data;             // otherwise, the removed node is removed
                      delete(currValue->next);
                      holder->next = holder->next->next;        // the next value of the removed node, stored in helper, is now fixed
                      size--;                                   // size decrements
                  }
            }
            currValue = currValue->next;                // traversing the list
        }


}


template <typename T>
bool LinkedList<T>::ElementExists(T data)
{
    
     Node<T>* currValue = head;


     

        while(currValue != NULL)
        {
            if(currValue->getData() == data)                    // looping through list and if element occurs, then true is returned
            {
                return true;
            } 
              
            currValue = currValue->next;                // continue looping through the list
        }

        return false;                               // if not found, then false is returned


}


template <typename T>
Node<T>* LinkedList<T>::Find(T data)
{
    
     Node<T>* currValue = head;


     

        while(currValue != NULL)
        {
            if(currValue->getData() == data)                // looping through list and if zombie is found then that node is returned
            {
                return currValue;
            } 
              
            currValue = currValue->next;                // otherwise we continue looping as normal
        }

       


}

template <typename T>
int LinkedList<T>::IndexOf(T data)
{
    
     Node<T>* currValue = head;
     int index = 0;

     

        while(currValue != NULL)
        {
            if(currValue->getData() == data)            // loop throughout the list and if target zombie is found, its index in list is returned
            {
                return index;
                break;
            } 

            index++;
            currValue = currValue->next;                // otherwise the looping through continues as usual
        }
        
        return index;


}

template <typename T>
T LinkedList<T>::RetrieveFront()
{
    
     Node<T>* currValue = head;                     // the head value is stored, and it's zombie value is returned

    return currValue->data;


}

template <typename T>
T LinkedList<T>::RetrieveEnd()
{
    
     Node<T>* currValue = tail;                     // the tail value is stored, and its zombie value is returned

    return currValue->data;


}

template <typename T>
T LinkedList<T>::Retrieve(int index)
{
    Node<T>* currValue = head;
    int i = 0;
    
    if(index >= size || index < 0)                  // if desired index is out of bounds, then exception is thrown
    {
        throw "index out of bounds exception";
    }


    else
    {
        while(currValue != NULL)
        {
            if(i == index)                              // otherwise we loop throughout the list
            {
                return currValue->data;                 // if index is found, tyhat index's zombie value is returned
                i++;
            } 
              
            currValue = currValue->next;                 // if not found, then traversal continues
        }
    }
    


}

template <typename T>
void LinkedList<T>::PrintList()
{ 
    Node<T>* currValue = head;
    

    while(currValue != NULL)            // loop through the contents of the list here
    {
        
        cout << currValue->data;                // since we overloaded the cout << in zombie class, it will print the color of the zombie here
              
        currValue = currValue->next;            // traversal through list with help of head value
    }
    
    
    

}

template <typename T>
void LinkedList<T>::Empty()
{
    Node<T>* currValue = head;
    

    while(currValue != NULL)               // loop through entire list
    {
        
        delete(currValue);                          // perform deletion operation on every value of list
              
        currValue = currValue->next;                // traversal with help of head->next
    }
    

}

template <typename T>
int LinkedList<T>::Length()
{
    Node<T>* currValue = head;
    
    int accum = 0;                                  // accum variable to keep track of list nodes

    while(currValue != NULL)
    {
        accum++;                            // as long as the current var isn't null, counter is incremented
        currValue = currValue->next;
    }          
    
    return accum;                       // return total length of list here

}

#endif