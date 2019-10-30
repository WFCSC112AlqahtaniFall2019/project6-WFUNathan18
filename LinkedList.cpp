#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    cout << "-Calling Constructor-" << endl;
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList &origList) {
    cout << "-Calling Copy Constructor-" << endl;
    Node* cursor = origList.head;
    while(cursor != nullptr) {
        Append(cursor ->value);
        cursor = cursor ->next;
    }
}

LinkedList::~LinkedList() {
    cout << "-Calling Destructor-" << endl;
    Node* cursor = head;
    while(cursor != nullptr) {
        cursor = cursor ->next;
        head ->next = nullptr;
        delete head;
        head = cursor;
    }
}

bool LinkedList::IsItem(int item) const {
    cout << "-Looking for Item in List-" << endl;
    Node* cursor = head;
    while (cursor != nullptr) {
        if (cursor ->value == item) {
            cout << "-Item Found-" << endl;
            return true;
        }
        cursor = cursor ->next;
    }
    cout << "-Item Not Found-" << endl;
    return false;
}

void LinkedList::Append(int item) {
    cout << "-Appending Node-" << endl;
    if (head == nullptr) { //If list is empty
        head = new Node(item); //Update head
    }
    else {
        Node* cursor = head; //Otherwise
        while (cursor ->next != nullptr) //Traverse to end of list
            cursor = cursor ->next;
        cursor ->next = new Node(item); //Create new node
    }
}

bool LinkedList::Remove(int item) {
    cout << "-Attempting to Remove Node-" << endl;
    if (head == nullptr) { //If list is empty
        cout << "-Attempt Failed-" << endl;
        return false; //Do nothing
    }

    Node* current = head;
    Node* previous;

    if (head ->value == item) { //If first node of list
        head = head ->next; //Make head point to second node
        current ->next = nullptr; //Disconnect from list
        delete current; //Delete
        cout << "-Attempt Successful-" << endl;
        return true;
    }

    while (current) {
        if (current ->value == item) { //If not head of list
            previous ->next = current ->next; //Make previous node point to next node
            current ->next = nullptr; //Disconnect
            delete current; //Delete
            cout << "-Attempt Successful-" << endl;
            return true;
        }
        previous = current;
        current = current -> next;
    }

    cout << "-Attempt Failed-" << endl;
    return false; //If item not in list, do nothing
}

LinkedList& LinkedList::operator=(LinkedList rhs) {
    cout << "-Calling Assignment Operator-" << endl;
    swap(head, rhs.head);
    return *this;
}

void LinkedList::PrintList() const {
    Node* cursor = head;
    cout << "-Printing List-" << endl;
    if (!cursor)
        cout << "-List is Empty-" << endl;
    else {
        while (cursor) {
            cout << cursor ->value << " ";
            cursor = cursor ->next;
        }
    }
}

void LinkedList::ListInsertionSort() {
    cout << "-Sorting List-" << endl;

}