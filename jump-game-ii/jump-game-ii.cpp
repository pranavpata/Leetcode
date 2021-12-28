class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,INT_MAX);
        ans[0] = 0;
        
        int i=0, j=1;
        while(i<nums.size()){
            j=i+1;
            while(j<nums.size() && j-i<=nums[i]){
                ans[j] = min(ans[i]+1, ans[j]);
                j++;
            }
            i++;
        }
        return ans[n-1];
    }
};