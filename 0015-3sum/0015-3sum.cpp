class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> toReturn;
        int size = nums.size();
        if (size >= 3) {
            int j, k, curSum;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < size - 1; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                j = i + 1;
                k = size - 1;
                while (j < k) {
                    curSum = nums[i] + nums[j] + nums[k];
                    if (curSum > 0) {
                    k--;
                    }
                    else if (curSum < 0) {
                        j++;
                    }
                    else {
                        toReturn.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j+1]) j++;
                        while(j < k && nums[k] == nums[k-1]) k--;
                        j++;
                        k--;
                    }
                }
            }
        }
        return toReturn;
    }
    
    
};