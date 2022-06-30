class Solution {
public:
    int numSplits(string s) {
        int size = s.length();
        int result = 0;
        
        vector<int> prefix(size);
        vector<int> suffix(size);
        unordered_set<int> seen;
        
        for (int i = 0; i < size; ++i) {
          seen.insert(s[i]);
          prefix[i] = seen.size();
        }
        
        seen.clear();
        
        for (int i = size - 1; i >= 0; --i) {
          seen.insert(s[i]);
          suffix[i] = seen.size();
        }
        
        for (int i = 0; i < size - 1; i++) {
            if (prefix[i] == suffix[i+1]) result++;
        }
        
        return result;
    }
};