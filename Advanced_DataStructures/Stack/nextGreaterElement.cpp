#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while (s.size() && s.top() < nums2[i]) {
                mp[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while (s.size()) {
            mp[s.top()] = -1;
            s.pop();
        }
        vector<int> ans;
        for (int i = 0;i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};


int main() {
    return 0;
}