class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int numsArr[10001] = {0};
        int maxTmp = 0;
        for(int i=0; i<nums.size(); i++){
            numsArr[nums[i]]++;
            if(maxTmp < nums[i])
                maxTmp = nums[i];
        }
        int incl = 0, excl = 0;
        for(int i=0; i<=maxTmp; i++){
            int tmp = excl;
            excl = max(excl, incl);
            incl = tmp + numsArr[i] * i; //We calculate the sum including the element
        }
        
        return max(incl, excl);
    }
};