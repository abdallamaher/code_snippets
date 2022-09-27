/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private: 
    TreeNode* dfs(TreeNode* original , TreeNode* cloned, TreeNode* target) {
        if(original == NULL) { 
            return NULL;
        }
        if(original == target) {
            return cloned;
        }
        TreeNode* ans1 = dfs(original->left, cloned->left, target);
        TreeNode* ans2 = dfs(original->right, cloned->right, target);
        return max(ans1, ans2);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //cout << dfs(original, cloned,target);
        return dfs(original, cloned, target);
    }
};
