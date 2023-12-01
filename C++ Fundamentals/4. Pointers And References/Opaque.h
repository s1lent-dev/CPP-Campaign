#include <iostream>
using namespace std;
class Opaque
{

public:
    Opaque();
    ~Opaque();

private:
    struct MyDataStruct
    {
        string name = "Paresh";
        int age = 23;
    };
    struct MyDataStruct *Struct_ptr;
    void MessageConstructed();
    void MessageDestructed()
    {
        cout << "The Destrcuter is called in Opaque.h file" << endl;
    }
};