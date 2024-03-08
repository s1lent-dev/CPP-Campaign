#include<iostream>
using namespace std;

class RBI{
    public:
        virtual void interest(){
            cout << "RBI Base Interest Rate: 4%" << endl;
        }; 
};

class SBI : public RBI{
    public:
        void interest() override{
            cout << "SBI Interest Rate: 6%" << endl;
        }
};

class ICICI : public RBI{
    public:
        void interest() override{
            cout << "ICICI Interest Rate: 8%" << endl;
        }
};

class Axis : public RBI{
    public:
        void interest() override{
            cout << "Axis Interest Rate: 10%" << endl << endl;
        }
};
int main(){

    /*
    ! Variations in Function Overriding --> 
    * 1. Call overriding function from child class -- By objects //? This is an example of run time polymorphism
    * 2. Call overriding function from parent class -- By pointers
    */

    //* 1. Call overriding function from child class -- By objects

    SBI sbi;
    ICICI icici;
    Axis axis;

    cout << "Calling Function by child class object -->" << endl; //* can be called without using virtaul functions in parent class
    sbi.RBI::interest(); // Calling function by child class object
    sbi.interest();
    icici.interest();
    axis.interest();
    

    //* 2. Call overriding function from parent class -- By pointers

    RBI* rbi1 = new SBI; // * RBI* rbi1 = &sbi; would also work
    RBI* rbi2 = new ICICI;
    RBI* rbi3 = new Axis;

    cout << "Calling Function by parent class dynamic pointer -->" << endl; //* can't be called without using virtaul functions in parent class
    rbi1->RBI::interest();
    rbi1->interest();
    rbi2->interest();
    rbi3->interest();
}