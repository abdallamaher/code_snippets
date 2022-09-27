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
private: 
    int sumChilds(TreeNode* N) {
        int sum = 0;
        if(N->left != NULL) sum += N->left->val;
        if(N->right != NULL) sum += N->right->val;
        return sum;
    }
public:
    bool checkTree(TreeNode* root) {
     return root->val == sumChilds(root) ? true: false;
    }
};
