class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool visited[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            visited[i] = false;
        }
        return jumper(nums, 0, visited);
    }
    
    bool jumper(vector<int>& nums, int index, bool *visited) {
        if (index == nums.size() - 1) return true;
        visited[index] = true;
        int jump = nums[index];
        for (int i = 1; i <= jump; i++) {
            if (index+i < nums.size() && !visited[index+i]) {
                if (jumper(nums, index+i, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};