#include <iostream>
using namespace std;

//Defining constant with pre-processor directive method
#define pi 3.14

//Defining constant with "const" keyword method
const float PI = 3.14;

float Circumference(int radius){
    return 2*pi*radius;
}

float Area(int radius){
    return PI*radius*radius;
}

int main(){

    /*
    There are two ways to define constants in C++:
    1. Pre-processor directive method
    2. "const" keyword mathod
    */

    cout << Circumference(5) << endl;
    cout << Area(5) << endl;

    /*
    The value stored in a constant variable is known as a literal.

    There are various types of literals:
    1. Integer literals
    2. Floating point literals
    3. Character literals
    4. String literals
    5. Boolean literals
    6. User defined literals

    */

    // Prefixes in integer literals --> 1. decimal 2. hexadecimal (prefix with 0x) 3. octal (prefix with 0) 4. binary (prefix with 0b)

    const int decimal = 10; //no prefix for decimal literals
    const int hexadecimal = 0x10; //prefix with 0x
    const int octal = 010; //prefix with 0
    const int binary = 0b10; //prefix with 0b

    cout << decimal << endl;
    cout << hexadecimal << endl;
    cout << octal << endl;
    cout << binary << endl;

    // Suffixes in integer literals --> 1. int 2. unsigned int 3. long int 4. unsigned long int 5. long long int 6. unsigned long long int

    const int int_var = 8712; //No suffix
    const unsigned int unsigned_int_var = 8712217810U; //suffix with U
    const long int long_int_var = 8712217810L; //suffix with L
    const unsigned long int unsigned_long_int_var = 8712217810UL; //suffix with UL
    const long long int long_long_int_var = 8712217810LL; //suffix with LL
    const unsigned long long int unsigned_long_long_int_var = 8712217810ULL; //suffix with ULL

    cout << int_var << endl;
    cout << unsigned_int_var << endl;
    cout << long_int_var << endl;
    cout << unsigned_long_int_var << endl;
    cout << long_long_int_var << endl;
    cout << unsigned_long_long_int_var << endl;

    
    return 0;
}



