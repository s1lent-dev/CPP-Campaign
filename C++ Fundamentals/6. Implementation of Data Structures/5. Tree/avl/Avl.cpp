#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    public:
        int val, height;
        TreeNode* left;
        TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->height = 1; // Initial height of new node is 1 (itself).
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVL {
    private:
    // Helper function to get the height of a node.
    int height(TreeNode* node) {
        if(!node) return 0;
        return node->height;
    }
    
    // Helper function to calculate the balance factor of a node.
    int getBalance(TreeNode* node) {
        if(!node) return 0;
        return height(node->left) - height(node->right);
    }
    
    // Left rotate subtree rooted with node.
    TreeNode* leftRotate(TreeNode* node) {
        TreeNode* newNode = node->right;
        TreeNode* temp = newNode->left;

        // Perform rotation.
        newNode->left = node;
        node->right = temp;

        // Update heights.
        node->height = 1 + max(height(node->left), height(node->right));
        newNode->height = 1 + max(height(newNode->left), height(newNode->right));

        // Return new root.
        return newNode;
    }
    
    // Right rotate subtree rooted with node.
    TreeNode* rightRotate(TreeNode* node) {
        TreeNode* newNode = node->left;
        TreeNode* temp = newNode->right;

        // Perform rotation.
        newNode->right = node;
        node->left = temp;

        // Update heights.
        node->height = 1 + max(height(node->left), height(node->right));
        newNode->height = 1 + max(height(newNode->left), height(newNode->right));

        // Return new root.
        return newNode;
    }

    // Recursive function to insert a value in the subtree rooted with node and balance the tree.
    TreeNode* insertHelper(TreeNode* node, int val) {
        // Step 1: Perform normal BST insertion.
        if(!node) return new TreeNode(val);

        if(val < node->val) 
            node->left = insertHelper(node->left, val);
        else if(val > node->val) 
            node->right = insertHelper(node->right, val);
        else // Equal values are not allowed in the AVL tree.
            return node;

        // Step 2: Update the height of this ancestor node.
        node->height = 1 + max(height(node->left), height(node->right));

        // Step 3: Get the balance factor of this ancestor node to check whether it became unbalanced.
        int balance = getBalance(node);

        // If the node is unbalanced, then there are 4 cases to handle.

        // Case 1: Left Left (LL) Case.
        if(balance > 1 && val < node->left->val) 
            return rightRotate(node);

        // Case 2: Right Right (RR) Case.
        if(balance < -1 && val > node->right->val) 
            return leftRotate(node);

        // Case 3: Left Right (LR) Case.
        if(balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Case 4: Right Left (RL) Case.
        if(balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer.
        return node;
    }

    public:
        TreeNode* root = nullptr;

        // Function to insert a new value in the AVL tree.
        void insert(int val) {
            root = insertHelper(root, val);
        }

        // Inorder traversal of the AVL tree.
        void inorder(TreeNode* root) {
            if(!root) return;
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
};

int main() {
    AVL avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(35);
    avl.insert(50);

    TreeNode* root = avl.root;
    avl.inorder(root); // Should print the AVL tree in ascending order.
}
