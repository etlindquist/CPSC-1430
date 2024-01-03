//OrderedList.h
//This program declares the methods of the OrderedList class

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <iostream>

using namespace std;
class OrderedList {
    private:
        struct Node{
            int value;
            Node *next;
        };
        Node* head;
    public:
        OrderedList();
        OrderedList(OrderedList &);
        ~OrderedList();
        void insert(int);
        void printList();
};
#endif
