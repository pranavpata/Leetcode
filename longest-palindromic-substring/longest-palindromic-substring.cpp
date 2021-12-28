class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int len, len1, len2;
        for (int i = 0; i < s.length(); i++) {
            len1 = expand(s, i, i);
            len2 = expand(s, i, i+1);
            len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};