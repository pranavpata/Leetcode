class Solution {
public:  
    int squared(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        for (int i = 0; i < points.size(); i++) {
            pair<int, int> entry = {squared(points[i]), i};
            if (maxPQ.size() < k) {
                maxPQ.push(entry);
            }
            else if (entry.first < maxPQ.top().first) {
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        
        
        vector<vector<int>> result;
        while (!maxPQ.empty()) {
            int index = maxPQ.top().second;
            maxPQ.pop();
            result.push_back(points[index]);
        }
        return result;
    }
};