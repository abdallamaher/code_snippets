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
// Runtime: 0 ms, faster than 100.00% of C++ 
class Solution {
    vector<int> ans;
    // post = left right root
    void DFS(TreeNode* root) {
        if(root->left != NULL) DFS(root->left);
        if(root->right != NULL)DFS(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        ans.clear();
        DFS(root);
        return ans;
    }
};
