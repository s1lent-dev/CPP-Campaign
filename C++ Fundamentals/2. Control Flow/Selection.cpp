#include <iostream>

using namespace std;

int main()
{

    /*
    There are majorly 3 types of selection statements -->

    1. If - else
        a] If statement
        b] if-else statement
        c] nested if statement
        d] if - else - if statement

    2. Switch case statement
    3. Conditional operator / Ternary operator

    */

    int a = 15, b = 51, c = 10;

    // If statement

    if (b > a)
    {
        cout << b << " is greater than " << a << endl;
    }

    // If - else statement

    if (b < a)
    {
        cout << b << " is greater than " << a << endl;
    }
    else
    {
        cout << b << " is not smaller than " << a << endl;
    }

    // Nested if

    if (c == 10)
    {
        if (a < b)
        {
            cout << a << " is smaller than " << b << endl;
        }

        if (b < a)
        {
            cout << b << " is greater than " << a << endl;
        }
        else
        {
            cout << b << " is not smaller than " << a << endl;
        }
    }

    // if - else - if ladder

    if (b < a)
    {
        cout << b << " is greater than " << a << endl;
    }
    else if (b == a)
    {
        cout << b << " is equal to " << a << endl;
    }
    else
    {
        cout << b << " is not smaller than " << a << endl;
    }

    // Switch case statement

    int case_var = 3;

    switch (case_var)
    {

    case 1:
        cout << "case 1 is executed" << endl;
        break;
    case 2:
        cout << "case 2 is executed" << endl;
        break;
    case 3:
        cout << "case 3 is executed" << endl;
        break;
    default:
        cout << "default case is executed" << endl;
        break;
    }

    // Conditional operator statement

    int Tern_var = (a > b) ? b + a : b - a;
    cout << Tern_var << endl;

    return 0;
}