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
    void DFS(TreeNode* root) {
        ans.push_back(root->val);
        if(root->left != NULL) DFS(root->left);
        if(root->right != NULL) DFS(root->right);
    }
public:
    // pre = root left right
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        ans.clear();
        DFS(root);
        return ans;
    }
    vector<int> preorderTraversalIterative(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.size()) {
            TreeNode* currNode = st.top();
            st.pop();
            
            ans.push_back(currNode->val);
            if(currNode->right) st.push(currNode->right);
            if(currNode->left) st.push(currNode->left);
            
        }
        
        return ans;
    }
};
