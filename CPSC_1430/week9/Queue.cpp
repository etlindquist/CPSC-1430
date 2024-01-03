#include "Queue.h"
Queue::Queue(){

}
Queue::~Queue(){
    QNode *ptr = head;
    while(ptr){
        QNode *temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}
void Queue::enqueue(int value){
    if(head == nullptr){
        head = new QNode;
        head->val = value;
    }
    else{
        QNode *ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = new QNode;
        ptr->next->val = value;
    }
}
int Queue::dequeue(){
    if(!isEmpty()){
        int output = head->val;
        QNode *temp = head->next;
        delete head;
        head = temp;
        return output;
    }
    return -1;
}
bool Queue::isEmpty(){
    return head==nullptr;
}