//Programmer: Catherine Stringfellow AND Joachim Isaac
//File: List.cpp
//Date:

//working.
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

//working.
template <class ItemType>
List<ItemType>::List(List &other)
{

    ItemType Item;
    ListNode *temp;

    //construct empty list - same code as in default constructor goes here
    ListNode *dummy;
    dummy = new ListNode;
    dummy->next = nullptr;
    this->head = dummy;
    this->cursor = dummy;
    this->count = 0;

    //copy items in other to this list
    other.cursor = other.head;
    while (other.cursor->next != NULL)
    {
        Item = other.cursor->next->item;

        temp = new ListNode;
        temp->item = Item;
        temp->next = cursor->next;
        cursor->next = temp;
        count++;

        other.cursor = other.cursor->next;
        cursor = cursor->next;
    }
}

template <class ItemType>
void List<ItemType>::printListtest()
{
    if (count == 0)
    {
        cout << "This list is empty\n";
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
    ListNode *temp;
    ResetCursor();
    temp = cursor;
    //starting at head of list, delete all nodes
    while (temp != nullptr)
    {
        cursor = cursor->next;
        delete temp;
        temp = cursor;
    }
    // dispose of dummy node
    head = cursor = nullptr;

} // destructor

//working
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

//working
template <class ItemType>
void List<ItemType>::ClearList()
{
    ResetCursor();
    while (!CursorAtEnd())
        DeleteItem();
}

//working
template <class ItemType>
void List<ItemType>::ResetCursor()
{

    this->cursor = head;

} // reset cursor

//working
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

//working!.
template <class ItemType>
void List<ItemType>::GetCurrentItem(ItemType &Item)
{
    if (cursor->next != nullptr)
        Item = cursor->next->item;
    else
        cout << "ERROR : cursor at end cannot get current item" << endl;

} // get current item

//working!
template <class ItemType>
void List<ItemType>::UpdateCurrentItem(const ItemType &Item)
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot get current item" << endl;
    else
        cursor->next->item = Item;
} // get current item

//working..
template <class ItemType>
void List<ItemType>::AdvanceCursor()
{
    if (cursor->next == NULL)
        cout << "ERROR : cursor at end cannot advance cursor" << endl;
    else
        cursor = cursor->next;
} // advance cursor

//working!
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

//working!
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
