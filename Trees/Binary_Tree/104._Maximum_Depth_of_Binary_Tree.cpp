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
    // Runtime: 12 ms, faster than 71.14% of C++
    int DFS(TreeNode* root) {
        if(root == NULL) return 0;
        int levels = 1;
        levels += max(DFS(root->left), DFS(root->right));
        return levels;
    }
    // Runtime: 3 ms, faster than 99.37% of C++
    int BFS(TreeNode* root) {
        if(root == NULL)return 0;
        int mx_level = 1;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 1});
        while(q.size()) {
            auto t = q.front();
            q.pop();
            TreeNode* currNode = t.first;
            int level = t.second;
            
            if(level > mx_level)mx_level = level;
            
            if(currNode->left)q.push({currNode->left, level + 1});
            if(currNode->right)q.push({currNode->right, level + 1});
        }
        return mx_level;
    }
public:
    int maxDepth(TreeNode* root) {
        // return DFS(root);
        return BFS(root);
    }
};
