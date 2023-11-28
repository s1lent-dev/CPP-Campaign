#include <iostream>

using namespace std;

int main()
{

    /*
    There are majorly 3 types of loops

    1. For loop
    2. While loop
    3. Do - while loop

    */

    // For loop

    int a = 0;
    for (int i = 0; i <= 10; i++)
    {
        a += i;
    }
    cout << "The addition of numbers from 0 to 10 is: " << a << endl;

    // While loop
    int b = 0;
    while (b < 10)
    {
        if (b % 2 == 0)
        {
            cout << b << " ";
        }
        b++;
    }
    cout << "\n";

    // Do - whihle loop

    int c = 0;
    do
    {
        if (c % 2 == 1)
        {
            cout << c << " ";
        }
        c++;
    } while (c < 10);

    return 0;
}