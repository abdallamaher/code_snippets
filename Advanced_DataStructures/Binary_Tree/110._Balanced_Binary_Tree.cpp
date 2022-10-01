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
/*
                            1
                    2                  3
              4        5           n       6
           7    n     n  n        n n     8   
          

*/
class Solution {
    // Runtime: 19 ms, faster than 68.26%
    pair<int, bool> DFSS(TreeNode* root) {
        if(root == NULL) return {0, 1};
        
        auto left = DFSS(root->left);
        auto right = DFSS(root->right);
        
        bool diff = abs(left.first - right.first) <= 1;
        int mx = max(left.first, right.first);
        //cout << root->val << ' ' << (diff && left.second && left.second) << ' ' << mx << endl;
        return {1 + mx, diff & left.second & right.second};
    }
    
    int DFS(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = DFS(root->left);
        if(left == -1)return -1;
        
        int right = DFS(root->right);
        if(right == -1)return -1;
        
        int diff = abs(left - right);
        
        return diff > 1 ? -1 : 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        //return DFSS(root).second;
        return DFS(root) != -1;
    }
};
