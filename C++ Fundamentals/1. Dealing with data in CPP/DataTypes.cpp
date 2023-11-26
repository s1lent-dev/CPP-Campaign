#include <iostream>
#include <string>
using namespace std;

int sum(int a, int b) // Function is a non primitive data type
{
    return a + b;
}

class add // Class is a user defined data type
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
};

class Union{ 

public:
    union {
        int m1;
        int m2;
        int m3;
    };
};

struct student
{
    int rollno;
    int marks;
    string name;
};

union marks // All of the memebers in an union uses same memory location 
{
    int m1;
    int m2;
    int m3;
};

enum color // Unscoped enum
{
    red ,
    green ,
    blue
};

enum class color2: int { // Scoped enum
    red ,
    green ,
    blue 
}enum_var;


int main()
{
    /*There are three types of data types in C++
    1. Primitive/built In data types --> int, float, double, char, bool, wchar_t
    2. Non-Primitive/ Derived data types --> string, array, pointer, reference, function, stack, queue, Linked list etc.
    3. User Defined data types --> class, struct, union, enum, typedef
    */

    // Primitive datatypes eg.
    int i = 10; // Declaring an integer
    float f = 10.53; // Declaring a float
    double d = 187.96; // Declaring a double
    char c = 'a'; // Declaring a character
    bool b = true; // Declaring a boolean
    wchar_t wc = L'a'; // Declaring a wide character
    cout << "Printing the values of primitive data types: " << endl;
    cout << i << endl;
    cout << f << endl;
    cout << d << endl;
    cout << c << endl;
    cout << b << endl;
    cout << wc << "\n" << endl;

// ----------------------------------------------------------------------------

    // Non-Primitive data types eg.
    int arr[10] = {11, 22, 33, 44}; // Declaring an array
    string s = "Hello"; // Declaring a string
    int *ptr = &i; // Declaring a pointer
    int &ref = i; // Declaring a reference

    cout << "Printing the values of non-primitive data types: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }
    cout << s << endl;
    cout << ptr << endl;
    cout << ref << endl;
    cout << sum(10, 20) << "\n" << endl;

// ----------------------------------------------------------------------------

    // User defined data types eg.
    cout << "Printing the values of user defined data types:" << endl;
    add a; // creating an object of a class add
    cout << a.sum(150, 300) << endl;

    student student; // creating a variable of a struct
    student.rollno = 10;
    student.marks = 90;
    student.name = "Paresh";
    cout << student.rollno << endl;
    cout << student.marks << endl;
    cout << student.name << endl;

    marks m; //Creating a variable of a union 
    m.m1 = 10;
    cout << m.m1 << " " << &m.m1 << endl;
    m.m2 = 20;
    cout << m.m2 << " " << &m.m2 << endl;
    m.m3 = 30;
    cout << m.m3 << " " << &m.m3 << endl;
    
    Union u; // Anonomous union eg.
    u.m1 = 100;
    cout << u.m1 << " " << &u.m1 << endl;
    u.m2 = 200;
    cout << u.m2 << " " << &u.m2 << endl;
    u.m3 = 300;
    cout << u.m3 << " " << &u.m3 << endl;

    color c1 = red; // creating enum variables for unscoped enum
    color c2 = green;
    color c3 = blue;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    
    for(color c : {red, green, blue}) // using enum in for loop
    {
        cout << c << endl;
    }

    color2 c4 = color2::red; // creating enum variables for scoped enum
    color2 c5 = color2::green;
    color2 c6 = color2::blue;
    enum_var = {color2::red}; // Alternate way to create enum variable for scoped enum
    cout << static_cast<int>(enum_var) << endl; // static_cast conversion into int is must when using scoped enums
    cout << static_cast<int>(c4) << endl;
    cout << static_cast<int>(c5) << endl;
    cout << static_cast<int>(c6) << endl;



    return 0;
}
