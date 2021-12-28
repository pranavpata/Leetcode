class Solution {
public:
    static bool cmp(vector<int>& one, vector<int>& two) { return one[1] < two[1]; }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 1;
        auto prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prev[1]) {
                prev = intervals[i];
                ans++;
            }
        }
        return intervals.size() - ans;
    }
};