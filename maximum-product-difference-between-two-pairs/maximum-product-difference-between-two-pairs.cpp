class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int lowest, low, highest, high;
        if (nums[0] < nums[1]) {
            lowest = 0;
            low = 1;
            highest = 1;
            high = 0;
        }
        else {
            lowest = 1;
            low = 0;
            highest = 0;
            high = 1;
        }
        int current;
        for (int i = 2; i < nums.size(); i++) {
            current = nums[i];
            if (current > nums[highest]) {
                high = highest;
                highest = i;
            }
            else if (current > nums[high]) {
                high = i;
            }
            if (current < nums[lowest]) {
                low = lowest;
                lowest = i;
            }
            else if (current < nums[low]) {
                low = i;
            }
        }
        return nums[highest] * nums[high] - nums[lowest] * nums[low];
    }
};