#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int r;
    int c;
    //getting array size
    cout << "Input row" << endl;
    cin >> r;
    cout << endl;
    cout << "Input col" << endl;
    cin >> c;
    int * * a = new int*[r];
    //getting values for the array
    for(int i = 0; i < r; ++i){
        a[i] = new int[c];
        for(int j = 0; j < c; ++j){
            cout << "\nInput number at row " << (i+1) << " col " << (j+1) << endl;
            cin >> a[i][j];
        }
    }
    cout << "\n\n";
    //displaying array
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    //sum of rows
    for(int i = 0; i < r; ++i){
        int count = 0;
        for(int j = 0; j < c; ++j){
            count = count + a[i][j];
        }
        cout << "\nSum of row " << (i+1) << " is " << count;
    }
    //sum of cols
    for(int i = 0; i < c; ++i){
        int count = 0;
        for(int j = 0; j < r; ++j){
            count = count + a[j][i];
        }
        cout << "\nSum of col " << (i+1) << " is " << count;
    }
    cout << endl;
    //deleting dynamically allocated memory
    for(int i = 0; i < r; ++i){
        delete [] a[i];
    }
    delete [] a;
    a = nullptr;
    return 0;
}