#include<iostream>
using namespace std;
#define pi 3.14


// ! Pure virtual class - Abstract class
class shape { 
    public:
        virtual void draw() = 0; //* Pure virtual function / Abstract function
        virtual double Area() = 0;
        void display() {
            cout << "Area: " << Area() << endl; //* Concrete function
        }
};

class rectangle : public shape {
    public:
        int length;
        int breadth;
        rectangle(int length, int breadth) {
            this->length = length;
            this->breadth = breadth;
        }
        void draw() {
            cout << "Drawing a Rectangle" << endl;
        }
        double Area() {
            return length * breadth;
        }
};

class circle : public shape {
    public:
        int radius;
        circle(int radius) {
            this->radius = radius;
        }
        void draw() {
            cout << "Drawing a Circle" << endl;
        }
        double Area() {
            return pi * radius * radius;
        }
};

int main(){

    shape* circle_ptr = new circle(10);
    shape* rectangle_ptr = new rectangle(10, 20);

    circle_ptr->draw();
    circle_ptr->display();

    rectangle_ptr->draw();
    rectangle_ptr->display();

    return 0;
}