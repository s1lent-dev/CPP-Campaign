#include <iostream>
#include <cmath>
using namespace std;

int Factorials(int num)
{ // Basic CPP function

    int fac = 1;
    for (int i = num; i >= 1; i--)
    {
        fac *= i;
    }

    return fac;
}

// Call by value function 

void Swap(int val1, int val2) { // Here val1 & val2 are the formal arguments

    int temp = val1;
    val1 = val2;
    val2 = temp;

    cout << "Inside Function: \n" << "First number: " << val1  << "\n" << "Second number: " << val2 <<  "\n" << endl;
    
}

// Call by pointer function 

void Ptr_swap(int* ptr1 , int* ptr2) { // Here ptr and ptr2 are the formal arguments which takes address of the actual parameter

    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    cout << "Inside Function: \n" << "First number: " << *ptr1  << "\n" << "Second number: " << *ptr2 <<  "\n" << endl;
}

// Call by reference function

void Ref_swap(int &ref1, int & ref2) {

    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;

    cout << "Inside Function: \n" << "First number: " << ref1  << "\n" << "Second number: " << ref2 <<  "\n" << endl;
}

int main()
{

    /*
    There are two types o functions in CPP

    1. Built In dunctions / Pre-Defined functions
    2. User Defined functions

    */
    
    int num = 5;
    cout << Factorials(num) << endl; // Calling a basic function to get the factorials of given functions

    // Built In functions

    int a = 12, b = 4;
    cout << pow(a, b) << endl; //Calling an In built function of <cmath> pre-processor directive where pow stands for power of eg. pow(12 , 4) stands for 12 to the power of 4.

    int c = 16;
    cout << sqrt(c) << endl; // using sqrt function of cmath lib which returns square root of given number eg. sqrt(16) = 4;
    cout << endl;


    
    // User defined functions

    /*
    
    There are three ways to call a function in CPP -->

    1. Call by value
    2. Call by pointers
    3. Call by reference

    */

    // Call by value
    // In call by value function --> The function doesn't actually work on the actual parameters but they work on a shallow copy of the actual parameter
    int val1 = 12, val2 = 21;

    Swap(val1, val2); // Here val1 and val2 are the actual arguments
    cout << "Outside Function: \n" << "First number: " << val1  << "\n" << "Second number: " << val2 <<  "\n" << endl; // This shows that the function doesn't actually change the values of its parameters because it works on the shallow copy of those parameters


    // Call by pointers
    // In call by pointer function --> The function take pointers as formal parameters and then the function works on the address of actual parameters and does not make any shallow copy of the actual parameters
    int ptr_val1 = 24, ptr_val2 = 42;

    Ptr_swap(&ptr_val1, &ptr_val2);
    cout << "Outside Function: \n" << "First number: " << ptr_val1  << "\n" << "Second number: " << ptr_val2 <<  "\n" << endl; // This shows that the function actually chnages the values of the actual parameters because it works on the addresses of that parameters.

    // Call by reference
    // In call call by reference --> The function takes reference of actual parameter as a formal parameter and works on the address of actual paameter
    int ref_val1 = 36, ref_val2 = 63;
    
    Ref_swap(ref_val1, ref_val2);
    cout << "Outside Function: \n" << "First number: " << ref_val1  << "\n" << "Second number: " << ref_val2 <<  "\n" << endl; // This shows that the function actually chnages the values of the actual parameters because it works on the addresses of that parameters.
    
    return 0;
}