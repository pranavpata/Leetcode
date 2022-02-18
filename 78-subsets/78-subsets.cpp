class Solution {
public:
    vector<vector<int>> toReturn;
    
    void recurse(vector<int>& nums, int index, vector<int>& cur) {
        if (index == nums.size()) return;
        
        if (find(toReturn.begin(), toReturn.end(), cur) == toReturn.end()) {
            toReturn.push_back(cur);
        }
        recurse(nums, index+1, cur);
        cur.push_back(nums[index]);
        if (find(toReturn.begin(), toReturn.end(), cur) == toReturn.end()) {
            toReturn.push_back(cur);
        }
        recurse(nums, index+1, cur);
        cur.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        recurse(nums, 0, current);
        return toReturn;
    }
};