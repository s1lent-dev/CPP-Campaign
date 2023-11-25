#include <iostream>
using namespace std;

int main()
{
    /*There are three types of data types in C++
    1. Primitive/built In data types --> int, float, double, char, bool, wchar_t
    2. Non-Primitive/ Derived data types --> string, array, pointer, reference, function
    3. User Defined data types --> class, struct, union, enum, typedef
    */

    int i = 10;
    float f = 10.53;
    double d = 187.96;
    char c = 'a';
    bool b = true;
    wchar_t wc = L'a';

    cout << i << endl;
    cout << f << endl;
    cout << d << endl;
    cout << c << endl;
    cout << b << endl;
    cout << wc << endl;

    return 0;
}