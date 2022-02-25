/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            time[i] %= 60;
            if(time[i] == 0)ans += mp[0];
            else ans += mp[60 - time[i]];
            mp[time[i]]++;
        }
        return ans;
    }
};
// @lc code=end

