#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main(int argc, char *argv[]){
    IntegerSet a;
    IntegerSet b;
    cout << "Enter set A:" << endl;
    a.inputSet();
    cout << endl;
    cout << "Enter set B:" << endl;
    b.inputSet();
    cout << endl;
    cout << "Union of A and B is:\n";
    a.unionOfSets(&b);
    cout << "\nIntersection of A and B is:\n";
    a.intersectionOfSets(&b);
    if(a.isEqualTo(&b)){
        cout << "\nSet A is equal to set B\n";
    }
    else{
        cout << "\nSet A is not equal to set B\n";
    }
    cout << "What element would you like to insert into set A?:";
    int x = a.insertElement();
    cout << "Set A is now:\n";
    a.printSet();
    cout << "\nDeleting " << x << " from set A...\n";
    a.deleteElement(x);
    cout << "Set A is now:\n";
    a.printSet();
    cout << "\nNow creating a set of specific values and testing the bounds limits.";
    cout << "\nCreating array of size 10: {25, 67, 2, 9, 99, 105, 45, -5, 100, 1}\n";
    int cArray[] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
    IntegerSet c(cArray, 10);
    cout << "Set C is now:\n";
    c.printSet();
    cout << endl;
    return 0;
}