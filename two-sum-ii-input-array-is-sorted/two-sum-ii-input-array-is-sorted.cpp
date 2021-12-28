class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp; //num to index
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            if (mp[target-numbers[i]]) {
                result.push_back(mp[target-numbers[i]]);
                result.push_back(i+1);
                return result;
            }
            mp[numbers[i]] = i+1;
        }
        return result;
    }
};