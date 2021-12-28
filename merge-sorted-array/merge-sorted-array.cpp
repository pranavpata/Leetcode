class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1=nums1.size()-1;
       for(int i=0;i<nums2.size();i++)
       {
           nums1[size1]=nums2[i];
           size1--;
       }
       sort(nums1.begin(),nums1.end());
    }
};