

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "AddressBook.h"

string getName();
string getPhone();
void isFull(const Addressbook&);
void isEmpty(const Addressbook&);

int main()
{
    Addressbook a;
    char choice;
    
    do
    {
        string name, phone;
        
        cout << "A-dd Contact\n";
        cout << "R-emove Contact\n";
        cout << "F-ind Contact\n";
        cout << "C-lear Contacts\n";
        cout << "E-isEmpty\n";
        cout << "U-isFull\n";
        cout << "Q-uit\n";
        cout << "> ";
        
        cin >> choice;
        cin.ignore();
        
        switch(choice)
        {
            case 'A':
            case 'a':
                name = getName();
                phone = getPhone();
                a.add(name, phone);
                break;
            case 'R':
            case 'r':
                name = getName();
                a.remove(name);
                break;
            case 'F':
            case 'f':
                name = getName();
                cout << a.find(name) << endl;
                break;
            case 'C':
            case 'c':
                a.clear();
                break;
            case 'E':
            case 'e':
                isEmpty(a);
                break;
            case 'U':
            case 'u':
                isFull(a);
                break;
        }
    } while(choice != 'Q' && choice != 'q');
}

string getName()
{
    string n;
    
    cout << "Enter contact's name: ";
    getline(cin, n);
    
    return n;
}

string getPhone()
{
    string p;
    
    cout << "Enter contact's number: ";
    getline(cin, p);
    
    return p;
}

void isFull(const Addressbook& r)
{
    if(r.isFull())
        cout << "AddressBook is full.\n";
    else
        cout << "AddressBook isn't full.\n";
}


void isEmpty(const Addressbook& r)
{
    if(r.isEmpty())
        cout << "AddressBook is empty.\n";
    else
        cout << "AddressBook isn't empty.\n";
}