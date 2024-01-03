#include <iostream>
using namespace std;

class Order{
    private:
    string name;
    int itemID;
    double total;
    bool status = false;

    public:

    Order(){
        name = "N/A";
        itemID = 0;
        total = 0.0;
    }
    Order(string name, int id, double total){
        this->name = name;
        itemID = id;
        this->total = total;
    }
    Order(string name, int id, double total, bool status){
        this->name = name;
        itemID = id;
        this->total = total;
        this->status = status;
    }

    void setName(string tempString){
        cout << "assigning name..." << endl;
        name = tempString;
    }
    void setID(int id){
        itemID = id;
        cout << "setting ID" << endl;
    }
    void setTotal(double tempTotal){
        cout << "total updated!" << endl;
        total = tempTotal;
    }
    void setStatus(bool tempStatus){
        cout << "new status set" << endl;
        status = tempStatus;
    }
    string getName(){
        cout << "getting name: " << name << endl;
        return name;
    }
    int getID(){
        cout << "the item ID is: " << itemID << endl;
        return itemID;
    }
    double getTotal(){
        cout << "your total is $" << total << endl;
        return total;
    }
    bool getStatus(){
        if(status){
            cout << "your order is active" << endl;
        }
        else{
            cout << "your order is not active" << endl;
        }
        return status;
    }
};

int main(){
    Order o1 = Order();
    Order o2 = Order("name2",4,5.0);
    Order o3 = Order("name3",23,7.60,true);
    o1.setName("laptop");
    bool o2Status = o2.getStatus();
    o3.setName("new name");
    cout << o1.getName() << endl;
    if (o2Status){
        cout << "order 2's status is active" << endl;
    }
    return 0;
}