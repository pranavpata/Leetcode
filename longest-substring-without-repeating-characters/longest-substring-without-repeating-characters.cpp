class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int toReturn = 0;
        int left = 0;
        int right = 0;
        vector<int> chars(128, -1);
        while (right < s.length()) {
            char r = s[right];
            int index = chars[r];
            if(index != -1 && index >= left && index < right) {
                left = index+1;
            }
            
            toReturn = max(toReturn, right - left + 1);
            chars[r] = right;
            right++;
        }
        return toReturn;
    }
};