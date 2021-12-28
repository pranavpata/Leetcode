class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //build graph
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] != 0) {
                    adj[i].push_back(j);
                }
            }
        }
        
        //keeps track of visited cities
        vector<int> vis(n, 0);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            //every unvisited city adds another province
            if(!vis[i]){
                ans+=1;
                //visit each city in the current province
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
    
    void dfs(int i,vector<int> adj[],vector<int> &vis) {
        vis[i] = 1;
        
        for(auto x: adj[i]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
};