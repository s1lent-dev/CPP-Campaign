#include<iostream>
using namespace std;

namespace ns1 {
    void fun() {
        cout << "This is a function in namespace 1" << endl;
    }
    int sum(int a, int b) {
        return a + b;
    }
}

namespace ns2 {
    void hello() {
        cout << "Hello from namespace 2" << endl;
    }
    int mul(int a, int b) {
        return a * b;
    }
}