#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"

class LinkedList {
public:
    LinkedList(); //Constructor
    LinkedList(const LinkedList &origList); //Copy Constructor
    ~LinkedList(); //Destructor
    bool IsItem(int item) const; //Searches if an item is in the list
    void Append(int item); //Adds to list
    bool Remove(int item); //Remove from list
    LinkedList &operator= (const LinkedList); //Copy Assignment Operator
    void PrintList() const; //Prints contents of the list
    void ListInsertionSort(int item);
private:
    Node *head; //Beginning of the Linked List
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
