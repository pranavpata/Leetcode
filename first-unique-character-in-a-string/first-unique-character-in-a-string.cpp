class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> counts;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            counts[s[i] - 'a']++;
        }
        for (int i = 0; i < size; i++) {
            if (counts[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};