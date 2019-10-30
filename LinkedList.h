#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"

class LinkedList {
public:
    LinkedList(); //Constructor
    LinkedList(const LinkedList &origList); //Copy Constructor
    ~LinkedList(); //Destructor
    bool IsItem(int item) const; //Searches if an item is in the list
    void Append(int item); //Adds to end of list
    bool Remove(int item); //Remove from list
    LinkedList &operator= (LinkedList rhs); //Copy Assignment Operator
    void PrintList() const; //Prints contents of the list
    void ListInsertionSort();
private:
    Node* head; //Beginning of the Linked List
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
