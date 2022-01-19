class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return;
        sort(nums.begin(),nums.end());
        int it1=(n%2!=0)?n/2:(n/2)-1;
        int it2=n-1,max=nums[it2]+1;;
        for(int i=0;i<n;i+=2)
            nums[i]=(nums[it1--]%max)*max+nums[i];
        for(int i=1;i<n;i+=2)
            nums[i]=(nums[it2--]%max)*max+nums[i];
        for(int i=0;i<n;i++)
            nums[i]/=max;
    }
};