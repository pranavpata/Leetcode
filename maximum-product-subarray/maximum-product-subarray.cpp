class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int toReturn = nums[0];
        int left = 1, right = 1;
        for (int i = 0; i < n; i++) {
            left = left * nums[i];
            right = right * nums[n - i - 1];
            toReturn = max(toReturn, max(left, right));
            if (left == 0) left = 1;
            if (right == 0) right = 1;
        }
        return toReturn;
    }
};