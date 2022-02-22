/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

 // @lc code=start
class Solution {
public:
    // O(N)
    void nextPermutation(vector<int>& ar) {
        int n = ar.size();
        int peak = -1;
        for (int i = 1; i < n; i++) {
            if (ar[i - 1] < ar[i]) peak = i;
        }

        if (peak == -1) {
            for (int i = 0; i < n / 2; i++) {
                swap(ar[i], ar[n - i - 1]);
            }
            return;
        }
        int mn_idx = peak;
        for (int i = peak; i < n; i++) {
            if (ar[peak - 1] < ar[i] && ar[mn_idx] >= ar[i])
                mn_idx = i;
        }
        swap(ar[peak - 1], ar[mn_idx]);
        reverse(ar.begin() + peak, ar.end());
        return;
    }
};
// @lc code=end

