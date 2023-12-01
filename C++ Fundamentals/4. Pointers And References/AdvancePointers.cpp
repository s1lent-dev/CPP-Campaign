#include <iostream>
using namespace std;
#include "Opaque.h"

Opaque::Opaque()
{
    MessageConstructed();
}

Opaque::~Opaque()
{
    MessageDestructed();
}

void Opaque::MessageConstructed()
{
    Struct_ptr = new MyDataStruct;
    cout << "My Name is: " << Struct_ptr->name << " And my age is: " << Struct_ptr->age << endl;
}
int main()
{

    /*
    Advance concepts regarding pointers -->

    1. Opaque Pointer
    2. Smart Pointers and it's types
    3. Pointers to functions
    4. Pointers to Pointers
    5. Pointers to class, structs etc

    */

    // Opaque Pointer -->

    Opaque obj;

    // Smart Pointer -->

    /*
    There are Four types of smart pointers -->
    1. Unique Pointer
    2. Shared Pointer
    3. Weak pointer
    4. Auto pointer

    */

    return 0;
}