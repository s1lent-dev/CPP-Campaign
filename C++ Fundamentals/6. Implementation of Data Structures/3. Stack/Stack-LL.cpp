#include<iostream> 
#include<bits/stdc++.h>
using namespace std;


class stackNode{
    public:
        int data;
        stackNode* next;
        stackNode(int data){
            this->data = data;
            next = NULL;
        }
};

class Stack{
    public:
        stackNode* index;
        int len;
        Stack(){
            index = NULL;
            len = 0;
        }
    void push(int x){
        stackNode* newNode = new stackNode(x);
        newNode->next = index;
        index = newNode;
        len++;
    }
    int pop(){
        if(index == NULL) return -1;
        int val = index->data;
        stackNode* temp = index;
        index = index->next;
        delete temp;
        --len;
        return val;
    }
    int top(){
        if(index == NULL) return -1;
        return index->data;
    }
    int size(){
        return len;
    }
    bool empty(){
        return (index == NULL);
    }

};
int main(){

    Stack st;
    
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