class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = nums[0];
        int result = INT_MAX;
        while (right < nums.size()) {
            if (sum >= target) {
                result = min(result, right - left + 1);
                if (left == right) return 1;
                else {
                    sum -= nums[left++];
                }
            }
            else {
                right++;
                if (right < nums.size()) {
                    sum += nums[right];
                }
            }
            cout << right << "\n";
        }
        if (result == INT_MAX) result = 0;
        return result;
    }
};