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
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        DFS(root, mx);
        return mx;
    }
private: 
    // Runtime: 15 ms, faster than 70.51% of C++ 
    int DFS(TreeNode* root, int& mx) {
        if(root == NULL) return 0;
        
        int l = DFS(root->left, mx);
        int r = DFS(root->right, mx);
        
        if(l + r > mx) mx = l + r;
        
        return 1 + max(l, r);
    }
};
