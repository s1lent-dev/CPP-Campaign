#include<iostream>
using namespace std;

class parent {
    public:
    virtual void print() {}
};

class child: public parent {};

int main() {
    
    /*
    There are two types of Type-casting
    1. Implicit type casting  
    a] Priority in implicit type casting (less to high priority) ==> bool --> char --> short int --> int --> unsigned int --> long --> unsigned long --> long long --> unsigned long long --> float --> double --> long double
    b] Data loss happens when Type is converted from High priority type to Low priority type
    c] No data loss happens when Type is converted from Low priority type to High priority type

    2. Explicit type casting
        a] C style type casting
        b] function style type casting
        c] static type casting
        d] dynamic type casting
        e] const type casting
        f] reinterpret type casting
    */

    //Implicit type casting :-->
    
    int a = 23, b, c = 0;
    float f = 43.45;
    b = f; // Implicit type conversion of float to int with data loss
    char ch = 'a';
    char var = 99;
    bool bl = true;
    bool bl1 = a;
    bool bl2 = c;
    cout << a/5.33 << endl; //Implicit type coversion of integer to float or double
    cout << b << endl; 
    cout << ch + 1 << endl; // char to int due to higher priority of int ---- // now by ASCII standards value of char 'a' is stored in memory as an integer which resembles 97 
    ch = ch + 1;
    cout << ch << endl; // now ch is char and we're storing int value which resembles to 98 in it. ---- // now we're storing 98 in char which resembles to char 'b'
    cout << var << endl; // we're storing integer value in char named var which resembles to 'c' according to the ASCII standards
    cout << bl + 1 << endl; // Coneverting bool to int 
    cout << bl1 << endl;
    cout << bl2 << endl;


    //Explicit Type casting -->
    // a] C-style type casting
    int x = 17, temp = 0;
    float y = 43;
    char z = 'A';
    bool X = false;
    char Y = 67; 
    float F = (float) x/2; //Explicitally converted int to float
    float f_var1 = z/2; // Implicitally char is converted into int therefore the output will be an int
    float f_var2 = (float) z/2; //Explicitally converted int to float

    cout << (int) z << endl; // explicit type casting from char to int
    cout << f_var1 << endl;
    cout << f_var2 << endl;
    cout << (bool) z << endl;
    cout << (bool) temp << endl;

    // b] function style type casting

    int I = 43;
    char Ch = 'B';
    float Fl1 = float(Ch - I) / 2;
    float Fl2 = float(I) / 2;

    cout << Fl1 << endl;
    cout << Fl2 << endl;
    cout << int(Ch) << endl;

    // c] static type casting

    double D = 237.43 / 34.54;
    int e = 34;
    int E = static_cast <int> (D);
    double D_var = static_cast <double> (e) / 3;
    int* s_cast = static_cast <int*> (&e); // Allows to type cast on pointers
    int* s_ptr = &e;
    int* s_ptr2 = static_cast <int*> (s_ptr);

    cout << * s_ptr2 << endl;

    *s_ptr2 = 43;

    cout << *s_ptr2 << endl;
    cout << E << endl;
    cout << D_var << endl;
    cout << s_cast << endl;

    // d] dynamic type casting

    //The dynamic cast can only be used with pointers and references to classes or void* i.e void pointers
    parent* pr = new child;
    child* cd = dynamic_cast <child*> (pr);
    
    if (cd != NULL) {
    cout << "dynamic_cast done" << endl;
    } else {
    cout << "dynamic_cast not done" << endl;
    }

    // e] const type casting

    const int const_var = 57;
    const int* const_ptr = &const_var;

    int* const_ptr2 = const_cast <int*> (const_ptr);

    cout << *const_ptr2 << endl;

    *const_ptr2 = 75;

    cout << *const_ptr2 << endl;

    // f] reinterpret type casting

    int re_var = 97;
    int* re_ptr = new int(re_var);

    char* char_ptr = reinterpret_cast <char*> (re_ptr);

    cout << re_var << endl;
    cout << re_ptr << endl;
    cout << char_ptr << endl;
    cout << *char_ptr << endl;

    return 0;
}