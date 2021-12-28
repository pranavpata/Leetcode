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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        
        if (!root)
            return out;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool bR2L = false; // Start from root
        
        while (!q.empty()) {
            
            int qLen = q.size();
            vector<int> vt;
            
            for (int i=0; i<qLen; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (bR2L)
                    vt.insert(vt.begin(), node->val);
                else
                    vt.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            
            bR2L = !bR2L;
            out.push_back(vt);
        }
        
        return out;
    }
};