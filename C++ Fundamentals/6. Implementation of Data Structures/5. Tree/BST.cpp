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
        
        //* Search element in a BST
        bool searchNode(Node* root, int data){
            if(!root) return false;
            if(data == root->data) return true;
            if(data < root->data){
                searchNode(root->left, data);
            }
            if(data > root->data){
                searchNode(root->right, data);
            }
        }

        //* Delete a Node from BST
        Node* deleteNode(Node* root, int data){
            if(!root) return nullptr;
            if(root->data == data){
                if(!root->left && !root->right){
                    delete root;
                    return nullptr;
                }else if(!root->right){
                    Node* temp1 = root->left;
                    delete root;
                    return temp1;
                }else if(!root->left){
                    Node* temp2 = root->right;
                    delete root;
                    return temp2;
                }else if(root->left && root->right){
                    int min = minData(root->right) -> data;
                    root->data = min;
                    root->right = deleteNode(root->right, min);
                    return root;
                }
            }else if(data < root->data){
                root->left = deleteNode(root->left, data);
                return root;
            }else if(data > root->data){
                root->right = deleteNode(root->right, data);
                return root;
            }
        }

        //* Function to find Minumum element to the right of the node to be deleted
        Node* minData(Node* root){
            if(!root->left) return root;
            root = root->left;
        }

        //* Graphical representation of tree
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
    
    int data;
    cout << "Enter the data to search iun BST: " << endl;
    cin >> data;

    bst->searchNode(root, data);
    if(bst->searchNode(root, data)){
        cout << "The number found in BST" << endl;
    }else{
        cout << "The number is not present in the BST" << endl;
    }

    int val;
    cout << "Enter the Node to be deleted: " << endl;
    cin >> val;
    bst->deleteNode(root, val);
    
    cout << "The BST after deletion of the nodes: " << endl;
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