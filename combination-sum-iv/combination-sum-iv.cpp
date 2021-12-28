class Solution {
public:
    unordered_map<int, int> m;
    
    int recurse(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (m.count(target)) return m[target];
        int toReturn = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target-nums[i] >= 0) {
                toReturn += recurse(nums, target-nums[i]);
            }
        }
        m[target] = toReturn;
        return toReturn;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return recurse(nums, target);
    }
};