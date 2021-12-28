class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int toReturn = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[toReturn++] = nums[i];
            }
        }
        
        return toReturn;
    }
};