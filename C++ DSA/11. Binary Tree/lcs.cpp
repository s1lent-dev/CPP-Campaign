#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class binaryTree {
    public:
        TreeNode* buildTree(vector<int> &arr, int &i) {
            if(arr[i] == -1) return nullptr;
            TreeNode* root = new TreeNode(arr[i]);
            i++;
            root->left = buildTree(arr, i);
            i++;
            root->right = buildTree(arr, i);
            return root;
        }
        void dfs(TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            cout << root->val << " ";
            dfs(root->right);
        }
        TreeNode* LCA(TreeNode* root, TreeNode* &p, TreeNode* &q) {
            if(!root) return nullptr;
            if(root->val == p->val || root->val == q->val) return root;
            TreeNode* left = LCA(root->left, p, q);
            TreeNode* right = LCA(root->right, p, q);
            if(left && right) return root;
            return left ? left : right;
        }
        void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* &leaf, int val) {
            if(!root) return;
            if(root->val == val) leaf = root;
            if(root->left) mp[root->left] = root;
            if(root->right) mp[root->right] = root;
            findParent(root->left, mp, leaf, val);
            findParent(root->right, mp, leaf, val);
        }
        int burningTree(TreeNode* leaf, set<TreeNode*> &visited, unordered_map<TreeNode*, TreeNode*> &mp) {
            if(!leaf || visited.count(leaf)) return 0;
            visited.insert(leaf);
            int left = burningTree(leaf->left, visited, mp);
            int right = burningTree(leaf->right, visited, mp);
            int parent = 0;
            if(mp.count(leaf)) parent = burningTree(mp[leaf], visited, mp);
            return 1 + max({left, right, parent});
        }
};



int main() {
    binaryTree bt;
    vector<int> arr = {1, 2, 4, 5, -1, -1, 6, -1, -1, 7, -1, -1, 3, 8, -1, -1, 9, -1, 10, -1, -1};
    int i = 0;
    TreeNode* root = bt.buildTree(arr, i);
    bt.dfs(root);
    cout << endl;
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(10);
    TreeNode* ans = bt.LCA(root, p, q);
    cout << ans->val << endl;
    unordered_map<TreeNode*, TreeNode*> mp;
    set<TreeNode*> visited;
    TreeNode* leaf = nullptr;
    bt.findParent(root, mp, leaf, 6);
    int time = bt.burningTree(leaf, visited, mp);
    cout << time << " ";
    
}