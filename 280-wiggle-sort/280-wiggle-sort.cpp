class Solution {
private:
    void mySwap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void wiggleSort(vector<int>& nums) {
        bool less = true;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (less) {
            if (nums[i] > nums[i + 1]) {
                mySwap(nums, i, i + 1);
            }
        } else {
            if (nums[i] < nums[i + 1]) {
                mySwap(nums, i, i + 1);
            }
        }
        less = !less;
    }
    }
};