/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

 // @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        int n = ar.size();
        vector<int> output(n, 1); // output array does not count extra space
        for (int i = 1; i < n; i++) {
            output[i] = output[i - 1] * ar[i - 1];
        }
        int r = 1;
        for (int i = n - 2; i >= 0; i--) {
            r *= ar[i + 1];
            output[i] *= r;
        }
        return output;
    }

    vector<int> productExceptSelfLinerSpace(vector<int>& ar) {
        int n = ar.size();
        vector<int> l(n + 2, 1), r(n + 2, 1);
        for (int i = 1; i <= n; ++i) {
            l[i] = ar[i - 1] * l[i - 1];
        }
        for (int i = n; i > 0; i--) {
            r[i] = ar[i - 1] * r[i + 1];
        }
        for (int i = 1;i <= n; i++) {
            ar[i - 1] = l[i - 1] * r[i + 1];
        }
        return ar;
    }
};
// @lc code=end

