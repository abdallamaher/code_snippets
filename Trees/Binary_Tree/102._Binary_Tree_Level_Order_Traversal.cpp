// Runtime: 6 ms, faster than 61.97% of C++
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> levels;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(q.size()) {
            auto t = q.front();
            TreeNode* curr = t.first;
            int level = t.second;
            q.pop();
            
            while(level >= (int)levels.size())
                levels.push_back(vector<int>());
            levels[level].push_back(curr->val);
            
            if(curr->left != NULL)
                q.push({curr->left, level + 1});
            if(curr->right != NULL)
                q.push({curr->right, level + 1});
        }
    
        return levels;
    }
};