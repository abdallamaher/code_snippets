/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

 // @lc code=start
class Solution {
public:
    // O(n)
    int subarraySum(vector<int>& ar, int k) {
        int n = ar.size();
        for (int i = 1; i < n; i++) ar[i] += ar[i - 1];
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int diff = ar[i] - k;
            ans += mp[diff];
            mp[ar[i]]++;
        }
        return ans;
    }
};
// @lc code=end

