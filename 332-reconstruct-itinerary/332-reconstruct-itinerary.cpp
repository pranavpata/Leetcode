class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> graph;
    vector<string> result;
    
    void dfs(string start) {
        while (!graph[start].empty()) {
            string temp = graph[start].top();
            graph[start].pop();
            dfs(temp);
        }
        result.push_back(start);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};