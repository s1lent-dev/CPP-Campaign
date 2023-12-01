#include <iostream>
using namespace std;
#define size 10
// Function which takes pointer to first element of an array as parameter

void odd(int *arr)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 1)
        {
            cout << arr[i] << " ";
        }
    }
}
// Function which takes Pointer to whole array as parameter
void even(int (*arr)[size])
{

    for (int i = 0; i < size; i++)
    {
        if ((*arr)[i] % 2 == 0)
        {
            cout << (*arr)[i] << " ";
        }
    }
}
int main()
{

    /*
    Major concepts regarding pointers and references -->

    1. Pointers
    2. References
    3. Pointers to arrays


    */

    // 1. Pointers
    int num1 = 12;
    int *ptr1 = &num1; // Pointers declaration --> storing the address of num1 into ptr by sing &(Address operator)
    int val = *ptr1;   // Dereferencing the address with *(Referencing/Dereferencing operator)

    cout << num1 << endl;
    cout << ptr1 << endl;
    cout << val << endl;

    *ptr1 = 21;           // Assigning value to the variable which has ptr as its pointer i.e indirectly ptr* == num1 == 21
    cout << num1 << endl; // Therefore the num1 will return 21

    // 2. References
    int num2 = 24;
    int &ref = num2; // referencing value of num to ref

    cout << ref << endl;
    cout << &ref << endl; // Dereferencing the variable with & operator

    ref = 42;             // Assigning value to the variable ref which is a reference to num2 variable i.e ref = num2 = 42
    cout << num2 << endl; // Therefore the num2 will return 42

    // 3. Pointers to Arrays

    // Pointer to first element of an array
    int arr1[size] = {12, 21, 30, 39, 48, 57, 66, 75, 84, 93};

    int *arr_ptr1 = arr1; // Or int* arr_ptr = &arr[0]; // Pointer to the first elements of an array
    odd(arr_ptr1);
    cout << endl;

    // Pointer to entire array
    int(*Ent_ptr)[size];

    Ent_ptr = &arr1; // Pointer to entire array
    even(Ent_ptr);

    // 4.

    return 0;
}