/** ADT bag: Link-based implementation.
@file LinkedBag.h */
#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG
#include <iostream>

#include "BagInterface.h"
#include "Node.h"


using namespace std;

template <class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node
    int itemCount; // Current count of bag items
    Node<ItemType>* tailPtr;
    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    DoublyLinkedBag();

    virtual ~DoublyLinkedBag(); // Destructor should be virtual
    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const ItemType& newEntry) override;
    bool remove(const ItemType& anEntry) override;
    void clear() override;
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const override;
    vector<ItemType> toVector() const override;

    void printForward();
    void printBackwards();
    void rightRotate(ItemType n);
    void leftRotate(ItemType n);


    friend ostream& operator<<(ostream& os, const DoublyLinkedBag<ItemType>& bag)
    {
        Node<ItemType>* current = bag.headPtr;
        while (current != nullptr)
        {
            os << current->getItem() << " ";
            current = current->getNext();
        }
        os << endl;
        return os;
    }
}; // end LinkedBag
#endif
