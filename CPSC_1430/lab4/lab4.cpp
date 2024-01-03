#include <iostream>
#include "Car.h"
using namespace std;

int main(){
    Car car(2005, "Ford F-Series");
    cout << "You have a " << car.getYearModel() << " " << car.getMake() << endl;
    for(int i = 0; i<5; i++){
        car.accelerate();
        int s = car.getSpeed();
        cout << "The current speed of your car is " << s << endl;
    }
    for(int i = 0; i<5; i++){
        car.brake();
        int s = car.getSpeed();
        cout << "The current speed of your car is " << s << endl;
    }
    return 0;
}