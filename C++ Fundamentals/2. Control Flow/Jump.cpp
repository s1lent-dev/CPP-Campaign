#include <iostream>

using namespace std;

int main()
{

    /*
    There are 4 types of jump statements -->

    1. continue
    2. break
    3. goto
    4. return

    */

    // continue
    for (int i = 0; i < 10; i++)
    {

        if (i == 5)
        {
            continue;
        }
        cout << i << " ";
    }
    cout << endl;

    // break

    for (int i = 1; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        cout << i << " ";
    }
    cout << endl;

    // goto

    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            goto even;
        }
        else
        {
            goto odd;
        }
        if (i % 2 == 0)
        {
        even:
        {
            cout << "Even numbers are: " << i << endl;
        };
        }

        if (i % 2 == 1)
        {
        odd:
        {
            cout << "Odd numbers are: " << i << endl;
        }
        }
    }

    // return

    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            return 0;
        }
        cout << i << " ";
    }
    cout << "labhesh lala" << endl; // will not work because return function terminated the int main() function with output 0;
    
}