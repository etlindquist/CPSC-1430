#include <iostream>
#include "IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet(){
    a = new int[101];
    for(int i = 0; i<101; i++){
        a[i] = 0;
    }
}
IntegerSet::IntegerSet(int numbers[], int size){
    a = new int[101];
    for(int i = 0; i<size; i++){
        if(validEntry(to_string(numbers[i]))){
            a[numbers[i]]=1;
        }
    }
}
void IntegerSet::inputSet(){
    string cont = "a";
    while (cont != "x"){
        cout << "Enter an element (Type x to stop): ";
        cin >> cont;
        if(cont !="x" && validEntry(cont)){
            int i = stoi(cont);
            a[i]=1;
        }
    }
    cout << "Entry complete" << endl;
}
int IntegerSet::insertElement(){
    int x;
    string input;
    cin >> input;
    if(validEntry(input)){
        x = stoi(input);
        a[x] = 1;
        return x;
    }
    return -1;
}
void IntegerSet::deleteElement(int x){
    if(validEntry(to_string(x))){
        a[x] = 0;
    }
}
int* IntegerSet::unionOfSets(IntegerSet* ptr){
    int* u = new int[101];
    bool empty = true;
    cout << "{ ";
    for(int i = 0; i<101; i++){
        if(a[i]+ptr->getSet()[i]>0){
            u[i] = 1;
            cout << i << " ";
            empty = false;
        }
    }
    if(empty){
        cout << "- ";
    }
    cout << "}\n";
    return u;
}
int* IntegerSet::intersectionOfSets(IntegerSet* ptr){
    int* intersect = new int[101];
    cout << "{ ";
    bool empty = true;
    for(int i = 0; i<101; i++){
        if(a[i]+ptr->getSet()[i]==2){
            intersect[i] = 1;
            cout << i << " ";
            empty = false;
        }
    }
    if(empty){
        cout << "- ";
    }
    cout << "}\n";
    return intersect;
}
bool IntegerSet::validEntry(string str){
    for (int i = 0; i < str.length(); i++) {
        if(!isdigit(str[i])){
            cout << "Invalid insert of " <<str << " attempted!" << endl;
            return false;
        }
    }
    int x = stoi(str);
    if(x>100 or x<0){
        cout << "Invalid insert of " <<str << " attempted!" << endl;
        return false;
    }
    return true;
}
void IntegerSet::printSet(){
    cout << "{ ";
    bool empty = true;
    for(int i=0; i<101; i++){
        if(a[i] == 1){
            empty = false;
            cout << i << " ";
        }
    }
    if(empty){
        cout << "- ";
    }
    cout << "}\n";
}
bool IntegerSet::isEqualTo(IntegerSet* ptr){
    int* x = ptr->getSet();
    for(int i = 0; i<101; i++){
        if(a[i]!=x[i]){
            return false;
        }
    }
    return true;
}
int* IntegerSet::getSet(){
    return a;
}