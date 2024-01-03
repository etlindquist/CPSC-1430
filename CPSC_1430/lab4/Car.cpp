#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(int yearModel, string make){
    this->yearModel = yearModel;
    this->make = make;
    speed = 0;
}
int Car::getYearModel(){
    return yearModel;
}
string Car::getMake(){
    return make;
}
int Car::getSpeed(){
    return speed;
}
void Car::accelerate(){
    speed +=5;
}
void Car::brake(){
    speed-=5;
}

