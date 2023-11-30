#include <iostream>
using namespace std;

// Nth fibonacci number using iterative method

int Fibonacci_iterative(int num)
{

    if (num == 0)
        return 0;
    int first_fib = 0, second_fib = 1, ans;
    for (int i = 2; i <= num; i++)
    {

        ans = first_fib + second_fib;
        first_fib = second_fib;
        second_fib = ans;
    }
    return ans;
}

// Nth fibonacci number using recursion

int Fibonacci_recursive(int num)
{

    if (num <= 1)
        return num;

    return Fibonacci_recursive(num - 1) + Fibonacci_recursive(num - 2);
}

int main()
{
    /*
    Dry run for num = 6 (recursion)
    first recursive call --> fib(6) = fib(5) + fib(4)
    second recursive call --> fib(6) = fib(4) + fib(3) + fib(3) + fib(2)
    third recursive call --> fib(6) = fib(3) + fib(2) + fib(2) + fib(1) + fib(2) + fib(1) + fib(1) + fib(0)
    fourth recursive call --> fib(6) = fib(2) + fib(1) + fib(1) + fib(0) + fib(1) + fib(0) + fib(1) + fib(1) + fib(0) + fib(1) + fib(1) + fib(0)
    fifth recursive call --> fib(6) = fib(1) + fib(0) + fib(1) + fib(1) + fib(0) + fib(1) + fib(0) + fib(1) + fib(1) + fib(0) + fib(1) + fib(1) + fib(0)

    return --> fib(6) = 1 + 0 + 1 + 1 + 0 + 1 + 0 + 1 + 1 + 0 + 1 + 1 + 0 = 8
    Therefore, fib(6) would return 8;

    */
    int num = 10;
    // With recursive method
    cout << "Nth number in fibonacci series by recursive method: " << Fibonacci_recursive(num) << endl;

    // With iterative method
    cout << "Nth number in fibonacci series by iterative method: " << Fibonacci_iterative(num) << endl;

    return 0;
}