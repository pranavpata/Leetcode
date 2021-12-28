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
    //dir = -1 if left, 0 for root, 1 for right
    bool isValid(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (min < root->val && max > root->val) {
            return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int val = root->val;
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};