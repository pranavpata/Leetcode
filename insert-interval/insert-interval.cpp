class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> toReturn;
        
        for (auto &interval : intervals) {
            if (interval[0] <= newInterval[0]) {
                toReturn.push_back(interval);
            }
            else {
                break;
            }
        }
        
        if (toReturn.empty() || toReturn.back()[1] < newInterval[0]) {
            toReturn.push_back(newInterval);
        }
        else {
            toReturn.back()[1] = max(toReturn.back()[1], newInterval[1]);
        }
        
        for (auto &interval : intervals) {
            if (interval[0] <= newInterval[0]) {
                continue;
            }
            if (toReturn.back()[1] >= interval[0]) {
                toReturn.back()[1] = max(toReturn.back()[1], interval[1]);
            }
            else {
                toReturn.push_back(interval);
            }
        }
        
        return toReturn;
    }
};