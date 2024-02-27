#include<iostream>
using namespace std;

//* Single Inheritance
class Salary{
    public:
        int salary;
        Salary(int salary){
            this->salary = salary;
        }
};

class Bonus : public Salary{
    public:
        int bonus;
        Bonus(int salary, int bonus) : Salary(salary), bonus(bonus){}
        void sum(){
            cout << "Total Salary is: " << (salary+bonus) << endl;
        }
};

//* Multilevel Inheritance

class shape{
    public:
        virtual void draw() = 0;
        virtual double Area() = 0;
        virtual void display() = 0;
};

class circle : public shape{
    public:
        int radius;
        circle(int radius){
            this->radius = radius;
        }
        void draw(){
            cout << "Drawing Circle" << endl;
        }
        double Area(){
            return 3.14 * radius * radius;
        }
};

class ColoredCircle : public circle{
    public:
        string color;
        ColoredCircle(int radius, string color) : circle(radius){
            this->color = color;
        }
        void display() override {
            cout << "The Area of " << color << " colored circle is: " << Area() << endl;
        }
};


//* Multiple Inheritance
class Company{
    public:
        string name;
        Company(string name) : name(name) {}
        virtual void display() = 0;
};

class Department{
    public:
        string dept;
        int dept_id;
        Department(string dept, int dept_id) : dept(dept), dept_id(dept_id){}
};

class Employee : public Company, public Department{
    public:
        string emp;
        int id;
        Employee(string emp, int id, string name, string dept, int dept_id) : emp(emp), id(id), Company(name), Department(dept, dept_id){}

        void display() override {
            cout << "The Employee named " << emp << " with id " << id << ", works in the " << dept << " department with id " << dept_id << " for " << name << endl;
        }
};

int main(){
    
    /*
    ! Types of Inheritance -->
    * 1. Single Inheritance
    * 2. Multilevel Inheritance
    * 3. Multiple Inheritance
    * 4. Hierarchical Inheritance --> Its Hierarchical multilevel inheritance like a tree
    * 5. Hybrid Inheritance --> Its a combination of multilevel inheritance and multiple inheritance
    * 6. Virtual Inheritance using virtual derived class --> * Its a combination of multiple inheritance and polymorphism // ? (to prevent the diamond problem in multiple inheritance) 
    */

    //* Single Inheritance
    Bonus Total(30000, 5000);
    Total.sum();
    cout << endl;

    //* Multilevel Inheritance
    ColoredCircle CC(5, "Red");
    CC.display();
    cout << endl;

    //* Multiple Inheritance
    Employee emp("John", 123, "Google", "Software", 5);
    emp.display();
}