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
        
        map<int, vector<int>> levels;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()) {
            auto t = q.front();
            TreeNode* curr = t.first;
            int level = t.second;
            q.pop();
            //cerr << level << ' ' << curr->val << endl;
            levels[level].push_back(curr->val);
            
            if(curr->left != NULL)
                q.push({curr->left, level + 1});
            if(curr->right != NULL)
                q.push({curr->right, level + 1});
        }
        //cerr << "here" << endl;
        vector<vector<int>> ans((int)levels.size());
        for(auto& it: levels) {
            for(auto& i: it.second) {
                ans[it.first].push_back(i);
            }
        }
        return ans;
    }
};
