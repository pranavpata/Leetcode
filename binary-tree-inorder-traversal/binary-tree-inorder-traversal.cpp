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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> toReturn;
        traverse(root, toReturn);
        return toReturn;
    }
    
    void traverse(TreeNode* root, vector<int>& toReturn) {
        if (!root) return;
        
        traverse(root->left, toReturn);
        toReturn.push_back(root->val);
        traverse(root->right, toReturn);
    }
};