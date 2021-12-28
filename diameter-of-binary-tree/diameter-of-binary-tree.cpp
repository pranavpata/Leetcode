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
    int maxVal = INT_MIN;
    
    int recurse(TreeNode* node) {
        if (!node) return 0;
        int left = recurse(node->left);
        int right = recurse(node->right);
        if (left + right > maxVal) maxVal = left + right;
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        recurse(root);
        return maxVal;
    }
};