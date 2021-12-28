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
    void recurse(TreeNode* node, unordered_map<int, int>& values) {
        if (!node) return;
        values[node->val]++;
        recurse(node->left, values);
        recurse(node->right, values);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> toReturn;
        unordered_map<int, int> values;
        recurse(root, values);
        
        int max_fr = 0;
        for(auto i=values.begin();i!=values.end();i++)
        {
            max_fr = max(max_fr,i->second);
        }
        
        for(auto i=values.begin();i!=values.end();i++)
        {
            if(i->second == max_fr)
            {
                toReturn.push_back(i->first);
            }
        }
        return toReturn;
    }
};