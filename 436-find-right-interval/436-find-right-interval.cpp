class Solution {
private:
    int binary_search(vector<pair<vector<int>, int>>& sorted, int target) {
        int size = sorted.size();
        if (sorted[size - 1].first[0] < target) return -1;
        
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (sorted[mid].first[0] >= target) right = mid - 1;
            else {
                left = mid + 1;
            }
        }
        return sorted[left].second;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<int> result(size, -1);
        vector<pair<vector<int>, int>> sorted;
        for (int i = 0; i < size; i++) {
            sorted.push_back({intervals[i], i});
        }
        
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < size; i++) {
            result[i] = binary_search(sorted, intervals[i][1]);
        }
        
        return result;
    }
};