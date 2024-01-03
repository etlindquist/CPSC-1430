//hw4.cpp
//Eric lindquist
//11/25/2023

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include "Stack.h"
#include "Queue.h"
using namespace std;
//performing the stack task
int sum(string funct){
    Stack values;
    bool sign = false;
    int value = 0;
    for(int i = 0; i<funct.length(); i++){
        if(funct[i]<58 && funct[i]>47){
            value = value*10+funct[i]-48;
        }
        if(funct[i]=='-'){
            if(sign){
                value = value*-1;
            }
            values.add(value);
            sign = true;
            value = 0;
        }
        else if(funct[i]=='+'){
            if(sign){
                value = value*-1;
            }
            values.add(value);
            sign = false;
            value = 0;
        }
    }
    if(sign){
        value = value*-1;
    }
    values.add(value);
    int output = 0;
    while(!values.isEmpty()){
        output = output+values.remove();
    }
    return output;
} 
//reading the file
vector<int> readFile(const string& filename) {
    vector<int> result;  // Vector to store integers
    ifstream inputFile(filename);
    if (!inputFile) {
        return result;
    }
    int value;
    while (inputFile >> value) {
        result.push_back(value);
    }
    inputFile.close();
    return result;
}
//performing the queue task
void window_size(char* argv[]){
    int size = stoi(argv[2]);
    Queue window;
    vector<int> values = readFile(argv[1]);
    for(int val:values){
        window.enqueue(val);
    }
    int *averages = new int[size];
    for(int j = 0; j<size; j++){
            averages[j] = 0;
        }
    int i = 1;
    cout << " The averages in each window of size " << size << " are [ ";
    while(!window.isEmpty()){
        int val = window.dequeue();
        for(int j = 0; j<size; j++){
            averages[j] = averages[j]+val;
        }
        if(i>=size){
            cout << averages[i%size]/size << " ";
        }
        averages[i%size] = 0;
        i++;
    }
    cout << "]\n";

    delete averages;
}

int main(int argc, char * argv[]){
    cout <<"****Showcasing the first task****\n";
    string input = "";
    cout << "    Type the expression (type # to quit):";
    cin >> input;
    while(input != "#"){
        int output = sum(input);
        cout << "    The value of this expression is " << output;
        cout << "\n\n    Type the expression (type # to quit):";
        cin >> input;
    }
    cout << "\n****Showcasing the second task****\n";
    window_size(argv);
}