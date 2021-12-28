class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid, num;
        while (low <= high) {
            mid = (low + high)/2;
            num = nums[mid];
            if (target == num) {
                return mid;
            }
            else if (target < num) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
};