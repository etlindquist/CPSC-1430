#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next = nullptr;
};

class Stack{
    public:
    Stack();
    ~Stack();
    void add(int);
    int remove();
    bool isEmpty();

    private:
    Node *head = nullptr;
};