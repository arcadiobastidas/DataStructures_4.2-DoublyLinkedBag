#include "DoublyLinkedBag.h"
#include<iostream>
using namespace std;

template <class T>
DoublyLinkedBag<T>::DoublyLinkedBag()
{
    headPtr = tailPtr = nullptr;
    itemCount = 0;
}

template <class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
    clear();
} // end destructor

template <class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
} // end isEmpty

template <class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
} // end getCurrentSize

template <class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is null if chain is empty) 
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newEntry);
    nextNodePtr->setNext(headPtr); // New node points to chain
    nextNodePtr->setPrevious(nullptr);

    //if head is not null, set it's previous
    if (headPtr != nullptr)
        headPtr->setPrevious(nextNodePtr);
    //Set current node as null
    headPtr = nextNodePtr; // New node is now first node

    //if tail is null, set it as headPtr
    if (tailPtr == nullptr)
        tailPtr = headPtr;

        //if tailPtr->prev is null, set it as head
    else if (tailPtr->getPrevious() == nullptr)
    {
        tailPtr->setPrevious(headPtr);
    }
    itemCount++;
    return true;
} // end add

template <class ItemType>
vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
{
    vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    } // end while
    return bagContents;
} // end toVector

template <class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        headPtr->setPrevious(nullptr);

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        nodeToDeletePtr->setPrevious(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCount--;
    } // end if
    return canRemoveItem;
} // end remove


template <class ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();
        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
    } // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr
    itemCount = 0;
} // end clear
template <class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        } // end if
        counter++;
        curPtr = curPtr->getNext();
    } // end while
    return frequency;
} // end getFrequencyOf

template <class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
} // end contains
// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template <class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    while (!found && (curPtr != nullptr))
    {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while
    return curPtr;
} // end getPointerTo


//Prints the contents of bag in forward direction
template <class ItemType>
void DoublyLinkedBag<ItemType>::printForward()
{
    Node<ItemType>* current = headPtr;
    while (current != nullptr)
    {
        cout << current->getItem() << " ";
        current = current->getNext();
    }
    cout << endl;
}

//Prints the contents of bag in backward direction
template <class ItemType>
void DoublyLinkedBag<ItemType>::printBackwards()
{
    Node<ItemType>* current = tailPtr;
    while (current != nullptr)
    {
        cout << current->getItem() << " ";
        current = current->getPrevious();
    }
    cout << endl;
}

//rightRotate: A function that rotates the list's contents from the right to one place, given a specific element.
template <class ItemType>
void DoublyLinkedBag<ItemType>::rightRotate(ItemType element)
{
    if (itemCount <= 1)
        return;

    Node<ItemType>* current = headPtr;
    Node<ItemType>* prev = nullptr;
    Node<ItemType>* next = nullptr;

    while (current != nullptr)
    {
        if (current->getItem() == element)
        {
            next = current->getNext();
            prev = current->getPrevious();
            if (next != nullptr)
            {
                next->setPrevious(prev);
                if (prev != nullptr)
                {
                    prev->setNext(next);
                }
                else
                {
                    headPtr = next;
                }
                current->setNext(nullptr);
                current->setPrevious(tailPtr);
                tailPtr->setNext(current);
                tailPtr = current;
            }
            return;
        }
        current = current->getNext();
    }
}

//leftRotate: A function that rotates the list's contents from left to one place, given a specific element.
template <class ItemType>
void DoublyLinkedBag<ItemType>::leftRotate(ItemType element)
{
    if (itemCount <= 1)
        return;

    Node<ItemType>* current = headPtr;
    Node<ItemType>* prev = nullptr;
    Node<ItemType>* next = nullptr;

    while (current != nullptr)
    {
        if (current->getItem() == element)
        {
            next = current->getNext();
            prev = current->getPrevious();
            if (prev != nullptr)
            {
                prev->setNext(next);
                if (next != nullptr)
                {
                    next->setPrevious(prev);
                }
                else
                {
                    tailPtr = prev;
                }
                current->setPrevious(nullptr);
                current->setNext(headPtr);
                headPtr->setPrevious(current);
                headPtr = current;
            }
            return;
        }
        current = current->getNext();
    }
}
