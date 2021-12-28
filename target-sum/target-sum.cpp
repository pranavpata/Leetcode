class Solution {
public:
    int toReturn = 0;
    
    int findTargetSumWays(vector<int>& nums, int target) {
        findWays(nums, target, 0, 0);
        return toReturn;
    }
    
    void findWays(vector<int>& nums, int target, int index, int sum) {
        //base case
        if (index == nums.size()) {
            if (target == sum) {
                toReturn++;
            }
            return;
        }
        
        findWays(nums, target, index + 1, sum + nums[index]);
        findWays(nums, target, index + 1, sum - nums[index]);
    }
    
};