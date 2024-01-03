#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main(int argc, char** argv){
    string str = argv[1];
    cout << str << endl;
    int num = stoi(str);
    if(num>10){
        return 1;
    }
    int basicArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Original   array: [";
    Queue q;
    for(int i = num; i<10; i++){
        q.enqueue(basicArr[i]);
    }
    for(int i:basicArr){
        cout<< basicArr[i-1];
        if(i<10){
            cout << ", ";
        }
    }
    cout << "]\nReversed first " << num << ": [";
    Stack s;
    int x = 0;
    for(int i = 0; i<num; i++){
        s.add(basicArr[i]);
    }
    for(int i=0; i<num; i++){
        cout << s.remove();
        if(x<9){
            cout << ", ";
        }
        x++;
    }
    for(int i = 0; i<10-num; i++){
        cout << q.dequeue();
        if(x<9){
            cout << ", ";
        }
        x++;
    }
    cout << "]\n";
    return 0;
}