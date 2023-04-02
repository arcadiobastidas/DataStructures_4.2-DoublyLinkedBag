#ifndef _NODE
#define _NODE
using namespace std;

template <class ItemType>
class Node
{
private:
    ItemType item; // A data item
    Node<ItemType>* next; // Pointer to next node
    Node<ItemType>* prev; // Pointer to previous node

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prev);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    void setPrevious(Node<ItemType>* prevNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
    Node<ItemType>* getPrevious() const;
}; // end Node
#endif
