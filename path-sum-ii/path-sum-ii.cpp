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
    vector<vector<int>> toReturn;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        toReturn.clear();
        if (root == nullptr)
            return toReturn;
        vector<int> path;
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                path.push_back(root->val);
                toReturn.push_back(path);
            }
            return toReturn;
        }
        int val = root->val;
        path.push_back(val);
        if (root->left != nullptr) 
            findPath(path, root->left, targetSum - val);
        if (root->right != nullptr)
            findPath(path, root->right, targetSum - val);
        return toReturn;
    }
    
    void findPath(vector<int> path, TreeNode* root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                path.push_back(root->val);
                toReturn.push_back(path);
            }
            return;
        }
        int val = root->val;
        path.push_back(val);
        if (root->left != nullptr) 
            findPath(path, root->left, targetSum - val);
        if (root->right != nullptr)
            findPath(path, root->right, targetSum - val);
    }
};