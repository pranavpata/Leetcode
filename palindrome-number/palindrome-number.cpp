class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0) {
            string num = to_string(x);
            for (int i = 0; i < num.size(); i++) {
                if (num[i] != num[num.size() - i - 1]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};