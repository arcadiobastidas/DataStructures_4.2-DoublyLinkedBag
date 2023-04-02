#include<iostream>
#include "BagInterface.h"
#include "DoublyLinkedBag.h"
#include "DoublyLinkedBag.cpp"
#include "Node.cpp"
using namespace std;

int getChoice()
{
    int choice;
    cout << "1- Print List of numbers\n";
    cout << "2- Remove an item from list\n";
    cout << "3- Print list in both directions\n";
    cout << "4- Rotate an element right\n";
    cout << "5- Rotate an element Left\n";
    cout << "6- Exit\n";
    cout << "Enter Your choice: ";
    cin >> choice;
    while (choice < 1 || choice > 6)
    {
        cout << "ERROR! Invalid choice\n";
        cout << "Enter again: ";
        cin >> choice;
    }
    return choice;
}

int main()
{
    DoublyLinkedBag<int> bag;
    bag.add(1);
    bag.add(2);
    bag.add(3);
    bag.add(4);
    bag.add(5);

    int choice;
    int num;
    do
    {
        choice = getChoice();
        if (choice == 1)
        {
            cout << "List is: " << endl;
            cout << bag;
        }
        else if (choice == 2)
        {
            cout << "Enter number to remove: ";
            cin >> num;
            bag.remove(num);
        }
        else if (choice == 3)
        {
            cout << "List printed forward is: " << endl;
            bag.printForward();
            cout << "List printed backward is: " << endl;
            bag.printBackwards();
        }
        else if (choice == 4)
        {
            cout << "Enter the number to rotate right: ";
            cin >> num;
            bag.rightRotate(num);
            cout << bag;
        }
        else if (choice == 5)
        {
            cout << "Enter the element to rotate left: ";
            cin >> num;
            bag.leftRotate(num);
            cout << bag;
        }
        else if (choice == 6)
        {
            cout << "Exiting program";
            exit(0);
        }
    }
    while (choice <= 6);
}
