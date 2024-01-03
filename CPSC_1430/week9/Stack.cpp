#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(){}
Stack::~Stack(){}
void Stack::add(int value){
    Node *temp = new Node;
    temp->next = head;
    temp->val = value;
    head = temp;
}
int Stack::remove(){
    if(!isEmpty()){
        int output = head->val;
        Node *temp = head->next;
        delete head;
        head = temp;
        return output;
    }
    return -1;
}
bool Stack::isEmpty(){
    return head==nullptr;
}