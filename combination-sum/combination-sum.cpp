class Solution {
public:
    
    vector<vector<int>> toReturn;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        find(candidates, target, current, 0);
        return toReturn;
    }
    
    void find(vector<int>& candidates, int target, vector<int>& current, int index) {
        if (index == candidates.size()) {
            if (target == 0) {
                toReturn.push_back(current);
            }
            return;
        }
        
        if (target >= candidates[index]) {
            current.push_back(candidates[index]);
            find(candidates, target - candidates[index], current, index);
            current.pop_back();
        }
        find(candidates, target, current, index + 1);
    }
};