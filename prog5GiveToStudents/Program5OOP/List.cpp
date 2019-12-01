//Programmer: Catherine Stringfellow AND Joachim Isaac
//File: List.cpp
//Date:

// #include "List.h"

template <class ItemType>
List<ItemType>::List()
{
    ListNode *dummy;
    dummy = new ListNode;
    dummy->next = nullptr;
    this->head = dummy;
    this->cursor = dummy;
    this->count = 0;

} //  defaultconstructor

// List::List(List &other)
// {

//     ItemType Item;
//     ListNode *temp;

//     //construct empty list - same code as in default constructor goes here

//     //copy items in other to this list
//     other.cursor = other.head;
//     while (other.cursor->next != NULL)
//     {
//         Item = other.cursor->next->item;

//         temp = new ListNode;
//         temp->item = Item;
//         temp->next = cursor->next;
//         cursor->next = temp;
//         count++;

//         other.cursor = other.cursor->next;
//         cursor = cursor->next;
//     }
// }

template <class ItemType>
void List<ItemType>::printListtest()
{
    if (count == 0)
    {
        cout << "This list is empty";
    }

    ListNode *tmp;
    tmp = this->head->next;
    while (tmp != nullptr)
    {
        cout << tmp->item << "  -->  ";
        tmp = tmp->next;
    }
}

template <class ItemType>
List<ItemType>::~List()
{
    // ListNode *temp;

    //starting at head of list, delete all nodes

    // dispose of dummy node

} // destructor

template <class ItemType>
void List<ItemType>::SwapLists(List &other)
{
    ListNode *temp;
    int tempCount;

    //swap cursors
    temp = cursor;
    cursor = other.cursor;
    other.cursor = temp;

    //swap heads
    temp = head;
    head = other.head;
    other.head = temp;

    //swap counts
    tempCount = count;
    count = other.count;
    other.count = count;
}

template <class ItemType>
void List<ItemType>::ClearList()
{
    ResetCursor();
    while (!CursorAtEnd())
        DeleteItem();
}

template <class ItemType>
void List<ItemType>::ResetCursor()
{

    this->cursor = head->next;

} // reset cursor

template <class ItemType>
bool List<ItemType>::CursorAtEnd()
{
    if (cursor->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

} // cursor at end

// template <class ItemType>
// void List<ItemType>::GetCurrentItem(ItemType &Item)
// {

// } // get current item

// template <class ItemType>
// void List<ItemType>::UpdateCurrentItem(const ItemType &Item)
// {
//     if (cursor->next == NULL)
//         cout << "ERROR : cursor at end cannot get current item" << endl;
//     else
//         cursor->next->item = Item;
// } // get current item

template <class ItemType>
void List<ItemType>::AdvanceCursor()
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot advance cursor" << endl;
    else
        cursor = cursor->next;
} // advance cursor

template <class ItemType>
void List<ItemType>::InsertItem(const ItemType &Item)
{
    ListNode *temp;
    if (cursor != head)
    {
        ResetCursor();
    }

    if (count == 0)
    {
        temp = new ListNode;
        temp->item = Item;
        temp->next = nullptr;
        cursor->next = temp;
    }
    else
    {
        temp = new ListNode;
        temp->item = Item;
        temp->next = cursor->next;
        cursor->next = temp;
    }

    count++;
}

template <class ItemType>
void List<ItemType>::DeleteItem()
{

    ListNode *temp;

    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot delete item" << endl;
    else
    {
        temp = cursor->next;
        cursor->next = temp->next;
        delete temp;
        count--;
    }
} // delete item

template <class ItemType>
int List<ItemType>::getCount()
{
    return this->count;
}
