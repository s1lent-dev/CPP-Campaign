#include<bits/stdc++.h>
using namespace std;

enum Color {RED, BLACK};
struct TreeNode {
    public:
        int val;
        Color color; 
        TreeNode* parent;
        TreeNode* left;
        TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->color = RED;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Red_Black {
    private:
        TreeNode* root;
    protected:
        void rotateLeft(TreeNode*);
        void rotateRight(TreeNode*);
        void fixViolation(TreeNode*);
    private:
        TreeNode* insertHelper(TreeNode*, TreeNode*);
        void preorderHelper(TreeNode*);
        void inorderHelper(TreeNode*);
        void postorderHelper(TreeNode*);
        void levelorderHelper(TreeNode*);
    public:
        Red_Black() { this->root = nullptr; }
        void insert(int val);
        void preorder();
        void inorder();
        void postorder();
        void levelorder();
};
void Red_Black::rotateLeft(TreeNode* node) {
    TreeNode* newNode = node->right;
    node->right = newNode->left;
    if(node->right) node->right->parent = node;
    newNode->parent = node->parent;
    if(!node->parent) this->root = newNode;
    else if(node == node->parent->left) node->parent->left = newNode;
    else node->parent->right = newNode;
    newNode->left = node;
    node->parent = newNode;
}
void Red_Black::rotateRight(TreeNode* node) {
    TreeNode* newNode = node->left;
    node->left = newNode->right;
    if(node->left) node->left->parent = node;
    newNode->parent = node->parent;
    if(!node->parent) this->root = newNode;
    else if(node == node->parent->left) node->parent->left = newNode;
    else node->parent->right = newNode;
    newNode->right = node;
    node->parent = newNode;
}
void Red_Black::fixViolation(TreeNode* node) {
    TreeNode* parent = nullptr;
    TreeNode* grandParent = nullptr;
    while((node != root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandParent = node->parent->parent;
        if(parent == grandParent->left) {
            TreeNode* uncle = grandParent->right;
            if(uncle && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandParent;
            } else {
                if(node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(grandParent);
                swap(parent->color, grandParent->color);
                node = parent;
            }
        } else {
            TreeNode* uncle = grandParent->left;
            if(uncle && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandParent;
            } else {
                if(node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateLeft(grandParent);
                swap(parent->color, grandParent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}
TreeNode* Red_Black::insertHelper(TreeNode* root, TreeNode* node) {
    if(!root) return node;
    if(node->val < root->val) {
        root->left = insertHelper(root->left, node);
        root->left->parent = root;
    } else if(node->val > root->val) {
        root->right = insertHelper(root->right, node);
        root->right->parent = root;
    }
    return root;
}
void Red_Black::insert(int val) {
    TreeNode* node = new TreeNode(val);
    this->root = insertHelper(this->root, node);
    fixViolation(node);
}
void Red_Black::inorderHelper(TreeNode* root) {
    if(!root) return;
    inorderHelper(root->left);
    cout << root->val << " ";
    inorderHelper(root->right);
}
void Red_Black::inorder() {
    inorderHelper(this->root);
    cout << endl;
}
int main() {
    Red_Black rb;
    rb.insert(20);
    rb.insert(30);
    rb.insert(40);
    rb.insert(35);
    rb.insert(10);
    rb.insert(15);
    rb.insert(25);
    rb.inorder();
}