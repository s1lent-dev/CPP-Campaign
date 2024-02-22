#include<iostream>
#include<string>
#include<array>
#include<stack>
#include<queue>
#include<list>
#include<forward_list>

using namespace std;


    int i = 10;
    int sum(int a,int b){
        return a+b;
    }

    void printa(int arr[]){
        for(int i=0;i<4;i++){
            cout << arr[i] << " ";
        }
    }

    void print(stack<int> st){
        stack<int> s = st;
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }

    void printq(queue<int> gq){
        queue<int> q = gq;
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }

    void printfl(forward_list<int> fl){
        for(auto it=fl.begin();it!=fl.end();it++){
            cout << *it << " ";
        }
    }

    void printl(list<int> l){
        for(auto it=l.begin();it!=l.end();it++){
            cout << *it << " ";
        }
    }
int main(){
    
    // Non-Primitive/ Derived data types --> string, array, pointer, reference, function, stack, queue, Linked list, graph, trees.
    string s = "Hello"; // decalring a string
    int arr[] = {1,2,3,4}; // declaring an array
    int *ptr = &i; // declaring a pointer
    int &ref = i; // declaring a reference
    int fun = sum(10,20); // declaring a function
    stack<int> st; // declaring a stack 
    for(int i=0;i<4;i++){
        st.push(arr[i]);
    }
    queue<int> q; // declaring a queue
    for(int i=0;i<4;i++){
        q.push(arr[i]);
    }
    forward_list<int> fl; // declaring a singly linked list
    for(int i=0;i<4;i++){
        fl.push_front(arr[i]);
    }
    list<int> l; // declaring a doubly linked list
    for(int i=0;i<4;i++){
        l.push_back(arr[i]);
    }
    

    cout << "Printing non-primitive data types" << endl;
    cout << s << endl;
    printa(arr);
    cout << endl;
    cout << ptr << " " << *ptr << endl;
    cout << &ref << " " << ref << endl;
    cout << fun << endl;
    print(st);
    cout << endl;
    printq(q);
    cout << endl;
    printfl(fl);
    cout << endl;
    printl(l);

    return 0;

}