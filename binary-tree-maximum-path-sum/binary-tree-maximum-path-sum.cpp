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
    int maxSum = INT_MIN;
public:
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        
        int left = max(maxGain(node->left), 0);
        int right = max(maxGain(node->right), 0);
        
        int newPath = node->val + left + right;
        maxSum = max(maxSum, newPath);
        
        return node->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};