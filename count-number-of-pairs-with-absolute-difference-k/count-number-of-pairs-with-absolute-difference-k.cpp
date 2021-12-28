class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int toReturn = 0;
        map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            toReturn += seen[nums[i] + k] + seen[nums[i] - k];
            seen[nums[i]] += 1;
        }
        return toReturn;
    }
};