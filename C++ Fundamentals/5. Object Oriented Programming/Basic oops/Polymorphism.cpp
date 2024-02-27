#include<iostream>
using namespace std;

class Animal {
    public:
        virtual void sound() = 0;
};
class Dog : public Animal {
    public:
        void sound() override{
            cout << "Bark Bark" << endl;
        }
};

class Cat : public Animal {
    public: 
        void sound() override{
            cout << "Meow Meow" << endl;
        }
};

class Bird : public Animal {
    public:
        void sound() override{
            cout << "Chirp Chirp" << endl;  
        }
};

int main(){

    /*
    ! Types of `Polymorphism` in C++ -->

    * 1. Compile time polymorphism --> a] Function Overloading, b] Operator Overloading
    * 2. Run time polymorphism --> a] Function Overriding, b] Virtual function 

    */

    //* Baisc polymorphism --> // Basically 

    Animal* dog = new Dog();
    Animal* cat = new Cat();
    Animal* bird = new Bird();
    
    cout << "Sounds of animals -->" << endl;
    dog->sound();
    cat->sound();
    bird->sound();
}