class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>lag(n+1,0);
        int i=0;
        int count=0;
        while(i<=n-k)
        {
            if(i!=0)
            lag[i]+=lag[i-1];
            if((nums[i]+lag[i])%2==0)
            {
                count++;
                lag[i+k]--;
                lag[i]++;
            }
            i++;
        }
        for(int i=n-k+1;i<n;i++)
        {
            lag[i]+=lag[i-1];
            if((nums[i]+lag[i])%2==0)
                return -1;
        }
        return count;
    }
};