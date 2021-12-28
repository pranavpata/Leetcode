class Solution {
public:
    vector<vector<int>> toReturn;
    
    vector<vector<int>> permute(vector<int>& nums) {
        pickNumbers(nums, 0, nums.size() - 1);
        return toReturn;
    }
    
    void pickNumbers(vector<int>& nums, int index, int end) {
        if (index == end) {
            toReturn.push_back(nums);
            return;
        }
        for (int i = index; i <= end; i++) {
            swap(nums[index], nums[i]);
            pickNumbers(nums, index+1, end);
            swap(nums[index], nums[i]);
        }
    }
};