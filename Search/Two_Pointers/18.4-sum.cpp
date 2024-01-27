/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++){
            if(i && nums[i-1] == nums[i])continue;
            for(int j=i+1; j<n-2; j++){
                if(i+1 < j && nums[j-1] == nums[j])continue;
                int l = j + 1, r = n-1;
                while(l < r){
                    long long sum = 1ll * nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    }
                    if(sum >= target){
                        r--;
                        while(l < r && nums[r] == nums[r + 1])r--;
                    }
                    else if(sum <= target){
                        l++;
                        while(l < r && nums[l - 1] == nums[l])l++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

