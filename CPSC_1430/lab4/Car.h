#include <string>
using namespace std;

class Car{
    public: 
    Car(int, string);
    int getYearModel();
    string getMake();
    int getSpeed();
    void accelerate();
    void brake();

    private:
    int yearModel;
    string make;
    int speed;
};