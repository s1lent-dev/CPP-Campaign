#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int partition(vector<int> &nums, int i, int j) {
            int pivot = nums[i];
            int l = i;
            int r = j;
            while(l < r) {
                while(pivot >= nums[l] && l < j) l++;
                while(pivot < nums[r] && r > i) r--;
                if(l < r) swap(nums[l], nums[r]);
            }
            swap(nums[i], nums[r]);
            return r;
        }
        void qs(vector<int> &nums, int i, int j) {
            if(i < j) {
                int pIndx = partition(nums, i, j);
                qs(nums, i, pIndx - 1);
                qs(nums, pIndx + 1, j);
            }
        }
        vector<int> quickSort(vector<int> nums) {
            qs(nums, 0, nums.size() - 1);
            return nums;
        }
};
int main() {
    Solution sol;
    vector<int> nums = {9,2,8,3,7,4,6,5};
    for(int i : nums) {
        cout << i << " ";
    }
    vector<int> ans = sol.quickSort(nums);
    cout << endl;
    for(int i : ans) {
        cout << i << " ";
    }
}