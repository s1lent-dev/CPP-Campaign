#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// Implementation of stack with the help of array

class stack_arr{
    int index;
    int * arr;
    public:
        stack_arr(){
            index = -1;
            arr = new int[MAX];
        }
    void push(int x){
        arr[++index] = x;
    }
    int pop(){
        int x = arr[index--];
        return x;
    }
    int top(){
        int x = arr[index];
        return x;
    } 
    int size(){
        return index + 1;
    }   
    bool empty(){
        return (index < 0);
    }
};

// Implementation of stack using vectors

class stack_vec {
    int index;
    public:
        vector<int> arr;
        stack_vec() { index = -1; }
    void push(int x){
        ++index;
        arr.push_back(x);
    }
    int pop(){
        int x = arr.back();
        --index;
        arr.pop_back();
        return x;
    }
    int top(){
        int x = arr.back();
        return x;
    }
    int size(){
        return index + 1;
    }
    bool empty(){
        return (index < 0);
    }
};
int main(){

    stack_arr st;
    
    // * Using push operation of stack
    int x;
    cout << "Enter the elements in the stack : " << endl;
    for(int i = 1;i < 6;i++){
        cin >> x;
        st.push(x);
    }
    
    // * Using top opertion of stack 
    cout << " The top element of the stack is : "<< st.top() << endl;
    
    // * Using pop operation of stack
    cout << " The element popped from stack is : "<< st.pop() << endl;

    //* Using size operation of stack
    cout << " The size of the stack is : "<< st.size() << endl;
    
    cout << "Printing stack after popping the top most elemeent :" << endl;
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}