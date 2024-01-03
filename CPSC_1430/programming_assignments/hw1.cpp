#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct state{
    string name;
    int cases, deaths;
};
void open();
int menu();
state** read(string);
void info(state**,string);
state* cases(state**);
state* deaths(state**);
void statistics(state**);
void end(state**);

//The main method does nothing
int main(){
    open();
    return 0;
}

//This displays the opening message and calls other methods
void open(){
    int choice = 0;
    string dataTemp;
    cout << "Please enter the input file name: ";
    cin >>  dataTemp;
    state** ptr = read(dataTemp);
    state* pointer = nullptr;
    while(choice!=5){
        choice = menu();
        if(choice == 1){
            info(ptr, dataTemp);
        }
        else if(choice == 2){
            pointer = cases(ptr);
            cout << "\n\n" << pointer->name << " has the most cases: " << pointer->cases;
        }
        else if(choice == 3){
            pointer = deaths(ptr);
            cout << "\n\n" << pointer->name << " has the most deaths: " << pointer->deaths;
        }
        else if(choice == 4){
            statistics(ptr);
        }
        else if(choice == 5){
            end(ptr);
        }
        else{
            cout << "Invalid response!";
        }
    }
}

//This displays the menu message and returns the user's choice
int menu(){
    int choice;
    cout << "\n\n************Menu************\n";
    cout << "1. Display the COVID info of all states\n";
    cout << "2. Display the COVID info of the state that has the most cases\n";
    cout << "3. Display the COVID info of the state that has the most deaths\n";
    cout << "4. Display the statistics of all states\n";
    cout << "5. Exit the program\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

//displays cases and deaths in alphabetical order by state
void info(state** ptr, string dataTemp){
    cout << "               **States**         **Cases**        **Deaths**";
    string const covidData = dataTemp;
    ifstream count;
    count.open(covidData);
    int x = 0;
    while(count.peek() != EOF){
        string line;
        getline(count,line);
        x++;
    }
    for(int i = 0; i<x; i++){
        cout << endl;
        int num = (ptr[i]->name).length();
        for(int j = 0; j<(25-num); j++){
            cout << " ";
        }
        cout << ptr[i]->name;
        if(!(ptr[i]->name == "American Samoa")){
            num = log10(ptr[i]->cases);
            for(int j = 0; j<(17-num); j++){
                cout << " ";
            }
            cout << ptr[i]->cases;
            num = log10(ptr[i]->deaths);
            for(int j = 0; j<(15-num); j++){
             cout << " ";
            }
            cout << ptr[i]->deaths;
        }
        else {
            cout << "                 " << ptr[i]->deaths << "               0";
        }
    }
}

//returns the file location of the state with the most cases
//if two states are tied it will return whichever was listed first on the input txt file
state* cases(state** ptr){
    state* greatest = nullptr;
    greatest = ptr[0];
    for(int i = 1; i<sizeof(ptr); i++){
        if(greatest->cases < ptr[i]->cases){
            greatest = ptr[i];
        }
    }
    return greatest;
} 


//returns the file location of the state with the most deaths
//if two states are tied it will return whichever was listed first on the input txt file
state* deaths(state** ptr){
    state* greatest = nullptr;
    greatest = ptr[0];
    for(int i = 1; i<sizeof(ptr); i++){
        if(greatest->deaths < ptr[i]->deaths){
            greatest = ptr[i];
        }
    }
    return greatest;
} 


//provides a variety of statistics on the data
void statistics(state** ptr){
    int cases = 0;
    for(int i = 0; i<sizeof(ptr); i++){
        cases = cases + ptr[i]->cases;
    }
    cout << "\n\n(a) There are " << cases << " cases in total, " << cases/sizeof(ptr) << " on average";
    int deaths = 0;
    for(int i = 0; i<sizeof(ptr); i++){
        deaths = deaths + ptr[i]->deaths;
    }
    cout << "\n(a) There are " << deaths << " deaths in total, " << deaths/sizeof(ptr) << " on average";
    cout << "\n(c) The average death rate for all states is " << deaths * 10000 / cases * .01 << "%";
    double rate = 0;
    string name;
    for(int i = 0; i<sizeof(ptr); i++){
        if(ptr[i]->deaths>100){
            if(ptr[i]->deaths*10000/ptr[i]->cases*.01 > rate){
                rate = ptr[i]->deaths*10000/ptr[i]->cases*.01;
                name = ptr[i]->name;
            }
        }
    }
    cout << "\n(d) Among all states that have more than 100 deaths, " << name << " has the highest death rate of " << rate << "%";
}


//reads the file provided and stores the data in the heap
state** read(string dataTemp){
    string const covidData = dataTemp;
    ifstream count;
    count.open(covidData);
    int i = 0;
    while(count.peek() != EOF){
        string line;
        getline(count,line);
        i++;
    }
    ifstream fin;
    fin.open(covidData);
    state ** ptr = new state*[i];
    i=0;
    while(fin.peek() != EOF){
        ptr[i] = new state;
        string line;
        getline(fin,line);
        int l = line.find(',',0);
        int m = line.find(',',l+1);
        ptr[i]->name = line.substr(l+1,m-l-1);
        l = line.find(',',m+1);
        m = line.find(',',l+1);
        ptr[i]->cases = stoi(line.substr(l+1,m-l));
        l = line.find(',',m+1);
        ptr[i]->deaths = stoi(line.substr(m+1,l-m));
        i++;
    }
    return ptr;
}


//deallocates memory
void end (state** ptr){
    for(int i = 0; i<sizeof(ptr); i++){
        delete ptr[i];
    }
}