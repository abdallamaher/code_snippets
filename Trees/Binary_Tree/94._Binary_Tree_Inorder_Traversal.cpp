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
    vector<int> ans;
    // inorder = left root right
    void DFS(TreeNode* root) {
        if(root->left != NULL)
            DFS(root->left);
        
        ans.push_back(root->val);
        
        if(root->right != NULL)
            DFS(root->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        ans.clear();
        DFS(root);
        return ans;
    }
};
