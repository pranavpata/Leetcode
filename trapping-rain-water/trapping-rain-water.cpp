class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int toReturn = 0;
        int lmax = 0, rmax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= lmax ? (lmax = height[left]) : toReturn += (lmax - height[left]);
                left++;
            }
            else {
                height[right] >= rmax ? (rmax = height[right]) : toReturn += (rmax - height[right]);
                right--;
            }
        }
        return toReturn;
    }
};