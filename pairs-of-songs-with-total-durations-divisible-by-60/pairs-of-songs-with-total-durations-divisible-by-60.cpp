class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        unordered_map<int, int> times;
        for (int num : time) {
            num = num%60;
            result += times[60-num];
            if (num == 0) num = 60;
            times[num]++;
        }
        return result;
    }
};