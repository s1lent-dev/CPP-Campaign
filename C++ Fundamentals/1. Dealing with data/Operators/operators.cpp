#include<iostream>
using namespace std;

class Dot{
    public: 
    void dot() {
        printf("dot function is called using dot operator ! \n");
    }
};
int main() {

    /*
    There are six types of operators in c++
    1. Arithmatic operators --> + , - , / , * , ++ , -- , % 
    2. Assignment operators --> = , += , -+ , /= , *= , %= 
    3. Relational operators --> == , != , > , < , <= , >=
    4. Logical operators --> ! , && , || 
    5. Bitwise operators --> ~ , & , | , ^ , >> , << 
    6. Cpp operators --> ?: , sizeof , & , -> , . 
    */


    int a = 12, b = 23, c = 34, d = 45, e = 56, f = 67, g = 78, h = 89, i = 100;


    // Arithmatic operators

    cout << "Printing the values after utilizing arithmatic operators" << endl;

    int add = a + b;
    cout << add << endl; // Addition

    int sub = a - b;
    cout << sub << endl; // Subtraction

    int mul = a * b;
    cout << mul << endl; // Multiplication

    int div = b / a;
    cout << div << endl; // Division

    int mod = a % 2;
    cout << mod << endl; // Modulus

    a++; // post increment
    int inc = a;
    cout << inc << endl;
    cout << ++inc << endl; // pre increment

    b--; // post decrement
    int dec = b;
    cout << dec << endl;
    cout << --dec << "\n" << endl; // pre decrement


    // Assignment operators 

    cout << "Printing the values after utilizing assignment operators" << endl;

    int equalto = c;
    cout << equalto << endl; // equal to
    
    c += 12;
    cout << c << endl; // plus and equal to

    d -= 12;
    cout << d << endl; // minus and equal to

    e *= 2;
    cout << e << endl; // multiply and equal to

    f /= 2;
    cout << f << endl; // divide and equal to

    g %= 2;
    cout << g << "\n" << endl; // modulud and equal to


    // Relational operators (prints 1 if true and 0 if false)

    cout << "Printing the values after utilizing Relational operators" << endl;

    cout << (f == d) << endl; // Equal to 
    cout << (c != d) << endl; // not equal to
    cout << (c < d) << endl; // smaller than
    cout << (c > d) << endl; // greater than
    cout << (e <= f) << endl; // smaller than and equal to
    cout << (e >= f) << "\n" << endl; // greater than and equal to


    // Logical operators

    cout << "Printing the values after utilizing Logical operators" << endl;

    cout << (!true) << endl; // 0 // Logical not "!"
    cout << (!false) << endl; //1
    
    cout << (false && false) << endl; //0 Logical and "&&"
    cout << (false && true) << endl; //0
    cout << (true && false) << endl; //0
    cout << (true && true) << endl; //1 

    cout << (false || false) << endl; //0 Logical or "||"
    cout << (false || true) << endl; //1
    cout << (true || false) << endl; //1
    cout << (true || true) << "\n" << endl; //1


    // Bitwise operators

    cout << "Printing the values after utilizing Bitwise operators" << endl;

    cout << (~h) << endl; // h = (1011001) then ~h = (0100110) = -90
    cout << (h & i) << endl;  //h = (89) base 10 = (1011001) base 2 and i = 100 = (1100100) therefore h & i = (1000000) base 2 = 64
    cout << (h | i) << endl; //h = (1011001) base 2 and i = (1100100) base 2 . Therefore h | i = (1111101) base 2 = 125
    cout << (h ^ i) << endl; //h = (1011001) and i = (1100100) Therefore h ^ i = (0111101) = 61
    cout << (h << 2) << endl; //h = (1011001). Therefore by left shifting (1011001) by 2 = (101100100) = 356
    cout << (h >> 2) << endl; //h = (1011001). Therefore by right shifting (1011001) by 2 = (10110) = 22
    


    // CPP operators

    cout << "Printing the values after utilizing other cpp operators" << endl;

    // Ternery operator

    int tern_var1 = 24 , tern_var2 = 42;
    int ternary1 = (tern_var1 < tern_var2) ? tern_var1 + 10 : tern_var1 - 10;
    int ternary2 = (tern_var1 > tern_var2) ? tern_var1 + 10 : tern_var1 - 10;
    cout << ternary1 << endl; // 34
    cout << ternary2 << endl; // 14

    // sizeof
    int arr[10];
    cout << sizeof(int) << endl; // 4 bytes i.e 4
    cout << sizeof(bool) << endl; // 1 bytes
    cout << sizeof(char) << endl; // 1 bytes
    cout << sizeof(float) << endl; // 4 - 6 bytes
    cout << sizeof(double) << endl; // 8 bytes
    cout << sizeof(arr) << endl; //4 bytes * 10 elements = 40 bytes

    // & reference operator

    int num = 52;
    int &ref = num;
    cout << ref << endl;
    ref = 25;
    cout << num << endl;
    num = 77;
    cout << ref << endl;

    // Dot operator
    
    Dot Dot_obj;
    Dot_obj.dot(); // using dot operator

    // Arrow operator ->

    Dot* Dot_ptr;
    Dot_ptr -> dot();


    return 0;
}