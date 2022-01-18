class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adjacency list graph
        vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
        for(auto &t : times){
             graph[t[0]].emplace_back(t[1], t[2]);
        }
        
        const int inf = 1e9;
        vector<int> distance(n+1, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes;
        
        nodes.push({0, k});
        distance[k] = 0;
        
        while(!nodes.empty()){
            int u = nodes.top().second; nodes.pop();
            
            for(auto adj : graph[u]){
                int v = adj.first, w = adj.second;
                if(distance[v] > (distance[u]+w)){
                    distance[v] = distance[u]+w ;
                    nodes.push({distance[v], v});
                }
            }
        }
        
        auto ans = *max_element(distance.begin()+1, distance.end());
        
        return ans == inf ? -1 : ans;
    }
};