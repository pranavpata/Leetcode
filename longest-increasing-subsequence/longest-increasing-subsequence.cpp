class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(lis[i]<lis[j]+1 && nums[i]>nums[j]) lis[i]=lis[j]+1;
            }
         }
      
        return *max_element(lis.begin(), lis.end());
    }
};