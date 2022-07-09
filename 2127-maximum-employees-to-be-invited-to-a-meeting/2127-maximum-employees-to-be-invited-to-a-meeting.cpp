class Solution {
public:
    int result = 0;
    vector<bool> visited;
    
    int dfs(int cur, vector<int> adj[]) {
        visited[cur] = true;
        int res = 0;
        for(auto x:adj[cur]){
            res = max(res,dfs(x,adj));
        }
        return res + 1;
    }
    
    int maximumInvitations(vector<int>& fav) {
        int size = fav.size();
        vector<int> adj[size];
        visited.resize(size,false);
        for (int i = 0; i < size; i++) {
            if (fav[fav[i]] != i) adj[fav[i]].push_back(i);
        }
        
        int result = 0;
        
        for (int i = 0; i < size; i++) {
            if(fav[fav[i]] == i) result += dfs(i,adj);
        }
        
        for (int i = 0; i < size; i++) {
            int count = 0, j = i;
            for (; !visited[j]; j = fav[j]) {
                visited[j] = true;
                count++;
            }
            for(int k = i;k != j;k = fav[k]) count--;
            result = max(result ,count);
        }
        
        return result;
    }
};