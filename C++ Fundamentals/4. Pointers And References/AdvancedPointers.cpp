#include<iostream>
#include<string>
#include <memory>
#include "Opaque.hh"
using namespace std;

struct Opaque::OpaqueData{
    string name;
    int id;

    OpaqueData(const string name, int id){
        this->name = name;
        this->id = id;
    }
    ~OpaqueData() = default;
};

Opaque::Opaque(const string name, int id){
    data = new OpaqueData(name, id);
}
Opaque::~Opaque(){
    delete data;
}
void Opaque::Introduce() const{
    cout << "Hello, my name is " << data->name << " and my id is " << data->id << endl;
}



class Rectangle{
    public:

        int length;
        int breadth;
        Rectangle(int length, int breadth){
            this->length = length;
            this->breadth = breadth;
        }
        int area(){
            return length*breadth;
        }
};

struct RectangleData{
    int length;
    int breadth;

    RectangleData(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }

    int area(){
        return length*breadth;
    }
};

union RectangleUnion{
    int length;
    int breadth;
    
    RectangleUnion(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }
    int area(){
        return length*breadth;
    }
};

int main(){

    /*
    Advance concepts regarding pointers -->

    1. Opaque Pointer
    2. Smart Pointers and it's types
    3. Pointers to Classes, Structs and Unions

    */
    
    // Opaque Pointer -->
    cout << "Printing the values after utilizing opaque pointers" << endl;
    Opaque opaque("Paresh", 10);
    opaque.Introduce();
    cout << endl;


    // Smart Pointer -->

    /*
    There are Four types of smart pointers -->

    1. Unique Pointer
    2. Shared Pointer
    3. Weak pointer

    */

    // Unique Pointer -->
    cout << "Printing the values after utilizing unique pointers" << endl;
    unique_ptr<int> un_ptr1 (new int(10)); // Declaring a unique pointer
    cout << *un_ptr1 << endl;
    unique_ptr<int> un_ptr2 = move(un_ptr1); // move() is used to move the ownership of un_ptr1 to un_ptr2
    cout << *un_ptr2 << "\n" << endl;
    //cout << *un_ptr1 << endl; // un_ptr1 doesn't have any value or reference anymore

    // Shared Pointer -->
    cout << "Printing the values after utilizing shared pointers" << endl;
    shared_ptr<int> sh_ptr1 (new int(20)); // Declaring a shared pointer
    cout << *sh_ptr1 << endl;
    shared_ptr<int> sh_ptr2 = sh_ptr1; // sh_ptr2 is a copy of sh_ptr1
    cout << *sh_ptr2 << endl;
    cout << *sh_ptr1 << endl;
    cout << "Reference Count: " << sh_ptr1.use_count() << "\n" << endl; // This shows that how much references are there on the object/value

    // Weak Pointer -->
    cout << "Printing the values after utilizing weak pointers" << endl;
    shared_ptr<int> w_ptr1 (new int(30)); 
    cout << *w_ptr1 << endl;
    weak_ptr<int> w_ptr2 = w_ptr1; // Declaring a weak pointer and copying shared pointer to it
    cout << *w_ptr1 << endl;
    cout << *w_ptr2.lock() << endl;
    cout << "Reference Count: " << w_ptr1.use_count() << "\n" << endl; // This only shows the refernces of shared pointer and weak pointers doesn't add up in reference count


    // Pointers to Classes, Structs and Unions -->
    cout << "Printing the values after utilizing pointers to classes, structs and unions" << endl;
    // Pointers to classes -->
    Rectangle* rect = new Rectangle(10, 20);
    cout << "The area of the rectangle from class Reactangle is: " << rect->area() << endl;

    // Pointers to structs -->
    RectangleData* rect_data = new RectangleData(10, 20);
    cout << "The area of the rectangle from struct RectangleData is: " << rect_data->area() << endl;

    // Pointers to unions -->
    RectangleUnion* rect_union = new RectangleUnion(10, 20);
    cout << "The area of the rectangle from union RectangleUnion is: " << rect_union->area() << endl; // This will print 20*20 == 400 because elements of union have same memory address

    return 0;

}