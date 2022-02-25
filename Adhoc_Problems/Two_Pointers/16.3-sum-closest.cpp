/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best_sum = 0;
        int diff = 1e9;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i && nums[i-1] == nums[i])continue;

            int l = i +1, r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(target - sum) < diff){
                    diff = abs(target - sum);
                    best_sum = sum;
                }
                if(target < sum)r--; // sum is big decrease it
                else l++;
            }
        }
        return best_sum;
    }
};
// @lc code=end

