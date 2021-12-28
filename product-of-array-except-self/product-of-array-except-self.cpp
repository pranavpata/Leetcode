class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int flag=0,mul=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) mul=mul*nums[i];
            else flag++;
        }
        for(int i=0;i<n;i++){
            if(flag==1){
                if(nums[i]==0) nums[i]=mul;
                else nums[i]=0;
            }
            if(flag==0 && nums[i]!=0) nums[i]=mul/nums[i];
            if(flag>1 || flag==n) nums[i]=0;
           
        }
        return nums;
    }
};