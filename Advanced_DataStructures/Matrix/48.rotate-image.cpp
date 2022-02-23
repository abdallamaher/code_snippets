/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

 // @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int square = 0; square < n / 2; square++) {
            for (int i = square; i + square + 1 < n; i++) {
                int tmp = matrix[square][i];
                matrix[square][i] = matrix[n - i - 1][square];
                matrix[n - i - 1][square] = matrix[n - square -1][n - i -  1];
                matrix[n - square -1][n - i -  1] = matrix[i][n -square -1];
                matrix[i][n-square-1] = tmp;
            }
        }
    }

    // O(n^2)
    void rotate__(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
                if (i == j)break;
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end

