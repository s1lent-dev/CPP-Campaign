#include<iostream>
#include <stdexcept>
using namespace std;

int division(int numerator, int denominator){
    if(denominator == 0){
        throw runtime_error("Denominator cannot be zero"); 
    }
    return numerator / denominator;
}
int main(){

    int numerator , denominator, ans;
    cin >> numerator >> denominator;
    
    try{
        ans = division(numerator, denominator);
        cout << "Answer: " << ans << endl;
    } catch(const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
}