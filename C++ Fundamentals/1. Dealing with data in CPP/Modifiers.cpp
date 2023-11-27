#include<iostream>
using namespace std;


int main(){

    /*
    In the integer data type there are variuos type of modifiers -->

    1. short int
    2. unsigned short int
    3. unsigned int
    4. int
    5. long int
    6. unsigned long int
    7. long long int
    8. unsigned long long int

------------------------------------------------------------

    In the char data type there are only two types of modifiers -->

    1. signed
    2. unsigned

------------------------------------------------------------

    In the float data type there are only two types of modifiers -->

    1. float
    2. double
    3. long double

    */

    // Modifiers in integer data type
    short int a = 97;
    unsigned short int b = 67;
    int c = 10;
    unsigned int d = 10;
    long int e = 10;
    unsigned long int f = 10;
    long long int g = 10;
    unsigned long long int h = 10;

    // Modifiers in char data type
    signed char i = a;
    unsigned char j = b;

    // Modifiers in float data type
    float k = 10.5353;
    double l = 10.5343;
    long double m = 10.5333434;

    cout << "Printing the values of various integer modifiers " << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << h << "\n" << endl;

    cout << "Printing the values of various char modifiers " << endl;
    cout << i << endl;
    cout << j << "\n" << endl;

    cout << "Printing the values of various float modifiers " << endl;
    cout << k << endl;
    cout << l << endl;
    cout << m << "\n" << endl;

    return 0;
}