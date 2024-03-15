#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

class binarySearchTree{
    public:
        Node* root;
        binarySearchTree() {}
    
    Node* buildTree(Node* root, int data){
        if(root == nullptr){
            root = new Node(data);
            return root;
        }
        if(data < root->data){
            root->left = buildTree(root->left, data);
        }else if(data > root->data){
            root->right = buildTree(root->right, data);
        }
        return root;
    }

    void takeInput(Node* &root){
        int data;
        cout << "Enter the value of the root : " << endl;
        cin >> data;
        while(data != -1){
            root = buildTree(root, data);
            cout << "Enter the value of the node : " << endl;
            cin >> data;
        }
    }

        //* Breadth First Search -->

        void levelorderTraversal(Node* root){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* newNode = q.front();
                cout << newNode->data << " ";
                q.pop();
                if(newNode->left) q.push(newNode->left);
                if(newNode->right) q.push(newNode->right);
            }
            cout << endl;
        }

        //* Depth First Search -->

        //* PreOrderTraversal in binary tree
        void preorderTraversal(Node* root){
            if(!root) return;
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        
        //* InOrderTraversal in binary tree
        void inordertraversal(Node* root){
            if(!root) return;
            inordertraversal(root->left);
            cout << root->data << " ";
            inordertraversal(root->right);
        }
        
        //* PostOrderTraversal in binary tree 
        void postorderTraversal(Node* root){
            if(!root) return;
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }

        void printTree(Node* root, int depth = 0) {
        if (root == nullptr) return;
        // Print right child first
        printTree(root->right, depth + 1);
        // Indent based on depth
        cout << string(depth * 4, ' ');
        // Print node's value
        cout << root->data << endl;
        // Print left child
        printTree(root->left, depth + 1);
    }
};
int main(){

    binarySearchTree* bst;
    Node* root = nullptr;

    bst->takeInput(root);
    
    cout << "Level Order Traversal of the Tree: " << endl;
    bst->levelorderTraversal(root);

    cout << "Pre Order Traversal of the Tree: " << endl;
    bst->preorderTraversal(root);
    cout << endl;

    cout << "In Order Traversal of the Tree: " << endl;
    bst->inordertraversal(root);
    cout << endl;

    cout << "Post Order Traversal of the Tree: " << endl;
    bst->postorderTraversal(root);
    cout << endl;

    cout << "Graphical Represenatation of Tree: " << endl;
    bst->printTree(root);
}