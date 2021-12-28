class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        int nums[size];
        
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2 && k < size) {
            if (nums1[i] <= nums2[j])
                nums[k++] = nums1[i++];
            else
                nums[k++] = nums2[j++];
        }
        
        while (i < size1) nums[k++] = nums1[i++];
        while (j < size2) nums[k++] = nums2[j++];
        
        if (size%2 == 1)
            return (double) nums[size/2];
        else 
            return ((double) (nums[size/2] + nums[size/2 - 1]))/2;
        
    }
};