#include<iostream>
using namespace std;
#include "Namespace.hh"
int main(){

    int a = 10; int b = 20;
    ns1::fun();
    cout << "The sum is: " << ns1::sum(a,b) << endl;
    ns2::hello();
    cout << "The multiplication is: " << ns2::mul(a,b) << endl;

}