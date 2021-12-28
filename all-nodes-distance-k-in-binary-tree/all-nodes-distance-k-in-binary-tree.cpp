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
    unordered_map<TreeNode*, TreeNode*> mp;
    
    void allocateParents(TreeNode* root) {
        if(root==NULL) return;
        
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        
        allocateParents(root->left);
        allocateParents(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
          allocateParents(root);    
          set<int> visited;
        
          queue<TreeNode*> q;
          int cnt = 0;
        
          q.push(target);
          vector<int> ans;
        
         while(!q.empty()){
              cnt++;
              int sz = q.size();
              
              for(int i=0; i<sz; i++){
                  TreeNode* tmp = q.front();
                  q.pop();
                  if(visited.find(tmp->val)==visited.end()){
                      visited.insert(tmp->val);
                      if(tmp->left && visited.find(tmp->left->val)==visited.end()) q.push(tmp->left);
                      if(tmp->right && visited.find(tmp->right->val)==visited.end()) q.push(tmp->right);
                      if(mp[tmp]!=NULL && visited.find(mp[tmp]->val)==visited.end()) q.push(mp[tmp]);
                  }
              }
                if(cnt==k) break;  
         }
            while(!q.empty()){
                TreeNode* tmp = q.front();
                q.pop();
                ans.push_back(tmp->val);
            }
        return ans;
    }
};