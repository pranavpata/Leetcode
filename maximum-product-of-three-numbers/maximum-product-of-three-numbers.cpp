class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return max(nums[0] * nums[1] * nums.back(), nums.back() * nums.end()[-2] * nums.end()[-3]);
    }
};