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
    // Runtime: 10 ms
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return vector<int>();
        
        vector<int> ans;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(q.size()) {
            pair<TreeNode*, int> t = q.front();
            TreeNode* currNode = t.first;
            int level = t.second;
            
            ans.push_back(currNode->val);
            
            while(q.size() && q.front().second == level) {
                currNode = q.front().first;
                q.pop();
                
                if(currNode->right)
                    q.push({currNode->right, level + 1});               
                if(currNode->left) 
                    q.push({currNode->left, level + 1});                
            }
        }
        
        return ans;
    }
    // Runtime: 6 ms, faster than 52.32% 
    vector<int> rightSideView2(TreeNode* root) {
        if(root == NULL)return vector<int>();
        
        vector<int> ans;
        map<int, bool> mark;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(q.size()) {
            pair<TreeNode*, int> t = q.front();
            TreeNode* currNode = t.first;
            int level = t.second;
            q.pop();
            
            if(mark[level] == 0) {
                ans.push_back(currNode->val);
                mark[level] = 1;
            }
            
            if(currNode->right)
                q.push({currNode->right, level + 1});
            if(currNode->left) 
                q.push({currNode->left, level + 1});
        }
        
        return ans;
    }
};
