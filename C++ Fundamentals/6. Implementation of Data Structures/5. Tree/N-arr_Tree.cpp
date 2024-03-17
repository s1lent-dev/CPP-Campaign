#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        vector<Node*> child;

        Node(int data){
            this->data = data;
        }
};

class N_Tree{
    public:
        N_Tree(){}
    
    Node* buildTree(Node* root){
        int size;
        cout << "Enter the number of children for node " << root->data << " (-1 to stop): ";
        cin >> size;

        if(size == -1) return nullptr;
        for(int i = 0;i < size;i++){
            int data;
            cout << "Enter the value of child " << i + 1 << " of node " << root->data << ": ";
            cin >> data;
            Node* child = new Node(data);
            root->child.push_back(child);
            buildTree(child);
        }
        return root;
    }

    void takeInput(Node* &root){
        int data;
        cout << "Enter the value of the root node: " << endl;
        cin >> data;
        root->data = data;
        buildTree(root);
    }

    void levelorderTraversal(Node* root){
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";
            for(Node* child : node->child){
                q.push(child);
            }
        }
    }

    void preorderTraversal(Node* root){
        if(!root) return;
        cout << root->data << " ";
        for(Node* child : root->child){
            preorderTraversal(child);
        }
    }

    void inorderTraversal(Node* root) {
        if (root == nullptr) return;
        for (int i = 0; i < root->child.size(); i++) {
            inorderTraversal(root->child[i]);
            if (!root->child.empty() && (i != 0 && i < root->child.size() - 1)) {
                cout << root->data << " ";
            }else if(!root->child.empty() && root->child.size() == 1){
                cout << root->data << " ";
            }
        }
        if(root->child.empty()) cout << root->data << " ";
    }

    void postorderTraversal(Node* root){
        if(!root) return;
        for(Node* child : root->child){
            postorderTraversal(child);
        }
        cout << root->data << " ";
    }

    void printIndented(Node* root, int depth = 0) {
        if (!root) return;
        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }
        cout << "|-- " << root->data << endl;
        for (Node* child : root->child) {
            printIndented(child, depth + 1);
        }
    }
};
int main(){

    N_Tree* nt;
    Node* root = new Node(0);
    nt->takeInput(root);
    
    cout << "LevelOrder Traversal of N-arr Tree : " << endl;
    nt->levelorderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal of N-arr Tree : " << endl;
    nt->preorderTraversal(root);
    cout << endl;

    cout << "InOrder Traversal of N-arr Tree : " << endl;
    nt->inorderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal of N-arr Tree : " << endl;
    nt->postorderTraversal(root);
    cout << endl;

    cout << "Graphical representation of the tree : " << endl;
    nt->printIndented(root, 0);
    cout << endl;
    return 0;
}