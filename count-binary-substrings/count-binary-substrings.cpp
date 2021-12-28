class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0, prev = 0, cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] != s[i]) {
                result += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            else {
                cur++;
            }
        }
        return result + min(prev, cur);
    }
};