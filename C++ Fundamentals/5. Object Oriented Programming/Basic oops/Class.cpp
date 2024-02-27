#include<iostream>
using namespace std;

class Car{
    
    public:
    Car(string brand, string model, int milage) : brand(brand), model(model), milage(milage){}
    int getMilage(){
        return milage;
    }
    void setMilage(int newMilage){
        if(newMilage > 0){
            milage = newMilage;
        }else {
            cout << "Invalid Milage" << endl;
        }
    }

    void about(){
        cout << "Brand : " << brand << ", Model : " << model << ", Milage : " << milage << endl;
    }

    public :
        string brand;

    private: 
        string model;

    protected:
        int milage;
    
};    
int main(){

    int a, b;

    Car car("BMW", "X5", 10); // Declaring an object
    car.about();
    cout << "Enter New Milage : ";
    cin >> a;
    car.setMilage(a);
    cout << "New Milage : " << car.getMilage() << endl;
    car.about();

    Car* car_ptr(new Car("buggati", "xs", 12)); // Declaring an object using pointer
    car_ptr->about();
    cout << "Enter New Milage : ";
    cin >> b;
    car_ptr->setMilage(b);
    cout << "New Milage : " << car_ptr->getMilage() << endl;
    car_ptr->about();

}