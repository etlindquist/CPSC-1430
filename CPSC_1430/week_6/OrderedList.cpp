//OrderedList.cpp
//Eric Lindquist
//10/31/23
//This program implements the methods in the OrderedList class

#include <iostream>
#include "OrderedList.h"
using namespace std;

OrderedList::OrderedList(){
    head = nullptr;
}

//Thism ethod overrides the default copy constructor to avoid multiple methods pointing to the same memory adresses on the heap
OrderedList::OrderedList(OrderedList &l){
    if(l.head){
        head = new Node;
        Node *ptr = head;
        Node *lPtr = l.head;
        ptr->value = lPtr->value;
        ptr->next = nullptr;
        lPtr = lPtr->next;
        while(lPtr){
            ptr->next = new Node;
            ptr = ptr->next;
            ptr->value = lPtr->value;
            ptr->next = nullptr;
            lPtr = lPtr->next;
        }
    }
}

//This method deletes all memory allocated on the heap
OrderedList::~OrderedList(){
    cout << "\n\n\nDeallocating...";
    Node *ptr = head;
    Node *altPtr = nullptr;
    while(ptr){
        altPtr = ptr->next;
        cout << "\n\nDeleting " << ptr->value;
        delete ptr;
        ptr = altPtr;
    }
}

//prints the values of the list, providing two spaces between each value
void OrderedList::printList(){
    Node *ptr = head;
    while(ptr){
        cout << ptr->value << "  ";
        ptr = ptr->next;
    }
}

//This class allows you to insert a value to the list
void OrderedList::insert(int val){
    //If this is the first value being added
    if(!head){
        head = new Node;
        head->value = val;
        head->next = nullptr;
    }
    else{
        Node *ptr = head;
        Node *prev = nullptr;
        //navigating to the correct position
        while(ptr->value<val && ptr->next){
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr->value>val){
            //If this is the first value
            if(head == ptr){    
                head = new Node;
                head->next = ptr;
                head->value = val;
            }
            //a value in the middle
            else{
                prev->next = new Node;
                prev->next->value = val;
                prev->next->next = ptr;
            }
        }
        //if this is the last value
        else{
            ptr->next = new Node;
            ptr->next->value = val;
            ptr->next->next = nullptr;
        }
    }
}