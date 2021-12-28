class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        int curArea;
        while (left < right) {
            curArea = (right - left)*min(height[left], height[right]);
            maxArea = max(maxArea, curArea);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea;
    }
};