class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> counts;
        int left = 0; int right = 0;
        int result = 0;
        char c;
        int unique = 0;
        while (right < s.size()) {
            //expand string
            c = s[right];
            counts[c]++;
            if (counts[c] == 1) {
                unique++;
            }
            right++;
            //shrink string
            while (unique > k) {
                c = s[left];
                counts[c]--;
                if (counts[c] == 0) {
                    unique--;
                }
                left++;
            }
            //guaranteed that string is a valid length
            result = max(result, right - left);
        }
        return result;
    }
};