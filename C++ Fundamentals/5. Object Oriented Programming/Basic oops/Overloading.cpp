#include <iostream>
using namespace std;

class Operations{
    public:
        int add(int a, int b){
            return a+b;
        }
        int add(int a, int b, int c){
            return a+b+c;
        }
        int add(double a, double b){
            return a+b;
        }
};

class Fractions{

    public:
        int numerator, denominator;

        Fractions(int numerator, int denominator) : numerator(numerator), denominator(denominator){}

        int gcd(int a, int b){
            if(b == 0){
                return a;
            }
            return gcd(b, a%b);
        }

        Fractions operator + (Fractions const &other){ // ! other is another object of same class
            int num = (numerator * other.denominator) + (denominator * other.numerator);
            int den = denominator * other.denominator;

            int common = gcd(num, den);
            num /= common;
            den /= common;

            return Fractions(num, den);
        }

        Fractions operator * (Fractions const &other){
            int num = numerator * other.numerator;
            int den = denominator * other.denominator;

            int common = gcd(num, den);
            num /= common;
            den /= common;

            return Fractions(num, den);
        }
};
int main(){

    /*
    ! Types of overlaoding in cpp -->   
    * 1. Function Overloading //? This is an example of compile time polymorphism
    * 2. Operator Overloading //? This is an example of compile time polymorphism
    */
    
    //* Function Overloading -->

    Operations func_obj;
    int a = 10, b = 20, c = 30;
    double x = 10.5, y = 20.5;

    cout << "Function Overloading -->" << endl;
    cout << func_obj.add(a, b) << endl;
    cout << func_obj.add(a, b, c) << endl;
    cout << func_obj.add(x, y) << endl;
    cout << endl;

    //* Operator Overloading -->

    Fractions Frac1(10, 2);
    Fractions Frac2(5, 3);
    
    Fractions Frac3 = Frac1 + Frac2;
    Fractions Frac4 = Frac1 * Frac2;
    cout << "Operator Overloading -->" << endl;
    cout << "Addition of fractions:" << endl;
    cout << Frac1.numerator << "/" << Frac1.denominator << " + " << Frac2.numerator << "/" << Frac2.denominator << " = " << Frac3.numerator << "/" << Frac3.denominator << "\n" << endl;
    cout << "Multiplication of fractions:" << endl;
    cout << Frac1.numerator << "/" << Frac1.denominator << " * " << Frac2.numerator << "/" << Frac2.denominator << " = " << Frac4.numerator << "/" << Frac4.denominator << endl;
}