//FancyList.cpp
//Eric Lindquist
//11/5/23
#include <iostream>
#include "FancyList.h"
using namespace std;

//constructor
FancyList::FancyList(){
    int x = 0;
    while(x != 5){
        x = menu();
        if(x == 1){
            insertNode();
        }
        else if(x == 2){
            displayList();
        }
        else if(x == 3){
            reverseList();
        }
        else if(x == 4){
            deleteNode();
        }
    }
}

//destructor
FancyList::~FancyList(){
    Node *ptr = head;
    while(ptr){
        Node *temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    head = nullptr;
}

//is the input an integer?
bool FancyList::isInt(string str){
    if(str == "x") return false;
    for (int i = 0; i < str.length(); i++) {
        if(!isdigit(str[i]) && str[i]!='-'){
            cout << "Invalid insert of " <<str << " attempted!" << endl;
            return false;
        }
    }
    int x = stoi(str);
    return true;
}

//menu message for user
int FancyList::menu(){
    int x = 0;
    cout << "********* FancyList Menu *********" << endl;
    cout << "1. Create a list" << endl;
    cout << "2. Display the list" << endl;
    cout << "3. Reverse the list" << endl;
    cout << "4. Delete the n-th node from the end of the list" << endl;
    cout << "5. Exit the program" << endl;
    cout << "\nEnter your choice: ";
    string input;
    cin >> input;
    if(isInt(input)){
        x = stoi(input);
    }
    return x;
}

//add a node at the end of the list
void FancyList::insertNode(){
    string input = "Hello world!";
    while(input != "x"){
        cout << "Type a number for appending (type x to stop): ";
        cin >> input;
        if(isInt(input)){
            int val = stoi(input);
            if(!head){
                head = new Node;
                head->value = val;
            }
            else{
                Node *ptr = head;
                while(ptr->next){
                    ptr = ptr->next;
                }
                ptr->next = new Node;
                ptr->next->value = val;
            }
            size++;
        }
    }
}

//print the list to the console
void FancyList::displayList(){
    Node *ptr = head;
    cout << "Current list is: ";
    while(ptr){
        cout << ptr->value << "  ";
        ptr = ptr->next;
    }
    cout << "\n\n";
}

//reverse the order of the list
void FancyList::reverseList(){
    Node *curr = head;
    Node *prev = nullptr;
    while(curr){
        Node *temp = curr;
        curr = curr->next;
        temp->next = prev;
        prev = temp;
    }
    head = prev;
}

//delete the nth node
void FancyList::deleteNode(){
    string input;
    cout << "Delete n-th node from the end of the list, your n is: ";
    cin >> input;
    if(isInt(input)){
        int n = stoi(input);
        Node *ptr = head;
        Node *prev;
        for(int i = 0; i<size-n; i++){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        delete ptr;
        size--;
    }
}

//delete the nth node
void FancyList::deleteNode(int n){
    Node *ptr = head;
    Node *prev = nullptr;
    for(int i = 0; i<size-n; i++){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    delete ptr;
    size--;
}