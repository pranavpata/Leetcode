class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // make adjacency list representation
        vector<vector<int>> graph(n, vector<int>());
        for(auto edge: prerequisites){
            int u = edge.at(1);
            int v = edge.at(0);
            graph[u].push_back(v);
        }
        
        // check vertex that has zero indegree
        queue<int> qq;
        vector<int> inDegree(n, 0);
        
        for(int i=0; i<n; ++i){
            for(auto v: graph.at(i)){
                inDegree.at(v)++;
            }
        }
        for(int i=0; i<n; ++i){
            if(inDegree.at(i)==0){
                qq.push(i);
            }
        }
        
        vector<int> result;
        
        while(!qq.empty()){
            int u = qq.front(); qq.pop();
            result.push_back(u);
            
            for(auto v : graph.at(u)){
                --inDegree.at(v);
                if(inDegree.at(v) == 0){
                    qq.push(v);
                }
            }
        }
        
        if(result.size() != n)return {};
        
        return result;
    }
};