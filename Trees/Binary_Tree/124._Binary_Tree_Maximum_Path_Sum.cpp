/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        DFS(root, mx);
        return mx;
    }

private: 
    int DFS(TreeNode* root, int& mx) {
        if(root == NULL)return 0;
        
        int l = DFS(root->left, mx);
        int r = DFS(root->right, mx);
        int& val = root->val;
        
        mx = max({mx, val, val + l + r, val + l, val + r});
        
        return max({val, val + l, val + r});
    }
};
