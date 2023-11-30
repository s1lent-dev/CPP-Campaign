#include <iostream>
using namespace std;

#define N 12
// Direct recursive function
void DirectRecursion(int num)
{

    if (num > N)
    {
        return;
    }
    cout << num << " ";
    DirectRecursion(num + 1);
}

// Indirect recursive functions

void Indirectrecursion2(int);
void Indirectrecursion1(int num)
{
    if (num > N)
    {
        return;
    }
    cout << num << " ";
    Indirectrecursion2(num + 1);
}

void Indirectrecursion2(int num)
{
    if (num > N)
    {
        return;
    }
    cout << num << " ";
    Indirectrecursion1(num + 1);
}

// Tailed recursion

int TailedSum(int num)
{

    if (num > N)
    {
        return 0;
    }
    else
    {
        return num + TailedSum(num + 1);
    }
}

// Non tailed recursion

int NonTailedSum(int num)
{

    if (num == 1)
    {
        return num;
    }
    else
    {
        return num + NonTailedSum(num - 1);
    }
}
int main()
{

    /*
    There are two types of recursiom

    1. Direct recursion --> a] Tailed recursion b] Non-Tailed recursion
    2. Indirect recursion

    */

    // DIrect recurion

    int num1 = 1;
    cout << "With direct recursion: " << endl;
    cout << "The Numbers are: ";
    DirectRecursion(num1);
    cout << endl;

    // Indirect recursion

    int num2 = 1;
    cout << "With Indirect recursion: " << endl;
    cout << "The Numbers are: ";
    Indirectrecursion1(num2);
    cout << endl;

    // Tailed recursion

    int num3 = 1;
    cout << "The sum of given numbers are: " << TailedSum(num3) << endl;

    // Non-Tailed recursion

    int num4 = 12;
    cout << "The sum of given numbers are: " << NonTailedSum(num4) << endl;

    return 0;
}