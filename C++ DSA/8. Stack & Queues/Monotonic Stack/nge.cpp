#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Next Greater Element
        vector<int> nge(vector<int> &nums) {
            stack<int> st;
            vector<int> nge(nums.size());
            for(int i = nums.size() - 1; i >= 0; i--) {
                while(!st.empty() && st.top() <= nums[i]) st.pop();
                nge[i] = !st.empty() ? st.top() : -1;
                st.push(nums[i]);
            }
            return nge;
        }

        // Next Smaller Element
        vector<int> nse(vector<int> &nums) {
            stack<int> st;
            vector<int> nse(nums.size());
            for(int i = nums.size() - 1; i >= 0; i--) {
                while(!st.empty() && st.top() >= nums[i]) st.pop();
                nse[i] = !st.empty() ? st.top() : -1;
                st.push(nums[i]);
            }
            return nse;
        }

        // Previous Greater Element
        vector<int> pge(vector<int> &nums) {
            stack<int> st;
            vector<int> pge(nums.size());
            for(int i = 0; i < nums.size(); i++) {
                while(!st.empty() && st.top() <= nums[i]) st.pop();
                pge[i] = !st.empty() ? st.top() : -1;
                st.push(nums[i]);
            }
            return pge;
        } 

        // Previuos Smaller Element
        vector<int> pse(vector<int> &nums) {
            stack<int> st;
            vector<int> pse(nums.size());
            for(int i = 0; i < nums.size(); i++) {
                while(!st.empty() && st.top() >= nums[i]) st.pop();
                pse[i] = !st.empty() ? st.top() : -1;
                st.push(nums[i]);
            }
            return pse;
        }
};
int main() {
    Solution s;
    vector<int> nums = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> nge = s.nge(nums);
    for(auto i : nge) cout << i << " ";
    cout << endl;
    vector<int> nse = s.nse(nums);
    for(auto i : nse) cout << i << " ";
    cout << endl;
    vector<int> pge = s.pge(nums);
    for(auto i : pge) cout << i << " ";
    cout << endl;
    vector<int> pse = s.pse(nums);
    for(auto i : pse) cout << i << " ";
    cout << endl;
    return 0;
}