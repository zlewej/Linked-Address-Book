/*****************
 Julius A. Garma
 Hank Stalica
 CS 3240
 Linked-Address-Book
 *****************/

#ifndef linkedAddyBook_Header_h
#define linkedAddyBook_Header_h
#include <iostream>
#include <string>
using namespace std;

class Addressbook
{
    private:
        /*********************
         Nested Struct Contact
         *********************/
        struct Contact
        {
            string name;
            string phone;
            Contact *next;  // points to the next node
        };
    Contact *list; // head pointer
    
    public:
    Addressbook()
    { list = nullptr; }
    ~Addressbook();
    bool isEmpty() const;
    bool isFull() const;
    void add(string, string);
    void remove(string);
    void clear();
    string find(string);
};

/**********************
 CLASS MEMBER FUNCTIONS
 **********************/

/*****************************************
            ~Addressbook
 Frees memory allocated by the AddressBook
 object
 *****************************************/
Addressbook::~Addressbook()
{
    clear();
}

/*******************************
            IsEmpty
 returns true if list is NULL
 false otherwise
 *******************************/
bool Addressbook::isEmpty() const
{
    if(list == nullptr)
    {
        return true;
    }
    return false;
}

/************************************************
                    isFull
 checks to see if theres enough memory to
 creat a new Contact by creating a temp node
 ptrNode using dynamic allocation. If successful,
 deletes Contact then returns true, false
 otherwise
 ************************************************/
bool Addressbook::isFull() const
{
    Contact *ptrNode;
    ptrNode = new Contact; // dummy Contact
    
    if(ptrNode == nullptr)
    {
        return true;
    }
    else
    {
        delete ptrNode;
        return false;
    }
    
}

/*****************************************
                    add
 accepts phone number and a name 
 to add to the list. Stores info in a 
 dynamically allocated Contact and appends
 it to the list
 *****************************************/
void Addressbook::add(string n, string p)
{
    Contact *newNode;
    Contact *currentNode;
    Contact *prevNode;
    
    newNode = new Contact;      // allocates a new node
    newNode->name = n;
    newNode->phone = p;
    newNode->next = nullptr;
    
    if(isEmpty())
    {
        list = newNode; // makes newNode first in the list
    }
    else{
        
        currentNode = list;
        prevNode = nullptr;
        
        while(currentNode != nullptr && n > currentNode->name)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        
        if(prevNode == nullptr)
        {
            newNode->next = list;
            list = newNode;
        }
        else{
            
            prevNode->next = newNode;
            newNode->next = currentNode;
        }
    }
}

/********************************************
                    Remove
 searches list for the name and removes first
 matching Contact in the list if found
 ********************************************/
void Addressbook::remove(string n)
{
    Contact *currentNode;
    Contact *prevNode;
    
    currentNode = list;
    prevNode = nullptr;
    
    if(isEmpty())
    {
        return;
    }

    while((currentNode != nullptr) && (currentNode->name != n))
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
        
    }
    
    if(currentNode == nullptr)
    {
        return;
    }
    else if(prevNode == nullptr)
    {
        list = list->next;
        delete currentNode;
    }
    else
    {
        prevNode->next = currentNode->next;
        delete currentNode;
    }
}

/*********************************************
                    Clear
 frees all memory created by AddressBook object
 and sets list to NULL
 *********************************************/
void Addressbook::clear()
{
    Contact *currentNode;
    
   while(list != nullptr)
   {
       currentNode = list;
       list = list->next;
       delete currentNode;
   }
}

/*******************************************
                    find
 searches Contact List and returns the phone
 number of the first matching
 *******************************************/
string Addressbook::find(string n)
{
    Contact *currentNode = list;
    string number = "NONE FOUND";
    bool found = false;
    
    while(currentNode != nullptr && !found)
    {
        if(currentNode->name == n)
        {
            found = true;
            number = currentNode->phone;
        }
        currentNode = currentNode->next;
    }
    return number;
}


#endif
