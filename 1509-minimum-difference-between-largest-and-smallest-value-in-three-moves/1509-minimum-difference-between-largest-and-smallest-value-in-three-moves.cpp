class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
	        return 0;
        sort(nums.begin(), nums.end());
        // we can reduce the difference by 'removing' element at both ends.
        // when we say 'remove', we actually mean: 
        // 1. select nums[0] and change it to nums[1], or
        // 2. select nums[n - 1] and change it to nums[n - 2].
        // both case will reduce the difference between largest and smallest elements.

        int n = nums.size();
        int ret = INT_MAX;

        // check if we remove i elements from left and remove j elements from right.
        for (int i = 0; i <= 3; ++i)
        {
            for (int j = 0; i + j <= 3; ++j)
            {
                int d = nums[n - 1 - j] - nums[i];
                ret = min(ret, d);
            }
        }

        return ret;
    }
};