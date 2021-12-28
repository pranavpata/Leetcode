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
    int minDepth(TreeNode* root) {
        return depth(root);
    }
    
    int depth(TreeNode* root) {
        if (!root) return 0;
        else if (!root->left && !root->right) return 1;
        else {
            int left = INT_MAX;
            int right = INT_MAX;
            if (root->left) left = depth(root->left);
            if (root->right) right = depth(root->right);
            return 1 + min(left, right);
        }
    }
};