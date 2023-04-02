/** @file Node.cpp */
#include "Node.h"
#include <cstddef>
#include <string>

template <class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor
template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
{
} // end constructor
template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr) :
    item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
} // end constructor
template <class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
} // end setItem
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

template <class ItemType>
void Node<ItemType>::setPrevious(Node<ItemType>* prevNodePtr)
{
    prev = prevNodePtr;
} // end setNext


template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
} // end getItem
template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
} // end getNext

template <class ItemType>
Node<ItemType>* Node<ItemType>::getPrevious() const
{
    return prev;
} // end getPrevious
