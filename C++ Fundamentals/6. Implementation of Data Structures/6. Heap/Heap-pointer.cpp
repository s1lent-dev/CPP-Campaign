#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Heap {
    public:
        Node* root;
        Heap() {
            this->root = nullptr;
        }

        void bfs(Node* root) {
            if (root == nullptr) {
                return;
            }
            queue<Node*> q;
            q.push(root);
            while(!q.empty()) {
                Node* temp = q.front();
                q.pop();
                cout << temp->val << " ";
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }

        void InsertHelper(Node* &node, int val) {
            if(node == nullptr) {
                node = new Node(val);
                return;
            }
            if(val > node->val) {
                swap(val, node->val);
            }
            if(node->left == nullptr) {
                node->left = new Node(val);
            } else if(node->right == nullptr) {
                node->right = new Node(val);
            } else {
                if(countNodes(node->left) <= countNodes(node->right)) {
                    InsertHelper(node->left, val);
                } else {
                    InsertHelper(node->right, val);
                }
            }
        }

        void insert(int val) {
            InsertHelper(root, val);
        }

        int countNodes(Node* node) {
            if(node == nullptr) {
                return 0;
            }
            return 1 + countNodes(node->left) + countNodes(node->right);
        }
};

int main() {
    Heap* h = new Heap();
    h->insert(10);
    h->insert(15);
    h->insert(20);
    h->bfs(h->root);

    return 0;
}
