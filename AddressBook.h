
/*****************************
 Julius A. Garma
 CS 3240
 Hank Stalica
 AddressBook.h
 *******************************/

#ifndef AddressBook_AddressBook_h
#define AddressBook_AddressBook_h
#include <string>
#include <iostream>
using std::string;
using namespace std;

class AddressBook
{
private:
    struct Contact
    {
        string name;
        string phone;
        bool used;
    };
    Contact *list; // pointer to the Contract structure
    int cap;       // stores number of elements in array
    
public:
    AddressBook(int);   // constructor
    ~AddressBook();     // destructor
    bool isEmpty() const;
    bool isFull() const;
    void add(string, string);
    void remove(string);
    void clear();
    string find(string) const;
    
};

/************************************
 CLASS MEMBER FUNCTIONS
 ************************************/

AddressBook::AddressBook(int num)
{
    cap = num;                                 // number of elements in array
    list = new Contact[num];
    for(int count = 0; count < num; count++) // initializes all Contact used fields to false
    {
        list[count].used = false;
    }
}

AddressBook::~AddressBook()
{
    delete [] list;
}

bool AddressBook::isEmpty() const
{
    bool found = true;
    int count = 0;
    
    while(count < cap && found)
    {
        if(list[count].used)
        {
            found = false;
        }
        count++;
    }
    return found;
}

bool AddressBook::isFull() const
{
    bool found = true;
    int count = 0;
    
    while(found && count < cap)
    {
        if(list[count].used)
        {
            found = false;
        }
        count++;
    }
    return found;
}

void AddressBook::add(string n, string p)
{
    for(int count = 0; count < cap; count++)
    {
        list[count].name = n;
        list[count].phone = p;
        list[count].used = true;
    }
}

void AddressBook::remove(string n) // perform a linear search
{
    if(!isEmpty())
    {
        bool found = false;
        int count = -1;
        
        while(count < cap && !found)
        {
            count++;
            if(list[count].name == n && list[count].used)
            {
                found = true;
            }
        }
        
        list[count].used = false;
    }
}

void AddressBook::clear()
{
    int count = 0;
    
    while(count < cap)
    {
        list[count].used = false;
        count++;
    }
}

string AddressBook::find(string n) const
{
    for(int count = 0; count < cap; count++)
        if(list[count].name == n)
        {
            return list[count].phone;
        }
    return "\nNO MATCH\n";
}



#endif
