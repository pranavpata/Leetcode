/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recurse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (p == root) return root;
        if (q == root) return root;
        TreeNode* left = recurse(root->left, p, q);
        TreeNode* right = recurse(root->right, p, q);
        if (left || right) {
            if (left == p && right == q || right == p && left == q) {
                return root;
            }
            else if (!right) {
                return left;
            }
            else {
                return right;
            }
        }
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recurse(root, p , q);
    }
};