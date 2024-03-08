#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Creatig a node of linked list using class
class Node {
    public:
        int data;
        Node* next;
        Node(){
            this->data = 0;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }
};

//Creating a node of Linekd list using struct
struct node {
    public: 
        int data;
        node* next;
        node(){
            this->data = 0;
            this->next = NULL;
        }
        node(int data){
            this->data = data;
            this->next = NULL;
        }
        node(int data, node* next){
            this->data = data;
            this->next = next;
        }
};

//Creating linked list

class LinkedList{
    Node* head;

    public:
        LinkedList(){
            head = NULL;
        }
        void InsertNode(int);
        void PrintList();
        void DeleteNode(int);
};

void LinkedList::InsertNode(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }

    Node* pre = head;
    while(pre->next != NULL){
        pre = pre->next;
    }
    pre->next = newNode;
}

void LinkedList::DeleteNode(int nodeOffset){
    Node* temp1 = head; 
    Node* temp2 = NULL;
    int size = 0;

    if(head == NULL){ // check whether the linked list is empty or not
        cout << "Linked list is empty" << endl;
        return;
    }

    while(temp1 != NULL){ // count the size of the linked list
        temp1 = temp1->next;
        size++;
    }

    if(size < nodeOffset){ //check if the node can be deleted of offset --> nodeOffset
        cout << "Index out of bound" << endl;
        return;
    }

    temp1 = head; // reallocate start node to head
    if(nodeOffset == 1){
        head = head->next;
        delete temp1;
        return;
    }

    while(nodeOffset > 1){
        temp2 = temp1;
        temp1 = temp1->next;
        nodeOffset--;
    }
    temp2->next = temp1->next;
    delete temp1;
}

void LinkedList::PrintList(){
    Node* temp = head;
    while(head == NULL){
        cout << "LinkedList is empty" << endl;
        return;
    }
    while(temp != NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){

    LinkedList list;
    int n = 6;
    int x;
    cout << "Enter elements in the linked list: " << endl;
    for(int i = 0;i < n;i++){
        cin >> x;
        list.InsertNode(x);
    }
    cout << "Printing the linked list" << endl;
    list.PrintList();
    cout << endl;
    
    cout << "Enter the NodeOffset of linkedlist to delete: " << endl;
    int y;
    cin >> y;
    list.DeleteNode(y);
    
    cout << "Printing the Linkedlist after the deletion of a node" << endl;
    list.PrintList();
    cout << endl;

    return 0;
}