#include<iostream>
using namespace std;

class Employee{
    public:
        int id; 
        int* id_ptr;
        string name; 
        string* name_ptr;
        double salary; 
        double* salary_ptr;
        int dynamic;
        string overloaded;

    //* Declaration of outside constructor inside class
    Employee(int id, string name);
    
    //* Default Constructor
    Employee(){
        id = 0;
        name = "name";
        salary = 0;
    }

    //* Parameterized Constructor
    Employee(int id, string name, double salary){
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    //* Copy Constructor
    Employee(const Employee &emp){
        id = emp.id;
        name = emp.name;
        salary = emp.salary;
    }

    //* Overloaded Constructor
    Employee(int id, string name, double salary, string overloaded) : id(id), name(name), salary(salary), overloaded(overloaded){}

    //* Dynamic Constructor type - 1
    Employee* setEmp(int id, string name, double salary){
        Employee* emp = new Employee(id, name, salary);
        return emp;
    }

    //* Dynamic Constructor type - 2
    Employee(int id, string name, double salary, int dynamic) : id(id), name(name), salary(salary), dynamic(dynamic){ 
        id_ptr = new int(id);
        name_ptr = new string(name);
        salary_ptr = new double(salary);
        dynamic = 0;
    }

    //* Destructor
    ~Employee() {
        cout << "Destructor called for object with id: " << id << ", name: " << name << endl;
    }
};

// * Declaration of outside constructor outside class
Employee::Employee(int id, string name) : id(id), name(name){
    cout << "This is a outside Constructor for" << " id: " << id << ", name: " << name << "" << endl;
};

int main(){

    /*
    ! Types of Constructors -->
    * 1. Default Constructor
    * 2. Parameterized Constructor
    * 3. Copy Constructor
    * 4. Overloaded Constructor
    * 5. Dynamic Constructor
    * 6. Outside Constructor
    * 7. Destructor
    */

    Employee emp; // Declaring an object with default constructor
    cout << "Printing the elements in class Employee by utilizing Default Constructor" << endl;
    cout << emp.id << " " << emp.name << " " << emp.salary << endl;
    cout << "\n";


    Employee employee(1, "John", 100.0); // Declaring an object with parameterized constructor
    cout << "Printing the elements in class Employee by utilizing Parameterized Constructor" << endl;
    cout << employee.id << " " << employee.name << " " << employee.salary << endl;
    cout << "\n";


    Employee employee2(employee); // Declaring an object with copy constructor
    cout << "Printing the elements in class Employee by utilizing Copy Constructor" << endl;
    cout << employee2.id << " " << employee2.name << " " << employee2.salary << endl;
    cout << "\n";


    Employee employee3(1, "John", 100.0, "Overloaded"); // Declaring an object with overloaded constructor
    cout << "Printing the elements in class Employee by utilizing Overloaded Constructor" << endl;
    cout << employee3.id << " " << employee3.name << " " << employee3.salary << " " << employee3.overloaded << endl;
    cout << "\n";


    Employee* emp1 = employee.setEmp(2, "Peter", 200.0); // Declaring an object using pointer with dynamic constructor
    cout << "Printing the elements in class Employee by utilizing Dynamic Constructor" << endl;
    cout << emp1->id << " " << emp1->name << " " << emp1->salary << endl;
    delete emp1; // Works as destructor
    cout << "\n";
    

    Employee* emp2 = new Employee(3, "Paresh", 300.0); // Declaring an object using pointer with dynamic constructor
    cout << "Printing the elements in class Employee by utilizing Dynamic Constructor" << endl;
    cout << emp2->id << " " << emp2->name << " " << emp2->salary << endl;
    delete emp2; // Works as destructor
    cout << "\n";
    

    cout << "Printing the elements in class Employee by utilizing Dynamic Constructor" << endl;
    Employee emp3(10,"maruf"); // Declaring an object for outside constructor
    cout << "\n";


    return 0;
}