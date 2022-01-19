class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int i=n-1,j=i/2;
        int k=0;
        while(k<n)
        {
            if( k % 2 == 1 )
            {
                nums[k++]=temp[i--];
            }
            else
            {
                nums[k++]=temp[j--];
            }
        }
    }
};