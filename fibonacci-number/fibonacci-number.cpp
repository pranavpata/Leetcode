class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int num1 = 0;
        int num2 = 1;
        for (int i = 2; i <= n; i++) {
            num2 += num1;
            num1 = num2 - num1;
        }
        return num2;
    }
};