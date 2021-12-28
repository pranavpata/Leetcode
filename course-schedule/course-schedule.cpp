class Solution {
public:
    bool hasCycle(unordered_map<int, vector<int>>& graph, int i, vector<int>& visited) {
        visited[i] = 1;
        for (auto vec:graph[i]) {
            if(visited[vec]==1 || (visited[vec]==0 && hasCycle(graph,vec,visited)))
                return true;
        }
        visited[i]=2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycle(graph, i, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};