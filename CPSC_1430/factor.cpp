#include <iostream>
using namespace std;

int main(){
    int again = 1;
    while(again == 1){
        int num1, num2;
        cout << "Please type two numbers. \nI will determine if the second is a factor of the first. ";
        cin >> num1 >> num2;
        if(num1%num2 == 0){
            cout << num2 << " is a factor of " << num1 << " and the other factor is " << num1/num2;
        }
        else{
            cout << num2 << " is not a factor of " << num1;
        }
        cout << "\nWould you like to do this again?\nType 1 for yes and 0 for no. ";
        cin >> again;
    }
}