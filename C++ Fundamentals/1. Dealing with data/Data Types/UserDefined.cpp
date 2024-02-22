#include<iostream>
#include<vector>
using namespace std;

class Employee{
    public:
        int id;
        string name;
        double salary;
};

struct Student{
    int rollno;
    string name;
    int age;
};

union Marks{      
    int marks1;
    int marks2;
    int marks3;
};

union Marks1{
    int marks1;
    int marks2;
    int marks3;
} marks_var;

class Union {
    public:
    union {
        int marks1;
        int marks2;
        int marks3;
    };
};

enum day{
    monday=1, tuesday, wednesday, thursday, friday, saturday, sunday
};

enum class day1: int{
    monday=1, tuesday, wednesday, thursday, friday, saturday, sunday
} day_var1, day_var2, day_var3, day_var4, day_var5, day_var6, day_var7;

int main(){

    Employee emp; // Declaring an object of class
    emp.id = 1;
    emp.name = "John";
    emp.salary = 1000;
    cout << "Printing the elements in class Employee" << endl;
    cout << emp.id << " " << emp.name << " " << emp.salary << endl;



    Student std; // Declaring an object of struct
    std.rollno = 10;
    std.name = "peter";
    std.age = 20;
    cout << "Printing the elements in struct Student" << endl;
    cout << std.rollno << " " << std.name << " " << std.age << endl;


    
    Marks marks; // Declaring an object of primitive union
    cout << "Printing the elements in primitive union Marks" << endl;
    marks.marks1 = 15;
    cout << marks.marks1 << " " << &marks.marks1 << endl;
    marks.marks2 = 17;
    cout << marks.marks2 << " " << &marks.marks2 << endl;
    marks.marks3 = 18;
    cout << marks.marks3 << " " << &marks.marks3 << endl;


    
    cout << "Printing the elements in variable union Marks" << endl;
    marks_var.marks1 = 15; // Declaring an object of variable union
    cout << marks_var.marks1 << " " << &marks_var.marks1 << endl;
    marks_var.marks2 = 17;
    cout << marks_var.marks2 << " " <<  &marks_var.marks2 << endl;
    marks_var.marks3 = 18;
    cout << marks_var.marks3 << " " << &marks_var.marks3 << endl;



    cout << "Printing the elements in unscoped enum day" << endl;
    day d1 = monday; // Using unscoped enum
    day d2 = tuesday; 
    day d3 = wednesday; 
    day d4 = thursday; 
    day d5 = friday; 
    day d6 = saturday; 
    day d7 = sunday;
    cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << " " << d6 << " " << d7 << endl;

    for(day d : {monday, tuesday, wednesday, thursday, friday, saturday, sunday}){
        cout << d << " ";
    }
    cout << endl;



    cout << "Printing the elements in scoped enum day1" << endl;
    day1 dy1 = day1::monday; // Using scoped enum
    day1 dy2 = day1::tuesday; 
    day1 dy3 = day1::wednesday; 
    day1 dy4 = day1::thursday; 
    day1 dy5 = day1::friday; 
    day1 dy6 = day1::saturday; 
    day1 dy7 = day1::sunday;
    cout << static_cast<int> (dy1) << static_cast<int> (dy2) << static_cast<int> (dy3) << static_cast<int> (dy4) << static_cast<int> (dy5) << static_cast<int> (dy6) << static_cast<int> (dy7) << endl;
    day_var1 = day1::monday; // Using variable scoped enum
    day_var2 = day1::tuesday; 
    day_var3 = day1::wednesday; 
    day_var4 = day1::thursday; 
    day_var5 = day1::friday; 
    day_var6 = day1::saturday; 
    day_var7 = day1::sunday;
    cout << static_cast<int> (day_var1) << static_cast<int> (day_var2) << static_cast<int> (day_var3) << static_cast<int> (day_var4) << static_cast<int> (day_var5) << static_cast<int> (day_var6) << static_cast<int> (day_var7) << endl;
    


    cout << "Printing the values for typedef" << endl;
    // typedef is used for aliasing of data type which have longer name
    typedef unsigned long long int ulli;
    ulli b = 1397437648376730;
    cout << b << endl;

    typedef vector<vector<int>> vec;
    vec v1 = {{1,2,3},{4,5,6}};
    for(auto i : v1){
        for(auto j : i){
            cout << j << " ";
        }
    }
    cout << endl;

    typedef int mat[5][4];
    mat m1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 4;j++){
            cout << m1[i][j] << " ";
        }
    }
    cout << endl;
    
    int a = 10;
    int c = 20;
    typedef int* ptr;
    ptr p = &a;
    ptr q = &c;

    cout << *p << " " << *q << endl;
}