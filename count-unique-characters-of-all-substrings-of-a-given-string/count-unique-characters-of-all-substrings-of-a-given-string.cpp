class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0;
        int count = 0;
        vector<int> lastCount(26);
        vector<int> lastSeen(26, -1);

        for (int i = 0; i < s.length(); ++i) {
          const int c = s[i] - 'A';
          const int currentCount = i - lastSeen[c];
          count = count - lastCount[c] + currentCount;
          lastCount[c] = currentCount;
          lastSeen[c] = i;
          ans += count;
        }

        return ans;
//         vector<vector<int>> locs(26, vector<int>(1, -1)); 
//         for (int i = 0; i < s.size(); ++i) locs[s[i] - 'A'].push_back(i); 
        
//         int ans = 0; 
//         for (int i = 0; i < 26; ++i) {
//             locs[i].push_back(s.size()); 
//             for (int k = 1; k < locs[i].size()-1; ++k) 
//                 ans += (locs[i][k] - locs[i][k-1]) * (locs[i][k+1] - locs[i][k]); 
//         }
//         return ans; 
    }
};