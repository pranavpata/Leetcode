class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        int start, end, inc;
        for (vector<int> vec : updates) {
            start = vec[0]; end = vec[1]; inc = vec[2];
            result[start] += inc;
            if (end < length - 1) {
                result[end + 1] -= inc;
            }
        }
        partial_sum(result.begin(), result.end(), result.begin());
        return result;
    }
};