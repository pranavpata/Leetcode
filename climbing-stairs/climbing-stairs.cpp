class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        int l1 = 1;
        int l2 = 2;
        for (int i = 3; i <= n; i++) {
            l2 = l1 + l2;
            l1 = l2 - l1;
        }
        return l2;
    }
};