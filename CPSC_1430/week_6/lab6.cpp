//lab6.cpp
//Eric Lindquist
//10/31/23
//This program implements the OrderedList class

#include <iostream>
#include "OrderedList.h"
using namespace std;

//This method will determine if the input from the user is an integer
bool isInt(string str){
    for (int i = 0; i < str.length(); i++) {
        if(str == "x"){
            return false;
        }
        if(!isdigit(str[i]) && str[i] != '-'){
            cout << "Invalid insert of " <<str << " attempted!" << endl;
            return false;
        }
    }
    return true;
}

int main(){
    OrderedList listA;
    cout << "Asking user to type and create listA...";
    string cont = "hello world!";
    //This loop will continue until the user presses "x" allowing htem to add as many items as they like
    while(cont !="x"){
        cout << "\n\nType a number for insertion (type x to stop):";
        cin >> cont;
        if(isInt(cont)){
            int x = stoi(cont);
            listA.insert(x);
        }
    }
    cout << "\n\nlistA is:                   ";
    listA.printList();
    OrderedList listB(listA);
    cout << "\n\nlistB is copied from listA: ";
    listB.printList();
    cont = "Hello world!";
    cout << "\n\nAsking user to type and add more to listB...";
    //This loop will continue until the user presses "x" allowing htem to add as many items as they like
    while(cont !="x"){
        cout << "\n\nType a number for insertion (type x to stop):";
        cin >> cont;
        if(isInt(cont)){
            int x = stoi(cont);
            listB.insert(x);
        }
    }
    cout << "\n\nlistA now is: ";
    listA.printList();
    cout << "\n\nlistB now is: ";
    listB.printList();
}