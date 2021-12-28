class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.back() >= nums[0]) return nums[0];
        int n = nums.size(); int low = 0; int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            else if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[mid] > nums[low]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return 0;
    }
};