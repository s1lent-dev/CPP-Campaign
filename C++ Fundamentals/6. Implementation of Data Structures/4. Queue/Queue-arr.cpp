#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int start,end;
        int len,maxLen;
        int * arr;
        Queue(){
            start = -1;
            end = -1;
            len = 0;
            maxLen = 16;
            arr = new int[maxLen];
        }
        Queue(int maxLen){
            start = -1;
            end = -1;
            len = 0;
            this->maxLen = maxLen;
            arr = new int[maxLen];
        }
    void push(int x){
        if(len == maxLen){
            cout << "Queue is full";
            exit(1);
        }
        if(end == -1){
            start = 0;
            end = 0;
        }else{
            end = (end + 1) % maxLen;
        }
        arr[end] = x;
        ++len;
    }
    int pop(){
        if(start == -1){
            cout << "Queue is empty";
            exit(1);
        }
        int val = arr[start];
        if(len == 1){
            start = -1;
            end = -1;
        }else{
            start = (start + 1) % maxLen;
        }
        --len;
        return val;
    }
    int front(){
        if(start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int back(){
        return arr[end];
    }
    int size(){
        return len;
    }
    bool empty(){
        return (start == -1);
    }
};
int main(){
    
    Queue q(10);

    //* Using push operation of queue
    int x;
    cout << "Enter the elements in a queue : " << endl;
    for(int i = 0;i < 5;i++){
        cin >> x;
        q.push(x);
    }

    //* Using front and back operation of queue
    cout << "This is the first element of queue : " << q.front() << " & " << "This is the last element of the queue : " << q.back() << endl;

    //* Using pop operqation of queue
    cout << "The element popped form the queue is : " << q.pop() << endl;

    //* Using size operation of queue
    cout << "The size of the queue is : " << q.size() << endl;

    //* Using empty operation of the queue
    cout << "Printing queue after popping first element : " << endl;
    while(!q.empty()){
        cout << "[" << q.front()<< "]" << "-->";
        q.pop(); 
    }
    cout << "NULL";
}