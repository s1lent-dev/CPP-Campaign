// ! Implementation of Binary tree using recursion
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// * Definition of a node in a binary tree
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

//* Implementation of binary tree and traversal in binary tree
class binaryTree{
    public:
        binaryTree() {}
        
        //* Building a tree using recursion
        Node* buildTree(){
            int data;
            cout << "Enter the node :" << " ";
            cin >> data;
            if(data == -1) return nullptr;
            Node* newNode = new Node(data);
            cout << "Enter the data to the left of the node " << data << endl;
            newNode->left = buildTree();
            cout << "Enter the data to the right of the node " << data << endl;
            newNode->right = buildTree();
            return newNode;
        }

        //* Bulinding a tree using level-order-Traversal
        Node* buildTree(Node* root){
            queue<Node*> q;
            cout << "Enter Data for root : " << endl;
            int data;
            cin >> data;
            root = new Node(data);
            q.push(root);
            while(!q.empty()){
                Node* newNode = q.front();
                q.pop();

                cout << "Enter the data to the left of " << newNode->data << endl;
                int leftData;
                cin >> leftData;
                if(leftData != -1){
                    newNode->left = new Node(leftData);
                    q.push(newNode->left);
                }
            
                cout << "Enter the data to the right of " << newNode->data << endl;
                int rightData;
                cin >> rightData;
                if(rightData != -1){
                    newNode->right = new Node(rightData);
                    q.push(newNode->right);
                }
            }
            return root;
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

    binaryTree* bt = new binaryTree();
    Node* root = bt->buildTree(); //* Building a tree using recusrion 

    /* //? Uncomment this and comment the above bulidtree to build the tree using level order traversal
    * Node* root = nullptr;
    * root = bt->buildTree(root);
    */

    cout << "Level Order Traversal of the Tree: " << endl;
    bt->levelorderTraversal(root);

    cout << "Pre Order Traversal of the Tree: " << endl;
    bt->preorderTraversal(root);

    cout << "In Order Traversal of the Tree: " << endl;
    bt->inordertraversal(root);

    cout << "Post Order Traversal of the Tree: " << endl;
    bt->postorderTraversal(root);
    
    cout << "Graphical Represenatation of Tree: " << endl;
    bt->printTree(root);
} 