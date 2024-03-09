#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class queueNode{
    public:
        int data;
        queueNode* next;
        queueNode(int data){
            this->data = data;
            next = NULL;
        }
};

class Queue{
    public:
        queueNode* start;
        queueNode* end;
        int len, maxLen;
        Queue(int maxLen){
            this->maxLen = maxLen;
            len = 0;
            start = nullptr;
            end = nullptr;
        }
    void push(int x){
        if(len == maxLen){
            cout << "Queue is full";
            exit(1);
        }
        queueNode* newNode = new queueNode(x);
        if(start == nullptr){
            end = newNode;
            start = newNode;
        }else{
            end->next = newNode;
            end = end->next;
        }
        len++;
    }
    int pop(){
        if(start == nullptr){
            cout << "Queue is empty";
            exit(1);
        }else{
            int val = start->data;
            queueNode* temp = start;
            start = start->next;
            delete temp;
            --len;
            return val;
        }
    }
    int front(){
        if(start == nullptr){
            cout << "Queue is empty";
            exit(1);
        }
        return start->data;
    }

    int back(){
        return end->data;
    }
    int size(){
        return len;
    }
    bool empty(){
        return (start == nullptr);
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