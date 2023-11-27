#include <iostream>
#include "External.hh"
#include <ostream>
using namespace std;

// Calling an external variable from External.hh file
extern int external_var;

// Declaring a global variable
int global_var = 150;

class Instance_var {
    public:
        int instance_var = 290; //Declaring an instance variable
};

class Static_var {
    public:
        static int static_var; //initializing a static variable
};

int Static_var::static_var = 8712; // Declaring a static variable

int main() {

    /*
    There are six types of variables in C++:
    1. Local variable
    2. Global variable
    3. Instance variable
    4. Static variable
    5. Automatic variable
    6. External variable
    */

    int local_var = 100; // Declaring a local variable
    Instance_var iv;
    auto auto_var = 1000; // Declaring an automatic variable
    auto auto_var2 = 'a';
    
    cout << local_var << endl;
    cout << global_var << endl;
    cout << iv.instance_var << endl;
    cout << Static_var::static_var << endl;
    cout << auto_var << endl;
    cout << auto_var2 << endl;
    cout << external_var << endl;

    return 0;
}