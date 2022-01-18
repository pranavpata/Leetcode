class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] - a[0] == b[1] - b[0]) return a[1] < b[1];
        return a[1] - a[0] > b[1] - b[0];
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        sort (tasks.begin(), tasks.end(), cmp);
        int result = 0;
        int current = 0;
        for (auto task : tasks) {
            if (current < task[1]) {
                result += task[1] - current;
                current = task[1] - task[0];
            }
            else {
                current = current - task[0];
            }
        }
        return result;
    }
};