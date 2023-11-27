#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

    // Recursive Void function to coverst decimal number into binar number
    void binary(int n) {

        if (n > 0) {
            binary(n/2);
            cout << n % 2;
        }
    }
    // Recursive Integer function to coverst decimal number into binar number 
    int decToBin(int n) {
        if (n > 0) {
            return (n % 2 + 10 * decToBin(n/2));
        }
    }

    //Function to convert decimal number to binary number using right shift operator
    void shiftBin(int n) {
        if(n > 1) {
            shiftBin(n >> 1);
        }
        printf("%d", n & 1);
    }


int main() {

    int num1, num2, num3, num4;
    
    cout << "Enter the first number for iterative method: " << endl;
    cin >> num1;

    cout << "Enter the second number for recursive method: " << endl;
    cin >> num2;

    cout << "Enter the third number for Array method: " << endl;
    cin >> num3;

    cout << "Enter the third number for Array method: " << endl;
    cin >> num4;

    int temp1 = num1;
    int temp2 = num3;

    //Iterative method
    int binaryNum1 = 0; 
    int i = 1, rem = 0;

    while (num1 > 0) {

        rem = num1 % 2;
        num1 /= 2;

        binaryNum1 += rem * i;
        i *= 10;
    }

    cout << "The Binary representation of " << temp1 << " with iterative method is: " <<  binaryNum1 << endl;
    

    //Recursive method
    int BINARY = decToBin(num2);
    cout << "The Binary representation of " << num2 << " with recursive method is " ;
    binary(num2);
    cout << endl;
    cout << "The Binary representation of " << num2 << " with recursive method2 is " << BINARY << endl;


    //Right shift method
    cout << "The Binary representation of " << num2 << " with right shift operator is: ";
    shiftBin(num2);
    cout << endl;


    //Array method

    int arr[32];
    int x = 0;
    while (num3 > 0) {
        arr[x] = num3 % 2;
        num3 /= 2;
        x++;
    }

    cout << "The Binary representation of " << temp2 << " with array method is ";
    for (int j=x-1;j>=0;j--){
        cout << arr[j];
    }
    cout << endl;


    //By using bitset class
    bitset<8> bin8(num4);

    cout << "The Binary representation of " << num4 << " with bitset class is: " << bin8 << endl;
    
    return 0;
}