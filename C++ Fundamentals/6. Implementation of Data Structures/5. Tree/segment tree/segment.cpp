#include<bits/stdc++.h>
using namespace std;

class Segment {
    public:
        void buildTree(vector<int> arr, int l, int r, int i) {
            if(l == r) { segment[i] = arr[l]; return; }
            int m = (l + r) / 2;
            buildTree(arr, l, m, (2 * i + 1));
            buildTree(arr, m + 1, r, (2 * i + 2));
            segment[i] = segment[(2 * i + 1)] + segment[(2 * i + 2)];
        }
        void lazyPropogate(int l, int r, int i) {
            if(lazy[i] != 0) {
                segment[i] += (r - l + 1) * lazy[i];
                if(l != r) {
                    lazy[2 * i + 1] += lazy[i];
                    lazy[2 * i + 2] += lazy[i];
                }
                lazy[i] = 0;
            }
        }
        int rangeQuery(int low, int high, int l, int r, int i) {
            lazyPropogate(low, high, i);
            if(high  < l || low > r) return 0;
            if(low >= l && high <= r) return segment[i];
            int m = (low + high) / 2;
            int left = rangeQuery(low, m, l, r, (2 * i + 1));
            int right = rangeQuery(m + 1, high, l, r, (2 * i + 2));
            return left + right;
        }
        void pointUpdate(int l, int r, int x, int val, int i) {
            lazyPropogate(l, r, i);
            if(l == r) { segment[i] = val; return; }
            int m = (l + r) / 2;
            if(x <= m) pointUpdate(l, m, x, val, (2 * i + 1)); 
            else pointUpdate(m + 1, r, x, val, (2 * i + 2));
            segment[i] = segment[(2 * i + 1)] + segment[(2 * i + 2)];
        }
        void rangeUpdate(int low, int high, int l, int r, int i, int val) {
            lazyPropogate(low, high, i);
            if(low > r || high < l) return;
            if(low >= l && high <= r) {
                lazy[i] += val;
                lazyPropogate(low, high, i);
                return;
            }
            int m = (low + high) / 2;
            rangeUpdate(low, m, l, r, (2 * i + 1), val);
            rangeUpdate(m + 1, high, l, r, (2 * i + 2), val);
            segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
        }
    public:
        vector<int> segment;
        vector<int> lazy;
        int n;
    Segment(vector<int> &arr) {
        this->n = arr.size();
        this->segment.resize(4 * n);
        this->lazy.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }
};
int main() {
    vector<int> arr = {2, 6, 12, 20, 30, 42, 22, 16, 8};
    Segment* seg = new Segment(arr);
    for(auto &i : seg->segment) {
        if(i == 0) break;
        cout << i << " ";
    }
    cout << endl;
    vector<pair<int, int>> nums = {{3, 6}, {1, 4}, {4, 7}};
    vector<int> ans(nums.size());
    for(int i = 0;i < nums.size();i++) {
        ans[i] = seg->rangeQuery(0, arr.size() - 1, nums[i].first, nums[i].second, 0);
    }
    for(auto i : ans) cout << i << " ";
    seg->pointUpdate(0, arr.size() - 1, 4, 36, 0);
    cout << endl;
    for(auto &i : seg->segment) {
        if(i == 0) break;
        cout << i << " ";
    }
    cout << endl;
    seg->rangeUpdate(0, arr.size() - 1, 3, 5, 0, 5);
    for(int i = 0;i < nums.size();i++) {
        ans[i] = seg->rangeQuery(0, arr.size() - 1, nums[i].first, nums[i].second, 0);
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    for(auto &i : seg->segment) {
        if(i == 0) break;
        cout << i << " ";
    }
}