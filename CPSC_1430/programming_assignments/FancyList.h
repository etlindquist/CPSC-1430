//FancyList.h
//Eric Lindquist
//11/5/23
#include <iostream>
using namespace std;


struct Node{
    int value;
    Node *next = nullptr;
};
class FancyList{
    public:
    FancyList();
    ~FancyList();
    void displayList();
    void reverseList();
    void deleteNode();
    void deleteNode(int);
    void insertNode();

    private:
    int menu();
    bool isInt(string);
    int size = 0;
    Node *head = nullptr;
    Node *last = nullptr;
};