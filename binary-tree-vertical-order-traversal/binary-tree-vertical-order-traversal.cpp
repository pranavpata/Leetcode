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

/*
not an empty tree
node value is 0 to a 1000

I: root node of a binary tree (not necessarily a binary search tree)
O: vector<vector<int>>

Approach 1 (dfs solution): do this recursively , keep track of column number
    every time I go to the left, column number decreases, and increases vice versa
    deal with the fact that the column number can be negative
    I could traverse through the tree, and store all of the coordinates of each node as a pair(value, col)
    At the very end I would sort the pairs by column (second element), and then return result grouped by columns
    - n is the number of nodes
    
    vector<pair<int, pair<int, int>>> - sort this by second element in the pair (column)
    
    0: (3, (0, 0))
    1: (9, (1, -1))
    2: (20, 1)
    3: (15, 0)
    4: (7, 0)
    
    using a hash table, where the key would be the column number, and the value would be all of the node values at that column, the order should be fine because the traversal would follow that order
    
    
    Time: O(n) + O(nlogn) = O(nlogn)
    Space: O(n) + O(n) = O(n)
    
Approach 2: do a level order traversal to guarantee that nodes that are being added are the correct order

 using a hash table, where the key would be the column number, and the value would be all of the node values at that column, the order should be fine because the traversal would follow that order
    
    
    Time: O(n)
    Space: O(n)
*/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        unordered_map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> nodes; //keep track of node and column
        nodes.push(make_pair(root, 0));
        int minCol = 0;
        int maxCol = 0;
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                pair<TreeNode*, int> element = nodes.front();
                TreeNode* node = element.first;
                int column = element.second;
                nodes.pop();
                columns[column].push_back(node->val);
                if (node->left) {
                    nodes.push(make_pair(node->left, column - 1));
                    if (minCol > column - 1) {
                        minCol = column - 1;
                    }
                }
                if (node->right) {
                    nodes.push(make_pair(node->right, column + 1));
                    if (maxCol < column + 1) {
                        maxCol = column + 1;
                    }
                }
            }
        }
        for (int i = minCol; i <= maxCol; i++) {
            result.push_back(columns[i]);
        }
        return result;
    }
};