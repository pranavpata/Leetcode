class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int j, k;
        int diff = INT_MAX;
        int curDiff = INT_MAX;
        int curSum;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
            }
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                curSum = nums[i] + nums[j] + nums[k];
                curDiff = curSum - target;
                if (abs(curDiff) < abs(diff)) diff = curDiff;
                if (curDiff > 0) {
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                }
                else if (curDiff < 0) {
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                }
                else {
                    return target;
                }
            }
        }
        return target + diff;
    }
};